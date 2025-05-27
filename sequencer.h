#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <ILI9341_t3.h> 
#include <Audio.h>    
#include "frequencies.h" 

// Structure to hold a waveform and its corresponding envelope
struct SequencerVoice {
    AudioSynthWaveform* waveform;
    AudioEffectEnvelope* envelope;
    const char* noteName; // e.g., "C3", "C#3" for display
};

class Sequencer {
public:
    static const int NUM_STEPS = 8;  // USER MODIFIED
    static const int NUM_NOTES = 12; // For one octave (C3 to B3)

    // --- GUI Dimensions & Colors (Customize these) ---
    int screenWidth; 
    int screenHeight; 
    
    int gridStartX = 10;        // USER MODIFIED
    int gridStartY = 10;        // USER MODIFIED
    int cellWidth = 21;         // USER MODIFIED
    int cellHeight = 12;        // USER MODIFIED
    int gridWidth = NUM_STEPS * cellWidth;
    int gridHeight = NUM_NOTES * cellHeight;

    int faderAreaStartX = gridStartX;
    int faderAreaStartY; // Calculated in init
    int faderWidth = cellWidth; 
    int faderMaxHeight = 30;    
    int faderAreaHeight = faderMaxHeight + 5; 

    int playButtonX = 174;      // USER MODIFIED
    int playButtonY; // Calculated in init
    int playButtonWidth = 60;
    int playButtonHeight = 25;

    int stopButtonX; // Calculated in init
    int stopButtonY; // Calculated in init
    int stopButtonWidth = 60;
    int stopButtonHeight = 25;

    // Colors
    uint16_t colorBackground = ILI9341_BLACK;
    uint16_t colorGridLines = ILI9341_DARKGREY;
    uint16_t colorCellOff = ILI9341_BLACK;     // USER MODIFIED
    uint16_t colorCellOn = TFT_SEAGREEN;       // USER MODIFIED (Ensure TFT_SEAGREEN is defined, e.g. from ILI9341_t3.h or as 0x3FE0)
    uint16_t colorCurrentStepHighlight = ILI9341_GREEN;
    uint16_t colorVelocityBar = ILI9341_CYAN;
    uint16_t colorText = ILI9341_WHITE;
    uint16_t colorButton = ILI9341_DARKCYAN;
    uint16_t colorButtonPressed = ILI9341_LIGHTGREY;


    Sequencer();

    void init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo = 120);
    void update(bool guiIsActive); // MODIFIED: Added guiIsActive parameter
    void drawGUI(); 
    void drawFullGUI(); 
    void drawGrid();
    void drawVelocities();
    void drawControls();
    void drawNoteNames();
    void highlightCurrentStep();
    void updateTempoDisplay(); 

    void handleTouch(int touchX, int touchY, bool isPressed);

    void play();
    void stop();
    void setTempo(int newTempo);
    int getTempo() const;
    bool isPlaying() const;

    void setCurrentOctaveVoices(SequencerVoice* voicesForOctave);
    void shiftOctave(int direction); 


private:
    ILI9341_t3* tft; 
    SequencerVoice* currentVoices; 

    bool note_active[NUM_STEPS][NUM_NOTES]; 
    uint8_t note_velocity[NUM_STEPS]; 

    bool is_playing;
    int current_step;
    int previous_step_drawn; 
    float bpm;
    unsigned long step_duration_ms;
    elapsedMillis time_since_last_step;

    bool touch_was_pressed_on_grid[NUM_STEPS][NUM_NOTES]; 
    bool touch_was_pressed_on_fader[NUM_STEPS];
    int  last_touch_y_on_fader[NUM_STEPS];
    
    int currentOctaveIndex = 0; 

    void triggerNotesForStep(int step);
    void turnOffNotesForStep(int step);
};

#endif // SEQUENCER_H