#include <ILI9341_t3.h>
#include <font_Arial.h> // from ILI9341_t3
#include <font_LiberationMonoBold.h>
#include <font_LiberationMono.h>
#include <font_GeorgiaBoldItalic.h>
#include <XPT2046_Touchscreen.h>
#include "frequencies.h"

#define TFT_DC 14
#define TFT_CS 15

#define CS_PIN 35
#define TIRQ_PIN  2

#define COL_A 5
#define COL_B 60
#define COL_C 115
#define COL_D 170

extern ILI9341_t3 tft;
extern XPT2046_Touchscreen ts;



extern float masterVol, rms, avg;
extern boolean wastouched;
extern boolean but1, but2, but3, but4;
extern int buttonState;
extern int prevButtonState;
extern int func;


float mapFloat(float x, float in_min, float in_max, float out_min, float out_max);
void waveformScreen();
void delayScreen();
void envelopeScreen();
void filterScreen();
void reverbScreen();
void octaveScreen();
void levelsScreen();
void drawSmallKnob(int x_pos, int y_pos);
void drawKnob(int x_pos, int y_pos);
void SIN();





