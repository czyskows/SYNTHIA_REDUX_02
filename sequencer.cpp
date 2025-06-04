#include "Sequencer.h" 
#include <cstdint>     
#include <cstring>     

Sequencer::Sequencer() : tft(nullptr), currentVoices(nullptr), 
                         current_sequence_total_steps(16), current_page_index(0), // Initialize new members
                         is_playing(false), current_step(0), previous_step_drawn(-1), bpm(120.0f) {
    for (int s = 0; s < MAX_TOTAL_STEPS; ++s) { // Initialize for max steps
        note_velocity[s] = 100; 
        for (int n = 0; n < NUM_NOTES; ++n) { 
            note_active[s][n] = false;
        }
    }
    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) { // Initialize touch state for visible page
         for (int n = 0; n < NUM_NOTES; ++n) {
            touch_was_pressed_on_grid[s_page][n] = false;
         }
        touch_was_pressed_on_fader[s_page] = false;
        last_touch_y_on_fader[s_page] = -1;
    }
    step_duration_ms = (60000.0f / bpm) / 4.0f; 
    time_since_last_step = 0;
}

void Sequencer::init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo, int initialTotalSteps) {
    tft = tftDisplay;
    currentVoices = voicesForOctave;
    
    if (!tft) return; 
    
    screenWidth = tft->width();
    screenHeight = tft->height();
    
    setTotalSteps(initialTotalSteps); // Set initial total steps
    current_page_index = 0;

    // gridWidth is already STEPS_PER_PAGE * cellWidth
    gridHeight = NUM_NOTES * cellHeight;
    faderAreaStartY = gridStartY + gridHeight + 10; 
    faderAreaHeight = faderMaxHeight + 5;

    playButtonY = faderAreaStartY + faderAreaHeight + 10; 
    stopButtonX = playButtonX + playButtonWidth + 10;
    stopButtonY = playButtonY;
    pageDisplayY = playButtonY + playButtonHeight + 5; // Position page display below buttons
    
    setTempo(initialTempo); 
}

void Sequencer::play() {
    if (is_playing) return;
    is_playing = true;
    time_since_last_step = 0; 
    // When playing, ensure the step highlighter starts from the correct visual step if current_step is on a different page
    int visual_step_on_current_page = current_step - (current_page_index * STEPS_PER_PAGE);
    if (visual_step_on_current_page < 0 || visual_step_on_current_page >= STEPS_PER_PAGE) {
        previous_step_drawn = -1; // Force redraw if current_step is not on current page
    } else {
        previous_step_drawn = (visual_step_on_current_page == 0) ? (STEPS_PER_PAGE -1) : (visual_step_on_current_page -1);
    }
}

void Sequencer::stop() {
    if (!is_playing) return; 
    is_playing = false;

    if (currentVoices) {
        for (int n = 0; n < NUM_NOTES; ++n) {
            if (currentVoices[n].envelope) { 
                currentVoices[n].envelope->noteOff();
            }
        }
    }
}

// <<<< NEW METHOD IMPLEMENTATION >>>>
void Sequencer::resetPlaybackPosition() {
    bool was_playing_before_reset = is_playing; // Store current play state
    if (is_playing) {
        stop(); // Call stop to turn off notes and set is_playing to false
    }
    current_step = 0;
    time_since_last_step = 0; // Reset timer
    
    // Force highlighter update if GUI is active
    // previous_step_drawn is set to -1 or an invalid step to ensure highlightCurrentStep redraws correctly
    // when update() is next called with guiIsActive = true.
    previous_step_drawn = STEPS_PER_PAGE; // Or any value that will trigger a redraw

    if (was_playing_before_reset) {
        play(); // Resume playing from step 0 if it was playing before reset
    }
    // If it wasn't playing, it remains stopped at step 0.
    // The visual update will occur in the next update(guiIsActive) call.
}


bool Sequencer::isPlaying() const {
    return is_playing;
}

void Sequencer::setTotalSteps(int totalSteps) {
    if (totalSteps == 8 || totalSteps == 16 || totalSteps == 24 || totalSteps == 32) {
        current_sequence_total_steps = totalSteps;
        // Ensure current_step and current_page_index are valid
        if (current_step >= current_sequence_total_steps) {
            current_step = 0; // Reset if current step is now out of bounds
        }
        int max_page_index = (current_sequence_total_steps / STEPS_PER_PAGE) - 1;
        if (current_page_index > max_page_index) {
            current_page_index = max_page_index;
        }
        if (tft) drawPageIndicator(); // Update page display if GUI is active
    }
}

