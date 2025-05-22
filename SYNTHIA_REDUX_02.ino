#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveformC2;     //xy=69.5,66
AudioSynthWaveform       waveformC1;     //xy=70.5,25
AudioSynthWaveform       waveformC3;     //xy=71.5,108
AudioSynthWaveform       waveformD3;     //xy=74.5,332
AudioSynthWaveform       waveformD1;     //xy=75.5,256
AudioSynthWaveform       waveformD2;     //xy=75.5,293
AudioSynthWaveform       waveformE1;     //xy=79.5,455
AudioSynthWaveform       waveformE2;     //xy=81.5,492
AudioSynthWaveform       waveformE3;     //xy=82.5,528
AudioSynthWaveform       waveformFS2;    //xy=84.5,701
AudioSynthWaveform       waveformFS3;    //xy=84.5,737
AudioSynthWaveform       waveformFS1;    //xy=85.5,665
AudioSynthWaveform       waveformGS1;    //xy=90.5,874
AudioSynthWaveform       waveformGS3;    //xy=90.5,950
AudioSynthWaveform       waveformGS2;    //xy=92.5,912
AudioSynthWaveform       waveformAS1;    //xy=99.5,1099
AudioSynthWaveform       waveformAS3;    //xy=99.5,1171
AudioSynthWaveform       waveformAS2;    //xy=100.5,1136
AudioSynthWaveform       waveformCS1;    //xy=212.5,139
AudioSynthWaveform       waveformCS2;    //xy=217.5,179
AudioSynthWaveform       waveformCS3;    //xy=219.5,220
AudioSynthWaveform       waveformDS1;    //xy=225.5,345
AudioSynthWaveform       waveformDS3;    //xy=226.5,420
AudioSynthWaveform       waveformF2;     //xy=226.5,596
AudioSynthWaveform       waveformDS2;    //xy=227.5,382
AudioSynthWaveform       waveformF1;     //xy=227.5,559
AudioSynthWaveform       waveformF3;     //xy=230.5,634
AudioSynthWaveform       waveformG1;     //xy=233.5,764
AudioSynthWaveform       waveformG2;     //xy=233.5,801
AudioSynthWaveform       waveformG3;     //xy=235.5,840
AudioMixer4              mixerC1;        //xy=247.5,58
AudioMixer4              mixerE1;        //xy=246.5,490
AudioSynthWaveform       waveformA1;     //xy=245.5,981
AudioSynthWaveform       waveformA2;     //xy=246.5,1019
AudioMixer4              mixerD1;        //xy=250.5,285
AudioSynthWaveform       waveformA3;     //xy=247.5,1057
AudioMixer4              mixerFS;        //xy=251.5,695
AudioSynthWaveform       waveformB2;     //xy=254.5,1236
AudioSynthWaveform       waveformB1;     //xy=255.5,1196
AudioSynthWaveform       waveformB3;     //xy=255.5,1275
AudioMixer4              mixerGS;        //xy=261.5,907
AudioMixer4              mixerAS;        //xy=263.5,1128
AudioMixer4              mixerCS;        //xy=376.5,174
AudioMixer4              mixerDS;        //xy=382.5,382
AudioEffectEnvelope      env1;           //xy=386.5,57
AudioEffectEnvelope      env5;           //xy=386.5,492
AudioMixer4              mixerF1;        //xy=390.5,591
AudioMixer4              mixerG1;        //xy=394.5,795
AudioEffectEnvelope      env9;           //xy=398.5,908
AudioMixer4              mixerA1;        //xy=401.5,1013
AudioEffectEnvelope      env3;           //xy=408.5,285
AudioEffectEnvelope      env11;          //xy=411.5,1125
AudioEffectEnvelope      env7;           //xy=415.5,687
AudioMixer4              mixerB1;        //xy=417.5,1236
AudioEffectEnvelope      env2;           //xy=511.5,175
AudioEffectEnvelope      env4;           //xy=519.5,379
AudioEffectEnvelope      env6;           //xy=533.5,595
AudioEffectEnvelope      env8;           //xy=534.5,798
AudioEffectEnvelope      env10;          //xy=538.5,1013
AudioEffectEnvelope      env12;          //xy=561.5,1237
AudioSynthNoisePink      noise1;         //xy=689.5,777
AudioMixer4              mixerKeys1;     //xy=695.5,291
AudioMixer4              mixerKeys2;     //xy=698.5,573
AudioMixer4              mixerKeys3;     //xy=702.5,941
AudioEffectEnvelope      env13;          //xy=771.5,689
AudioMixer4              mixerKeys4;     //xy=863.5,580
AudioEffectFreeverb      freeverb1;      //xy=1002.5,496
AudioAnalyzePeak         peak1;          //xy=1002.500150680542,661.0000200271606
AudioFilterStateVariable filter1;        //xy=1066.5,588
AudioMixer4              mixerFilter1;   //xy=1267.5,595
AudioMixer4              mixerFeedback;  //xy=1461.5,614
AudioEffectDelay         delay1;         //xy=1470.5,465
AudioAnalyzePeak         peak2;          //xy=1627.515625,685.515625
AudioMixer4              mixerDelay1;    //xy=1631.5,429
AudioMixer4              mixerDelay2;    //xy=1631.5,498
AudioMixer4              mixerDryWet1;   //xy=1936.5,586
AudioMixer4              mixerDryWet2;   //xy=1936.5,658
AudioOutputI2S           i2s1;           //xy=2105.5,628
AudioAnalyzePeak         peak3;          //xy=2109.5156860351562,520.5156478881836
AudioAnalyzePeak         peak4;          //xy=2110.515625,739.515625
AudioConnection          patchCord1(waveformC2, 0, mixerC1, 1);
AudioConnection          patchCord2(waveformC1, 0, mixerC1, 0);
AudioConnection          patchCord3(waveformC3, 0, mixerC1, 2);
AudioConnection          patchCord4(waveformD3, 0, mixerD1, 2);
AudioConnection          patchCord5(waveformD1, 0, mixerD1, 0);
AudioConnection          patchCord6(waveformD2, 0, mixerD1, 1);
AudioConnection          patchCord7(waveformE1, 0, mixerE1, 0);
AudioConnection          patchCord8(waveformE2, 0, mixerE1, 1);
AudioConnection          patchCord9(waveformE3, 0, mixerE1, 2);
AudioConnection          patchCord10(waveformFS2, 0, mixerFS, 1);
AudioConnection          patchCord11(waveformFS3, 0, mixerFS, 2);
AudioConnection          patchCord12(waveformFS1, 0, mixerFS, 0);
AudioConnection          patchCord13(waveformGS1, 0, mixerGS, 0);
AudioConnection          patchCord14(waveformGS3, 0, mixerGS, 2);
AudioConnection          patchCord15(waveformGS2, 0, mixerGS, 1);
AudioConnection          patchCord16(waveformAS1, 0, mixerAS, 0);
AudioConnection          patchCord17(waveformAS3, 0, mixerAS, 2);
AudioConnection          patchCord18(waveformAS2, 0, mixerAS, 1);
AudioConnection          patchCord19(waveformCS1, 0, mixerCS, 0);
AudioConnection          patchCord20(waveformCS2, 0, mixerCS, 1);
AudioConnection          patchCord21(waveformCS3, 0, mixerCS, 2);
AudioConnection          patchCord22(waveformDS1, 0, mixerDS, 0);
AudioConnection          patchCord23(waveformDS3, 0, mixerDS, 2);
AudioConnection          patchCord24(waveformF2, 0, mixerF1, 1);
AudioConnection          patchCord25(waveformDS2, 0, mixerDS, 1);
AudioConnection          patchCord26(waveformF1, 0, mixerF1, 0);
AudioConnection          patchCord27(waveformF3, 0, mixerF1, 2);
AudioConnection          patchCord28(waveformG1, 0, mixerG1, 0);
AudioConnection          patchCord29(waveformG2, 0, mixerG1, 1);
AudioConnection          patchCord30(waveformG3, 0, mixerG1, 2);
AudioConnection          patchCord31(mixerC1, env1);
AudioConnection          patchCord32(mixerE1, env5);
AudioConnection          patchCord33(waveformA1, 0, mixerA1, 0);
AudioConnection          patchCord34(waveformA2, 0, mixerA1, 1);
AudioConnection          patchCord35(mixerD1, env3);
AudioConnection          patchCord36(waveformA3, 0, mixerA1, 2);
AudioConnection          patchCord37(mixerFS, env7);
AudioConnection          patchCord38(waveformB2, 0, mixerB1, 1);
AudioConnection          patchCord39(waveformB1, 0, mixerB1, 0);
AudioConnection          patchCord40(waveformB3, 0, mixerB1, 2);
AudioConnection          patchCord41(mixerGS, env9);
AudioConnection          patchCord42(mixerAS, env11);
AudioConnection          patchCord43(mixerCS, env2);
AudioConnection          patchCord44(mixerDS, env4);
AudioConnection          patchCord45(env1, 0, mixerKeys1, 0);
AudioConnection          patchCord46(env5, 0, mixerKeys2, 0);
AudioConnection          patchCord47(mixerF1, env6);
AudioConnection          patchCord48(mixerG1, env8);
AudioConnection          patchCord49(env9, 0, mixerKeys3, 0);
AudioConnection          patchCord50(mixerA1, env10);
AudioConnection          patchCord51(env3, 0, mixerKeys1, 2);
AudioConnection          patchCord52(env11, 0, mixerKeys3, 2);
AudioConnection          patchCord53(env7, 0, mixerKeys2, 2);
AudioConnection          patchCord54(mixerB1, env12);
AudioConnection          patchCord55(env2, 0, mixerKeys1, 1);
AudioConnection          patchCord56(env4, 0, mixerKeys1, 3);
AudioConnection          patchCord57(env6, 0, mixerKeys2, 1);
AudioConnection          patchCord58(env8, 0, mixerKeys2, 3);
AudioConnection          patchCord59(env10, 0, mixerKeys3, 1);
AudioConnection          patchCord60(env12, 0, mixerKeys3, 3);
AudioConnection          patchCord61(noise1, env13);
AudioConnection          patchCord62(mixerKeys1, 0, mixerKeys4, 0);
AudioConnection          patchCord63(mixerKeys2, 0, mixerKeys4, 1);
AudioConnection          patchCord64(mixerKeys3, 0, mixerKeys4, 2);
AudioConnection          patchCord65(env13, 0, mixerKeys4, 3);
AudioConnection          patchCord66(mixerKeys4, freeverb1);
AudioConnection          patchCord67(mixerKeys4, peak1);
AudioConnection          patchCord68(freeverb1, 0, filter1, 0);
AudioConnection          patchCord69(freeverb1, 0, mixerFilter1, 3);
AudioConnection          patchCord70(filter1, 0, mixerFilter1, 0);
AudioConnection          patchCord71(filter1, 1, mixerFilter1, 1);
AudioConnection          patchCord72(filter1, 2, mixerFilter1, 2);
AudioConnection          patchCord73(mixerFilter1, 0, mixerFeedback, 0);
AudioConnection          patchCord74(mixerFeedback, delay1);
AudioConnection          patchCord75(mixerFeedback, 0, mixerDryWet1, 0);
AudioConnection          patchCord76(mixerFeedback, 0, mixerDryWet2, 0);
AudioConnection          patchCord77(mixerFeedback, peak2);
AudioConnection          patchCord78(delay1, 0, mixerDelay1, 0);
AudioConnection          patchCord79(delay1, 1, mixerDelay2, 0);
AudioConnection          patchCord80(delay1, 2, mixerDelay1, 1);
AudioConnection          patchCord81(delay1, 3, mixerDelay2, 1);
AudioConnection          patchCord82(delay1, 4, mixerDelay1, 2);
AudioConnection          patchCord83(delay1, 5, mixerDelay2, 2);
AudioConnection          patchCord84(delay1, 6, mixerDelay1, 3);
AudioConnection          patchCord85(delay1, 7, mixerDelay2, 3);
AudioConnection          patchCord86(mixerDelay1, 0, mixerFeedback, 1);
AudioConnection          patchCord87(mixerDelay1, 0, mixerDryWet1, 1);
AudioConnection          patchCord88(mixerDelay2, 0, mixerFeedback, 2);
AudioConnection          patchCord89(mixerDelay2, 0, mixerDryWet2, 1);
AudioConnection          patchCord90(mixerDryWet1, 0, i2s1, 0);
AudioConnection          patchCord91(mixerDryWet1, peak3);
AudioConnection          patchCord92(mixerDryWet2, 0, i2s1, 1);
AudioConnection          patchCord93(mixerDryWet2, peak4);
AudioControlSGTL5000     sgtl5000_1;     //xy=1337.5,705
// GUItool: end automatically generated code

