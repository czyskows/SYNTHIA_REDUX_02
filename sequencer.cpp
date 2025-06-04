#include "Sequencer.h" 
#include <cstdint>     
#include <cstring>     

Sequencer::Sequencer() : 
    tft(nullptr), currentVoices(nullptr), 
    current_sequence_total_steps(16), current_page_index(0), // Default to 16 steps, page 0
    is_playing(false), current_step(0), previous_step_drawn(-1), 
    bpm(120.0f), time_since_last_step(0), currentOctaveIndex(0) 
{
    for (int s = 0; s < MAX_TOTAL_STEPS; ++s) {
        note_velocity[s] = 100; 
        for (int n = 0; n < NUM_NOTES; ++n) { 
            note_active[s][n] = false;
        }
    }
    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) {
         for (int n = 0; n < NUM_NOTES; ++n) {
            touch_was_pressed_on_grid[s_page][n] = false;
         }
        touch_was_pressed_on_fader[s_page] = false;
        last_touch_y_on_fader[s_page] = -1;
    }
    step_duration_ms = (60000.0f / bpm) / 4.0f; 
}

void Sequencer::init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo, int initialTotalSteps) {
    tft = tftDisplay;
    currentVoices = voicesForOctave;
    
    if (!tft) return; 
    
    screenWidth = tft->width();
    screenHeight = tft->height();
    
    setTotalSteps(initialTotalSteps); // Set initial total steps, this also validates page_index
    current_page_index = 0;           // Start on the first page

    gridWidth = STEPS_PER_PAGE * cellWidth; 
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
    // The previous_step_drawn should be an actual data step.
    // If current_step is 0, the "previous" for highlighting purposes could be the last step of the sequence.
    previous_step_drawn = (current_step == 0) ? (current_sequence_total_steps -1) : (current_step -1);
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

void Sequencer::resetPlaybackPosition() {
    bool was_playing_before_reset = is_playing; 
    if (is_playing) {
        stop(); // Turns off notes and sets is_playing = false
    }
    current_step = 0;
    time_since_last_step = 0; 
    previous_step_drawn = current_sequence_total_steps; // Force redraw of step 0 as current

    if (was_playing_before_reset) {
        play(); // Resume playing from step 0
    }
    // Visual update will happen in the next update(guiIsActive) call if GUI is active.
}


bool Sequencer::isPlaying() const {
    return is_playing;
}

void Sequencer::setTotalSteps(int totalSteps) {
    if (totalSteps == 8 || totalSteps == 16 || totalSteps == 24 || totalSteps == MAX_TOTAL_STEPS) { // Use MAX_TOTAL_STEPS for 32
        bool was_playing = is_playing;
        if(was_playing) stop();

        current_sequence_total_steps = totalSteps;
        if (current_step >= current_sequence_total_steps) {
            current_step = 0; 
        }
        int max_page_index = (current_sequence_total_steps / STEPS_PER_PAGE) - 1;
        if (max_page_index < 0) max_page_index = 0; // Handle case of 8 steps (1 page)
        if (current_page_index > max_page_index) {
            current_page_index = max_page_index;
        }
        if (tft) { // If GUI might be active
            drawGrid(); // Redraw grid for new length/page
            drawVelocities();
            drawPageIndicator();
            highlightCurrentStep();
        }
        if(was_playing) play();
    }
}

void Sequencer::setPage(int pageIndex) {
    int num_pages = current_sequence_total_steps / STEPS_PER_PAGE;
    if (num_pages == 0 && current_sequence_total_steps > 0) num_pages = 1; // e.g. if total_steps < STEPS_PER_PAGE but > 0
    if (num_pages == 0) num_pages = 1; // Default to 1 page if total_steps is 0 or very small

    int max_page_index = num_pages - 1;
    if (max_page_index < 0) max_page_index = 0;


    if (pageIndex < 0) pageIndex = 0; 
    if (pageIndex > max_page_index) pageIndex = max_page_index; 

    if (current_page_index != pageIndex) {
        current_page_index = pageIndex;
        if (tft) { 
            drawGrid();
            drawVelocities();
            drawPageIndicator();
            highlightCurrentStep(); 
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

            int previous_logical_step = current_step;
            current_step = (current_step + 1) % current_sequence_total_steps; // Use new total steps
            
            turnOffNotesForStep(previous_logical_step);
            triggerNotesForStep(current_step);
        }
    }

    if (guiIsActive && tft) {
        highlightCurrentStep();
    }
}


void Sequencer::triggerNotesForStep(int actual_data_step) { 
    if (!currentVoices || actual_data_step < 0 || actual_data_step >= current_sequence_total_steps) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[actual_data_step][n]) { // Access using actual_data_step
            if (currentVoices[n].waveform && currentVoices[n].envelope) {
                float amp = note_velocity[actual_data_step] / 127.0f; // Use actual_data_step
                currentVoices[n].waveform->amplitude(amp); 
                currentVoices[n].envelope->noteOn();
            }
        }
    }
}

