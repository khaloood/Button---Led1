this project send to serial monitor led state - button state and temperature without any delay
you must set
delay (1000);
in loop to see output

if you need led as toggle

loop will be like this


int pin_LED = 13;
int pin_switch = 2;
 
// variables to hold the new and old switch states
boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
 
boolean LEDstatus = LOW;
 
void loop()
{

    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  // read the state of the pushbutton value:

  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" Temp : ");
  Serial.print(Celcius);
  Serial.println(); 
  }



    newSwitchState = digitalRead(pin_switch);
 
    if ( newSwitchState != oldSwitchState ) 
    {
       // has the button switch been closed?
       if ( newSwitchState == HIGH )
       {
           if ( LEDstatus == LOW ) { digitalWrite(pin_LED, HIGH);  LEDstatus = HIGH; }
           else                    { digitalWrite(pin_LED, LOW);   LEDstatus = LOW;  }
       }
       oldSwitchState = newSwitchState;
    }     
}