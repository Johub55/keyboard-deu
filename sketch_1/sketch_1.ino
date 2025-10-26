// button1 y (deur openen links tsw6)
// button3 u (deur openen rechts tsw6)
//https://theasciicode.com.ar/ascii-printable-characters/capital-letter-h-uppercase-ascii-code-72.html (control numbers)

#include "Keyboard.h"

//vanaf kant zonder draadjes
//onder pin 2
//midden pin 3
//boven pin 4
//declaring button pins
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;           

int previousButton1State = HIGH; 
int previousButton2State = HIGH; 
int previousButton3State = HIGH;
bool Button2IsNotPressed = true;

void setup() {
  //declare the buttons as input_pullup
  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP); 
  Keyboard.begin();
  Serial.begin(9600);
 // delay(10);
  Serial.println("start");
}

void loop() {
  //checking the state of the button
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);
  
 //replaces button press with UP arrow
  if (button1State == LOW && previousButton1State == HIGH && Button2IsNotPressed == true) {
      // and it's currently pressed:
    
    Serial.println("laag1");
    Keyboard.press(121);
    delay(50);
    
  }

  if (button1State == HIGH && previousButton1State == LOW && Button2IsNotPressed == true) {
      // and it's currently released:
    Serial.println("hoog1");
    Keyboard.release(121);
    delay(50);
    
  }

  if (button2State == LOW && previousButton2State == HIGH) {
      // and it's currently pressed:
    
    Serial.println("laag2");
    //Keyboard.press(98);
    Button2IsNotPressed = false;
    delay(50);
    
  }

  if (button2State == HIGH && previousButton2State == LOW) {
      // and it's currently released:
    Serial.println("hoog2");
    //Keyboard.release(98);
    Button2IsNotPressed = true;
    delay(50);
    
  }

  if (button3State == LOW && previousButton3State == HIGH && Button2IsNotPressed == true) {
      // and it's currently pressed:
    
    Serial.println("laag3");
    Keyboard.press(117);
    delay(50);

  }

  if (button3State == HIGH && previousButton3State == LOW && Button2IsNotPressed == true) {
      // and it's currently released:
    Serial.println("hoog3");
    Keyboard.release(117);
    delay(50);

  }
 
  previousButton1State = button1State;
  previousButton2State = button2State;
  previousButton3State = button3State;


}