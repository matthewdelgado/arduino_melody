/*
 * Matthew Delgado
 * ECE 3551: Microcomputer Systems 1
 * Arduino Lab 4
 * Melody

 * Plays a melody using the Arduino tone function
*/

#include "pitches.h"
// OUTPUT Pin for Piezo Buzzer
#define PIEZO_PIN 8
#define THREE_SECONDS 3000

// Notes in melody
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Variables required by Melody Player assignment
float WHOLE = 1;
float HALF = 0.5;
float QUARTER = 0.25;
float EIGTH = 0.125;
float SIXTEENTH = 0.0625;

// Notes in the tune specified in "Melody Player" assignment
int tune[] = {
    NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_A3, 
    NOTE_C4, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_F3, 
    NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_B3, 
    NOTE_C4, NOTE_D4
};

// Length of array
int arr_length;

// Note duration (4 = quarter note, 8 = eighth note, etc.)
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
    pinMode(OUTPUT, PIEZO_PIN);
    arr_length = sizeof(tune) / sizeof(tune[0]);
}

// Loop plays melody for infinite with 1.5*noteDuration delay between notes, when melody restarts there is a 3s delay
void loop() 
{
    // Iterate over all notes in melody
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
        // Calculate note duration by taking one second divided by the note type
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(PIEZO_PIN, tune[thisNote], noteDuration);
        // Distinguish the notes by setting a minimum time between them
        int pauseBetweenNotes = noteDuration * 1.50;
        delay(pauseBetweenNotes);
        // Stop the tone which is playing
        noTone(PIEZO_PIN);
    }
    delay(THREE_SECONDS);
}
