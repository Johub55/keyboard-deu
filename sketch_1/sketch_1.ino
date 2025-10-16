#include "Keyboard.h"

//declaring button pins
const int button1Pin = 2;
const int button2Pin = 3;           

int previousButton1State = HIGH; 
int previousButton2State = HIGH; 

void setup() {
  //declare the buttons as input_pullup
  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(button2Pin, INPUT_PULLUP); 
  Keyboard.begin();
  Serial.begin(9600);
 // delay(10);
  Serial.println("start");
}

void loop() {
  //checking the state of the button
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  
  
 //replaces button press with UP arrow
  if (button1State == LOW && previousButton1State == HIGH) {
      // and it's currently pressed:
    
    Serial.println("laag1");
    Keyboard.press(97);
    delay(50);
    
  }

  if (button1State == HIGH && previousButton1State == LOW) {
      // and it's currently released:
    Serial.println("hoog1");
    Keyboard.release(97);
    delay(50);
    
  }

  if (button2State == LOW && previousButton2State == HIGH) {
      // and it's currently pressed:
    
    Serial.println("laag2");
    Keyboard.press(98);
    delay(50);
    
  }

  if (button2State == HIGH && previousButton2State == LOW) {
      // and it's currently released:
    Serial.println("hoog2");
    Keyboard.release(98);
    delay(50);
    
  }
 
  previousButton1State = button1State;
  previousButton2State = button2State;

}