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

#define COL_A 5
#define COL_B 60
#define COL_C 115
#define COL_D 170

extern ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);

void setSliderVals();
void drawKnob();

// MOSI=11, MISO=12, SCK=13
extern XPT2046_Touchscreen ts(CS_PIN);
#define TIRQ_PIN  2

float masterVol, rms, avg;
boolean wastouched = true;
boolean but1, but2, but3, but4 = false;
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


void pulseScreen(){
  tft.setFont(LiberationMono_12);
  tft.setCursor(10, 10);
  tft.print("OSC1 PULSE WIDTH");
}

///////Variables for Sine wave below////////////////////
float Xi= 10, Yi= 10, Xf= 319-Xi, Yf= 239-Yi, Ym= 239/2;

void SIN(){
  for ( long  i = 0 ; i<=359 ; i++)
    {  
       tft.drawPixel((Xi+i), (Ym-(90*sin(3*i*PI/180))), ILI9341_BLUE);
       delay(10);
    }

}

