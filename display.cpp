#include "display.h"

//////////Map Floating Points////////////////////////////////
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void drawKnob(int x_pos, int y_pos){
  tft.fillRect(x_pos, y_pos, 38, 10, ILI9341_MAROON);
  tft.fillRect(x_pos+10, y_pos+2, 20, 5, ILI9341_WHITE);
}

void drawSmallKnob(int x_pos, int y_pos){
  tft.fillRect(x_pos, y_pos, 7, 18, ILI9341_MAROON);
  tft.fillRect(x_pos+1, y_pos+3, 4, 7, ILI9341_WHITE);
}

void waveformScreen(){

  tft.drawFastHLine(0, 40, 155, 0x7800);
  tft.drawFastVLine(54, 20, 180, 0x7800);
  tft.drawFastVLine(108, 20, 180, 0x7800);

  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 20);
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.print("OSC1");
  tft.setCursor(COL_A, 50);
  tft.setFont(LiberationMono_16);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("SIN");
  tft.setCursor(COL_A, 80);
  tft.print("SAW");
  tft.setCursor(COL_A, 110);
  tft.print("SQR");
  tft.setCursor(COL_A, 140);
  tft.print("TRI");
  tft.setCursor(COL_A, 170);
  tft.print("PUL");

  tft.setFont(LiberationMono_12);
  tft.setCursor(COL_B, 20);
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.print("OSC2");
  tft.setCursor(COL_B, 50);
  tft.setFont(LiberationMono_16);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("SIN");
  tft.setCursor(COL_B, 80);
  tft.print("SAW");
  tft.setCursor(COL_B, 110);
  tft.print("SQR");
  tft.setCursor(COL_B, 140);
  tft.print("TRI");
  tft.setCursor(COL_B, 170);
  tft.print("PUL");

  tft.setFont(LiberationMono_12);
  tft.setCursor(COL_C, 20);
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.print("OSC3");
  tft.setCursor(COL_C, 50);
  tft.setFont(LiberationMono_16);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("SIN");
  tft.setCursor(COL_C, 80);
  tft.print("SAW");
  tft.setCursor(COL_C, 110);
  tft.print("SQR");
  tft.setCursor(COL_C, 140);
  tft.print("TRI");
  tft.setCursor(COL_C, 170);
  tft.print("PUL");

  tft.drawRect(COL_D, 50, 36, 30, TFT_LIGHTSTEELBLUE);
  tft.drawRect(COL_D, 105, 36, 30, TFT_LIGHTSTEELBLUE);
  tft.drawRect(COL_D, 160, 36, 30, TFT_LIGHTSTEELBLUE);
  tft.setFont(LiberationMono_10);
  tft.setCursor(COL_D, 40);
  tft.print("PULSE1");
  tft.setCursor(COL_D, 95);
  tft.print("PULSE2");
  tft.setCursor(COL_D, 150);
  tft.print("PULSE3");
  tft.drawFastHLine(170, 55, 8, ILI9341_WHITE);
  tft.drawFastVLine(178, 55, 20, ILI9341_WHITE);
  tft.drawFastHLine(170, 110, 8, ILI9341_WHITE);
  tft.drawFastVLine(178, 110, 20, ILI9341_WHITE);
  tft.drawFastHLine(170, 165, 8, ILI9341_WHITE);
  tft.drawFastVLine(178, 165, 20, ILI9341_WHITE);

  tft.fillRect(0, 200, 130, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 210);
  tft.print("WAVEFORMS");
}

