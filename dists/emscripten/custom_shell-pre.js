/*global Module*/
Module["arguments"] = [];

// Add all parameters passed via the fragment identifier
if (window.location.hash.length > 0) {
    params = decodeURI(window.location.hash.substring(1)).split(" ")
    params.forEach((param) => {
        Module["arguments"].push(param);
    })
}

// MIDI support
var midiOutputMap;
if (globalThis.faustNoMidi) {
	// Faust has no MIDI music: don't ask the player for MIDI access
} else if (!("requestMIDIAccess" in navigator)) {
	console.error("No MIDI support in your browser.");
} else {
	navigator
		.requestMIDIAccess({ sysex: true, software: true })
		.then((midiAccess) => {
			midiOutputMap = midiAccess.outputs;
			midiAccess.onstatechange = (e) => {
				midiOutputMap = e.target.outputs;
			};
		});
}
