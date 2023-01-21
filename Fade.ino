/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int brightness = 0;  // how bright the LED is
int fadeAmount = 3;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 8 and 9 to be an output:
  // declare pin 10 to be an input
  for (int led = 8; led <= 10; led++) {
      if (led == 10) {
        pinMode(led, INPUT);
      } else {
        pinMode(led, OUTPUT);
      }
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // set pin 8 to high so that we may turn LED(red) on when press button
  digitalWrite(8, HIGH);
  // when pressing the button the green LED will fade
  if (digitalRead(10) == HIGH) {
    // set the brightness of pin 9:
    analogWrite(9, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 200) {
      fadeAmount = -fadeAmount;
    }
    // wait for 8 milliseconds to see the dimming effect
    delay(8);
  } else {
    // if not pressing the button, the green one will stop fading
    analogWrite(9, LOW);
  }
}
