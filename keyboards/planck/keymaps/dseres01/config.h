#pragma once

//These two lines are added for link level optimization

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#ifdef AUDIO_ENABLE

    #define A_CSIKOSOK \
        E__NOTE(_A6), E__NOTE(_A6), E__NOTE(_A6), E__NOTE(_F6), E__NOTE(_A6), E__NOTE(_A6), E__NOTE(_A6), E__NOTE(_F6), \
        E__NOTE(_D6), E__NOTE(_E6), E__NOTE(_F6), E__NOTE(_E6), Q__NOTE(_D6), Q__NOTE(_D6),

    #define STARTUP_SONG SONG(A_CSIKOSOK)
    //#define STARTUP_SONG SONG(PLANCK_SOUND)
    //#define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */

#define COMBO_COUNT 3
#define COMBO_TERM 100

#define MK_COMBINED
