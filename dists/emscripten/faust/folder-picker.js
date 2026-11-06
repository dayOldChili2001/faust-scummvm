/*global Module, addRunDependency, removeRunDependency*/
// Faust: the player picks their own game folder before the engine starts.
// Nothing is uploaded or served: the files are read in the browser and
// mounted read-only at /game (backends/fs/emscripten/local-fs.cpp).
//
// Browsers with showDirectoryPicker (Chrome, Edge) keep the folder handle in
// IndexedDB, so a return visit only needs one click to grant access again.
// Other browsers use <input webkitdirectory> and ask on every visit.
(function () {
	var DEP = "faust-folder";

	// Read by custom_shell-pre.js (loaded after this file): Faust has no MIDI
	// music, so the page never asks for Web MIDI access
	globalThis.faustNoMidi = true;

	// Lower-cased path -> { name, dir: [lower-cased child paths] } or { name, file | handle }
	var entries = {};
	globalThis.faustLocalFs = {
		stat: function (path) {
			var e = entries[path.toLowerCase()];
			return e ? (e.dir ? 2 : 1) : 0;
		},
		list: function (path) {
			var e = entries[path.toLowerCase()];
			if (!e || !e.dir) return null;
			return e.dir.map(function (p) { return (entries[p].dir ? "D" : "F") + entries[p].name; }).join("\n");
		},
		realName: function (path) {
			var e = entries[path.toLowerCase()];
			return e ? e.name : null;
		},
		read: async function (path) {
			var e = entries[path.toLowerCase()];
			if (!e || e.dir) return null;
			var file = e.file || await e.handle.getFile();
			return new Uint8Array(await file.arrayBuffer());
		}
	};

	function addDir(path, name) {
		var key = path.toLowerCase();
		if (!entries[key]) {
			entries[key] = { name: name, dir: [] };
			var slash = key.lastIndexOf("/");
			if (slash > 0) {
				var parent = path.substring(0, slash);
				addDir(parent, parent.substring(parent.lastIndexOf("/") + 1));
				entries[parent.toLowerCase()].dir.push(key);
			}
		}
	}
	function addFile(path, value) {
		var key = path.toLowerCase(), slash = path.lastIndexOf("/");
		var parent = path.substring(0, slash);
		addDir(parent, parent.substring(parent.lastIndexOf("/") + 1));
		if (!entries[key]) entries[parent.toLowerCase()].dir.push(key);
		value.name = path.substring(slash + 1);
		entries[key] = value;
	}

	// Picking the folder above Game (or the CD itself) is fine too: use the
	// first folder, breadth first, that holds FAUST.EXE.
	function findGameRoot(list) {
		var best = null;
		list.forEach(function (rel) {
			var parts = rel.split("/");
			if (parts[parts.length - 1].toLowerCase() === "faust.exe" &&
				(best === null || parts.length - 1 < best.length))
				best = parts.slice(0, -1);
		});
		return best;
	}
	function mount(items) { // items: [{ rel: "a/b/c", file | handle }]
		var root = findGameRoot(items.map(function (i) { return i.rel; }));
		if (!root) return false;
		var prefix = root.length ? root.join("/") + "/" : "";
		entries = {};
		addDir("/game", "game");
		items.forEach(function (i) {
			if (i.rel.substring(0, prefix.length).toLowerCase() !== prefix.toLowerCase()) return;
			addFile("/game/" + i.rel.substring(prefix.length), i.file ? { file: i.file } : { handle: i.handle });
		});
		return true;
	}

	async function walk(dirHandle, rel, out) {
		for await (var h of dirHandle.values()) {
			var p = rel ? rel + "/" + h.name : h.name;
			if (h.kind === "directory") await walk(h, p, out);
			else out.push({ rel: p, handle: h });
		}
		return out;
	}

	// The handle store (one key, "game")
	function db() {
		return new Promise(function (resolve, reject) {
			var r = indexedDB.open("faust-folder", 1);
			r.onupgradeneeded = function () { r.result.createObjectStore("handles"); };
			r.onsuccess = function () { resolve(r.result); };
			r.onerror = function () { reject(r.error); };
		});
	}
	async function storeHandle(h) {
		try {
			var d = await db();
			d.transaction("handles", "readwrite").objectStore("handles").put(h, "game");
		} catch (e) { console.warn("Faust: can't remember the folder", e); }
	}
	async function loadHandle() {
		try {
			var d = await db();
			return await new Promise(function (resolve) {
				var r = d.transaction("handles").objectStore("handles").get("game");
				r.onsuccess = function () { resolve(r.result || null); };
				r.onerror = function () { resolve(null); };
			});
		} catch (e) { return null; }
	}

	var ui = {};
	function message(text, isError) {
		ui.msg.textContent = text;
		ui.msg.style.color = isError ? "#f88" : "#ddd";
	}
	function done() {
		ui.box.remove();
		removeRunDependency(DEP);
	}
	async function useHandle(h) {
		message("Reading the folder…");
		var items = await walk(h, "", []);
		if (!mount(items)) {
			message("FAUST.EXE isn't in “" + h.name + "”. Choose the folder of your Faust copy that contains FAUST.EXE.", true);
			return;
		}
		await storeHandle(h);
		done();
	}
	async function pickWithApi() {
		var h;
		try {
			h = await window.showDirectoryPicker({ id: "faust", mode: "read" });
		} catch (e) {
			if (e.name !== "AbortError") message("The folder couldn't be opened: " + e.message, true);
			return;
		}
		await useHandle(h);
	}
	function pickWithInput() {
		var files = ui.input.files;
		if (!files || !files.length) return;
		var items = Array.prototype.map.call(files, function (f) {
			return { rel: f.webkitRelativePath.split("/").slice(1).join("/") || f.name, file: f };
		});
		if (!mount(items)) {
			message("FAUST.EXE isn't in that folder. Choose the folder of your Faust copy that contains FAUST.EXE.", true);
			return;
		}
		done();
	}

	function button(label, onclick) {
		var b = document.createElement("button");
		b.textContent = label;
		b.style.cssText = "margin:6px;padding:10px 18px;font-size:16px;background:#5a1012;color:#fff;border:1px solid #c9a24a;border-radius:4px;cursor:pointer";
		b.onclick = onclick;
		return b;
	}

	async function show() {
		var box = ui.box = document.createElement("div");
		box.id = "faust-folder";
		box.style.cssText = "position:fixed;inset:0;z-index:100;display:flex;flex-direction:column;align-items:center;justify-content:center;" +
			"background:#1a0304;color:#ddd;font-family:Georgia,serif;text-align:center;padding:20px";
		var title = document.createElement("h1");
		title.textContent = "Faust";
		title.style.cssText = "color:#c9a24a;font-weight:normal;margin:0 0 12px";
		var text = document.createElement("p");
		text.style.cssText = "max-width:560px;line-height:1.4";
		text.textContent = "Faust plays from your own copy of the game. Choose the game folder (the one that contains FAUST.EXE). " +
			"The files stay on your computer: they are read by this page and never uploaded.";
		ui.msg = document.createElement("p");
		ui.msg.id = "faust-folder-msg";
		ui.msg.style.cssText = "max-width:560px;min-height:1.4em";
		var buttons = document.createElement("div");

		ui.input = document.createElement("input");
		ui.input.type = "file";
		ui.input.id = "faust-folder-input";
		ui.input.webkitdirectory = true;
		ui.input.multiple = true;
		ui.input.style.display = "none";
		ui.input.onchange = pickWithInput;

		var stored = window.showDirectoryPicker ? await loadHandle() : null;
		if (stored) {
			buttons.appendChild(button("Continue with “" + stored.name + "”", async function () {
				var p = await stored.requestPermission({ mode: "read" });
				if (p === "granted") await useHandle(stored);
				else message("Access to the folder was not allowed.", true);
			}));
		}
		buttons.appendChild(button(stored ? "Choose another folder" : "Choose the game folder", function () {
			if (window.showDirectoryPicker) pickWithApi();
			else ui.input.click();
		}));
		box.append(title, text, buttons, ui.msg, ui.input);
		document.body.appendChild(box);
	}

	Module["preRun"] = Module["preRun"] || [];
	Module["preRun"].push(function () {
		addRunDependency(DEP);
		if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", show);
		else show();
	});
})();
