/*
 * Matthew Delgado
 * ECE 3551: Microcomputer Systems 1
 * Arduino Lab 4
 * Melody

 * Plays a melody using the Arduino tone function
*/

#include "pitches.h"

// Notes in melody
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Note duration (4 = quarter note, 8 = eighth note, etc.)
int noteDurations[] = {  4, 8, 8, 4, 4, 4, 4, 4 };

void setup() {
  // Iterate over all notes in melody
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // Calculate note duration by taking one second divided by the note type
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    // Distinguish the notes by setting a minimum time between them
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone which is playing
    noTone(8);
  }
}

void loop() {}
