#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <Arduino.h> // For millis(), basic types

// --- Configuration ---
const int MAX_STEPS = 16; // Number of steps in the sequence
const int DEFAULT_MIDI_NOTE_OFF = 0; // A value to signify note off or empty step for pitch
const int DEFAULT_VELOCITY = 100;   // Default MIDI velocity (0-127)
const int MIN_MIDI_NOTE = 0;    // Lowest possible MIDI note
const int MAX_MIDI_NOTE = 127;  // Highest possible MIDI note


// --- Step Data Structure ---
struct SequenceStep {
    int notePitch;      // MIDI note number (e.g., 60 for C4). 0 could mean "off" or "rest".
    bool gateOn;        // Is the gate active for this step? (i.e., should a note be triggered)
    int velocity;       // MIDI velocity (0-127)
    // float duration;  // Optional: Duration of the note 
};

class Sequencer {
public:
    Sequencer();

    void begin(float initialBPM = 120.0f); 

    // --- Transport Controls ---
    void start();
    void stop();
    // void pause(); // Optional
    bool isPlaying() const;
    void togglePlayStop();


    // --- Tempo and Timing ---
    void setTempo(float bpm);
    float getTempo() const;
    void clockTick(); 

    // --- Step Data Management ---
    void setStepNote(int stepIndex, int note);
    int getStepNote(int stepIndex) const;
    void setStepGate(int stepIndex, bool gateState);
    bool getStepGate(int stepIndex) const;
    void setStepVelocity(int stepIndex, int velocity);
    int getStepVelocity(int stepIndex) const;
    void clearStep(int stepIndex);
    void clearAllSteps();


    // --- Callbacks for Note On/Off ---
    void (*onNoteOn)(int note, int velocity);     
    void (*onNoteOff)(int note);                  

    // --- Getters for UI ---
    int getCurrentStep() const;
    int getNumSteps() const;


private:
    SequenceStep steps[MAX_STEPS];
    int currentStep;
    bool playing;
    float bpm;
    unsigned long stepIntervalMillis; 
    unsigned long lastStepTimeMillis;

    int lastNotePlayed; 
    int lastVelocityPlayed;


    void calculateStepInterval();
    void triggerStep(int stepIndex);
};

#endif // SEQUENCER_H