#include <FastLED.h>
#include <Keypad.h>
#define NUM_LEDS 16
#define DATA_PIN 0
#define speakerPin 9
CRGB leds[NUM_LEDS]
int rgb = 0;

void lights(int rgb,int pos){
  if(rgb == 0){
    rgb++;
    led[pos] = CRGB::Red;
  }else if(rgb == 1){
    rgb++;
    led[pos] = CRGB::Green;
  }else if(rgb == 2){
    rgb++;
    led[pos] = CRGB::Blue;
  }else if(rgb == 3){
    rgb == 0;
    led[pos] == CRGB::Black;
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

byte rowPins[ROWS] = {1,2,3,4}; 
byte colPins[COLS] = {5,6,7,8}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds,NUM_LEDS)
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey == "a"){
    lights(rgb,0);
  }
  if (customKey == "b"){
    lights(rgb,1);
  }
  if (customKey == "c"){
    lights(rgb,2);
  }
  if (customKey == "d"){
    lights(rgb,3);
  }
  if (customKey == "e"){
    lights(rgb,4);
  }
  if (customKey == "f"){
    lights(rgb,5);
  }
  if (customKey == "g"){
    lights(rgb,6);
  }
  if (customKey == "h"){
    lights(rgb,7);
  }
  if (customKey == "i"){
    lights(rgb,8);
  }
  if (customKey == "j"){
    lights(rgb,9);
  }
  if (customKey == "k"){
    lights(rgb,10);
  }
  if (customKey == "l"){
    lights(rgb,11);
  }
  if (customKey == "m"){
    lights(rgb,12);
  }
  if (customKey == "n"){
    lights(rgb,13);
  }
  if (customKey == "o"){
    lights(rgb,14);
  }
  if (customKey == "p"){
    lights(rgb,15);
  }


}