void Sequencer::turnOffNotesForStep(int actual_data_step) { 
    if (!currentVoices || actual_data_step < 0 || actual_data_step >= current_sequence_total_steps) return;
    for (int n = 0; n < NUM_NOTES; ++n) { 
        if (note_active[actual_data_step][n]) { // Access using actual_data_step
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
    drawPageIndicator(); 
    highlightCurrentStep(); 
}

void Sequencer::drawGUI() { 
    if (!tft) return;
    drawGrid(); 
    drawVelocities(); 
    drawPageIndicator();
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

    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) { 
        int actual_data_step = start_step_of_page + s_page;
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + s_page * cellWidth; 
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            
            uint16_t cellColor = colorCellOff; // Default to off if step is beyond total length
            if (actual_data_step < current_sequence_total_steps) { 
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

    for (int s_page = 0; s_page < STEPS_PER_PAGE; ++s_page) { 
        int actual_data_step = start_step_of_page + s_page;
        int x = faderAreaStartX + s_page * faderWidth; 
        int y_fader_area = faderAreaStartY; 
        tft->fillRect(x + 1, y_fader_area + 1, faderWidth - 2, faderMaxHeight - 1, colorBackground);
        
        int barHeight = 1; 
        if (actual_data_step < current_sequence_total_steps) { 
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
    int end_step_of_page = start_step_of_page + STEPS_PER_PAGE - 1;

    // Clear previous highlight if it was on the current page and is different
    if (previous_step_drawn != current_step && 
        previous_step_drawn >= start_step_of_page && 
        previous_step_drawn <= end_step_of_page &&
        previous_step_drawn < current_sequence_total_steps) {
        
        int visual_prev_step_on_page = previous_step_drawn - start_step_of_page;
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + visual_prev_step_on_page * cellWidth;
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            uint16_t cellColor = note_active[previous_step_drawn][n] ? colorCellOn : colorCellOff;
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor); 
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines); 
        }
    }
    
    // Draw new highlight if playing and current_step is on the current page
    if (is_playing && 
        current_step >= start_step_of_page && 
        current_step <= end_step_of_page && 
        current_step < current_sequence_total_steps) {
        
        int visual_current_step_on_page = current_step - start_step_of_page;
        for (int n = 0; n < NUM_NOTES; ++n) { 
            int x = gridStartX + visual_current_step_on_page * cellWidth;
            int y = gridStartY + ((NUM_NOTES - 1) - n) * cellHeight; 
            tft->drawRect(x, y, cellWidth, cellHeight, colorCurrentStepHighlight);
        }
    }
    previous_step_drawn = current_step; 
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
    int tempoDisplayY = stopButtonY - 15; 

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
    tft->fillRect(180, 160, 80, 10, colorBackground); 
    tft->setCursor(180, 160);
    tft->setTextColor(colorText);
    tft->print("Page: ");
    tft->print(current_page_index + 1);
    tft->print("/");
    if (STEPS_PER_PAGE > 0 && current_sequence_total_steps > 0) { 
        int total_pages = (current_sequence_total_steps + STEPS_PER_PAGE - 1) / STEPS_PER_PAGE; // Ceiling division
        tft->print(total_pages);
    } else {
        tft->print("1"); // Default to 1 page if steps are 0 or invalid
    }
}


void Sequencer::handleTouch(int touchX, int touchY, bool isPressed) {
    if (!tft) return;

    bool needsRedrawGrid = false;
    bool needsRedrawVelocities = false;
    int start_step_of_page = current_page_index * STEPS_PER_PAGE;

    if (touchX >= gridStartX && touchX < gridStartX + gridWidth && 
        touchY >= gridStartY && touchY < gridStartY + gridHeight) {
        int page_step_touched = (touchX - gridStartX) / cellWidth; 
        int screen_row_touched = (touchY - gridStartY) / cellHeight; 

        if (screen_row_touched >= 0 && screen_row_touched < NUM_NOTES) {
            int note_data_index = (NUM_NOTES - 1) - screen_row_touched; 
            int actual_data_step = start_step_of_page + page_step_touched;

            if (actual_data_step < current_sequence_total_steps) { 
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

    if (touchX >= faderAreaStartX && touchX < faderAreaStartX + STEPS_PER_PAGE * faderWidth &&
        touchY >= faderAreaStartY && touchY < faderAreaStartY + faderMaxHeight) {
        int page_step_touched = (touchX - faderAreaStartX) / faderWidth; 
        int actual_data_step = start_step_of_page + page_step_touched;

        if (actual_data_step < current_sequence_total_steps) { 
            if (isPressed) {
                int rawVelocity = 127 - ((touchY - faderAreaStartY) * 127 / (faderMaxHeight -1));
                if (rawVelocity < 0) rawVelocity = 0;
                if (rawVelocity > 127) rawVelocity = 127;
                if (!touch_was_pressed_on_fader[page_step_touched] || abs(touchY - last_touch_y_on_fader[page_step_touched]) > 1 ) { 
                    note_velocity[actual_data_step] = rawVelocity; 
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