#include "frequencies.h"
#include "display.h"
#include <AT42QT2120.h>
#include <Bounce.h>
#include <SPI.h>
#include <Wire.h>
#include <CapacitiveSensor.h>

#define change1 28
#define change2 29
#define change3 30
#define change4 31
#define change5 32

#define muxS0Pin 0  
#define muxS1Pin 1
#define muxS2Pin 2
#define muxS3Pin 3

// the filter shapes for our switch cases below
#define FilterHP 1
#define FilterBP 2
#define FilterLP 3
#define FilterNo 4

// Use these with the Teensy 3.5 & 3.6 SD card
#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11  // not actually used
#define SDCARD_SCK_PIN   13  // not actually used

Bounce Ckey =   Bounce(cKey, 15);
Bounce CSkey =  Bounce(csKey, 15);
Bounce Dkey =   Bounce(dKey, 15);
Bounce DSkey =  Bounce(dsKey, 15);
Bounce Ekey =   Bounce(eKey, 15);
Bounce Fkey =   Bounce(fKey, 15);
Bounce FSkey =  Bounce(fsKey, 15);
Bounce Gkey =   Bounce(gKey, 15);
Bounce GSkey =  Bounce(gsKey, 15);
Bounce Akey =   Bounce(aKey, 15);
Bounce ASkey =  Bounce(asKey, 15);
Bounce Bkey =   Bounce(bKey, 15);

#define STATUS_KEY1     0   //TCA INPUT CHANNEL FOR SCREEN CONTROL
#define STATUS_KEY2     4
#define muxSignalPin    22  //CAPSENSE INPUT PIN
#define capSenseSendPin 4   
#define sampleRate      10
#define n_inputs        12
#define deltaVal        9000   
#define thresh          24000    //KEY THREShOLD SETTING//

//we're going to create references to our controls in an array
AudioEffectEnvelope *envs[13] = {
  &env1, &env2, &env3, &env4, &env5,
  &env6, &env7, &env8, &env9, &env10,
  &env11, &env12, &env13
};
//and our waveforms
AudioSynthWaveform *waves1[12] = {
  &waveformC1, &waveformCS1, &waveformD1, &waveformDS1,
  &waveformE1, &waveformF1, &waveformFS1, &waveformG1,
  &waveformGS1, &waveformA1, &waveformAS1, &waveformB1,
};
AudioSynthWaveform *waves2[12] = {
  &waveformC2, &waveformCS2, &waveformD2, &waveformDS2,
  &waveformE2, &waveformF2, &waveformFS2, &waveformG2,
  &waveformGS2, &waveformA2, &waveformAS2, &waveformB2,
};
AudioSynthWaveform *waves3[12] = {
  &waveformC3, &waveformCS3, &waveformD3, &waveformDS3,
  &waveformE3, &waveformF3, &waveformFS3, &waveformG3,
  &waveformGS3, &waveformA3, &waveformAS3, &waveformB3,
};

AudioMixer4 *mixers[12] = {
  &mixerC1, &mixerCS, &mixerD1, &mixerDS, &mixerE1, &mixerF1, 
  &mixerFS, &mixerG1, &mixerGS, &mixerA1, &mixerAS, &mixerB1,
};

int octaves0 [12] = {  C0, CS0, D0, DS0, E0, F0, FS0, G0, GS0, A0, AS0, B_0 };
int octaves1 [12] = {  C1, CS1, D1, DS1, E1, F1, FS1, G1, GS1, A1, AS1, B_1 };
int octaves2 [12] = {  C2, CS2, D2, DS2, E2, F2, FS2, G2, GS2, A2, AS2, B2 };
int octaves3 [12] = {  C3, CS3, D3, DS3, E3, F3, FS3, G3, GS3, A3, AS3, B3 };
int octaves4 [12] = {  C4, CS4, D4, DS4, E4, F4, FS4, G4, GS4, A4, AS4, B4 };
int octaves5 [12] = {  C5, CS5, D5, DS5, E5, F5, FS5, G5, GS5, A5, AS5, B5 };
int octaves6 [12] = {  C6, CS6, D6, DS6, E6, F6, FS6, G6, GS6, A6, AS6, B6 };