void Sequencer::setPage(int pageIndex) {
    int max_page_index = (current_sequence_total_steps / STEPS_PER_PAGE) - 1;
    if (pageIndex >= 0 && pageIndex <= max_page_index) {
        if (current_page_index != pageIndex) {
            current_page_index = pageIndex;
            // When page changes, force redraw of grid and velocities for the new page
            if (tft) { // Only if tft is available
                drawGrid();
                drawVelocities();
                drawPageIndicator();
                // Also ensure highlighter is correct for the new page
                highlightCurrentStep(); // This will use the global current_step
            }
        }
    }
}


void Sequencer::setTempo(int newTempo) {
    if (newTempo < 20) newTempo = 20;
    if (newTempo > 300) newTempo = 300; 
    bpm = newTempo;
    step_duration_ms = (60000.0f / bpm) / 4.0f; 
    if (tft) { 
      updateTempoDisplay(); 
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

void Sequencer::update(bool guiIsActive) {
    if (is_playing && currentVoices) {
        if (time_since_last_step >= step_duration_ms) {
            time_since_last_step -= step_duration_ms; 

            int step_to_turn_off_notes = current_step; // Turn off notes of the step that just finished
                                                       // or the one before current_step if current_step already advanced
                                                       // Logic: turn off notes for the step that was *just playing*

            // If current_step is 0, the step that just finished was the last step of the sequence
            if (current_step == 0) {
                 step_to_turn_off_notes = current_sequence_total_steps -1;
            } else {
                 step_to_turn_off_notes = current_step -1;
            }
            // This needs to be more robust with note hold logic later.
            // For now, assume notes last one step.
            // The `triggerNotesForStep` will play the new step.
            // `turnOffNotesForStep` should ideally turn off notes from the *previous logical step index*.
            
            // Let's refine: turn off notes for the step that *was* current_step before advancing
            int previous_logical_step = current_step;

            // Advance step first
            current_step = (current_step + 1) % current_sequence_total_steps; // Use dynamic total steps

            // Turn off notes from the step that just finished
            turnOffNotesForStep(previous_logical_step);
            
            // Trigger notes for the new current_step
            triggerNotesForStep(current_step);
        }
    }

    if (guiIsActive && tft) {
        highlightCurrentStep();
    }
}


void Sequencer::triggerNotesForStep(int step_index) { // step_index is 0 to current_sequence_total_steps-1
    if (!currentVoices || step_index < 0 || step_index >= current_sequence_total_steps) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[step_index][n]) {
            if (currentVoices[n].waveform && currentVoices[n].envelope) {
                float amp = note_velocity[step_index] / 127.0f;
                currentVoices[n].waveform->amplitude(amp); 
                currentVoices[n].envelope->noteOn();
            }
        }
    }
}

void Sequencer::turnOffNotesForStep(int step_index) { // step_index is 0 to current_sequence_total_steps-1
    if (!currentVoices || step_index < 0 || step_index >= current_sequence_total_steps) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[step_index][n]) { // Only turn off if it was supposed to be active
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
    drawGrid(); // Will draw current page
    drawVelocities(); // Will draw current page
    drawControls();
    updateTempoDisplay(); 
    drawPageIndicator(); // Draw initial page indicator
    highlightCurrentStep(); 
}

void Sequencer::drawGUI() { // For partial updates if sequencer screen is active
    if (!tft) return;
    drawGrid(); 
    drawVelocities(); 
    drawPageIndicator();
    // highlightCurrentStep(); // Handled by update()
}

void Sequencer::drawNoteNames() {
    if (!tft || !currentVoices) return;
    tft->setFont(LiberationMono_10); 
    tft->setTextSize(1);
    for (int n = 0; n < NUM_NOTES; ++n) { 
        int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight + cellHeight / 2 - 4; 
        int x_offset = ( (currentVoices[n].noteName && strlen(currentVoices[n].noteName) > 1) ? 10 : 5); 
        int x = gridStartX - x_offset - 6; 
        if (x < 0) x = 0; 
        int rect_y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight;
        tft->fillRect(0, rect_y, gridStartX -1 , cellHeight, colorBackground); 
        if (currentVoices[n].noteName) { 
            tft->setCursor(x, y);
            tft->setTextColor(colorText);
            tft->print(currentVoices[n].noteName);
        }
    }
}

