#include <LiquidCrystal.h>

#define analogPin  A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-down resistor
float tempC, tempF; // make two variables to store the values of temperature
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // connect the lcd to those pins

void setup() {
  lcd.begin(16, 2); // initialize the lcd, this time I want it display two lines
}

void loop() {
  long a = analogRead(analogPin); // read the voltage of the resistor
  //the calculating formula of temperature
  tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  tempF = 1.8*tempC + 32.0; //convert centigrade to Fahrenheit
  lcd.setCursor(0, 0); // set the first line, display from the left most
  lcd.print("TempC= "); // display "TempC= "
  lcd.print(tempC); // display the centigrade temperature
  lcd.setCursor(0, 1); // set the second line, display from the left most
  lcd.print("TempF= "); // display "TempF= "
  lcd.print(tempF); // display the Fahrenheit temperature
  delay(800); // wait for 800 ms  
  // when the temperature is higher than 25 centigrade
  // the red LED turns on
  // else, it will not
  if (tempC >= 25.0) {
    analogWrite(10, 255);
  } else {
    analogWrite(10, 0);
  }      
}

