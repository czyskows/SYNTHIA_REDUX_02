#include "Sequencer.h" 
#include <cstdint>     
#include <cstring>     
#include <font_LiberationMono.h>



Sequencer::Sequencer() : tft(nullptr), currentVoices(nullptr), is_playing(false), current_step(0), previous_step_drawn(-1), bpm(120.0f) {
    for (int s = 0; s < NUM_STEPS; ++s) {
        note_velocity[s] = 100; 
        for (int n = 0; n < NUM_NOTES; ++n) { 
            note_active[s][n] = false;
            touch_was_pressed_on_grid[s][n] = false;
        }
        touch_was_pressed_on_fader[s] = false;
        last_touch_y_on_fader[s] = -1;
    }
    step_duration_ms = (60000.0f / bpm) / 4.0f; 
    time_since_last_step = 0;
}

void Sequencer::init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo) {
    tft = tftDisplay;
    currentVoices = voicesForOctave;
    
    if (!tft) return; 
    
    screenWidth = tft->width();
    screenHeight = tft->height();
    
    // Recalculate GUI element positions based on current settings
    gridWidth = NUM_STEPS * cellWidth;
    gridHeight = NUM_NOTES * cellHeight;
    faderAreaStartY = gridStartY + gridHeight + 10; 
    faderAreaHeight = faderMaxHeight + 5;

    playButtonY = faderAreaStartY + faderAreaHeight + 10; // User specified playButtonX = 174
    stopButtonX = playButtonX + playButtonWidth + 10;
    stopButtonY = playButtonY;
    
    setTempo(initialTempo); // Call after tft is set so updateTempoDisplay can work if called by setTempo
}

void Sequencer::play() {
    if (is_playing) return;
    is_playing = true;
    // current_step = 0; // User's version starts from current_step
    time_since_last_step = 0; 
    previous_step_drawn = (current_step == 0) ? (NUM_STEPS -1) : (current_step -1); 
}

void Sequencer::stop() {
    if (!is_playing) return;
    is_playing = false;
    turnOffNotesForStep(current_step); 
    if (tft) { // Only try to draw if tft is available
        highlightCurrentStep(); 
    }
}

bool Sequencer::isPlaying() const {
    return is_playing;
}

void Sequencer::setTempo(int newTempo) {
    if (newTempo < 20) newTempo = 20;
    if (newTempo > 300) newTempo = 300; 
    bpm = newTempo;
    step_duration_ms = (60000.0f / bpm) / 4.0f; 
    if (tft) { 
      updateTempoDisplay(); // Update display if tft is available
    }
}

int Sequencer::getTempo() const {
    return static_cast<int>(bpm);
}

void Sequencer::setCurrentOctaveVoices(SequencerVoice* voicesForOctave) {
    bool wasPlaying = is_playing;
    if (wasPlaying) stop(); 

    currentVoices = voicesForOctave;
    if (tft) { 
        drawNoteNames(); 
    }

    if (wasPlaying) play(); 
}

void Sequencer::shiftOctave(int direction) {
    // Placeholder
}

// MODIFIED: Added guiIsActive parameter and conditional drawing
void Sequencer::update(bool guiIsActive) {
    if (is_playing && currentVoices) {
        if (time_since_last_step >= step_duration_ms) {
            time_since_last_step -= step_duration_ms; 

            int justFinishedStep = (current_step == 0) ? (NUM_STEPS - 1) : (current_step - 1);
            turnOffNotesForStep(justFinishedStep); 

            triggerNotesForStep(current_step);
            current_step = (current_step + 1) % NUM_STEPS;
        }
    }

    // Only draw/update the visual step highlighter if the sequencer's GUI is active
    if (guiIsActive && tft) {
        highlightCurrentStep();
    }
}


void Sequencer::triggerNotesForStep(int step) {
    if (!currentVoices) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[step][n]) {
            if (currentVoices[n].waveform && currentVoices[n].envelope) {
                float amp = note_velocity[step] / 127.0f;
                currentVoices[n].waveform->amplitude(amp); 
                currentVoices[n].envelope->noteOn();
            }
        }
    }
}

