#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <ILI9341_t3.h> 
#include <Audio.h>      
#include "frequencies.h" 
#include <font_LiberationMono.h>

// Structure to hold a waveform and its corresponding envelope
struct SequencerVoice {
    AudioSynthWaveform* waveform;
    AudioEffectEnvelope* envelope;
    const char* noteName; // e.g., "C3", "C#3" for display
};

class Sequencer {
public:
    // Constants for step configuration
    static const int MAX_TOTAL_STEPS = 32; // Maximum possible steps
    static const int STEPS_PER_PAGE = 8;   // Steps visible on screen at once
    static const int NUM_NOTES = 12; // This remains the number of vertical note rows
    // Publicly accessible to allow .ino to set it based on controls
    int current_sequence_total_steps; // Active total steps (8, 16, 24, or 32)
    int current_page_index;           // Which 8-step page is visible (0, 1, 2, or 3)


    // --- GUI Dimensions & Colors (Customize these) ---
    int screenWidth; 
    int screenHeight; 
    
    int gridStartX = 10;        
    int gridStartY = 10;        
    int cellWidth = 21; // Width to display STEPS_PER_PAGE         
    int cellHeight = 12;        
    int gridWidth = STEPS_PER_PAGE * cellWidth; // Grid width is for visible steps
    int gridHeight; // Calculated in init based on NUM_NOTES

    int faderAreaStartX = gridStartX;
    int faderAreaStartY; 
    int faderWidth = cellWidth; 
    int faderMaxHeight = 30;    
    int faderAreaHeight = faderMaxHeight + 5; 

    int playButtonX = 174;      
    int playButtonY; 
    int playButtonWidth = 60;
    int playButtonHeight = 25;

    int stopButtonX; 
    int stopButtonY; 
    int stopButtonWidth = 60;
    int stopButtonHeight = 25;

    // Page display
    int pageDisplayX = 10;
    int pageDisplayY; // Will be set below buttons

    // Colors
    uint16_t colorBackground = ILI9341_BLACK;
    uint16_t colorGridLines = ILI9341_DARKGREY;
    uint16_t colorCellOff = ILI9341_BLACK;     
    uint16_t colorCellOn = TFT_SEAGREEN;       
    uint16_t colorCurrentStepHighlight = ILI9341_GREEN;
    uint16_t colorVelocityBar = ILI9341_CYAN;
    uint16_t colorText = ILI9341_WHITE;
    uint16_t colorButton = ILI9341_DARKCYAN;
    uint16_t colorButtonPressed = ILI9341_LIGHTGREY;


    Sequencer();

    void init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo = 120, int initialTotalSteps = 16);
    void update(bool guiIsActive); 
    void drawGUI(); 
    void drawFullGUI(); 
    void drawGrid();
    void drawVelocities();
    void drawControls();
    void drawNoteNames();
    void highlightCurrentStep();
    void updateTempoDisplay(); 
    void drawPageIndicator(); // For multi-page display

    void handleTouch(int touchX, int touchY, bool isPressed);

    void play();
    void stop();
    void resetPlaybackPosition(); // <<<< NEW METHOD
    void setTempo(int newTempo);
    int getTempo() const;
    bool isPlaying() const;

    void setTotalSteps(int totalSteps); // Method to change total sequence length
    void setPage(int pageIndex);        // Method to change visible page

    void setCurrentOctaveVoices(SequencerVoice* voicesForOctave);
    void shiftOctave(int direction); 


private:
    ILI9341_t3* tft; 
    SequencerVoice* currentVoices; 
    // Data arrays now use MAX_TOTAL_STEPS
    bool note_active[MAX_TOTAL_STEPS][NUM_NOTES]; 
    uint8_t note_velocity[MAX_TOTAL_STEPS]; 

    bool is_playing;
    int current_step; // This will now go from 0 to current_sequence_total_steps - 1
    int previous_step_drawn; 
    float bpm;
    unsigned long step_duration_ms;
    elapsedMillis time_since_last_step;

    bool touch_was_pressed_on_grid[STEPS_PER_PAGE][NUM_NOTES]; // Touch grid is for visible page
    bool touch_was_pressed_on_fader[STEPS_PER_PAGE];          // Touch faders are for visible page
    int  last_touch_y_on_fader[STEPS_PER_PAGE];
    
    int currentOctaveIndex = 0; 

    void triggerNotesForStep(int step);
    void turnOffNotesForStep(int step);
};

#endif // SEQUENCER_H