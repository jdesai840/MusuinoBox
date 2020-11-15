#include <IRremote.h>


#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

const int buzzerPin = 5;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int IRPin = 3;

IRrecv IR(IRPin);
decode_results cmd;

int r = 0;
int g = 0;
int b = 0;

int tempo = 240;

//Songs were all saved directly in program memory
const int melody[] PROGMEM = {

  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4,
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4,
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2,

};

const int melody1[] PROGMEM = {
  
  NOTE_AS4, 4,  NOTE_F4, -4,  NOTE_AS4, 8,  NOTE_AS4, 16,  NOTE_C5, 16, NOTE_D5, 16, NOTE_DS5, 16,
  NOTE_F5, 2,  NOTE_F5, 8,  NOTE_F5, 8,  NOTE_F5, 8,  NOTE_FS5, 16, NOTE_GS5, 16,
  NOTE_AS5, -2,  NOTE_AS5, 8,  NOTE_AS5, 8,  NOTE_GS5, 8,  NOTE_FS5, 16,
  NOTE_GS5, -8,  NOTE_FS5, 16,  NOTE_F5, 2,  NOTE_F5, 4,

  NOTE_DS5, -8, NOTE_F5, 16, NOTE_FS5, 2, NOTE_F5, 8, NOTE_DS5, 8,
  NOTE_CS5, -8, NOTE_DS5, 16, NOTE_F5, 2, NOTE_DS5, 8, NOTE_CS5, 8,
  NOTE_C5, -8, NOTE_D5, 16, NOTE_E5, 2, NOTE_G5, 8,
  NOTE_F5, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 8, NOTE_F4, 16, NOTE_F4, 8,

  NOTE_AS4, 4,  NOTE_F4, -4,  NOTE_AS4, 8,  NOTE_AS4, 16,  NOTE_C5, 16, NOTE_D5, 16, NOTE_DS5, 16,
  NOTE_F5, 2,  NOTE_F5, 8,  NOTE_F5, 8,  NOTE_F5, 8,  NOTE_FS5, 16, NOTE_GS5, 16,
  NOTE_AS5, -2, NOTE_CS6, 4,
  NOTE_C6, 4, NOTE_A5, 2, NOTE_F5, 4,
  NOTE_FS5, -2, NOTE_AS5, 4,
  NOTE_A5, 4, NOTE_F5, 2, NOTE_F5, 4,

  NOTE_FS5, -2, NOTE_AS5, 4,
  NOTE_A5, 4, NOTE_F5, 2, NOTE_D5, 4,
  NOTE_DS5, -2, NOTE_FS5, 4,
  NOTE_F5, 4, NOTE_CS5, 2, NOTE_AS4, 4,
  NOTE_C5, -8, NOTE_D5, 16, NOTE_E5, 2, NOTE_G5, 8,
  NOTE_F5, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 16, NOTE_F4, 8, NOTE_F4, 16, NOTE_F4, 8

};

const int melody2[] PROGMEM = {

  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,

  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , 4, REST, 8,

  NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,

  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16,
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,

  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,

  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16,

  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,

  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,

  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_C5, 16, NOTE_C5, 16, NOTE_C5, 16,

  NOTE_C5 , 4, NOTE_F5, -16, NOTE_E5, 32,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_AS5, -16, NOTE_A5, 32,
  NOTE_A5, 16, NOTE_G5, 16, NOTE_F5, 16, NOTE_E5, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4, 8, NOTE_A4, 8, NOTE_A4, 32, NOTE_G4, 32, NOTE_A4, 32, NOTE_B4, 32,
  NOTE_C5 , 4, NOTE_D5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_E5, 16, NOTE_F5, 16, NOTE_A4, 16,
  NOTE_C5 , 4,  NOTE_D5, -16, NOTE_B4, 32,


  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32,
  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32,
  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32,

  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32,
  NOTE_E5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, REST, 16,

  REST, 16, NOTE_DS5, 16, NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,

  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16,
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,

  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_D5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,

  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, REST, 16, REST, 8,
  NOTE_CS5 , -4,
  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16,
  NOTE_F5 , 4, NOTE_F5, 8,
  NOTE_E5 , -4,
  NOTE_D5 , 4, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , 4, NOTE_A4, 8,
  NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8,
  NOTE_A4 , -4,
  NOTE_CS5 , -4,

  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16,
  NOTE_F5 , 4, NOTE_F5, 8,
  NOTE_F5 , -4,
  NOTE_DS5 , 4, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4 , 4, NOTE_A4, 8,
  NOTE_GS4 , 4, NOTE_G4, 8,
  NOTE_A4 , -4,
  NOTE_B4 , 4, REST, 8,
  NOTE_A3, -32, NOTE_C4, -32, NOTE_E4, -32, NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_D5, -32, NOTE_C5, -32, NOTE_B4, -32,

  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32,
  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32,
  NOTE_AS5, -32, NOTE_A5, -32, NOTE_GS5, -32, NOTE_G5, -32, NOTE_FS5, -32, NOTE_F5, -32, NOTE_E5, -32, NOTE_DS5, -32, NOTE_D5, -32,

  NOTE_CS5, -32, NOTE_C5, -32, NOTE_B4, -32, NOTE_AS4, -32, NOTE_A4, -32, NOTE_GS4, -32, NOTE_G4, -32, NOTE_FS4, -32, NOTE_F4, -32,
  NOTE_E4, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, -8, REST, -8,
  REST, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5 , 4, REST, 8,
  REST, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,

  NOTE_B4, -8, NOTE_E4, 16, NOTE_E5, 8,
  NOTE_E5, 8, NOTE_E6, -8, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , -4,

};

