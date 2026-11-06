# Faust: The Seven Games of the Soul, on ScummVM

This is a ScummVM build for one game: **Faust: The Seven Games of the Soul**
(Arxel Tribe, 1999). It runs in a web browser now, and Mac and Windows builds
are on the way. It uses the ScummVM "Ring" engine, originally written by
Littleboy, with every missing piece filled in so that all seven episodes play
to the end.

**You need your own copy of the game.** This repository and its builds contain
none of Faust's files. The game is copyrighted and isn't distributed here.

## Playing in the browser

1. Open the web build (or build and serve it yourself, see below).
2. When the page asks, pick your Faust folder: the one that contains
   `FAUST.EXE`. Picking the folder above it works too. The files are read in
   your browser and are never uploaded anywhere.
3. Chrome and Edge remember the folder, so later visits only need one click
   ("Continue with …"). Firefox and Safari ask for the folder on every visit.

Your saves and settings are kept in the browser's storage for this site.
Clearing the site's data deletes them.

### Keys

| Key | What it does |
| --- | --- |
| **F8** | Opens the ScummVM menu (volume, key mapping, About). |
| Escape | Skips a movie or credits, and closes menus. |
| Space | Opens the in-game menu (map, hints) during play. |
| F12 | Opens the game's main menu (save, load, options). Some browsers use F12 for their developer tools. If yours does, right-click in the game and click **Menu** at the top left. |
| Up / Down | Zooms in a panorama. |

**Don't press Ctrl+F5 in the browser.** In desktop ScummVM it opens the
ScummVM menu, but in a browser it reloads the page, and anything since your
last in-game save is lost. Use F8 instead.

### Tested and not yet tested

- Tested: headless Chrome. The whole game plays to the end in the desktop
  build's automated tests. The web build was checked with a new user, a game
  start, a save, a page reload and a load.
- Not yet tested: Firefox, Safari, phones and tablets, and long sessions.
  Bug reports are welcome.
- Only the English version has been tested.

## Building

The web build needs `git`, `python3`, `make`, `zip` and `curl`. The script
downloads the Emscripten SDK version ScummVM pins (into `~/.cache/faust-web`).
ScummVM's `configure` doesn't support spaces in paths.

```sh
git clone <this repository> faust-scummvm
cd faust-scummvm
dists/faust/build-web.sh ~/faust-web
cd ~/faust-web && python3 -m http.server 8000
# then open http://localhost:8000/
```

For a desktop build to develop with:

```sh
./configure --disable-all-engines --enable-engine=ring,faust \
    --disable-detection-full --enable-faust-standalone
make -j8
./scummvm
```

The `faust` branch holds the changes on top of ScummVM. Most of them are in
`engines/ring/`, plus `--enable-faust-standalone` (start straight into the
game, with Faust branding) and the browser folder picker
(`dists/emscripten/faust/`, `backends/fs/emscripten/local-fs.cpp`).

## Licence and credits

This is GPL-3.0-or-later software, like ScummVM itself (see `COPYING`).

- The Ring engine for ScummVM: Littleboy.
- ScummVM: the ScummVM team (see `AUTHORS`).
- Faust: The Seven Games of the Soul © 1999 Arxel Tribe / Cryo Interactive.
  This project isn't affiliated with or endorsed by the rights holders.

ScummVM's own README is [`README.md`](../README.md) in the root folder.
