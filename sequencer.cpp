#include "Sequencer.h" // Ensures Sequencer class definition is known
#include <cstdint>     // For uint16_t
#include <cstring>     // For strlen
#include "display.h"
// #include <Arduino.h>   // Include if you use Serial.print within Sequencer methods for debugging

Sequencer::Sequencer() : tft(nullptr), currentVoices(nullptr), is_playing(false), current_step(0), previous_step_drawn(-1), bpm(120.0f) {
    // Initialize sequencer data
    for (int s = 0; s < NUM_STEPS; ++s) {
        note_velocity[s] = 100; // Default velocity
        for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
            note_active[s][n] = false;
            touch_was_pressed_on_grid[s][n] = false;
        }
        touch_was_pressed_on_fader[s] = false;
        last_touch_y_on_fader[s] = -1;
    }
    step_duration_ms = (60000.0f / bpm) / 4.0f; // Assuming 16th notes (4 steps per beat)
    time_since_last_step = 0;
}

void Sequencer::init(ILI9341_t3* tftDisplay, SequencerVoice* voicesForOctave, int initialTempo) {
    tft = tftDisplay;
    currentVoices = voicesForOctave;
    setTempo(initialTempo);

    // Sanity check
    if (!tft) {
        // Serial.println("Sequencer Error: TFT display not initialized!");
        return; // Or handle error appropriately
    }
    if (!currentVoices) {
        // Serial.println("Sequencer Error: Voices for octave not provided!");
        return;
    }
    screenWidth = tft->width();
    screenHeight = tft->height();
    // Update cellHeight based on NUM_NOTES to better fit the screen if desired
    // Example: if screenHeight is 240, gridStartY is 30, faderAreaHeight is ~45, control buttons ~35
    // Available height for grid ~ 240 - 30 - 10 - 45 - 10 - 35 = 110
    // cellHeight = (110 / NUM_NOTES); // This would make them fit.
    // Or keep cellHeight fixed as defined in header and adjust gridStartY or other elements.
    // For now, using the fixed cellHeight from the header.
    gridHeight = NUM_NOTES * cellHeight; // Recalculate gridHeight based on potentially adjusted cellHeight or new NUM_NOTES
    faderAreaStartY = gridStartY + gridHeight + 10;
    playButtonY = faderAreaStartY + faderAreaHeight + 10;
    stopButtonY = playButtonY;
    tempoUpButtonY = playButtonY;
    tempoDownButtonY = playButtonY;
    octaveUpButtonY = playButtonY;
    octaveDownButtonY = playButtonY;

}

void Sequencer::play() {
    if (is_playing) return;
    is_playing = true;
    current_step = 0; // Or option to resume from where it stopped
    time_since_last_step = 0; // Reset timer for immediate first step
    previous_step_drawn = (NUM_STEPS - 1); // Force redraw of first step highlight
    // Serial.println("Sequencer: Play");
}

void Sequencer::stop() {
    if (!is_playing) return;
    is_playing = false;
    turnOffNotesForStep(current_step); // Turn off any sounding notes from the current step
    // Serial.println("Sequencer: Stop");
    // Redraw the current step without highlight if needed
    if (tft) {
        highlightCurrentStep(); // This will draw it in non-highlight color if not playing
    }
}

void Sequencer::setTempo(int newTempo) {
    if (newTempo < 20) newTempo = 20;
    if (newTempo > 300) newTempo = 300;
    bpm = newTempo;
    step_duration_ms = (60000.0f / bpm) / 4.0f; // 16th notes
    if (tft) { // Update display if it's visible (removed "is_playing" condition to allow tempo update always)
      updateTempoDisplay();
    }
    // Serial.print("Sequencer: Tempo set to "); Serial.println(bpm);
}

int Sequencer::getTempo() const {
    return static_cast<int>(bpm);
}


void Sequencer::setCurrentOctaveVoices(SequencerVoice* voicesForOctave) {
    bool wasPlaying = is_playing;
    if (wasPlaying) stop(); // Stop playback to change voices safely

    currentVoices = voicesForOctave;
    // You might want to redraw note names or other octave-specific GUI elements here
    if (tft) {
        drawNoteNames(); // Redraw note names for the new octave
    }

    if (wasPlaying) play(); // Resume playback if it was playing
}