int osc1Octave, osc2Octave, osc3Octave; 

//initialize waveform variables
int current_waveform1, current_waveform2, current_waveform3, current_filter = 0;

//declare the control variable
int   atck    = 10;
float sust    = 0.4;
int   decy    = 50;
int   rels    = 600;
int   deltime = 0;
float delAmt  = 0.0;
float fback   = 0.0;
float dmix    = 0.0; 
int   freq    = 1000;
float reso    = 0.5;
float room    = 0.0;
float damp    = 0.0;
float osc1Vol = 0.9; 
float osc2Vol = 0.9;
float osc3Vol = 0.9;
float noizAmp = 0.0; 
float pWidth1 = 128;
float pWidth2 = 128;
float pWidth3 = 128;
//variables for the displa
int atckD    = 170;
int sustD    = 120;
int decyD    = 120;
int relsD    = 160;
int deltimeD = 170;
int delAmtD  = 170;
int fbackD   = 170;
int dmixD    = 170;
int freqD    = 170;
int resoD    = 170; 
int roomD    = 170;
int dampD    = 170;
int osc1VolD = 70;
int osc2VolD = 70;
int osc3VolD = 70;
int noizAmpD = 170;
//VAriables for Note On/Off
int Cval  = 0;
int CSval = 0;
int Dval  = 0;
int DSval = 0;
int Eval  = 0;
int Fval  = 0;
int FSval = 0;
int Gval  = 0;
int GSval = 0;
int Aval  = 0;
int ASval = 0;
int Bval  = 0;
//Variables for Note On/Off Too
int P_Cval  = 0;
int P_CSval = 0;
int P_Dval  = 0;
int P_DSval = 0;
int P_Eval  = 0;
int P_Fval  = 0;
int P_FSval = 0;
int P_Gval  = 0;
int P_GSval = 0; 
int P_Aval  = 0;
int P_ASval = 0;
int P_Bval  = 0;

float gain1 = .75;
float amp1  = .9;

float displayedLvlMtr1 = 0;
float displayedLvlMtr2 = 0;
unsigned long lastDecayTimeMtr1 = 0;
unsigned long lastDecayTimeMtr2 = 0;
const long decayIntervalMtr = 50; // Adjust for desired decay speed
const int barHeightSegment = 7;   // Height of each bar segment
const int barWidth = 17;
const int barStartX1 = 260;
const int barStartX2 = 280;
const int barTopY= 51;

int sliderVal1, P_sliderVal1, sliderVal2, sliderVal3, sliderVal4, wheelVal, buttons;
int sliChange1, sliChange2, sliChange3, sliChange4, sliChange5;

/////////////Arrays for storing delta values from touchPads////////
// int diff[n_inputs] = {};
// int previousTouch[n_inputs] = {};
int touch[n_inputs] = {};

CapacitiveSensor capSense = CapacitiveSensor( capSenseSendPin, muxSignalPin );

AT42QT2120 touch_sensor;

bool shift;

const long BAUD = 115200;
const int RESET_DELAY = 2000;
const int CALIBRATION_DELAY = 150;
elapsedMillis calibration_timeout;

////////////////////////READ FROM MUX//////////////////////////////////
int readMux(int channel) {
    int controlPin[] = {muxS0Pin, muxS1Pin, muxS2Pin, muxS3Pin};
  
    int muxChannel[16][4] = {
      {0, 0, 0, 0}, //channel 0
      {1, 0, 0, 0}, //channel 1
      {0, 1, 0, 0}, //channel 2
      {1, 1, 0, 0}, //channel 3
      {0, 0, 1, 0}, //channel 4
      {1, 0, 1, 0}, //channel 5
      {0, 1, 1, 0}, //channel 6
      {1, 1, 1, 0}, //channel 7
      {0, 0, 0, 1}, //channel 8
      {1, 0, 0, 1}, //channel 9
      {0, 1, 0, 1}, //channel 10
      {1, 1, 0, 1}, //channel 11
      {0, 0, 1, 1}, //channel 12
      {1, 0, 1, 1}, //channel 13
      {0, 1, 1, 1}, //channel 14
      {1, 1, 1, 1} //channel 15
    };
  
    //loop through the 4 contol pins
    for (int k = 0; k < 4; k ++) {
      digitalWrite(controlPin[k], muxChannel[channel][k]);
    }
    //read the value at the SIG pin
    return capSense.capacitiveSensor( sampleRate );
    delay(10);
  }

// Select I2C BUS ON TCA9548//////////////////////////////////
void TCA9548A(uint8_t bus){
    Wire.beginTransmission(0x70);  // TCA9548A address
    Wire.write(1 << bus);          // send byte to select bus
    Wire.endTransmission();
    //Serial.print(bus);
  }

////////////Average RMS Readings///////////////////////////
float rmsAve(float rms, int num){
    float sum = 0;
    for(int i = 0; i < num; i++);
    sum += rms;
    return sum/num;
  }


///////////////////////////////////SETUP///////////////////////////////////////////////////////////////////
void setup() {
  
  Serial.begin(115200);
  //while (!Serial && (millis() <= 1000));
  Wire.begin();
  //////Slider Change Pins////////////
  pinMode(change1, INPUT);
  pinMode(change2, INPUT);
  pinMode(change3, INPUT);
  pinMode(change4, INPUT);
  pinMode(change5, INPUT);
  //////Note Pads////////////////
  pinMode(cKey,   OUTPUT);
  pinMode(csKey,  OUTPUT);
  pinMode(dKey,   OUTPUT);
  pinMode(dsKey,  OUTPUT);
  pinMode(eKey,   OUTPUT);
  pinMode(fKey,   OUTPUT);
  pinMode(fsKey,  OUTPUT);
  pinMode(gKey,   OUTPUT);
  pinMode(gsKey,  OUTPUT);
  pinMode(aKey,   OUTPUT);
  pinMode(asKey,  OUTPUT);
  pinMode(bKey,   OUTPUT);

  ///////////////SET UP SCREEN//////////////
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  ts.begin();
  ts.setRotation(3);
  tft.setCursor(20,100);
  tft.setFont(LiberationMono_48);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("SYNTHIA");
  
////////////AUDIO SETUP//////////////
  AudioMemory(896);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  //setting initial waveforms
  current_waveform1 = WAVEFORM_SINE;
  current_waveform2 = WAVEFORM_TRIANGLE;
  current_waveform3 = WAVEFORM_SAWTOOTH;
  //and filter
  current_filter = FilterNo;

  //setting up mixers
  mixerKeys1.gain(0, gain1);
  mixerKeys1.gain(1, gain1);
  mixerKeys1.gain(2, gain1);
  mixerKeys1.gain(3, gain1);
  mixerKeys2.gain(0, gain1);
  mixerKeys2.gain(1, gain1);
  mixerKeys2.gain(2, gain1);
  mixerKeys2.gain(3, gain1);
  mixerKeys3.gain(0, gain1);
  mixerKeys3.gain(1, gain1);
  mixerKeys3.gain(2, gain1);
  mixerKeys3.gain(3, gain1);
  mixerKeys4.gain(0, gain1);
  mixerKeys4.gain(1, gain1);
  mixerKeys4.gain(2, gain1);
  mixerKeys4.gain(3, gain1);
  mixerFilter1.gain(0, 0);
  mixerFilter1.gain(1, 0);
  mixerFilter1.gain(2, 0);
  mixerFilter1.gain(3, 0.9);
  mixerFeedback.gain(0, 0.9);
  mixerFeedback.gain(1, 0.0);
  mixerFeedback.gain(2, 0.0);
  mixerDryWet1.gain(0, 0.9);
  mixerDryWet2.gain(0, 0.9);
  mixerDryWet1.gain(1, 0.0);
  mixerDryWet2.gain(1, 0.0);
  
  //Initialize waveforms at given frequencies 
  waveformC1.begin(amp1, C2, current_waveform1);
  waveformC2.begin(amp1, C2, current_waveform2);
  waveformC3.begin(amp1, C3, current_waveform3);
  waveformCS1.begin(amp1, CS2, current_waveform1);
  waveformCS2.begin(amp1, CS2, current_waveform2);
  waveformCS3.begin(amp1, CS3, current_waveform3);
  waveformD1.begin(amp1, D2, current_waveform1);
  waveformD2.begin(amp1, D2, current_waveform2);
  waveformD3.begin(amp1, D3, current_waveform3);
  waveformDS1.begin(amp1, DS2, current_waveform1);
  waveformDS2.begin(amp1, DS2, current_waveform2);
  waveformDS3.begin(amp1, DS3, current_waveform3);
  waveformE1.begin(amp1, E2, current_waveform1);
  waveformE2.begin(amp1, E2, current_waveform2);
  waveformE3.begin(amp1, E3, current_waveform3);
  waveformF1.begin(amp1, F2, current_waveform1);
  waveformF2.begin(amp1, F2, current_waveform2);
  waveformF3.begin(amp1, F3, current_waveform3);
  waveformFS1.begin(amp1, FS2, current_waveform1);
  waveformFS2.begin(amp1, FS2, current_waveform2);
  waveformFS3.begin(amp1, FS3, current_waveform3);
  waveformG1.begin(amp1, G2, current_waveform1);
  waveformG2.begin(amp1, G2, current_waveform2);
  waveformG3.begin(amp1, G3, current_waveform3);
  waveformGS1.begin(amp1, GS2, current_waveform1);
  waveformGS2.begin(amp1, GS2, current_waveform2);
  waveformGS3.begin(amp1, GS3, current_waveform3);
  waveformA1.begin(amp1, A2, current_waveform1);
  waveformA2.begin(amp1, A2, current_waveform2);
  waveformA3.begin(amp1, A3, current_waveform3);
  waveformAS1.begin(amp1, AS2, current_waveform1);
  waveformAS2.begin(amp1, AS2, current_waveform2);
  waveformAS3.begin(amp1, AS3, current_waveform3);
  waveformB1.begin(amp1, B2, current_waveform1);
  waveformB2.begin(amp1, B2, current_waveform2);
  waveformB3.begin(amp1, B3, current_waveform3);

///////////ENABLE QTOUCH/////////////
  for(int i = 0; i< 5; i++){
    TCA9548A(i);
    touch_sensor.begin();
    
    touch_sensor.enableSlider();
    Serial.println("reseting...");
    touch_sensor.reset();
    
    Serial.println("triggerCalibration");
    touch_sensor.triggerCalibration();
    delay(CALIBRATION_DELAY);
    while (touch_sensor.calibrating()){
      Serial.println("calibrating...");
      delay(CALIBRATION_DELAY); 
    }
    Serial.println("finished calibrating");
    
    delay(500);
  }
  // tft.fillScreen(ILI9341_BLACK);
  SIN();
  delay(1000);

  ////////////SET UP MUX///////////////////
  // set control pins to output mode
  pinMode(muxS0Pin, OUTPUT);
  pinMode(muxS1Pin, OUTPUT);
  pinMode(muxS2Pin, OUTPUT);
  pinMode(muxS3Pin, OUTPUT);
  // and set them low
  digitalWrite(muxS0Pin, LOW);
  digitalWrite(muxS1Pin, LOW);
  digitalWrite(muxS2Pin, LOW);
  digitalWrite(muxS3Pin, LOW);

///////////////CLEAR SCREEN//////////
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setFont(LiberationMono_16);

  envelopeScreen(); 
  buttonState = 1;

}

