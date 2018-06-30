

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 5
//
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
/////
const long interval = 3000; 
unsigned long previousMillis = 0;
const bool  buttonPin = 2;     // the number of the pushbutton pin
const bool  ledPin =  13;      // the number of the LED pin
////////////
// variables will change:
bool  buttonState = 0; 
 float Celcius=0;
////////////////////
void setup() {
  Serial.begin(9600);
  sensors.begin();
 
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}
/////////////////////////////
void loop() {


    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  // read the state of the pushbutton value:

  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" temperature sensor : ");
  Serial.print(Celcius);
  Serial.println(); 
  }


  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.print("  button status : pressed ");
    Serial.print("  led state : ON ");
    Serial.println(); 
   delay
  } else {
      digitalWrite(ledPin, LOW);
      Serial.print("  button status : Unpressed ");
      Serial.print("  led state : off ");
      Serial.println(); 
   
    // turn LED off:
    
  }
}