void Sequencer::drawGrid() {
    if (!tft) return;
    int start_step_of_page = current_page_index * STEPS_PER_PAGE;

    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) { // Loop for visible steps on page
        int actual_data_step = start_step_of_page + s_page;
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + s_page * cellWidth; // Use s_page for screen X position
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            
            uint16_t cellColor = colorCellOff;
            if (actual_data_step < current_sequence_total_steps) { // Only access data if within total steps
                 cellColor = note_active[actual_data_step][n] ? colorCellOn : colorCellOff;
            }
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor);
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines);
        }
    }
}

void Sequencer::drawVelocities() {
    if (!tft) return;
    int start_step_of_page = current_page_index * STEPS_PER_PAGE;

    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) { // Loop for visible steps on page
        int actual_data_step = start_step_of_page + s_page;
        int x = faderAreaStartX + s_page * faderWidth; // Use s_page for screen X position
        int y_fader_area = faderAreaStartY; 
        tft->fillRect(x + 1, y_fader_area + 1, faderWidth - 2, faderMaxHeight - 1, colorBackground);
        
        int barHeight = 1; // Default to min bar height
        if (actual_data_step < current_sequence_total_steps) { // Only access data if within total steps
            barHeight = (note_velocity[actual_data_step] / 127.0f) * (faderMaxHeight - 2); 
            if (barHeight < 1) barHeight = 1; 
        }
        tft->fillRect(x + 1, y_fader_area + faderMaxHeight - barHeight -1 , faderWidth - 2, barHeight, colorVelocityBar);
        tft->drawRect(x, y_fader_area, faderWidth, faderMaxHeight, colorGridLines);
    }
}

void Sequencer::highlightCurrentStep() {
    if (!tft) return;

    int start_step_of_page = current_page_index * STEPS_PER_PAGE;
    int end_step_of_page = start_step_of_page + STEPS_PER_PAGE -1;

    // Determine the visual representation of the previous_step_drawn on the current page
    int visual_previous_step = -1;
    if (previous_step_drawn >= start_step_of_page && previous_step_drawn <= end_step_of_page) {
        visual_previous_step = previous_step_drawn - start_step_of_page;
    }
    
    // Determine the visual representation of current_step on the current page
    int visual_current_step = -1;
    if (current_step >= start_step_of_page && current_step <= end_step_of_page && current_step < current_sequence_total_steps) {
        visual_current_step = current_step - start_step_of_page;
    }


    // Clear previous highlight only if it was on the current page and is different from new current step
    if (visual_previous_step != -1 && previous_step_drawn != current_step) {
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + visual_previous_step * cellWidth;
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            uint16_t cellColor = colorCellOff;
            if(previous_step_drawn < current_sequence_total_steps) { // Check bounds for data access
                cellColor = note_active[previous_step_drawn][n] ? colorCellOn : colorCellOff;
            }
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor); 
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines); 
        }
    }
    
    // Draw new highlight if playing and current_step is on the current page
    if (is_playing && visual_current_step != -1) {
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + visual_current_step * cellWidth;
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            tft->drawRect(x, y, cellWidth, cellHeight, colorCurrentStepHighlight);
        }
    }
    previous_step_drawn = current_step; // Store the actual data step index
}

void Sequencer::drawControls() {
    if (!tft) return;
    tft->setFont(LiberationMono_10); 
    tft->setTextSize(1);

    tft->fillRect(playButtonX, playButtonY, playButtonWidth, playButtonHeight, colorButton);
    tft->setTextColor(colorText);
    tft->setCursor(playButtonX + 10, playButtonY + 8);
    tft->print("PLAY");

    tft->fillRect(stopButtonX, stopButtonY, stopButtonWidth, stopButtonHeight, colorButton);
    tft->setCursor(stopButtonX + 10, stopButtonY + 8);
    tft->print("STOP");
}