const int melody3[] PROGMEM = {

  REST, 4, NOTE_G5, 4,
  NOTE_A5, 4, NOTE_AS5, 4,
  NOTE_A5, 4, NOTE_F5, 4,
  NOTE_A5, 4, NOTE_G5, 4,
  REST, 4, NOTE_G5, 4,
  NOTE_A5, 4, NOTE_AS5, 4,
  NOTE_C6, 4, NOTE_AS5, 4,

  NOTE_A5, 4, NOTE_G5, 4,
  REST, 4, NOTE_G5, 4,
  NOTE_A5, 4, NOTE_AS5, 4,
  NOTE_A5, 4, NOTE_F5, 4,
  NOTE_A5, 4, NOTE_G5, 4,
  NOTE_D6, 4, REST, 8, NOTE_C6, 8,
  REST, 4, NOTE_AS5, 4,

  NOTE_A5, 4, NOTE_AS5, 8, NOTE_C6, 8,
  NOTE_F6, 8, REST, 8, REST, 4,
  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,

  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,

  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_AS5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,

  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_C6, 16, NOTE_C6, 16, NOTE_F6, 16, NOTE_D6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_C6, 16, NOTE_AS5, 16,

  NOTE_C6, -8,  NOTE_F6, -8, NOTE_D6, -4,
  NOTE_C6, 8, NOTE_AS5, 8,
  NOTE_C6, 8, NOTE_F6, 16, NOTE_D6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_C6, 8, NOTE_D6, 8,
  NOTE_DS6, -8, NOTE_F6, -8,

  NOTE_D6, -8, REST, 16, NOTE_DS6, 8, REST, 8,
  NOTE_C6, 8, NOTE_F6, 16, NOTE_D6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_C6, 8, NOTE_AS5, 8,
  NOTE_C6, -8,  NOTE_F6, -8, NOTE_D6, -4,
  NOTE_C6, 8, NOTE_AS5, 8,

  NOTE_C6, 8, NOTE_F6, 16, NOTE_D6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_C6, 8, NOTE_D6, 8,
  NOTE_DS6, -8, NOTE_F6, -8,
  NOTE_D5, 8, NOTE_FS5, 8, NOTE_F5, 8, NOTE_A5, 8,
  NOTE_A5, -8, NOTE_G5, -4,

  NOTE_A5, -8, NOTE_G5, -4,
  NOTE_A5, -8, NOTE_G5, -4,
  NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_A5, -8, NOTE_G5, -8, NOTE_D5, 8,
  NOTE_A5, -8, NOTE_G5, -8, NOTE_D5, 8,
  NOTE_A5, -8, NOTE_G5, -8, NOTE_D5, 8,

  NOTE_AS5, 4, NOTE_C6, 4, NOTE_A5, 4, NOTE_AS5, 4,
  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,

  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_G5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,

  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,
  NOTE_AS5, 16, NOTE_D5, 16, NOTE_D6, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_A5, 16, NOTE_D5, 16, NOTE_G5, 16, NOTE_D5, 16,

  NOTE_A5, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16, NOTE_C6, 16, NOTE_D5, 16, NOTE_AS5, 16, NOTE_D5, 16,
  NOTE_A5, 16, NOTE_D5, 16, NOTE_F5, 16, NOTE_D5, 16, NOTE_A5, 8, NOTE_G5, 32, NOTE_A5, 32, NOTE_AS5, 32, NOTE_C6, 32,
  NOTE_D6, 16, NOTE_G5, 16, NOTE_AS5, 16, NOTE_G5, 16, NOTE_C6, 16, NOTE_G5, 16, NOTE_D6, 16, NOTE_G5, 16,
  NOTE_C6, 16, NOTE_G5, 16, NOTE_A5, 16, NOTE_G5, 16, NOTE_F6, 16, NOTE_G5, 16, NOTE_D6, 16, NOTE_DS5, 16,
  NOTE_D6, 4, REST, 4,

  NOTE_C5, 8, REST, 8, NOTE_A4, -16, NOTE_AS4, -16, NOTE_C5, 16,
  NOTE_D6, 16, NOTE_G4, 16, NOTE_AS4, 16, NOTE_G4, 16, NOTE_C5, 16, NOTE_G4, 16, NOTE_D6, 16, NOTE_G4, 16,
  NOTE_C6, 16, NOTE_F4, 16, NOTE_A4, 16, NOTE_F4, 16, NOTE_F5, 16, NOTE_F4, 16, NOTE_D6, 16, NOTE_DS4, 16,
  NOTE_D6, 16, REST, 8, NOTE_E4, 16, NOTE_F4, 16,

  NOTE_GS4, 8, REST, 8, NOTE_AS4, 8, REST, 8,

  NOTE_DS5, 16, NOTE_GS4, 16, NOTE_B4, 16, NOTE_GS4, 16, NOTE_CS5, 16, NOTE_GS4, 16, NOTE_DS5, 16, NOTE_GS4, 16,
  NOTE_CS5, 16, NOTE_FS4, 16, NOTE_AS4, 16, NOTE_FS4, 16, NOTE_FS5, 16, NOTE_FS4, 16, NOTE_DS5, 16, NOTE_E5, 16,
  NOTE_D5, 4, REST, 4,
  NOTE_CS5, 8, REST, 8, NOTE_AS4, -16,  NOTE_B4, -16, NOTE_CS5, 16,
  NOTE_DS5, 16, NOTE_GS4, 16, NOTE_B4, 16, NOTE_GS4, 16, NOTE_CS5, 16, NOTE_GS4, 16, NOTE_DS5, 16, NOTE_GS4, 16,

  NOTE_CS5, 16, NOTE_FS4, 16, NOTE_AS4, 16, NOTE_FS4, 16, NOTE_FS5, 16, NOTE_FS4, 16, NOTE_DS5, 16, NOTE_E5, 16,
  NOTE_DS5, 4, REST, 8, NOTE_DS5, 16,  NOTE_E5, 16,
  NOTE_FS5, 16, NOTE_CS5, 16, NOTE_E5, 16, NOTE_CS4, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_G5, 16, NOTE_AS5, 16,
  NOTE_GS5, 16, NOTE_DS5, 16, NOTE_DS6, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,

  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_GS5, 16, NOTE_DS5, 16, NOTE_DS6, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,

  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_GS5, 16, NOTE_DS5, 16, NOTE_DS6, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,

  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_GS5, 16, NOTE_DS5, 16, NOTE_DS6, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,

  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16, NOTE_CS6, 16, NOTE_DS5, 16, NOTE_B5, 16, NOTE_DS5, 16,
  NOTE_AS5, 16, NOTE_DS5, 16, NOTE_FS5, 16, NOTE_DS5, 16, NOTE_AS5, 16, NOTE_DS5, 16, NOTE_GS5, 16, NOTE_DS5, 16,

  NOTE_CS6, 8, NOTE_FS6, 16, NOTE_DS6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_CS6, 8, NOTE_B5, 8,
  NOTE_CS6, -8, NOTE_FS6, -8, NOTE_DS6, -4,
  NOTE_CS6, 8, NOTE_B5, 8,
  NOTE_CS6, 8, NOTE_FS6, 16, NOTE_DS6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_CS6, 8, NOTE_B5, 8,
  NOTE_E6, -8, NOTE_F6, -8,

  NOTE_DS6, -8, REST, 16, NOTE_E6, 8, REST, 16, REST, 16,
  NOTE_CS6, 8, NOTE_FS6, 16, NOTE_DS6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_CS6, 8, NOTE_B5, 8,
  NOTE_CS6, -8, NOTE_FS6, -8, NOTE_DS6, -4,
  NOTE_CS6, 8, NOTE_B5, 8,

  NOTE_CS6, 8, NOTE_FS6, 16, NOTE_DS6, 8, REST, 16, REST, 8,
  REST, 4, NOTE_CS5, 8, NOTE_DS5, 8,
  NOTE_E5, -8, NOTE_F5, -8,
  NOTE_DS5, 8, NOTE_G5, 8, NOTE_GS5, 8, NOTE_AS5, 8,
  NOTE_AS5, -8, NOTE_GS5, -8,

  NOTE_AS5, -8, NOTE_GS5, -8,
  NOTE_AS5, -8, NOTE_GS5, -8,
  NOTE_B6, 8, NOTE_AS5, 8, NOTE_GS5, 8, NOTE_FS5, 8,
  NOTE_AS5, -8, NOTE_GS6, -8, NOTE_DS5, 8,
  NOTE_AS5, -8, NOTE_GS6, -8, NOTE_DS5, 8,
  NOTE_AS5, -8, NOTE_GS6, -8, NOTE_DS5, 8,

  NOTE_B5, 8, NOTE_CS6, 8, NOTE_AS5, 8, NOTE_B5, 8,
  NOTE_GS5, 8, REST, 8, REST, 16

};

