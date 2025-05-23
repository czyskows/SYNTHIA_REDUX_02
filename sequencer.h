// Sequencer.h
#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <ILI9341_t3.h> // For TFT display
#include "Audio.h"      // For AudioEffectEnvelope and AudioSynthWaveform

// Forward declaration for the touch handling function if it's complex
// or part of another library you use.
// For simplicity, we'll assume basic touch reading here.

// Structure to hold a waveform and its corresponding envelope
// This will be provided by your main sketch, populated with your actual audio objects
struct SequencerVoice {
    AudioSynthWaveform* waveform;
    AudioEffectEnvelope* envelope;
    const char* noteName; // e.g., "C3", "C#3" for display
};

class Sequencer {
public:
    static const int NUM_STEPS = 16;
    static const int NUM_NOTES = 12; // For one octave (C3 to B3) // MODIFIED

    // --- GUI Dimensions & Colors (Customize these) ---
    // General Layout
    int screenWidth = 320; // Adjust to your screen width
    int screenHeight = 240; // Adjust to your screen height
    
    // Sequencer Grid
    int gridStartX = 10;
    int gridStartY = 30;
    int cellWidth = 18;  // Width of each step cell
    int cellHeight = 13; // Height of each note cell (Adjusted slightly for 12 notes to fit)
    int gridWidth = NUM_STEPS * cellWidth;
    int gridHeight = NUM_NOTES * cellHeight;

    // Velocity Faders
    int faderAreaStartX = gridStartX;
    int faderAreaStartY = gridStartY + gridHeight + 10; // 10px spacing
    int faderWidth = cellWidth; // Same width as step cells
    int faderMaxHeight = 30;    // Max height of a velocity fader
    int faderAreaHeight = faderMaxHeight + 5; // Include some padding

    // Control Buttons (Example positions)
    int playButtonX = 10;
    int playButtonY = faderAreaStartY + faderAreaHeight + 10;
    int playButtonWidth = 60;
    int playButtonHeight = 25;

    int stopButtonX = playButtonX + playButtonWidth + 10;
    int stopButtonY = playButtonY;
    int stopButtonWidth = 60;
    int stopButtonHeight = 25;

    int tempoUpButtonX = stopButtonX + stopButtonWidth + 20;
    int tempoUpButtonY = playButtonY;
    int tempoUpButtonWidth = 30;
    int tempoUpButtonHeight = 25;

    int tempoDownButtonX = tempoUpButtonX + tempoUpButtonWidth + 5;
    int tempoDownButtonY = playButtonY;
    int tempoDownButtonWidth = 30;
    int tempoDownButtonHeight = 25;
    
    int octaveUpButtonX = tempoDownButtonX + tempoDownButtonWidth + 10;
    int octaveUpButtonY = playButtonY;
    int octaveUpButtonWidth = 30;
    int octaveUpButtonHeight = 25;

    int octaveDownButtonX = octaveUpButtonX + octaveUpButtonWidth + 5;
    int octaveDownButtonY = playButtonY;
    int octaveDownButtonWidth = 30;
    int octaveDownButtonHeight = 25;


    // Colors
    uint16_t colorBackground = ILI9341_BLACK;
    uint16_t colorGridLines = ILI9341_DARKGREY;
    uint16_t colorCellOff = ILI9341_BLUE;
    uint16_t colorCellOn = ILI9341_YELLOW;
    uint16_t colorCurrentStepHighlight = ILI9341_GREEN;
    uint16_t colorVelocityBar = ILI9341_CYAN;
    uint16_t colorText = ILI9341_WHITE;
    uint16_t colorButton = ILI9341_DARKCYAN;
    uint16_t colorButtonPressed = ILI9341_LIGHTGREY;


    Sequencer();

    // Call this in your main setup()
    // Pass your TFT object and the array of SequencerVoice structs for the current octave
    void init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo = 120);

    // Call this in your main loop()
    void update(); // Handles timing and note triggering

    // Call this to draw/redraw the GUI
    void drawGUI();
    void drawFullGUI(); // Draws everything
    void drawGrid();
    void drawVelocities();
    void drawControls();
    void drawNoteNames();
    void highlightCurrentStep();
    void updateTempoDisplay();


    // Call this when touch is detected
    // x, y are screen coordinates of the touch
    // isPressed is true if touch is currently active
    void handleTouch(int touchX, int touchY, bool isPressed);

    void play();
    void stop();
    void setTempo(int newTempo);
    int getTempo() const;

    // For octave switching later
    void setCurrentOctaveVoices(SequencerVoice* voicesForOctave);
    void shiftOctave(int direction); // +1 for up, -1 for down


private:
    ILI9341_t3* tft; // Pointer to the TFT object
    SequencerVoice* currentVoices; // Pointers to Waveform/Envelope pairs for the current octave

    bool note_active[NUM_STEPS][NUM_NOTES]; // Array dimension updated due to NUM_NOTES change
    uint8_t note_velocity[NUM_STEPS]; // 0-127

    bool is_playing;
    int current_step;
    int previous_step_drawn; // To clear previous highlight
    float bpm;
    unsigned long step_duration_ms;
    elapsedMillis time_since_last_step;

    // Touch state
    bool touch_was_pressed_on_grid[NUM_STEPS][NUM_NOTES]; // Array dimension updated
    bool touch_was_pressed_on_fader[NUM_STEPS];
    int  last_touch_y_on_fader[NUM_STEPS];
    
    // Placeholder for actual octave management
    int currentOctaveIndex = 0; // e.g., 0 for C3-B3, 1 for C4-B4, etc.
                                // You'll need a way to map this index to the correct SequencerVoice array
                                // and update `currentVoices` when this changes.
                                // For now, this is just a placeholder.

    void triggerNotesForStep(int step);
    void turnOffNotesForStep(int step);

    // Helper to convert MIDI note number to frequency (if you ever need it)
    // float midiNoteToFrequency(int midiNote); 
    // Since you are using direct envelope control, this might not be strictly needed
    // by the sequencer itself, but could be useful for other things.
};

#endif // SEQUENCER_H