void delayScreen(){
  tft.fillRect(5, 35, 200, 25, ILI9341_BLACK);
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(6, 17);
  tft.print("0-1");
  tft.setCursor(56, 17);
  tft.print("ms");  
  tft.setCursor(106, 17);
  tft.print("0-1");
  tft.setCursor(156, 17);
  tft.print("0-1");
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 35);
  tft.print("MIX");
  tft.setCursor(55, 35);
  tft.print("TIM");
  tft.setCursor(105, 35);
  tft.print("FBK");
  tft.setCursor(155, 35);
  tft.print("AMT");
  tft.fillRect(0, 200, 110, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(5, 210);
  tft.print("DELAY");
  tft.drawRect(5, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(55, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(105, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(155, 50, 40, 130, SYNTHIA_BLUISH);
}

void envelopeScreen(){
  //////////////////SET TEXT///////////////////////////
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(6, 17);
  tft.print("ms");
  tft.setCursor(56, 17);
  tft.print("ms"); 
  tft.setCursor(106, 17);
  tft.print("0-1"); 
  tft.setCursor(156, 17);
  tft.print("ms");
  tft.fillRect(5, 30, 200, 25, ILI9341_BLACK);
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 35);
  tft.print("ATT");
  tft.setCursor(55, 35);
  tft.print("DEC");
  tft.setCursor(105, 35);
  tft.print("SUS");
  tft.setCursor(155, 35);
  tft.print("REL");
  tft.fillRect(0, 200, 120, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(5, 210);
  tft.print("ENVELOPE");
  tft.drawRect(5, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(55, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(105, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(155, 50, 40, 130, SYNTHIA_BLUISH);
}

void filterScreen(){
  tft.fillRect(5, 35, 200, 25, ILI9341_BLACK);
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(6, 17);
  tft.print("kHz");
  tft.setCursor(56, 17);
  tft.print(".7-5.0");
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 35);
  tft.print("FRQ");
  tft.setCursor(55, 35);
  tft.print("RES");
  tft.setCursor(155, 35);
  tft.print("TYP");
  tft.setFont(LiberationMono_16);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(155, 70);
  tft.print("LOP");
  tft.setCursor(155, 100);
  tft.print("BDP");
  tft.setCursor(155, 130);
  tft.print("HIP");
  tft.setCursor(155, 160);
  tft.print("NUN");
  tft.fillRect(0, 200, 120, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 210);
  tft.print("FILTER");
  tft.drawRect(5, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(55, 50, 40, 130, SYNTHIA_BLUISH);

}

void levelsScreen(){
  tft.fillRect(5, 35, 200, 25, ILI9341_BLACK);
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(6, 17);
  tft.print("0-1");
  tft.setCursor(56, 17);
  tft.print("0-1"); 
  tft.setCursor(106, 17);
  tft.print("0-1"); 
  tft.setCursor(156, 17);
  tft.print("0-1");
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 35);
  tft.print("OSC1");
  tft.setCursor(55, 35);
  tft.print("OSC2");
  tft.setCursor(105, 35);
  tft.print("OSC3");
  tft.setCursor(155, 35);
  tft.print("NOIZ");
  tft.fillRect(0, 200, 120, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(5, 210);
  tft.print("LEVELS");
  tft.drawRect(5, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(55, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(105, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(155, 50, 40, 130, SYNTHIA_BLUISH);  
}

void octaveScreen(){

  tft.drawFastHLine(0, 34, 155, SYNTHIA_LIGHTBLUE);
  tft.drawFastVLine(54, 20, 180, SYNTHIA_LIGHTBLUE);
  tft.drawFastVLine(108, 20, 180, SYNTHIA_LIGHTBLUE);
  tft.setFont(LiberationMono_12);
  tft.setCursor(5, 17);
  tft.setTextColor(SYNTHIA_BLUISH);
  tft.print("OSC1");
  tft.setFont(LiberationMono_12);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(COL_A, 38);
  tft.print("OCT0");
  tft.setCursor(COL_A, 60);
  tft.print("OCT1");
  tft.setCursor(COL_A, 82);
  tft.print("OCT2");
  tft.setCursor(COL_A, 104);
  tft.print("OCT3");
  tft.setCursor(COL_A, 126);
  tft.print("OCT4");
  tft.setCursor(COL_A, 148);
  tft.print("OCT5");
  tft.setCursor(COL_A, 170);
  tft.print("OCT6");

  tft.setFont(LiberationMono_12);
  tft.setCursor(COL_B, 17);
  tft.setTextColor(SYNTHIA_BLUISH);
  tft.print("OSC2");
  tft.setFont(LiberationMono_12);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(COL_B, 38);
  tft.print("OCT0");
  tft.setCursor(COL_B, 60);
  tft.print("OCT1");
  tft.setCursor(COL_B, 82);
  tft.print("OCT2");
  tft.setCursor(COL_B, 104);
  tft.print("OCT3");
  tft.setCursor(COL_B, 126);
  tft.print("OCT4");
  tft.setCursor(COL_B, 148);
  tft.print("OCT5");
  tft.setCursor(COL_B, 170);
  tft.print("OCT6");

  tft.setFont(LiberationMono_12);
  tft.setCursor(COL_C, 17);
  tft.setTextColor(SYNTHIA_BLUISH);
  tft.print("OSC3");
  tft.setFont(LiberationMono_12);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(COL_C, 38);
  tft.print("OCT0");
  tft.setCursor(COL_C, 60);
  tft.print("OCT1");
  tft.setCursor(COL_C, 82);
  tft.print("OCT2");
  tft.setCursor(COL_C, 104);
  tft.print("OCT3");
  tft.setCursor(COL_C, 126);
  tft.print("OCT4");
  tft.setCursor(COL_C, 148);
  tft.print("OCT5");
  tft.setCursor(COL_C, 170);
  tft.print("OCT6");

  tft.fillRect(0, 200, 120, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(5, 210);
  tft.print("OCTAVES");
}

void reverbScreen(){
  tft.fillRect(5, 35, 200, 25, ILI9341_BLACK);
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(6, 17);
  tft.print("0-1");
  tft.setCursor(56, 17);
  tft.print("0-1");
  tft.setTextColor(SYNTHIA_LIGHTBLUE);
  tft.setCursor(5, 35);
  tft.print("ROOM");
  tft.setCursor(55, 35);
  tft.print("DAMP");
  tft.setFont(LiberationMono_16);
  tft.setTextColor(ILI9341_WHITE);
  tft.fillRect(0, 200, 120, 30, ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.setCursor(5, 210);
  tft.print("REVERB");
  tft.drawRect(5, 50, 40, 130, SYNTHIA_BLUISH);
  tft.drawRect(55, 50, 40, 130, SYNTHIA_BLUISH);
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