const int melody4[] PROGMEM = {

  NOTE_E5, 16, NOTE_E5, 8, NOTE_D5, 16, REST, 16, NOTE_CS5, -4, NOTE_E4, 8, NOTE_FS4, 16, NOTE_G4, 16, NOTE_A4, 16,

  NOTE_B4, -8, NOTE_E4, -8, NOTE_B4, 8, NOTE_A4, 16, NOTE_D5, -4,
  NOTE_E5, 16, NOTE_E5, 8, NOTE_D5, 16, REST, 16, NOTE_CS5, -4, NOTE_E4, 8, NOTE_FS4, 16, NOTE_G4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, -8, NOTE_B4, 8, NOTE_A4, 16, NOTE_D4, -4,
  REST, 8, NOTE_E5, 8, REST, 16, NOTE_B5, 16, REST, 8, NOTE_AS5, 16, NOTE_B5, 16, NOTE_AS5, 16, NOTE_G5, 16, REST, 4,

  NOTE_B5, 8, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_AS5, 16, NOTE_A5, 16, REST, 16, NOTE_B5, 16, NOTE_G5, 16, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_B5, 16, NOTE_A5, 16, NOTE_G5, 16,
  REST, 8, NOTE_E5, 8, REST, 16, NOTE_B5, 16, REST, 8, NOTE_AS5, 16, NOTE_B5, 16, NOTE_AS5, 16, NOTE_G5, 16, REST, 4,
  NOTE_B5, 8, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_AS5, 16, NOTE_A5, 16, REST, 16, NOTE_B5, 16, NOTE_G5, 16, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_B5, 16, NOTE_A5, 16, NOTE_G5, 16,

  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, NOTE_E4, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, REST, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, NOTE_E4, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_CS5, -8, NOTE_DS5, 8,

  NOTE_E5, 16, NOTE_E5, 16, NOTE_E4, 16, NOTE_E4, -2,
  NOTE_C4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_G4, -8, NOTE_D4, 8, NOTE_D4, 8, NOTE_FS4, 16, NOTE_A4, -8,
  NOTE_E5, 16, NOTE_E5, 16, NOTE_E4, 16, NOTE_E4, -2,
  NOTE_C4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_G4, -8, NOTE_D4, 8, NOTE_D4, 8, NOTE_B3, 16, NOTE_D4, -8,


  NOTE_E5, 16, NOTE_E5, 8, NOTE_D5, 16, REST, 16, NOTE_CS5, -4, NOTE_E4, 8, NOTE_FS4, 16, NOTE_G4, 16, NOTE_A4, 16,

  NOTE_B4, -8, NOTE_E4, -8, NOTE_B4, 8, NOTE_A4, 16, NOTE_D5, -4, //7
  NOTE_E5, 16, NOTE_E5, 8, NOTE_D5, 16, REST, 16, NOTE_CS5, -4, NOTE_E4, 8, NOTE_FS4, 16, NOTE_G4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, -8, NOTE_B4, 8, NOTE_A4, 16, NOTE_D4, -4,
  REST, 8, NOTE_E5, 8, REST, 16, NOTE_B5, 16, REST, 8, NOTE_AS5, 16, NOTE_B5, 16, NOTE_AS5, 16, NOTE_G5, 16, REST, 4,

  NOTE_B5, 8, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_AS5, 16, NOTE_A5, 16, REST, 16, NOTE_B5, 16, NOTE_G5, 16, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_B5, 16, NOTE_A5, 16, NOTE_G5, 16,
  REST, 8, NOTE_E5, 8, REST, 16, NOTE_B5, 16, REST, 8, NOTE_AS5, 16, NOTE_B5, 16, NOTE_AS5, 16, NOTE_G5, 16, REST, 4,
  NOTE_B5, 8, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_AS5, 16, NOTE_A5, 16, REST, 16, NOTE_B5, 16, NOTE_G5, 16, NOTE_B5, 16, NOTE_AS5, 16, REST, 16, NOTE_B5, 16, NOTE_A5, 16, NOTE_G5, 16,

  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, NOTE_E4, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, REST, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, -8, NOTE_E4, 8,
  NOTE_DS4, -8, NOTE_FS4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_CS5, -8, NOTE_DS5, 8,

  NOTE_E5, 16, NOTE_E5, 16, NOTE_E4, 16, NOTE_E4, -2,
  NOTE_C4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_G4, -8, NOTE_D4, 8, NOTE_D4, 8, NOTE_FS4, 16, NOTE_A4, -8,
  NOTE_E5, 16, NOTE_E5, 16, NOTE_E4, 16, NOTE_E4, -2,
  NOTE_C4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_G4, -8, NOTE_D4, 8, NOTE_D4, 8, NOTE_B3, 16, NOTE_D4, -8,

};