void Sequencer::shiftOctave(int direction) {
    // This is a placeholder for your actual octave shifting logic.
    // You'll need to manage your arrays of SequencerVoice structures for different octaves
    // in your main sketch and call setCurrentOctaveVoices() with the new array.
    
    // Example:
    // currentOctaveIndex += direction;
    // if (currentOctaveIndex < MIN_OCTAVE) currentOctaveIndex = MIN_OCTAVE;
    // if (currentOctaveIndex > MAX_OCTAVE) currentOctaveIndex = MAX_OCTAVE;
    // SequencerVoice* newOctaveVoiceArray = getVoicesForOctave(currentOctaveIndex); // You implement this
    // setCurrentOctaveVoices(newOctaveVoiceArray);

    // Serial.print("Octave shifted. New index: "); Serial.println(currentOctaveIndex);
}


void Sequencer::update() {
    if (!is_playing || !currentVoices) {
        return;
    }

    if (time_since_last_step >= step_duration_ms) {
        time_since_last_step -= step_duration_ms; // Subtract, don't reset, for better timing

        int justFinishedStep = (current_step == 0) ? (NUM_STEPS - 1) : (current_step - 1);
        turnOffNotesForStep(justFinishedStep); // Turn off notes from the step that just finished playing

        // Trigger notes for the new current_step
        triggerNotesForStep(current_step);

        // Advance step
        current_step = (current_step + 1) % NUM_STEPS;

        if (tft) {
            highlightCurrentStep();
        }
    }
}

void Sequencer::triggerNotesForStep(int step) {
    if (!currentVoices) return;

    for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
        if (note_active[step][n]) {
            if (currentVoices[n].waveform && currentVoices[n].envelope) {
                float amp = note_velocity[step] / 127.0f;
                currentVoices[n].waveform->amplitude(amp); // Set amplitude based on velocity
                currentVoices[n].envelope->noteOn();
                // Serial.print("Step "); Serial.print(step); Serial.print(": Note ON "); Serial.print(n); Serial.print(" Vel: "); Serial.println(note_velocity[step]);
            }
        }
    }
}

void Sequencer::turnOffNotesForStep(int step) {
    if (!currentVoices) return;
    for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
        // Only turn off if it was active in that step.
        if (note_active[step][n]) { 
            if (currentVoices[n].envelope) {
                currentVoices[n].envelope->noteOff();
                 // Serial.print("Step "); Serial.print(step); Serial.print(": Note OFF "); Serial.println(n);
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
    highlightCurrentStep(); // Initial highlight
}

void Sequencer::drawGUI() {
    // This could be smarter, only redrawing changed parts.
    // For now, it's a full redraw of dynamic elements.
    if (!tft) return;
    drawGrid(); // Redraws active/inactive cells
    drawVelocities(); // Redraws velocity bars
}

void Sequencer::drawNoteNames() {
    if (!tft || !currentVoices) return;
    tft->setFont(LiberationMono_10); // MODIFIED: Revert to classic built-in font
    tft->setTextSize(1);
    for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
        int y = gridStartY + n * cellHeight + cellHeight / 2 - 4; // Center text in cell
        // Adjust x for note name width to prevent overlap with grid
        int x_offset = ( (currentVoices[n].noteName && strlen(currentVoices[n].noteName) > 1) ? 10 : 5); // Wider for "C#3" than "C3"
        int x = gridStartX - x_offset - 2; // Ensure space
        if (x < 0) x = 0; // Prevent drawing off-screen

        // Clear previous text area more reliably
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
        for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
            int x = gridStartX + s * cellWidth;
            int y = gridStartY + n * cellHeight;
            uint16_t cellColor = note_active[s][n] ? colorCellOn : colorCellOff;
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor);
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines);
        }
    }
    // Redraw current step highlight if playing
    if (is_playing) {
         highlightCurrentStep();
    }
}

void Sequencer::drawVelocities() {
    if (!tft) return;
    for (int s = 0; s < NUM_STEPS; ++s) {
        int x = faderAreaStartX + s * faderWidth;
        int y = faderAreaStartY;
        // Clear previous bar
        tft->fillRect(x + 1, y + 1, faderWidth - 2, faderMaxHeight - 1, colorBackground);
        // Draw new bar
        int barHeight = (note_velocity[s] / 127.0f) * (faderMaxHeight - 2); // -2 for border
        if (barHeight < 1) barHeight = 1; // Ensure minimum visible bar
        tft->fillRect(x + 1, y + faderMaxHeight - barHeight -1 , faderWidth - 2, barHeight, colorVelocityBar);
        tft->drawRect(x, y, faderWidth, faderMaxHeight, colorGridLines);
    }
}

