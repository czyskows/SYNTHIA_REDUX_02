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
    static const int MAX_TOTAL_STEPS = 32; // Maximum possible steps the sequencer can store
    static const int STEPS_PER_PAGE = 8;   // Steps visible on screen at once
    static const int NUM_NOTES = 12;       // Number of vertical note rows (C3-B3)

    // Publicly accessible to allow .ino to set it based on controls
    int current_sequence_total_steps; // Active total steps (e.g., 8, 16, 24, or 32)
    int current_page_index;           // Which 8-step page is visible (0, 1, 2, or 3)


    // --- GUI Dimensions & Colors ---
    int screenWidth; 
    int screenHeight; 
    
    int gridStartX = 10;        
    int gridStartY = 10;        
    int cellWidth = 21;         
    int cellHeight = 12;        
    int gridWidth; // Calculated in init: STEPS_PER_PAGE * cellWidth
    int gridHeight; // Calculated in init: NUM_NOTES * cellHeight

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
    int pageDisplayX = playButtonX - 15; // X position for "Page: X/Y" text
    int pageDisplayY = 195;      // Y position, calculated in init

    // Colors
    uint16_t colorBackground = ILI9341_BLACK;
    uint16_t colorGridLines = ILI9341_DARKGREY;
    uint16_t colorCellOff = ILI9341_BLACK;     
    uint16_t colorCellOn = TFT_SEAGREEN; // Ensure TFT_SEAGREEN is defined (e.g., 0x3FE0)      
    uint16_t colorCurrentStepHighlight = ILI9341_GREEN;
    uint16_t colorVelocityBar = ILI9341_CYAN;
    uint16_t colorText = ILI9341_WHITE;
    uint16_t colorButton = ILI9341_DARKCYAN;
    uint16_t colorButtonPressed = ILI9341_LIGHTGREY;


    Sequencer();

    void init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo = 120, int initialTotalSteps = 16);
    void update(bool guiIsActive); 
    void drawGUI(); // For partial redraws when page changes or sequencer screen is active
    void drawFullGUI(); // Draws everything, call when screen becomes active
    void drawGrid();
    void drawVelocities();
    void drawControls();
    void drawNoteNames();
    void highlightCurrentStep();
    void updateTempoDisplay(); 
    void drawPageIndicator(); // NEW: To display current page info

    void handleTouch(int touchX, int touchY, bool isPressed);

    void play();
    void stop();
    void resetPlaybackPosition(); 
    void setTempo(int newTempo);
    int getTempo() const;
    bool isPlaying() const;

    void setTotalSteps(int totalSteps); // NEW: To change total sequence length
    void setPage(int pageIndex);        // NEW: To change visible page

    void setCurrentOctaveVoices(SequencerVoice* voicesForOctave);
    void shiftOctave(int direction); 


private:
    ILI9341_t3* tft; 
    SequencerVoice* currentVoices; 

    // Data arrays are sized for the maximum possible steps
    bool note_active[MAX_TOTAL_STEPS][NUM_NOTES]; 
    uint8_t note_velocity[MAX_TOTAL_STEPS]; 

    bool is_playing;
    int current_step; // This will now go from 0 to current_sequence_total_steps - 1
    int previous_step_drawn; // Stores the *actual data step index* that was last highlighted
    float bpm;
    unsigned long step_duration_ms;
    elapsedMillis time_since_last_step;

    // Touch helper arrays are for the visible page (STEPS_PER_PAGE)
    bool touch_was_pressed_on_grid[STEPS_PER_PAGE][NUM_NOTES]; 
    bool touch_was_pressed_on_fader[STEPS_PER_PAGE];          
    int  last_touch_y_on_fader[STEPS_PER_PAGE];
    
    int currentOctaveIndex = 0; 

    void triggerNotesForStep(int actual_data_step); // Parameter is actual data step
    void turnOffNotesForStep(int actual_data_step); // Parameter is actual data step
};

#endif // SEQUENCER_H