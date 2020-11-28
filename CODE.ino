//https://github.com/going-digital/Talkie
// what helps the sound from the speaker
#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"
#include "Vocab_US_TI99.h"


//define two button vars
#define BUTTON_PIN_1 7
#define BUTTON_PIN_2 8
#define BUTTON_PIN_3 9
#define ARRAY_TEST_NUM 3


Talkie voice;
const uint8_t spA[] PROGMEM ={ 0xA7,0x8A,0xCE,0x25,0xA7,0x2A,0xDD,0x62,0xE7,0x3B,0xBF,0xF9,0xAD,0x56,0xD5,0x72,0xA0,0x44,0x7D,0x99,0x4D,0xED,0xFC,0xE0,0x87,0x07,0x00,0x00};
const uint8_t spB[] PROGMEM ={0xAB,0xED,0xD1,0x14,0x5D,0xBB,0xAD,0xB6,0x45,0x57,0xF0,0xDE,0x3A,0x9A,0x59,0x94,0x31,0x62,0xCD,0x6E,0x76,0xB3,0x9B,0xD9,0xF4,0xB6,0xB6,0xB1,0xB7,0x3D,0xEF,0x1F,0x00,0x00};
const uint8_t spC[] PROGMEM ={0x08,0xD0,0xB4,0x42,0x00,0x8B,0x88,0x3A,0xE0,0x2B,0xD5,0x00,0xFC,0x18,0xE6,0x81,0x08,0x78,0xC0,0x00,0x4F,0xAB,0x1C,0xA7,0xF8,0x60,0x31,0x7D,0x73,0xE2,0x1A,0x93,0xD8,0xED,0xEB,0x8D,0x6F,0x72,0xB3,0x51,0xF4,0x9A,0x02,0x1A,0x6F,0x77,0xB5,0xEB,0xD9,0x94,0xB6,0x34,0x22,0xA9,0xA9,0x93,0xBB,0xD0,0x25,0xC7,0x94,0x97,0xA1,0x4D,0xE7,0x95,0xF0,0x9E,0x18,0x35,0x5D,0xF4,0xA0,0xD3,0x29,0x4C,0x75,0xC1,0x82,0x86,0xB9,0xB3,0x07};
uint8_t * arrayTest[ARRAY_TEST_NUM]={spA,spB,spC};

int prevButtonValOne = 0;
int buttonPushCounterOne = 0;   // counter for the number of button presses

int prevButtonValTwo = 0;
int buttonPushCounterTwo = 0;   

int prevButtonValThree = 0;
int buttonPushCounterThree = 0;

void setup() {
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
  Serial.begin(9600);

}

void loop() {
 
/* FOR BUTTON ONE */
  int buttonValOne = digitalRead(BUTTON_PIN_1); // read value from button
  
  // compare the buttonState to its previous state
  if (buttonValOne != prevButtonValOne) {
    // if the state has changed, increment the counter
    
    if (buttonValOne == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounterOne++;

      //make a random num
//      int randomNum = random(ARRAY_TEST_NUM);
      speakNumP1(0);
      
    } 
    
    else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("one is off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  prevButtonValOne = buttonValOne;

  /* FOR BUTTON TWO */
  int buttonValTwo = digitalRead(BUTTON_PIN_2); // read value from button

  // compare the buttonState to its previous state
  if (buttonValTwo != prevButtonValTwo) {
    // if the state has changed, increment the counter
    
    if (buttonValTwo == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounterTwo++;
 
      //make a random num

      speakNumP2(1);
      
    } 
    
    else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("one is off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  prevButtonValTwo = buttonValTwo;

/* FOR BUTTON THREE */
  int buttonValThree = digitalRead(BUTTON_PIN_3); // read value from button

  // compare the buttonState to its previous state
  if (buttonValThree != prevButtonValThree) {
    // if the state has changed, increment the counter
    
    if (buttonValThree == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounterThree++;
 
      //make a random num

      speakNumP3(2);
      
    } 
    
    else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("one is off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  prevButtonValThree = buttonValThree;
  }
  

  void speakNumP1(int choice){
      Serial.print("the choice::");
      Serial.println(choice);
      voice.say(arrayTest[choice]);
 }

  void speakNumP2(int choice){
      Serial.print("the choice::");
      Serial.println(choice);
   voice.say(arrayTest[choice]);

 }

  void speakNumP3(int choice){
      Serial.print("the choice::");
     Serial.println(choice);
     voice.say(arrayTest[choice]);

 }