void Sequencer::highlightCurrentStep() {
    if (!tft) return;

    // Clear previous highlight by redrawing that column normally
    if (previous_step_drawn >= 0 && previous_step_drawn < NUM_STEPS && previous_step_drawn != current_step) {
        for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
            int x = gridStartX + previous_step_drawn * cellWidth;
            int y = gridStartY + n * cellHeight;
            uint16_t cellColor = note_active[previous_step_drawn][n] ? colorCellOn : colorCellOff;
            tft->fillRect(x + 1, y + 1, cellWidth - 1, cellHeight - 1, cellColor); // Fill
            tft->drawRect(x, y, cellWidth, cellHeight, colorGridLines); // Border
        }
    }
    
    // Draw new highlight if playing
    if (is_playing && current_step >= 0 && current_step < NUM_STEPS) {
        for (int n = 0; n < NUM_NOTES; ++n) { // Loop bound updated by NUM_NOTES change
            int x = gridStartX + current_step * cellWidth;
            int y = gridStartY + n * cellHeight;
            // Keep the cell on/off color, but change border
            tft->drawRect(x, y, cellWidth, cellHeight, colorCurrentStepHighlight);
        }
    }
    previous_step_drawn = current_step;
}


void Sequencer::drawControls() {
    if (!tft) return;
    tft->setFont(LiberationMono_10); // MODIFIED: Revert to classic built-in font
    tft->setTextSize(1);

    // Play Button
    tft->fillRect(playButtonX, playButtonY, playButtonWidth, playButtonHeight, colorButton);
    tft->setTextColor(colorText);
    tft->setCursor(playButtonX + 10, playButtonY + 8);
    tft->print("PLAY");

    // Stop Button
    tft->fillRect(stopButtonX, stopButtonY, stopButtonWidth, stopButtonHeight, colorButton);
    tft->setCursor(stopButtonX + 10, stopButtonY + 8);
    tft->print("STOP");

    // Tempo Buttons & Display (Tempo display updated separately)
    tft->fillRect(tempoUpButtonX, tempoUpButtonY, tempoUpButtonWidth, tempoUpButtonHeight, colorButton);
    tft->setCursor(tempoUpButtonX + 10, tempoUpButtonY + 8);
    tft->print("+");
    tft->fillRect(tempoDownButtonX, tempoDownButtonY, tempoDownButtonWidth, tempoDownButtonHeight, colorButton);
    tft->setCursor(tempoDownButtonX + 10, tempoDownButtonY + 8);
    tft->print("-");
    
    // Octave Buttons
    tft->fillRect(octaveUpButtonX, octaveUpButtonY, octaveUpButtonWidth, octaveUpButtonHeight, colorButton);
    tft->setCursor(octaveUpButtonX + 4, octaveUpButtonY + 8);
    tft->print("O+");
    tft->fillRect(octaveDownButtonX, octaveDownButtonY, octaveDownButtonWidth, octaveDownButtonHeight, colorButton);
    tft->setCursor(octaveDownButtonX + 4, octaveDownButtonY + 8);
    tft->print("O-");

    updateTempoDisplay(); // Initial tempo display
}

void Sequencer::updateTempoDisplay() {
    if (!tft) return;
    // Position for tempo display (example)
    int tempoDisplayX = stopButtonX + stopButtonWidth + 5; // Position next to stop button
    int tempoDisplayY = playButtonY - 12; // Position above the control buttons

    tft->setFont(LiberationMono_10); // MODIFIED: Revert to classic built-in font
    tft->setTextSize(1);   // Use small text size
    tft->fillRect(tempoDisplayX, tempoDisplayY, 60, 10, colorBackground); // Clear old tempo text area
    tft->setTextColor(colorText);
    tft->setCursor(tempoDisplayX, tempoDisplayY);
    tft->print("BPM:"); // Removed space for tighter fit
    tft->print(getTempo());
}