void Sequencer::updateTempoDisplay() {
    if (!tft) return; 
    int tempoDisplayX = stopButtonX; 
    int tempoDisplayY = playButtonY - 15; 

    tft->setFont(LiberationMono_10); 
    tft->setTextSize(1);   
    tft->fillRect(tempoDisplayX, tempoDisplayY, 70, 10, colorBackground); 
    tft->setTextColor(colorText);
    tft->setCursor(tempoDisplayX, tempoDisplayY);
    tft->print("BPM: "); 
    tft->print(getTempo());
}

void Sequencer::drawPageIndicator() {
    if (!tft) return;
    tft->setFont(LiberationMono_10);
    tft->setTextSize(1);
    tft->fillRect(pageDisplayX, pageDisplayY, 80, 10, colorBackground); // Clear old text
    tft->setCursor(pageDisplayX, pageDisplayY);
    tft->setTextColor(colorText);
    tft->print("Page: ");
    tft->print(current_page_index + 1);
    tft->print("/");
    tft->print(current_sequence_total_steps / STEPS_PER_PAGE);
}


void Sequencer::handleTouch(int touchX, int touchY, bool isPressed) {
    if (!tft) return;

    bool needsRedrawGrid = false;
    bool needsRedrawVelocities = false;
    int start_step_of_page = current_page_index * STEPS_PER_PAGE;

    // --- Grid Interaction ---
    if (touchX >= gridStartX && touchX < gridStartX + gridWidth && // gridWidth is for visible page
        touchY >= gridStartY && touchY < gridStartY + gridHeight) {
        int page_step_touched = (touchX - gridStartX) / cellWidth; // Step index on current page (0-7)
        int screen_row_touched = (touchY - gridStartY) / cellHeight; 

        if (screen_row_touched >= 0 && screen_row_touched < NUM_NOTES) {
            int note_data_index = (NUM_NOTES - 1) - screen_row_touched; 
            int actual_data_step = start_step_of_page + page_step_touched;

            if (actual_data_step < current_sequence_total_steps) { // Ensure we're not touching beyond total steps
                if (isPressed && !touch_was_pressed_on_grid[page_step_touched][note_data_index]) {
                    note_active[actual_data_step][note_data_index] = !note_active[actual_data_step][note_data_index];
                    touch_was_pressed_on_grid[page_step_touched][note_data_index] = true;
                    needsRedrawGrid = true; 
                } else if (!isPressed) {
                    touch_was_pressed_on_grid[page_step_touched][note_data_index] = false;
                }
            }
        }
    } else { 
        if (!isPressed) { 
            for(int s_page=0; s_page<STEPS_PER_PAGE; ++s_page) for(int n=0; n<NUM_NOTES; ++n) touch_was_pressed_on_grid[s_page][n] = false; 
        }
    }

    // --- Velocity Fader Interaction ---
    if (touchX >= faderAreaStartX && touchX < faderAreaStartX + STEPS_PER_PAGE * faderWidth &&
        touchY >= faderAreaStartY && touchY < faderAreaStartY + faderMaxHeight) {
        int page_step_touched = (touchX - faderAreaStartX) / faderWidth; // Step index on current page (0-7)
        int actual_data_step = start_step_of_page + page_step_touched;

        if (actual_data_step < current_sequence_total_steps) { // Ensure we're not touching beyond total steps
            if (isPressed) {
                int rawVelocity = 127 - ((touchY - faderAreaStartY) * 127 / (faderMaxHeight -1));
                if (rawVelocity < 0) rawVelocity = 0;
                if (rawVelocity > 127) rawVelocity = 127;
                if (!touch_was_pressed_on_fader[page_step_touched] || abs(touchY - last_touch_y_on_fader[page_step_touched]) > 1 ) { 
                    note_velocity[actual_data_step] = rawVelocity; // Use actual_data_step for data storage
                    needsRedrawVelocities = true; 
                }
                touch_was_pressed_on_fader[page_step_touched] = true;
                last_touch_y_on_fader[page_step_touched] = touchY;
            } else { 
                 touch_was_pressed_on_fader[page_step_touched] = false;
                 last_touch_y_on_fader[page_step_touched] = -1; 
            }
        }
    } else { 
        if(!isPressed) { 
            for(int s_page=0; s_page<STEPS_PER_PAGE; ++s_page) {
                touch_was_pressed_on_fader[s_page] = false;
                last_touch_y_on_fader[s_page] = -1;
            }
        }
    }

    // --- Control Button Interaction (Play/Stop only) ---
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