////////////////////////////////////////////////////////LOOP/////////////////////////////////////////////////////////////////////////////
void loop() {

  boolean istouched = ts.touched();

  //////////Slider Value Change///////////////////
  sliChange1 = digitalRead(change4);
  sliChange2 = digitalRead(change3);
  sliChange3 = digitalRead(change2);
  sliChange4 = digitalRead(change1);
  sliChange5 = digitalRead(change5);

  ///////////GET SLIDER/WHEEL VALUES//////////////////////////
  TCA9548A(STATUS_KEY1);
  AT42QT2120::Status status1 = touch_sensor.getStatus();

  TCA9548A(STATUS_KEY2);
  AT42QT2120::Status status2 = touch_sensor.getStatus();

  TCA9548A(0);
  touch_sensor.enableSlider();
  sliderVal1 = (touch_sensor.getSliderValue());

  TCA9548A(1);
  touch_sensor.enableSlider();
  sliderVal2 = (touch_sensor.getSliderValue());

  TCA9548A(2);
  touch_sensor.enableSlider();
  sliderVal3 = (touch_sensor.getSliderValue());

  TCA9548A(3);
  touch_sensor.enableSlider();
  sliderVal4 = (touch_sensor.getSliderValue());

  TCA9548A(4);
  touch_sensor.enableWheel();
  wheelVal = map(touch_sensor.getSliderValue(), 0, 255, 255, 0);

  /////////////////////MASTER VOLUME///////////////////////////
  mixerDryWet1.gain(0, mapFloat(wheelVal, 0, 255, 0.0, 1.0));
  mixerDryWet1.gain(1, mapFloat(wheelVal, 0, 255, 0.0, 1.0));
  mixerDryWet2.gain(0, mapFloat(wheelVal, 0, 255, 0.0, 1.0));
  mixerDryWet2.gain(1, mapFloat(wheelVal, 0, 255, 0.0, 1.0));

  //////////////////////////////////////READ THE KEYS///////////////////////////////////////////////////
  for ( byte channel = 0; channel < n_inputs; ++channel ) {
    touch[channel] = readMux(channel);
    //diff[channel] = touch[channel] - previousTouch[channel];
    Serial.print(touch[channel]);
    Serial.print("\t");
  }
  Serial.println();
  
  ////////////////////////////////////PLAY THE NOTES//////////////////////////////////////////////////
  if(touch[8] >= thresh){ 
    Cval = 0;}
  else{Cval = 1;}
  if(Cval != P_Cval){
    digitalWrite(cKey, Cval);
  }  
  P_Cval = Cval;

  if(touch[9] >= thresh){ 
    CSval = 0;}
  else{CSval = 1;}
  if(CSval != P_CSval){
    digitalWrite(csKey, CSval);
  }  
  P_CSval = CSval;
    
  if(touch[10] >= thresh){ 
    Dval = 0;}
  else{Dval = 1;}
  if(Dval != P_Dval){
    digitalWrite(dKey, Dval);
  }  
  P_Dval = Dval;

  if(touch[11] >= thresh){ 
    DSval = 0;}
  else{DSval = 1;}
  if(DSval != P_DSval){
    digitalWrite(dsKey, DSval);
  }  
  P_DSval = DSval;

  if(touch[7] >= thresh){ 
  Eval = 0;}
  else{Eval = 1;}
  if(Eval != P_Eval){
    digitalWrite(eKey, Eval);
  }  
  P_Eval = Eval;

  if(touch[6] >= thresh){ 
    Fval = 0;}
  else{Fval = 1;}
  if(Fval != P_Fval){
    digitalWrite(fKey, Fval);
  }  
  P_Fval = Fval;

  if(touch[5] >= thresh){ 
    FSval = 0;}
  else{FSval = 1;}
  if(FSval != P_FSval){
    digitalWrite(fsKey, FSval);
  }  
  P_FSval = FSval;

  if(touch[4] >= thresh){ 
    Gval = 0;}
  else{Gval = 1;}
  if(Gval != P_Gval){
    digitalWrite(gKey, Gval);
  }  
  P_Gval = Gval;

  if(touch[3] >= thresh){ 
    GSval = 0;}
  else{GSval = 1;}
  if(GSval != P_GSval){
    digitalWrite(gsKey, GSval);
  }  
  P_GSval = GSval;

  if(touch[2] >= thresh){ 
  Aval = 0;}
  else{Aval = 1;}
  if(Aval != P_Aval){
    digitalWrite(aKey, Aval);
  }  
  P_Aval = Aval;

  if(touch[1] >= thresh){ 
    ASval = 0;}
  else{ASval = 1;}
  if(ASval != P_ASval){
    digitalWrite(asKey, ASval);
  }  
  P_ASval = ASval;

  if(touch[0] >= thresh){ 
    Bval = 0;}
  else{Bval = 1;}
  if(Bval != P_Bval){
    digitalWrite(bKey, Bval);
  }  
  P_Bval = Bval;

  //////////////////////////////////////////UPDATE TOUCh PAD BOUNCE//////////////////////////////////////////////////////
  Ckey.update();
  CSkey.update();
  Dkey.update();
  DSkey.update();
  Ekey.update();
  Fkey.update();
  FSkey.update();
  Gkey.update();
  GSkey.update();
  Akey.update();
  ASkey.update();
  Bkey.update();

  //playing notes
  if (Ckey.fallingEdge()){env1.noteOn();env13.noteOn();}
  if (CSkey.fallingEdge()){env2.noteOn();env13.noteOn();}
  if (Dkey.fallingEdge()){env3.noteOn();env13.noteOn();}
  if (DSkey.fallingEdge()){env4.noteOn();env13.noteOn();}
  if (Ekey.fallingEdge()){env5.noteOn();env13.noteOn();}
  if (Fkey.fallingEdge()){env6.noteOn();env13.noteOn();}
  if (FSkey.fallingEdge()){env7.noteOn();env13.noteOn();}
  if (Gkey.fallingEdge()){env8.noteOn();env13.noteOn();}
  if (GSkey.fallingEdge()){env9.noteOn();env13.noteOn();}
  if (Akey.fallingEdge()){env10.noteOn();env13.noteOn();}
  if (ASkey.fallingEdge()){env11.noteOn();env13.noteOn();}
  if (Bkey.fallingEdge()){env12.noteOn();env13.noteOn();} 

  if (Ckey.risingEdge()){env1.noteOff();env13.noteOff();} 
  if (CSkey.risingEdge()){env2.noteOff();env13.noteOff();} 
  if (Dkey.risingEdge()){env3.noteOff();env13.noteOff();} 
  if (DSkey.risingEdge()){env4.noteOff();env13.noteOff();} 
  if (Ekey.risingEdge()){env5.noteOff();env13.noteOff();} 
  if (Fkey.risingEdge()){env6.noteOff();env13.noteOff();} 
  if (FSkey.risingEdge()){env7.noteOff();env13.noteOff();} 
  if (Gkey.risingEdge()){env8.noteOff();env13.noteOff();} 
  if (GSkey.risingEdge()){env9.noteOff();env13.noteOff();} 
  if (Akey.risingEdge()){env10.noteOff();env13.noteOff();} 
  if (ASkey.risingEdge()){env11.noteOff();env13.noteOff();} 
  if (Bkey.risingEdge()){env12.noteOff();env13.noteOff();} 

  /////////////////////////////////SET BUTTON STATES FOR CONTROL////////////////////////////////////
  func = status1.keys;
  switch(func){
    case 64:
      buttonState = 1;      
      break;
    case 32:
      buttonState = 2;      
      break;
    case 16: 
      buttonState = 3;      
      break;
    case 8:
      buttonState = 4;      
      break;
    case 96:
      buttonState = 5;     
      waveformScreen();
      break;
    case 24:
      buttonState = 6;
      octaveScreen();
      break;
    case 48:
      buttonState = 7;      
      break;
  }

    //////////////DRAW KNOB VALUES ON SCREEN CHANGE//////////
  if(buttonState != prevButtonState){
    tft.fillRect(0, 0, 220, 240, ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);
    switch(buttonState){
      case 1: 
      envelopeScreen();
      tft.fillRect(6, 50, 38, 130, ILI9341_BLACK);
      drawKnob(6, atckD);
      tft.setCursor(6, 5);
      tft.print(atck);
      tft.fillRect(56, 50, 38, 130, ILI9341_BLACK);
      drawKnob(56, decyD);
      tft.setCursor(56, 5);
      tft.print(decy);
      tft.fillRect(106, 50, 38, 130, ILI9341_BLACK);
      drawKnob(106, sustD); 
      tft.setCursor(106, 5);
      tft.print(sust);
      tft.fillRect(156, 50, 38, 130, ILI9341_BLACK);
      drawKnob(156, relsD); 
      tft.setCursor(156, 5);
      tft.print(rels);  
      break;

      case 2:
      delayScreen();
      tft.fillRect(6, 50, 38, 130, ILI9341_BLACK);
      drawKnob(6, dmixD);
      tft.setCursor(6, 5);
      tft.print(dmix);
      tft.fillRect(56, 50, 38, 130, ILI9341_BLACK);
      drawKnob(56, deltimeD);
      tft.setCursor(56, 5);
      tft.print(deltime);
      tft.fillRect(106, 50, 38, 130, ILI9341_BLACK);
      drawKnob(106, fbackD);
      tft.setCursor(106, 5);
      tft.print(fback); 
      tft.fillRect(156, 50, 38, 130, ILI9341_BLACK);
      drawKnob(156, delAmtD);
      tft.setCursor(156, 5);
      tft.print(delAmt);
      break;

      case 3:
      filterScreen();
      tft.fillRect(6, 50, 38, 130, ILI9341_BLACK);
      drawKnob(6, resoD);
      tft.setCursor(56, 5);
      tft.print(reso);
      tft.fillRect(56, 50, 38, 130, ILI9341_BLACK);
      drawKnob(56, freqD);
      tft.setCursor(6, 5);
      tft.print(freq);
      break;

      case 4:
      levelsScreen();
      tft.fillRect(6, 50, 38, 130, ILI9341_BLACK);
      drawKnob(6, osc1VolD);
      tft.setCursor(6, 5);     
      tft.print(osc1Vol);
      tft.fillRect(56, 50, 38, 130, ILI9341_BLACK);
      drawKnob(56, osc2VolD);
      tft.setCursor(56, 5);
      tft.print(osc2Vol);
      tft.fillRect(106, 50, 38, 130, ILI9341_BLACK);
      drawKnob(106, osc3VolD); 
      tft.setCursor(106, 5);
      tft.print(osc3Vol);
      tft.fillRect(156, 50, 38, 130, ILI9341_BLACK);
      drawKnob(156, noizAmpD);
      break;

      case 5:
      waveformScreen();
      switch(current_waveform1){
        case WAVEFORM_PULSE:
        tft.drawRect(3, 167, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_TRIANGLE:
        tft.drawRect(3, 137, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_SQUARE:
        tft.drawRect(3, 107, 44, 20, ILI9341_PINK);
        case WAVEFORM_SAWTOOTH:
        break;
        tft.drawRect(3, 77, 44, 20, ILI9341_PINK);
        case WAVEFORM_SINE:
        break;
        tft.drawRect(3, 47, 44, 20, ILI9341_PINK);
        break;
      }
      switch(current_waveform2){
        case WAVEFORM_PULSE:
        tft.drawRect(58, 167, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_TRIANGLE:
        tft.drawRect(58, 137, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_SQUARE:
        tft.drawRect(58, 107, 44, 20, ILI9341_PINK);
        case WAVEFORM_SAWTOOTH:
        break;
        tft.drawRect(58, 77, 44, 20, ILI9341_PINK);
        case WAVEFORM_SINE:
        break;
        tft.drawRect(58, 47, 44, 20, ILI9341_PINK);
        break;
      }
      switch(current_waveform3){
        case WAVEFORM_PULSE:
        tft.drawRect(112, 167, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_TRIANGLE:
        tft.drawRect(112, 137, 44, 20, ILI9341_PINK);
        break;
        case WAVEFORM_SQUARE:
        tft.drawRect(112, 107, 44, 20, ILI9341_PINK);
        case WAVEFORM_SAWTOOTH:
        break;
        tft.drawRect(112, 77, 44, 20, ILI9341_PINK);
        case WAVEFORM_SINE:
        break;
        tft.drawRect(112, 47, 44, 20, ILI9341_PINK);
        break;
      }
      break;

      case 7:
      reverbScreen();
      tft.fillRect(6, 50, 38, 130, ILI9341_BLACK);
      drawKnob(6, roomD);
      tft.fillRect(56, 50, 38, 130, ILI9341_BLACK);
      drawKnob(56, dampD);
      break;
    }
  }

  /////////////////////////////////////////////DISPLAY/////////////////////////////////////////////
  
  if(buttonState == 1){
    /////////ENVELOPE SETTINGS/////////////////////     
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){      
      atck  = map(sliderVal1, 0, 255, 0, 1000);
      atckD = map(sliderVal1, 0, 255, 169, 51);
      tft.fillRect(6, 0, 40, 17, ILI9341_BLACK);
      tft.fillRect(6, 51, 38, 128, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(6, 5);
      tft.print(atck);
      
      drawKnob(6, atckD);
    } P_sliderVal1 = sliderVal1;       
             
    if(sliChange2 == 0){
      decy  = map(sliderVal2, 0, 255, 0, 2000);
      decyD = map(sliderVal2, 0, 255, 169, 51);   
      tft.fillRect(56, 0, 40, 17, ILI9341_BLACK);
      tft.fillRect(56, 51, 38, 128, ILI9341_BLACK);  
      tft.setFont(LiberationMono_10); 
      tft.setTextColor(ILI9341_WHITE); 
      tft.setCursor(56, 5);
      tft.print(decy);
      drawKnob(56, decyD);     
    }           
    if(sliChange3 == 0){
      sust  = mapFloat(sliderVal3, 0, 255, 0, 1.0 );
      sustD = map(sliderVal3, 0, 255, 169, 51);
      tft.fillRect(106, 0, 40, 17, ILI9341_BLACK);
      tft.fillRect(106, 51, 38, 128, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(106, 5);
      tft.print(sust);
      drawKnob(106, sustD);      
    }       
    if(sliChange4 == 0){
      tft.fillRect(156, 51, 38, 128, ILI9341_BLACK);
      drawKnob(156, relsD);   
      rels  = map(sliderVal4, 0, 255, 0, 4000);
      relsD = map(sliderVal4, 0, 255, 169, 51);
      tft.fillRect(156, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(156, 5);
      tft.print(rels);   
    }    
  }

  if(buttonState == 2){
    /////////////DELAY SETTINGS/////////////////////////////    
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){  
      tft.fillRect(6, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(6, 5);
      tft.print(dmix);
      dmix = (mapFloat(sliderVal1, 0.0, 255.0, 0.0, 1.0));
      dmixD = map(sliderVal1, 0, 255, 169, 51);     
      tft.fillRect(6, 51, 38, 128, ILI9341_BLACK);
      drawKnob(6, dmixD);  
    } P_sliderVal1 = sliderVal1;  

    if(sliChange2 == 0){
      tft.fillRect(56, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(56, 5);
      tft.print(deltime);
      deltime = (map(sliderVal2, 0, 255, 0, 1000));
      deltimeD = map(sliderVal2, 0, 255, 169, 51); 
      tft.fillRect(56, 51, 38, 128, ILI9341_BLACK);
      drawKnob(56, deltimeD);
    }   

    if(sliChange3 == 0){
      tft.fillRect(106, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(106, 5);
      tft.print(fback); 
      fback = (mapFloat(sliderVal3, 0, 255, 0, 0.5));
      fbackD = map(sliderVal3, 0, 255, 169, 51);
      tft.fillRect(106, 51, 38, 128, ILI9341_BLACK);
      drawKnob(106, fbackD);
    }  

    if(sliChange4 == 0){
      tft.fillRect(156, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(156, 5);
      tft.print(delAmt);
      delAmt = (mapFloat(sliderVal4, 0.0, 255.0, 0.0, 0.9)); 
      delAmtD = map(sliderVal4, 0, 255, 169, 51);
      tft.fillRect(156, 51, 38, 128, ILI9341_BLACK);
      drawKnob(156, delAmtD);
    }     
  }

  if(buttonState == 3){
    /////////////FILTER SETTINGS/////////////////////////
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){  
      tft.fillRect(6, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(6, 5);
      tft.print(freq);
      freq = map(sliderVal1, 0, 255, 0, 10000);
      freqD = map(sliderVal1, 0, 255, 169, 51);
      tft.fillRect(6, 51, 38, 128, ILI9341_BLACK);
      drawKnob(6, freqD);
    } P_sliderVal1 = sliderVal1; 

    if(sliChange2 == 0){
      tft.fillRect(56, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(56, 5);
      tft.print(reso);
      reso = mapFloat((float)sliderVal2, 0, 255, 0.7, 5.0);
      resoD = map(sliderVal2, 0, 255, 169, 51);
      tft.fillRect(56, 51, 38, 128, ILI9341_BLACK);
      drawKnob(56, resoD);
    }
    if(sliChange4 == 0){
      switch(sliderVal4){ 
        case 0 ... 64:
          tft.drawRect(152, 68, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 98, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 128, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 158, 44, 20, ILI9341_PINK);
          mixerFilter1.gain(0, 0);
          mixerFilter1.gain(1, 0);
          mixerFilter1.gain(2, 0);
          mixerFilter1.gain(3, 0.9);
          break;
        case 65 ... 124:
          tft.drawRect(152, 68, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 98, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 128, 44, 20, ILI9341_PINK);
          tft.drawRect(152, 158, 44, 20, ILI9341_BLACK);
          mixerFilter1.gain(0, 0);
          mixerFilter1.gain(1, 0);
          mixerFilter1.gain(2, 0.9);
          mixerFilter1.gain(3, 0);
          break;
        case 125 ... 190:
          tft.drawRect(152, 68, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 98, 44, 20, ILI9341_PINK);
          tft.drawRect(152, 128, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 158, 44, 20, ILI9341_BLACK);
          mixerFilter1.gain(0, 0);
          mixerFilter1.gain(1, 0.9);
          mixerFilter1.gain(2, 0);
          mixerFilter1.gain(3, 0);
          break;
        case 191 ... 255:
          tft.drawRect(152, 68, 44, 20, ILI9341_PINK);
          tft.drawRect(152, 98, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 128, 44, 20, ILI9341_BLACK);
          tft.drawRect(152, 158, 44, 20, ILI9341_BLACK);
          mixerFilter1.gain(0, 0.9);
          mixerFilter1.gain(1, 0);
          mixerFilter1.gain(2, 0);
          mixerFilter1.gain(3, 0);
          break;
      }
    }
  }  

  if(buttonState == 4){
    ////////////////SET OSCILLATOR LEVELS/////////////////////    
    tft.setFont(LiberationMono_10);
    tft.setTextColor(ILI9341_WHITE);    
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){      
      tft.fillRect(6, 0, 40, 17, ILI9341_BLACK);
      tft.setCursor(6, 5);     
      tft.print(osc1Vol);
      tft.fillRect(6, 51, 38, 128, ILI9341_BLACK);      
      drawKnob(6, osc1VolD);
      osc1Vol = (mapFloat(sliderVal1, 0.0, 255.0, 0.0, 1.0));
      osc1VolD = map(sliderVal1, 0, 255, 169, 51); 
    }   
 
    if(sliChange2 == 0){
      tft.fillRect(56, 0, 40, 17, ILI9341_BLACK);
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(56, 5);
      tft.print(osc2Vol);
      osc2Vol = (mapFloat(sliderVal2, 0.0, 255.0, 0.0, 1.0));
      osc2VolD = map(sliderVal2, 0, 255, 169, 51);
      tft.fillRect(56, 51, 38, 128, ILI9341_BLACK);
      drawKnob(56, osc2VolD);
    }   
    
    if(sliChange3 == 0){
      tft.fillRect(106, 0, 40, 17, ILI9341_BLACK);   
      tft.setFont(LiberationMono_10);
      tft.setTextColor(ILI9341_WHITE);
      tft.setCursor(106, 5);
      tft.print(osc3Vol);
      osc3Vol = (mapFloat(sliderVal3, 0.0, 255.0, 0.0, 1.0));
      osc3VolD = map(sliderVal3, 0, 255, 169, 51);   
      tft.fillRect(106, 51, 38, 128, ILI9341_BLACK);
      drawKnob(106, osc3VolD);
    } 

    if(sliChange4 == 0){
      tft.fillRect(156, 0, 40, 17, ILI9341_BLACK);   
      tft.setTextColor(ILI9341_WHITE);
      tft.setFont(LiberationMono_10);
      tft.setCursor(156, 5);
      tft.print(noizAmp);
      noizAmp = (mapFloat(sliderVal4, 0.0, 255.0, 0.0, 0.6));
      noizAmpD = map(sliderVal4, 0, 255, 169, 51);
      tft.fillRect(156, 51, 38, 128, ILI9341_BLACK);
      drawKnob(156, noizAmpD);
    } 
  }

  if(buttonState == 5){

    tft.setCursor(COL_D, 205);   ////////////////////////SHIFT BUTTON
    tft.fillRect(COL_D, 205, 40, 10, ILI9341_WHITE);
    tft.setTextColor(ILI9341_BLACK);
    tft.print("shift");

    //////////////////PICK AND UPDATE WAVEFORMS//////////////////////
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1 && status2.keys != 8){  

      switch(sliderVal1) {
        case 0 ... 50:
          tft.drawRect(3, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 167, 44, 20, ILI9341_PINK);
          current_waveform1 = WAVEFORM_PULSE;
          break;
        case 51 ... 100:
          tft.drawRect(3, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 137, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 167, 44, 20, ILI9341_BLACK);
          current_waveform1 = WAVEFORM_TRIANGLE;
          break;
        case 101 ... 150:
          tft.drawRect(3, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 107, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 167, 44, 20, ILI9341_BLACK);
          current_waveform1 = WAVEFORM_SQUARE;
          break;
        case 151 ... 200:
          tft.drawRect(3, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 77, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 167, 44, 20, ILI9341_BLACK);
          current_waveform1 = WAVEFORM_SAWTOOTH;
          break;
        case 201 ... 255:
          tft.drawRect(3, 47, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 167, 44, 20, ILI9341_BLACK);
          current_waveform1 = WAVEFORM_SINE;
          break;        
      }
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves1[i]->begin(current_waveform1);
      }
      AudioInterrupts();
    }  P_sliderVal1 = sliderVal1; 
    
    if(sliChange2 == 0 && status2.keys != 8){
      switch(sliderVal2) {
        case 0 ... 50:
          tft.drawRect(58, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 167, 44, 20, ILI9341_PINK);
          current_waveform2 = WAVEFORM_PULSE;
          break;
        case 51 ... 100:
          tft.drawRect(58, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 137, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 167, 44, 20, ILI9341_BLACK);
          current_waveform2 = WAVEFORM_TRIANGLE;
          break;
        case 101 ... 150:
          tft.drawRect(58, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 107, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 167, 44, 20, ILI9341_BLACK);
          current_waveform2 = WAVEFORM_SQUARE;
          break;
        case 151 ... 200:
          tft.drawRect(58, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 77, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 167, 44, 20, ILI9341_BLACK);
          current_waveform2 = WAVEFORM_SAWTOOTH;
          break;
        case 201 ... 255:
          tft.drawRect(58, 47, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 167, 44, 20, ILI9341_BLACK);
          current_waveform2 = WAVEFORM_SINE;
          break;  
        }      
      
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves2[i]->begin(current_waveform2);
      }
      AudioInterrupts();
    }
    
    if(sliChange3 == 0 && status2.keys != 8){
      switch(sliderVal3) {
        case 0 ... 50:
          tft.drawRect(112, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 167, 44, 20, ILI9341_PINK);
          current_waveform3 = WAVEFORM_PULSE;
          break;
        case 51 ... 100:
          tft.drawRect(112, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 137, 44, 20, ILI9341_PINK);
          tft.drawRect(112, 167, 44, 20, ILI9341_BLACK);
          current_waveform3 = WAVEFORM_TRIANGLE;
          break;
        case 101 ... 150:
          tft.drawRect(112, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 107, 44, 20, ILI9341_PINK);
          tft.drawRect(112, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 167, 44, 20, ILI9341_BLACK);
          current_waveform3 = WAVEFORM_SQUARE;
          break;
        case 151 ... 200:
          tft.drawRect(112, 47, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 77, 44, 20, ILI9341_PINK);
          tft.drawRect(112, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 167, 44, 20, ILI9341_BLACK);
          current_waveform3 = WAVEFORM_SAWTOOTH;
          break;
        case 201 ... 255:
          tft.drawRect(112, 47, 44, 20, ILI9341_PINK);
          tft.drawRect(112, 77, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 107, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 137, 44, 20, ILI9341_BLACK);
          tft.drawRect(112, 167, 44, 20, ILI9341_BLACK);
          current_waveform3 = WAVEFORM_SINE;
          break;        
      }
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves3[i]->begin(current_waveform3);
      }
      AudioInterrupts();
    }  
    ///////////////////////ADJUST PWM DUTY CYCLE/////////////////
    if(status2.keys == 8){
      tft.fillRect(COL_D, 205, 40, 10, ILI9341_BLACK);
      tft.setCursor(COL_D, 205);
      tft.drawRect(COL_D, 203, 40, 12, ILI9341_WHITE);
      tft.setTextColor(ILI9341_WHITE);
      tft.print("shift");

      pWidth1 = mapFloat(sliderVal1, 0, 255, 0.1, 0.9);
      for (int i = 0; i < 12; i++) {
        waves1[i]->pulseWidth(pWidth1);
        tft.fillRect(181, 51, 24, 28, ILI9341_BLACK);
        tft.drawFastHLine(178, 75, map(sliderVal1, 0 , 255, 3, 29), ILI9341_WHITE);
        tft.drawFastVLine(map(sliderVal1, 0, 255, 182, 205), 55, 20, ILI9341_WHITE);
        tft.drawLine(205, 55, map(sliderVal1, 0, 255, 184, 204), 55, ILI9341_WHITE);
      }

      pWidth2 = mapFloat(sliderVal2, 0, 255, 0.1, 0.9);
      for (int i = 0; i < 12; i++) {
        waves2[i]->pulseWidth(pWidth2);
        tft.fillRect(181, 106, 24, 28, ILI9341_BLACK);
        tft.drawFastHLine(178, 130, map(sliderVal2, 0 , 255, 3, 29), ILI9341_WHITE);
        tft.drawFastVLine(map(sliderVal2, 0, 255, 182, 205), 110, 20, ILI9341_WHITE);
        tft.drawLine(205, 110, map(sliderVal2, 0, 255, 185, 205), 110, ILI9341_WHITE);
      }

      pWidth3 = mapFloat(sliderVal3, 0, 255, 0.1, 0.9);
      for (int i = 0; i < 12; i++) {
        waves3[i]->pulseWidth(pWidth3);
        tft.fillRect(181, 161, 24, 28, ILI9341_BLACK);
        tft.drawFastHLine(178, 185, map(sliderVal3, 0 , 255, 3, 29), ILI9341_WHITE);
        tft.drawFastVLine(map(sliderVal3, 0, 255, 182, 205), 165, 20, ILI9341_WHITE);
        tft.drawLine(205, 165, map(sliderVal3, 0, 255, 185, 205), 165, ILI9341_WHITE);
      }
    }    
  }

    if(buttonState == 7){
      ///////Update Reverb Settings
      if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){  
        room = (mapFloat(sliderVal1, 0.0, 255.0, 0.0, 1.0));
        roomD = map(sliderVal1, 0, 255, 169, 51);
        tft.fillRect(6, 51, 38, 128, ILI9341_BLACK);
        tft.fillRect(6, 0, 40, 17, ILI9341_BLACK);
        tft.setFont(LiberationMono_10);
        tft.setCursor(6, 5);
        tft.print(room);
        drawKnob(6, roomD);
    } P_sliderVal1 = sliderVal1; 

      if(sliChange2 == 0){
        damp = (mapFloat(sliderVal2, 0.0, 255.0, 0.0, 1.0));
        dampD = map(sliderVal2, 0, 255, 169, 51);
        tft.fillRect(56, 51, 38, 128, ILI9341_BLACK);
        tft.fillRect(56, 0, 40, 17, ILI9341_BLACK);
        tft.setFont(LiberationMono_10);
        tft.setCursor(56, 5);
        tft.print(damp);
        drawKnob(56, dampD);
      }  
    }

    if(buttonState == 6){
    //////////////////PICK AND UPDATE WAVEFORM OCTAVE//////////////////////
    if(sliChange1 == 0 && P_sliderVal1 != sliderVal1){  
      switch(sliderVal1) {
        case 0 ... 36:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_PINK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves0[i]);
          }
          break;
        case 37 ... 72:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves1[i]);
          }
          break;
        case 73 ... 109:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves2[i]);
          }
          break;
        case 110 ... 146:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves3[i]);
          }
          break;
        case 147 ... 183:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves4[i]);
          }
          break; 
        case 184 ... 215:
          tft.drawRect(3, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 58, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves5[i]);
          }
          break;  
        case 216 ... 254:
          tft.drawRect(3, 36, 44, 20, ILI9341_PINK);
          tft.drawRect(3, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(3, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves1[i]->frequency(octaves6[i]);
          }
          break;        
      }
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves1[i]->begin(current_waveform1);
      }
      AudioInterrupts();
    } P_sliderVal1 = sliderVal1; 

    if(sliChange2 == 0){
      switch(sliderVal2) {
        case 0 ... 36:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_PINK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves0[i]);
          }
          break;
        case 37 ... 72:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves1[i]);
          }
          break;
        case 73 ... 109:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves2[i]);
          }
          break;
        case 110 ... 146:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves3[i]);
          }
          break;
        case 147 ... 182:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves4[i]);
          }
          break;
        case 183 ... 215:
          tft.drawRect(58, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 58, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves5[i]);
          }
          break; 
        case 216 ... 255:
          tft.drawRect(58, 36, 44, 20, ILI9341_PINK);
          tft.drawRect(58, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(58, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves2[i]->frequency(octaves6[i]);
          }
          break;        
      }
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves1[i]->begin(current_waveform1);
      }
      AudioInterrupts();
    }

        if(sliChange3 == 0){
      switch(sliderVal3) {
        case 0 ... 36:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_PINK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves0[i]);
          }
          break;
        case 37 ... 72:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves1[i]);
          }
          break;
        case 73 ... 109:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves2[i]);
          }
          break;
        case 110 ... 146:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves3[i]);
          }
          break;
        case 147 ... 182:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves4[i]);
          }
          break;
        case 183 ... 215:
          tft.drawRect(113, 36, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 58, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves5[i]);
          }
          break; 
        case 216 ... 255:
          tft.drawRect(113, 36, 44, 20, ILI9341_PINK);
          tft.drawRect(113, 58, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 80, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 102, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 124, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 146, 44, 20, ILI9341_BLACK);
          tft.drawRect(113, 168, 44, 20, ILI9341_BLACK);
          for(int i = 0; i < 12; i++){
            waves3[i]->frequency(octaves6[i]);
          }
          break;        
      }
      AudioNoInterrupts();
      for (int i = 0; i < 12; i++) {
        waves1[i]->begin(current_waveform1);
      }
      AudioInterrupts();
    }
  }//////////////////////END DISPLAY SECTION/////////////////////////////////

  ///////////////////////UPDATE ARRAYS///////////////////////
  //envelope control 
  for (int i =  0; i < 12; i++) {
    envs[i]->attack(atck);
    envs[i]->decay(decy);
    envs[i]->sustain(sust);
    envs[i]->release(rels);
  }    
  //mixer control
  for( int i = 0; i < 12; i++){
    mixers[i]->gain(0, osc1Vol);
    mixers[i]->gain(1, osc2Vol);
    mixers[i]->gain(2, osc3Vol);
  }
  noise1.amplitude(noizAmp);

  ///////////////// Display Wheel Value///////////////////
  tft.setFont(LiberationMono_10);
  tft.setTextColor(ILI9341_WHITE);    
  tft.setCursor(225, 15);
  tft.print("Master:");
  tft.setCursor(285, 15);   
  tft.drawRect(225, 30, 80, 20, ILI9341_RED);
  if(sliChange5 == 0){
    tft.fillRect(278, 12, 60, 15, ILI9341_BLACK);
    tft.print(map(wheelVal, 0, 255, 0, 100));
    tft.fillRect(226, 31, 78, 18, ILI9341_BLACK);
    drawSmallKnob(map(wheelVal, 0, 255, 227, 299), 31);  
  }

  /////////////////////////////////////////////////////LEVEL METER//////////////////////////
  float targetLvlMtr1 = mapFloat(peak3.read(), 0.0, 1.0, 0, 16);
  float targetLvlMtr2 = mapFloat(peak4.read(), 0.0, 1.0, 0, 16);

  // Update displayed level for meter 1
  if (targetLvlMtr1 > displayedLvlMtr1) {
    displayedLvlMtr1 = targetLvlMtr1;
    lastDecayTimeMtr1 = millis(); // Reset decay timer
  } else {
    if (millis() - lastDecayTimeMtr1 > decayIntervalMtr && displayedLvlMtr1 > 0) {
      displayedLvlMtr1 -= 1; // Decrease the displayed level
      lastDecayTimeMtr1 = millis();
    }
  }
  // Clear the area where the first VU meter is drawn
  tft.fillRect(barStartX1, barTopY, barWidth, 220 - barTopY + 1, ILI9341_BLACK);
  // Draw the individual bars based on displayedLvlMtr1
  int numBarsToDraw1 = int(displayedLvlMtr1);
  for (int i = 0; i < numBarsToDraw1; i++) {
    int barY = 180 - ((i + 1) * barHeightSegment) + 1; // Calculate Y from bottom up with optional spacing
    //Serial.println(barY); // ADDED FOR DEBUGGING
    tft.fillRect(barStartX1, barY, barWidth, barHeightSegment, ILI9341_GREEN);
  }

  // Update displayed level for meter 1
  if (targetLvlMtr2 > displayedLvlMtr2) {
    displayedLvlMtr2 = targetLvlMtr2;
    lastDecayTimeMtr1 = millis(); // Reset decay timer
  } else {
    if (millis() - lastDecayTimeMtr2 > decayIntervalMtr && displayedLvlMtr2 > 0) {
      displayedLvlMtr2 -= 1; // Decrease the displayed level
      lastDecayTimeMtr2 = millis();
    }
  }
  // Clear the area where the first VU meter is drawn
  tft.fillRect(barStartX2, barTopY, barWidth, 220 - barTopY + 1, ILI9341_BLACK);
  // Draw the individual bars based on displayedLvlMtr1
  int numBarsToDraw2 = int(displayedLvlMtr2);
  for (int i = 0; i < numBarsToDraw2; i++) {
    int barY = 180 - ((i + 1) * barHeightSegment) + 1; // Calculate Y from bottom up with optional spacing
    //Serial.println(barY); // ADDED FOR DEBUGGING
    tft.fillRect(barStartX2, barY, barWidth, barHeightSegment, ILI9341_GREEN);
  }


  
  
  //////////////////////////////////DELAY PARAMETERS///////////////////////// THIS NEEDS WORK
  delay1.delay(0, 0);
  delay1.delay(1, deltime);
  delay1.delay(2, (float)deltime * 1.5);
  delay1.delay(3, (float)deltime * 2);
  delay1.delay(4, (float)deltime * 2.5);
  delay1.delay(5, (float)deltime * 3);
  delay1.delay(6, (float)deltime * 3.5);
  delay1.delay(7, (float)deltime * 4); 
  //create the delay feedback amount
  mixerDelay1.gain(0, 1.0 * delAmt);
  mixerDelay1.gain(1, 0.85 * delAmt);
  mixerDelay1.gain(2, 0.75 * delAmt);
  mixerDelay1.gain(3, 0.6 * delAmt);
  mixerDelay2.gain(0, 5.0 * delAmt);
  mixerDelay2.gain(1, 0.45 * delAmt);
  mixerDelay2.gain(2, 0.35 * delAmt);
  mixerDelay2.gain(3, 0.25 * delAmt);
  mixerFeedback.gain(0, 1.0 - fback);
  mixerFeedback.gain(1, fback * 0.5);
  mixerFeedback.gain(2, fback * 0.5);
  //this creates the dry/wet mix for the delay signal
  mixerDryWet1.gain(0, 1.0 - dmix);
  mixerDryWet1.gain(1, dmix * 0.5);
  mixerDryWet2.gain(0, 1.0 - dmix);
  mixerDryWet2.gain(1, dmix * 0.5);

  //////////REVERB SETTINGS//////////////////////////
  freeverb1.roomsize(room);
  freeverb1.damping(damp);

  ////////////////////TOUCH SCREEN READINGS///////////
  /*
  if (istouched) {
    TS_Point p = ts.getPoint();
  if (!wastouched) {     
  }
  tft.fillRect(225, 195, 200, 60, ILI9341_BLACK);
  tft.setTextColor(ILI9341_GREEN);
  tft.setFont(Arial_12);
  tft.setCursor(225, 195);
  tft.print("X = ");
  tft.print(p.x);
  tft.setCursor(225, 215);
  tft.print("Y = ");
  tft.print(p.y);
  Serial.print(", x = ");
  Serial.print(p.x);
  Serial.print(", y = ");
  Serial.println(p.y);
  } 
  */
  prevButtonState = buttonState;
  wastouched = istouched;

  // Serial.print(peak1.read());
  // Serial.print("\t");
  // Serial.print(peak2.read());
  // Serial.print("\t");
  // Serial.print(peak3.read());
  // Serial.print("\t");
  // Serial.println(peak4.read());
  // Serial.print("\t");
  // Serial.print(atck);
  // Serial.print("\t");
  // Serial.println(osc1Vol);

}