void Sequencer::turnOffNotesForStep(int step) {
    if (!currentVoices) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[step][n]) { 
            if (currentVoices[n].envelope) {
                currentVoices[n].envelope->noteOff();
            }
        }
    }
}

void Sequencer::drawFullGUI() {
    if (!tft) return;
    tft->fillScreen(colorBackground);
    drawNoteNames();
    drawGrid();
    drawVelocities();
    drawControls();
    updateTempoDisplay(); 
    highlightCurrentStep(); 
}

void Sequencer::drawGUI() {
    if (!tft) return;
    drawGrid(); 
    drawVelocities(); 
}

void Sequencer::drawNoteNames() {
    if (!tft || !currentVoices) return;
    tft->setFont(LiberationMono_10); // USER MODIFIED FONT
    tft->setTextSize(1);
    for (int n = 0; n < NUM_NOTES; ++n) { 
        int y = gridStartY + n * cellHeight + cellHeight / 2 - 4; 
        int x_offset = ( (currentVoices[n].noteName && strlen(currentVoices[n].noteName) > 1) ? 10 : 5); 
        int x = gridStartX - x_offset - 6; // USER MODIFIED X OFFSET
        if (x < 0) x = 0; 
        tft->fillRect(0, gridStartY + n * cellHeight, gridStartX -1 , cellHeight, colorBackground);
        if (currentVoices[n].noteName) {
            tft->setCursor(x, y);
            tft->setTextColor(colorText);
            tft->print(currentVoices[n].noteName);
        }
    }
}

void Sequencer::drawGrid() {
    if (!tft) return;
    for (int s = 0; s < NUM_STEPS; ++s) {
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + s * cellWidth;
            int y = gridStartY + n * cellHeight;
            uint16_t cellColor = note_active[s][n] ? colorCellOn : colorCellOff;
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor);
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines);
        }
    }
    if (is_playing) { // User's version had this here, it's fine, highlightCurrentStep checks is_playing again.
         highlightCurrentStep();
    }
}

void Sequencer::drawVelocities() {
    if (!tft) return;
    for (int s = 0; s < NUM_STEPS; ++s) {
        int x = faderAreaStartX + s * faderWidth;
        int y = faderAreaStartY;
        tft->fillRect(x + 1, y + 1, faderWidth - 2, faderMaxHeight - 1, colorBackground);
        int barHeight = (note_velocity[s] / 127.0f) * (faderMaxHeight - 2); 
        if (barHeight < 1) barHeight = 1; 
        tft->fillRect(x + 1, y + faderMaxHeight - barHeight -1 , faderWidth - 2, barHeight, colorVelocityBar);
        tft->drawRect(x, y, faderWidth, faderMaxHeight, colorGridLines);
    }
}

void Sequencer::highlightCurrentStep() {
    if (!tft) return;

    if (previous_step_drawn != current_step && previous_step_drawn >=0 && previous_step_drawn < NUM_STEPS) {
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + previous_step_drawn * cellWidth;
            int y = gridStartY + n * cellHeight;
            uint16_t cellColor = note_active[previous_step_drawn][n] ? colorCellOn : colorCellOff;
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor); 
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines); 
        }
    }
    
    if (is_playing && current_step >= 0 && current_step < NUM_STEPS) {
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + current_step * cellWidth;
            int y = gridStartY + n * cellHeight;
            tft->drawRect(x, y, cellWidth, cellHeight, colorCurrentStepHighlight);
        }
    }
    previous_step_drawn = current_step;
}

void Sequencer::drawControls() {
    if (!tft) return;
    tft->setFont(LiberationMono_10); // USER MODIFIED FONT
    tft->setTextSize(1);

    tft->fillRect(playButtonX, playButtonY, playButtonWidth, playButtonHeight, colorButton);
    tft->setTextColor(colorText);
    tft->setCursor(playButtonX + 10, playButtonY + 8);
    tft->print("PLAY");

    tft->fillRect(stopButtonX, stopButtonY, stopButtonWidth, stopButtonHeight, colorButton);
    tft->setCursor(stopButtonX + 10, stopButtonY + 8);
    tft->print("STOP");

    // Tempo and Octave buttons removed as per user's sequencer.cpp
    updateTempoDisplay(); 
}

