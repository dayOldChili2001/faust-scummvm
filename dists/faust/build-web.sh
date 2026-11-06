#!/bin/sh
# Build the Faust web version (Emscripten) into a folder you can serve.
#
#   dists/faust/build-web.sh [output dir]      (default: ./dist-web)
#   cd dist-web && python3 -m http.server 8000
#   then open http://localhost:8000/
#
# Needs: git, python3, make, zip, curl. The emsdk version ScummVM pins is
# downloaded once into ~/.cache/faust-web. configure can't handle spaces in
# paths, so keep the source and output folders on space-free paths.
#
# No game data is built in or served: the page asks each player for their
# own Faust folder and reads it in the browser (mounted at /game).
set -e

EMSDK_VERSION=4.0.10
SRC=$(cd "$(dirname "$0")/../.." && pwd)
OUT=${1:-$PWD/dist-web}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
BUILD=$SRC/build-web
CACHE=$HOME/.cache/faust-web

case "$SRC$OUT" in
*" "*) echo "error: the source and output paths must not contain spaces" >&2; exit 1 ;;
esac

if [ ! -d "$CACHE/emsdk-$EMSDK_VERSION/upstream" ]; then
	mkdir -p "$CACHE"
	curl -sL "https://github.com/emscripten-core/emsdk/archive/refs/tags/$EMSDK_VERSION.tar.gz" | tar xz -C "$CACHE"
	"$CACHE/emsdk-$EMSDK_VERSION/emsdk" install $EMSDK_VERSION
	"$CACHE/emsdk-$EMSDK_VERSION/emsdk" activate $EMSDK_VERSION
fi
. "$CACHE/emsdk-$EMSDK_VERSION/emsdk_env.sh" >/dev/null 2>&1

mkdir -p "$BUILD"
cd "$BUILD"
if [ ! -f config.mk ]; then
	# Keep this machine's source path out of the binary (assert messages)
	CXXFLAGS="-ffile-prefix-map=$SRC/=" CFLAGS="-ffile-prefix-map=$SRC/=" \
	emconfigure "$SRC/configure" --host=wasm32-unknown-emscripten --build=wasm32-unknown-emscripten \
		--disable-all-engines --enable-engine=ring,faust --disable-detection-full \
		--enable-faust-standalone --enable-release
fi
emmake make -j"$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)"
emmake make dist-emscripten
cp -R build-emscripten/. "$OUT/"

# First-run settings (the browser keeps them in IndexedDB afterwards)
printf '%s\n' '[scummvm]' 'enable_unsupported_game_warning=false' '' \
	'[faust]' 'gameid=faust' 'engineid=ring' 'description=Faust' 'path=/game' > "$OUT/scummvm.ini"

# The site root opens the game
cat > "$OUT/index.html" <<'EOF'
<!DOCTYPE html>
<html lang="en"><head><meta charset="utf-8"><title>Faust</title>
<meta http-equiv="refresh" content="0; url=scummvm.html#faust">
</head><body><a href="scummvm.html#faust">Play Faust</a></body></html>
EOF

echo "Built into $OUT"