const int melody5[] PROGMEM = {

  NOTE_FS5, 8, NOTE_FS5, 8, NOTE_D5, 8, NOTE_B4, 8, REST, 8, NOTE_B4, 8, REST, 8, NOTE_E5, 8,
  REST, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, NOTE_GS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_B5, 8,
  NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_E5, 8, REST, 8, NOTE_D5, 8, REST, 8, NOTE_FS5, 8,
  REST, 8, NOTE_FS5, 8, REST, 8, NOTE_FS5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_FS5, 8, NOTE_E5, 8,
  NOTE_FS5, 8, NOTE_FS5, 8, NOTE_D5, 8, NOTE_B4, 8, REST, 8, NOTE_B4, 8, REST, 8, NOTE_E5, 8,

  REST, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, NOTE_GS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_B5, 8,
  NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_E5, 8, REST, 8, NOTE_D5, 8, REST, 8, NOTE_FS5, 8,
  REST, 8, NOTE_FS5, 8, REST, 8, NOTE_FS5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_FS5, 8, NOTE_E5, 8,
  NOTE_FS5, 8, NOTE_FS5, 8, NOTE_D5, 8, NOTE_B4, 8, REST, 8, NOTE_B4, 8, REST, 8, NOTE_E5, 8,
  REST, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, NOTE_GS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_B5, 8,

  NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_E5, 8, REST, 8, NOTE_D5, 8, REST, 8, NOTE_FS5, 8,
  REST, 8, NOTE_FS5, 8, REST, 8, NOTE_FS5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_FS5, 8, NOTE_E5, 8,

};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