void Sequencer::updateTempoDisplay() {
    if (!tft) return; 
    int tempoDisplayX = stopButtonX; // User's positioning
    int tempoDisplayY = playButtonY - 15; // User's positioning

    tft->setFont(LiberationMono_10); // User's font
    tft->setTextSize(1);   
    tft->fillRect(tempoDisplayX, tempoDisplayY, 70, 10, colorBackground); // User's width
    tft->setTextColor(colorText);
    tft->setCursor(tempoDisplayX, tempoDisplayY);
    tft->print("BPM: "); 
    tft->print(getTempo());
}

void Sequencer::handleTouch(int touchX, int touchY, bool isPressed) {
    if (!tft) return;

    bool needsRedrawGrid = false;
    bool needsRedrawVelocities = false;

    if (touchX >= gridStartX && touchX < gridStartX + gridWidth &&
        touchY >= gridStartY && touchY < gridStartY + gridHeight) {
        int step = (touchX - gridStartX) / cellWidth;
        int note = (touchY - gridStartY) / cellHeight;

        if (step >= 0 && step < NUM_STEPS && note >= 0 && note < NUM_NOTES) { 
            if (isPressed && !touch_was_pressed_on_grid[step][note]) {
                note_active[step][note] = !note_active[step][note];
                touch_was_pressed_on_grid[step][note] = true;
                needsRedrawGrid = true; 
            } else if (!isPressed) {
                touch_was_pressed_on_grid[step][note] = false;
            }
        }
    } else { 
        if (!isPressed) { 
            for(int s=0; s<NUM_STEPS; ++s) for(int n=0; n<NUM_NOTES; ++n) touch_was_pressed_on_grid[s][n] = false; 
        }
    }

    if (touchX >= faderAreaStartX && touchX < faderAreaStartX + NUM_STEPS * faderWidth &&
        touchY >= faderAreaStartY && touchY < faderAreaStartY + faderMaxHeight) {
        int step = (touchX - faderAreaStartX) / faderWidth;

        if (step >= 0 && step < NUM_STEPS) {
            if (isPressed) {
                int rawVelocity = 127 - ((touchY - faderAreaStartY) * 127 / (faderMaxHeight -1));
                if (rawVelocity < 0) rawVelocity = 0;
                if (rawVelocity > 127) rawVelocity = 127;
                
                if (!touch_was_pressed_on_fader[step] || abs(touchY - last_touch_y_on_fader[step]) > 1 ) { 
                    note_velocity[step] = rawVelocity;
                    needsRedrawVelocities = true; 
                }
                touch_was_pressed_on_fader[step] = true;
                last_touch_y_on_fader[step] = touchY;
            } else { 
                 touch_was_pressed_on_fader[step] = false;
                 last_touch_y_on_fader[step] = -1; 
            }
        }
    } else { 
        if(!isPressed) { 
            for(int s=0; s<NUM_STEPS; ++s) {
                touch_was_pressed_on_fader[s] = false;
                last_touch_y_on_fader[s] = -1;
            }
        }
    }

    // Control button interaction for Play/Stop (Tempo/Octave buttons removed from user's cpp)
    static bool playPressedLast = false;
    static bool stopPressedLast = false;

    bool currentPlayPressed = false;
    bool currentStopPressed = false;

    if (isPressed) {
        if (touchX >= playButtonX && touchX < playButtonX + playButtonWidth &&
            touchY >= playButtonY && touchY < playButtonY + playButtonHeight) currentPlayPressed = true;
        else if (touchX >= stopButtonX && touchX < stopButtonX + stopButtonWidth &&
                 touchY >= stopButtonY && touchY < stopButtonY + stopButtonHeight) currentStopPressed = true;
    }

    if (currentPlayPressed && !playPressedLast) play();
    if (currentStopPressed && !stopPressedLast) stop();
    
    playPressedLast = currentPlayPressed;
    stopPressedLast = currentStopPressed;

    if (needsRedrawGrid) drawGrid(); 
    if (needsRedrawVelocities) drawVelocities(); 
}