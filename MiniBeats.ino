#include <FastLED.h>
#include <Keypad.h>

#define NUM_LEDS 16
#define DATA_PIN 0
#define speakerPin 9

CRGB leds[NUM_LEDS];
bool a = false; // 1 -
bool b = false; // 2
bool c = false; // 3
bool d = false; // 4
bool e = false; // 5 -
bool f = false; // 6
bool g = false; // 7
bool h = false; // 8
bool i = false; // 9 -
bool j = false; // 10
bool k = false; // 11
bool l = false; // 12
bool m = false; // 13 -
bool n = false; // 14
bool o = false; // 15
bool p = false; // 16
int speed = 100;

bool top[] = {a, e, i, m};
bool topMid[] = {b, f, j, n};
bool botMid[] = {c, g, k, o};
bool bot[] = {d, h, l, p};

void lights(int pos, bool &check) {
  if (check) {
    leds[pos] = CRGB::Black;
    check = false;
  } else if (pos == 0 || pos == 4 || pos == 8 || pos == 12) {
    leds[pos] = CRGB::Red;
    check = true;
  } else if (pos == 1 || pos == 5 || pos == 9 || pos == 13) {
    leds[pos] = CRGB::Green;
    check = true;
  } else if (pos == 2 || pos == 6 || pos == 10 || pos == 14) {
    leds[pos] = CRGB::Blue;
    check = true;
  } else if (pos == 3 || pos == 7 || pos == 11 || pos == 15) {
    leds[pos] = CRGB::Purple;
    check = true;
  }
}

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(speakerPin, INPUT);
}

void loop() {
  for(int i = 0; i<=4;i++){
    char customKey = customKeypad.getKey();
    if (customKey) {
      switch (customKey) {
        case 'a': lights(0, a); break;
        case 'b': lights(1, b); break;
        case 'c': lights(2, c); break;
        case 'd': lights(3, d); break;
        case 'e': lights(4, e); break;
        case 'f': lights(5, f); break;
        case 'g': lights(6, g); break;
        case 'h': lights(7, h); break;
        case 'i': lights(8, i); break;
        case 'j': lights(9, j); break;
        case 'k': lights(10, k); break;
        case 'l': lights(11, l); break;
        case 'm': lights(12, m); break;
        case 'n': lights(13, n); break;
        case 'o': lights(14, o); break;
        case 'p': lights(15, p); break;
      }
    }

    if (digitalRead(10) == HIGH) {
      if(speed = 20){
        speed = 100;
      }else{
        speed-=20;
      }
    }

    for (int p = 0; p < speed; p++) {
      leds[1+(i*4)] == CRGB::White;
      leds[2+(i*4)] == CRGB::White;
      leds[3+(i*4)] == CRGB::White;
      leds[4+(i*4)] == CRGB::White;
      leds.show()
      if (top[p]) {
        tone(speakerPin, 261);
        delay(1);
      }delay(1);
      delay(1);if (topMid[p]) {
        tone(speakerPin, 294);
        delay(1);
      }delay(1);
      if (botMid[p]) {
        tone(speakerPin, 329);
        delay(1);
      }delay(1);
      if (bot[p]) {
        tone(speakerPin, 349);
        
      }delay(1);
    }
    noTone(speakerPin);
    leds[1+(i*4)] == CRGB::Red;
    leds[2+(i*4)] == CRGB::Green;
    leds[3+(i*4)] == CRGB::Blue;
    leds[4+(i*4)] == CRGB::Purple;
    leds.show()
  }
}
