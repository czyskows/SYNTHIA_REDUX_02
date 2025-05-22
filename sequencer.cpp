#include "sequencer.h"

Sequencer::Sequencer() :
    currentStep(0),
    playing(false),
    bpm(120.0f),
    lastStepTimeMillis(0),
    onNoteOn(nullptr), 
    onNoteOff(nullptr),
    lastNotePlayed(DEFAULT_MIDI_NOTE_OFF),
    lastVelocityPlayed(0)
{
    for (int i = 0; i < MAX_STEPS; ++i) {
        steps[i].notePitch = DEFAULT_MIDI_NOTE_OFF; 
        steps[i].gateOn = false;
        steps[i].velocity = DEFAULT_VELOCITY; 
    }
    calculateStepInterval();
}

void Sequencer::begin(float initialBPM) {
    setTempo(initialBPM);
    Serial.println("Sequencer initialized.");
}

void Sequencer::start() {
    if (!playing) {
        playing = true;
        // currentStep = 0; // Start from the beginning, or let clockTick handle first step
        lastStepTimeMillis = millis() - stepIntervalMillis; // Ensure first step triggers on next clockTick if playing
        Serial.println("Sequencer started.");
    }
}

void Sequencer::stop() {
    if (playing) {
        playing = false;
        if (onNoteOff && lastNotePlayed != DEFAULT_MIDI_NOTE_OFF) {
            onNoteOff(lastNotePlayed);
            lastNotePlayed = DEFAULT_MIDI_NOTE_OFF;
        }
        Serial.println("Sequencer stopped.");
    }
    // currentStep = 0; // Optionally reset step on stop, or leave it for resume
}

void Sequencer::togglePlayStop() {
    if (isPlaying()) {
        stop();
    } else {
        start();
    }
}


bool Sequencer::isPlaying() const {
    return playing;
}

void Sequencer::setTempo(float newBpm) {
    if (newBpm >= 1.0f && newBpm <= 300.0f) { // Added reasonable tempo limits
        bpm = newBpm;
        calculateStepInterval();
        Serial.print("Sequencer tempo set to: "); Serial.println(bpm);
    }
}

float Sequencer::getTempo() const {
    return bpm;
}

void Sequencer::calculateStepInterval() {
    // Assuming 4 steps per beat (16th notes)
    float beatsPerSecond = bpm / 60.0f;
    float stepsPerSecond = beatsPerSecond * 4.0f; 
    if (stepsPerSecond > 0) {
        stepIntervalMillis = (unsigned long)(1000.0f / stepsPerSecond);
    } else {
        stepIntervalMillis = 0xFFFFFFFF; // Effectively infinite if BPM is 0 or less
    }
    // Serial.print("Step interval (ms): "); Serial.println(stepIntervalMillis); // Can be verbose
}

void Sequencer::clockTick() {
    if (!playing) {
        return;
    }

    unsigned long currentTimeMillis = millis();
    if (currentTimeMillis - lastStepTimeMillis >= stepIntervalMillis) {
        lastStepTimeMillis = currentTimeMillis; 

        // Turn off the previous note if one was played by the sequencer
        if (onNoteOff && lastNotePlayed != DEFAULT_MIDI_NOTE_OFF) {
            onNoteOff(lastNotePlayed);
            lastNotePlayed = DEFAULT_MIDI_NOTE_OFF; 
        }
        
        // Advance to the current step (which might have been incremented already)
        // or handle first step if just started.
        // currentStep was incremented *after* last triggerStep.
        
        triggerStep(currentStep);

        currentStep++;
        if (currentStep >= MAX_STEPS) {
            currentStep = 0;
        }
    }
}

void Sequencer::triggerStep(int stepIndex) {
    if (stepIndex < 0 || stepIndex >= MAX_STEPS) return;

    SequenceStep& step = steps[stepIndex];

    // Serial.print("Sequencer Triggering Step: "); Serial.print(stepIndex);
    // Serial.print(", Gate: "); Serial.print(step.gateOn);
    // Serial.print(", Pitch: "); Serial.print(step.notePitch);
    // Serial.print(", Velocity: "); Serial.println(step.velocity);

    if (step.gateOn && step.notePitch != DEFAULT_MIDI_NOTE_OFF) {
        if (onNoteOn) {
            onNoteOn(step.notePitch, step.velocity);
            lastNotePlayed = step.notePitch; 
            lastVelocityPlayed = step.velocity;
        }
    }
}

void Sequencer::setStepNote(int stepIndex, int note) {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        steps[stepIndex].notePitch = constrain(note, MIN_MIDI_NOTE, MAX_MIDI_NOTE);
        if (note == 0) steps[stepIndex].gateOn = false; // Convention: note 0 also means gate off
    }
}

int Sequencer::getStepNote(int stepIndex) const {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        return steps[stepIndex].notePitch;
    }
    return DEFAULT_MIDI_NOTE_OFF; 
}

void Sequencer::setStepGate(int stepIndex, bool gateState) {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        steps[stepIndex].gateOn = gateState;
        if (!gateState && steps[stepIndex].notePitch == lastNotePlayed && onNoteOff) {
            // If turning gate off for the currently playing note, send note off immediately
            // onNoteOff(steps[stepIndex].notePitch);
            // lastNotePlayed = DEFAULT_MIDI_NOTE_OFF; // This might be too aggressive here, clockTick handles it.
        }
    }
}

bool Sequencer::getStepGate(int stepIndex) const {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        return steps[stepIndex].gateOn;
    }
    return false;
}

void Sequencer::setStepVelocity(int stepIndex, int velocity) {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        steps[stepIndex].velocity = constrain(velocity, 0, 127);
    }
}

int Sequencer::getStepVelocity(int stepIndex) const {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        return steps[stepIndex].velocity;
    }
    return DEFAULT_VELOCITY;
}

void Sequencer::clearStep(int stepIndex) {
    if (stepIndex >= 0 && stepIndex < MAX_STEPS) {
        steps[stepIndex].notePitch = DEFAULT_MIDI_NOTE_OFF;
        steps[stepIndex].gateOn = false;
        steps[stepIndex].velocity = DEFAULT_VELOCITY;
    }
}

void Sequencer::clearAllSteps() {
    for (int i = 0; i < MAX_STEPS; ++i) {
        clearStep(i);
    }
    Serial.println("Sequencer cleared all steps.");
}


int Sequencer::getCurrentStep() const {
    return currentStep;
}

int Sequencer::getNumSteps() const {
    return MAX_STEPS;
}