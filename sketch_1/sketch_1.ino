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
const int ButtonNoodstopPin = 3;
const int button3Pin = 4;           

int previousButton1State = HIGH; 
int previousButtonNoodstopState = HIGH; 
int previousButton3State = HIGH;
bool ButtonNoodstopIsNotPressed = true;

void setup() {
  //declare the buttons as input_pullup
  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(ButtonNoodstopPin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP); 
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();
  Serial.begin(9600);
 // delay(10);
  Serial.println("start");
}

void loop() {
  //checking the state of the button
  int button1State = digitalRead(button1Pin);
  int ButtonNoodstopState = digitalRead(ButtonNoodstopPin);
  int button3State = digitalRead(button3Pin);

   if (ButtonNoodstopState == LOW && previousButtonNoodstopState == HIGH) {
      // and it's currently pressed:
    
    Serial.println("laag2");
    //Keyboard.press(98);
    ButtonNoodstopIsNotPressed = false;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    
  }

  if (ButtonNoodstopState == HIGH && previousButtonNoodstopState == LOW) {
      // and it's currently released:
    Serial.println("hoog2");
    //Keyboard.release(98);
    ButtonNoodstopIsNotPressed = true;
    digitalWrite(LED_BUILTIN, LOW);  
    delay(50);
    
  }
  
 //replaces button press with UP arrow
  if (button1State == LOW && previousButton1State == HIGH && ButtonNoodstopIsNotPressed == true) {
      // and it's currently pressed:
    
    Serial.println("laag1");
    Keyboard.press(121);
    delay(50);
    
  }

  if (button1State == HIGH && previousButton1State == LOW && ButtonNoodstopIsNotPressed == true) {
      // and it's currently released:
    Serial.println("hoog1");
    Keyboard.release(121);
    delay(50);
    
  }

 

  if (button3State == LOW && previousButton3State == HIGH && ButtonNoodstopIsNotPressed == true) {
      // and it's currently pressed:
    
    Serial.println("laag3");
    Keyboard.press(117);
    delay(50);

  }

  if (button3State == HIGH && previousButton3State == LOW && ButtonNoodstopIsNotPressed == true) {
      // and it's currently released:
    Serial.println("hoog3");
    Keyboard.release(117);
    delay(50);

  }
 
  previousButton1State = button1State;
  previousButtonNoodstopState = ButtonNoodstopState;
  previousButton3State = button3State;


}