void Sequencer::handleTouch(int touchX, int touchY, bool isPressed) {
    if (!tft) return;

    bool needsRedrawGrid = false;
    bool needsRedrawVelocities = false;
    // bool needsRedrawControls = false; // If button visual state changes on press

    // --- Grid Interaction ---
    if (touchX >= gridStartX && touchX < gridStartX + gridWidth &&
        touchY >= gridStartY && touchY < gridStartY + gridHeight) {
        int step = (touchX - gridStartX) / cellWidth;
        int note = (touchY - gridStartY) / cellHeight;

        if (step >= 0 && step < NUM_STEPS && note >= 0 && note < NUM_NOTES) { // Condition updated by NUM_NOTES
            if (isPressed && !touch_was_pressed_on_grid[step][note]) {
                note_active[step][note] = !note_active[step][note];
                touch_was_pressed_on_grid[step][note] = true;
                needsRedrawGrid = true; // Redraw only the affected cell for efficiency later
            } else if (!isPressed) {
                touch_was_pressed_on_grid[step][note] = false;
            }
        }
    } else { 
        if (!isPressed) { 
            for(int s=0; s<NUM_STEPS; ++s) for(int n=0; n<NUM_NOTES; ++n) touch_was_pressed_on_grid[s][n] = false; // Loop bound updated
        }
    }

    // --- Velocity Fader Interaction ---
    if (touchX >= faderAreaStartX && touchX < faderAreaStartX + NUM_STEPS * faderWidth &&
        touchY >= faderAreaStartY && touchY < faderAreaStartY + faderMaxHeight) {
        int step = (touchX - faderAreaStartX) / faderWidth;

        if (step >= 0 && step < NUM_STEPS) {
            if (isPressed) {
                // Calculate velocity based on touch Y within the fader area
                // Touch at top of fader area = max velocity (127)
                // Touch at bottom of fader area = min velocity (0)
                int rawVelocity = 127 - ((touchY - faderAreaStartY) * 127 / (faderMaxHeight -1));
                if (rawVelocity < 0) rawVelocity = 0;
                if (rawVelocity > 127) rawVelocity = 127;
                
                if (!touch_was_pressed_on_fader[step] || abs(touchY - last_touch_y_on_fader[step]) > 1 ) { // Update if Y changed or new press
                    note_velocity[step] = rawVelocity;
                    needsRedrawVelocities = true; // Redraw only affected fader for efficiency later
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

    // --- Control Button Interaction ---
    // Process button presses only once on initial touch to avoid multiple triggers if touch is held.
    static bool playPressedLast = false;
    static bool stopPressedLast = false;
    static bool tempoUpPressedLast = false;
    static bool tempoDownPressedLast = false;
    static bool octaveUpPressedLast = false;
    static bool octaveDownPressedLast = false;

    bool currentPlayPressed = false;
    bool currentStopPressed = false;
    bool currentTempoUpPressed = false;
    bool currentTempoDownPressed = false;
    bool currentOctaveUpPressed = false;
    bool currentOctaveDownPressed = false;

    if (isPressed) {
        if (touchX >= playButtonX && touchX < playButtonX + playButtonWidth &&
            touchY >= playButtonY && touchY < playButtonY + playButtonHeight) currentPlayPressed = true;
        else if (touchX >= stopButtonX && touchX < stopButtonX + stopButtonWidth &&
                 touchY >= stopButtonY && touchY < stopButtonY + stopButtonHeight) currentStopPressed = true;
        else if (touchX >= tempoUpButtonX && touchX < tempoUpButtonX + tempoUpButtonWidth &&
                 touchY >= tempoUpButtonY && touchY < tempoUpButtonY + tempoUpButtonHeight) currentTempoUpPressed = true;
        else if (touchX >= tempoDownButtonX && touchX < tempoDownButtonX + tempoDownButtonWidth &&
                 touchY >= tempoDownButtonY && touchY < tempoDownButtonY + tempoDownButtonHeight) currentTempoDownPressed = true;
        else if (touchX >= octaveUpButtonX && touchX < octaveUpButtonX + octaveUpButtonWidth &&
                 touchY >= octaveUpButtonY && touchY < octaveUpButtonY + octaveUpButtonHeight) currentOctaveUpPressed = true;
        else if (touchX >= octaveDownButtonX && touchX < octaveDownButtonX + octaveDownButtonWidth &&
                 touchY >= octaveDownButtonY && touchY < octaveDownButtonY + octaveDownButtonHeight) currentOctaveDownPressed = true;
    }

    if (currentPlayPressed && !playPressedLast) play();
    if (currentStopPressed && !stopPressedLast) stop();
    if (currentTempoUpPressed && !tempoUpPressedLast) { setTempo(getTempo() + 1); /* updateTempoDisplay(); // called by setTempo */ }
    if (currentTempoDownPressed && !tempoDownPressedLast) { setTempo(getTempo() - 1); /* updateTempoDisplay(); // called by setTempo */ }
    if (currentOctaveUpPressed && !octaveUpPressedLast) shiftOctave(1);
    if (currentOctaveDownPressed && !octaveDownPressedLast) shiftOctave(-1);
    
    playPressedLast = currentPlayPressed;
    stopPressedLast = currentStopPressed;
    tempoUpPressedLast = currentTempoUpPressed;
    tempoDownPressedLast = currentTempoDownPressed;
    octaveUpPressedLast = currentOctaveUpPressed;
    octaveDownPressedLast = currentOctaveDownPressed;


    // Redraw affected parts
    if (needsRedrawGrid) drawGrid(); 
    if (needsRedrawVelocities) drawVelocities(); 
}