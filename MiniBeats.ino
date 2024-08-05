#include <FastLED.h>
#include <Keypad.h>
#define NUM_LEDS 16
#define DATA_PIN 0
#define speakerPin 9
CRGB leds[NUM_LEDS]

void drum(int freq, int time)){
  for(int i = 0; i <time; i++{
  tone(speakerPin,freq);
  delay(1);
  int elap = time-i*time-i;
  freq -= 0.08*elap;
  }
}

void cmaj7(int time){
  for(i = 0; i<time/3;i++){
    tone(speakerPin,261);
    delay(1);
    tone(speakerPin,329);
    delay(1);
    tone(speakerPin,391);
    delay(1)
  }
}

void gmaj7(int time){
  for(i = 0; i<time/3;i++){
    tone(speakerPin,391);
    delay(1);
    tone(speakerPin,294);
    delay(1);
    tone(speakerPin,698);
    delay(1);
  }
}

void lights(int pos){
  
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
    drum(200,50);
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