int wholeNote = (60000 * 4) / tempo;

int divider = 0;
int duration = 0;



void setup() {
  //Start up tune
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = pgm_read_word_near(melody + thisNote + 1);

    if (divider > 0) {
      duration = (wholeNote) / divider;
    }

    else if (divider < 0) {
      duration = (wholeNote) / abs(divider);
      duration = duration * 1.5;
    }

    tone(buzzerPin, pgm_read_word_near(melody + thisNote), duration * 0.9);
    delay(duration);
    noTone(buzzerPin);

    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);


    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);

  }

  //Enable IR communications after startup tune
  IR.enableIRIn();
}



void loop() {

  //LED loop while waiting for IR signal from remote
  while (IR.decode(&cmd) == 0) {
    digitalWrite(redPin, HIGH);
    delay(200);
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(200);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(200);
    digitalWrite(greenPin, LOW);
  }


  //Plays melody 1, The Legend of Zelda Theme
  if (cmd.value == 0xFF30CF || cmd.value == 0x9716BE3F) {
    delay(500);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    tempo = 120;

    notes = sizeof(melody1) / sizeof(melody1[0]) / 2;

    wholeNote = (60000 * 4) / tempo;

    divider = 0;
    duration = 0;

    delay(100);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = pgm_read_word_near(melody1 + thisNote + 1);  //pgm_read_word_near is used to access data stored in program memory (ex: melody1)

      if (divider > 0) {
        duration = (wholeNote) / divider;
      }

      else if (divider < 0) {
        duration = (wholeNote) / abs(divider);
        duration = duration * 1.5;
      }

      tone(buzzerPin, pgm_read_word_near(melody1 + thisNote), duration * 0.9);
      delay(duration);
      noTone(buzzerPin);

    }
    IR.resume();
  }


  //Plays melody 2, Fur Elise. We got the music notes arranged from work by Robson Couta. You can check out his work at https://robsoncouto.com
  if (cmd.value == 0xFF18E7 || cmd.value == 0x3D9AE3F7) {
    delay(500);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    tempo = 90;

    notes = sizeof(melody2) / sizeof(melody2[0]) / 2;

    wholeNote = (60000 * 4) / tempo;

    divider = 0;
    duration = 0;

    delay(100);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = pgm_read_word_near(melody2 + thisNote + 1);

      if (divider > 0) {
        duration = (wholeNote) / divider;
      }

      else if (divider < 0) {
        duration = (wholeNote) / abs(divider);
        duration = duration * 1.5;
      }

      tone(buzzerPin, pgm_read_word_near(melody2 + thisNote), duration * 0.9);
      delay(duration);
      noTone(buzzerPin);

    }
    IR.resume();
  }


  //Plays melody 3
  if (cmd.value == 0x6182021B || cmd.value == 0x7B302124 || cmd.value == 0xFF7A85 || cmd.value == 0xE1455E68) {
    delay(500);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    tempo = 154;

    notes = sizeof(melody3) / sizeof(melody3[0]) / 2;

    wholeNote = (60000 * 4) / tempo;

    divider = 0;
    duration = 0;

    delay(100);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = pgm_read_word_near(melody3 + thisNote + 1);

      if (divider > 0) {
        duration = (wholeNote) / divider;
      }

      else if (divider < 0) {
        duration = (wholeNote) / abs(divider);
        duration = duration * 1.5;
      }

      tone(buzzerPin, pgm_read_word_near(melody3 + thisNote), duration * 0.9);
      delay(duration);
      noTone(buzzerPin);

    }
    IR.resume();
  }


  //Plays melody 4
  if (cmd.value == 0xFF10EF || cmd.value == 0x8C22657B) {
    delay(500);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    tempo = 130;

    notes = sizeof(melody4) / sizeof(melody4[0]) / 2;

    wholeNote = (60000 * 4) / tempo;

    divider = 0;
    duration = 0;

    delay(100);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = pgm_read_word_near(melody4 + thisNote + 1);

      if (divider > 0) {
        duration = (wholeNote) / divider;
      }

      else if (divider < 0) {
        duration = (wholeNote) / abs(divider);
        duration = duration * 1.5;
      }

      tone(buzzerPin, pgm_read_word_near(melody4 + thisNote), duration * 0.9);
      delay(duration);
      noTone(buzzerPin);

    }
    IR.resume();
  }


  //Plays melody 5, Take On Me!
  if (cmd.value == 0xFF38C7 || cmd.value == 0x488F3CBB) {
    delay(500);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    tempo = 160;

    notes = sizeof(melody5) / sizeof(melody5[0]) / 2;

    wholeNote = (60000 * 4) / tempo;

    divider = 0;
    duration = 0;

    delay(100);

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
      divider = pgm_read_word_near(melody5 + thisNote + 1);

      if (divider > 0) {
        duration = (wholeNote) / divider;
      }

      else if (divider < 0) {
        duration = (wholeNote) / abs(divider);
        duration = duration * 1.5;
      }

      tone(buzzerPin, pgm_read_word_near(melody5 + thisNote), duration * 0.9);
      delay(duration);
      noTone(buzzerPin);

    }
    IR.resume();
  }

  if (cmd.value != 0xFF38C7 || cmd.value != 0x488F3CBB || cmd.value != 0xFF10EF || cmd.value != 0x8C22657B || cmd.value != 0x6182021B || cmd.value != 0x7B302124 || cmd.value != 0xFF7A85 || cmd.value != 0xE1455E68 ||
      cmd.value != 0xFF18E7 || cmd.value != 0x3D9AE3F7 ||cmd.value != 0xFF30CF || cmd.value != 0x9716BE3F) {
    IR.resume();
  }
}
