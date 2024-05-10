/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <IRremote.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



const int RECV_PIN = 3;
const int Led1 = 5;
const int Led2 = 6;
const int Led3 = 9;
const int Led4 = 10;
const int redPin = 11;    // Define the pin for the red color of the RGB LED
const int greenPin = 12;  // Define the pin for the green color of the RGB LED
const int bluePin = 13;  // Define the pin for the blue color of the RGB LED

int count = 1;
int bright = 255;
int rgbcount = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if (results.value == 284099070) {

      if (count == 1) {
        analogWrite(Led1, bright);
        count++;
      } else if (count == 2) {
        analogWrite(Led2, bright);
        count++;
      } else if (count == 3) {
        analogWrite(Led3, bright);
        count++;
      } else if (count == 4) {
        analogWrite(Led4, bright);
        count++;
      } else if (count == 5) {
        digitalWrite(redPin, 1);    // Turn on  red
        digitalWrite(greenPin, 0);  // Turn off green
        digitalWrite(bluePin, 0);   // Turn off blue
        count++;
        rgbcount++;
      } else if (count == 6) {
        digitalWrite(redPin, 0);    // Turn off red
        digitalWrite(greenPin, 1);  // Turn on green
        digitalWrite(bluePin, 0);   // Turn off blue
        count++;
        rgbcount++;
      } else if (count == 7) {
        digitalWrite(redPin, 0);    // Turn off red
        digitalWrite(greenPin, 0);  // Turn off green
        digitalWrite(bluePin, 1);   // Turn on blue
        count++;
        rgbcount++;
      } else if (count == 8) {
        digitalWrite(redPin, 1);    // Turn on red
        digitalWrite(greenPin, 1);  // Turn on green
        digitalWrite(bluePin, 0);   // Turn off blue
        count++;
        rgbcount++;
      } else if (count == 9) {
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 1);
        digitalWrite(bluePin, 1);
        count++;
        rgbcount++;
      } else if (count == 10) {
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 0);
        digitalWrite(bluePin, 1);
        count++;
        rgbcount++;
      } else if (count == 11) {
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 1);
        digitalWrite(bluePin, 1);
        count++;
        rgbcount++;
        if (count == 12) {
          count = count - 7;
        }
      }
    }

    if (results.value == 284127630) {
      if (count == 2) {
        analogWrite(Led1, 0);
        count--;
      } else if (count == 3) {
        analogWrite(Led2, 0);
        count--;
      } else if (count == 4) {
        analogWrite(Led3, 0);
        count--;
      } else if (count == 5) {
        analogWrite(Led4, 0);
        count--;

      } else if (count == 6 && rgbcount % 7 == 1) {
        if (rgbcount == 1) {
          digitalWrite(redPin, 0);
          digitalWrite(greenPin, 0);
          digitalWrite(bluePin, 0);
          count--;
          rgbcount--;
        } else {
          digitalWrite(redPin, 1);
          digitalWrite(greenPin, 1);
          digitalWrite(bluePin, 1);
          count = count + 6;
          rgbcount--;
        }

      } else if (count == 7 && rgbcount % 7 == 2) {
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 0);  // Turn off green
        digitalWrite(bluePin, 0);   // Turn off blue
        count--;
        rgbcount--;
      } else if (count == 8 && rgbcount % 7 == 3) {
        digitalWrite(redPin, 0);    // Turn off red
        digitalWrite(greenPin, 1);  // Turn off green
        digitalWrite(bluePin, 0);
        count--;
        rgbcount--;
      } else if (count == 9 && rgbcount % 7 == 4) {
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 0);
        digitalWrite(bluePin, 1);
        count--;
        rgbcount--;
      } else if (count == 10 && rgbcount % 7 == 5) {
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 1);
        digitalWrite(bluePin, 0);
        count--;
        rgbcount--;
      } else if (count == 11 && rgbcount % 7 == 6) {
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 1);
        digitalWrite(bluePin, 1);
        count--;
        rgbcount--;
      } else if (count == 12 && rgbcount % 7 == 0) {
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 0);
        digitalWrite(bluePin, 1);
        count--;
        rgbcount--;
      }
    }

    if (results.value == 284123550) {
      if (bright >= 25 && bright <= 255) {
        bright -= 50;

        switch (count) {
          case 1:
            analogWrite(Led1, bright);
            break;
          case 2:
            analogWrite(Led1, bright);
            break;
          case 3:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            break;
          case 4:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            analogWrite(Led3, bright);
            break;
          case 5:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            analogWrite(Led3, bright);
            analogWrite(Led4, bright);
            break;
        }
        if (count > 4) {
          analogWrite(Led1, bright);
          analogWrite(Led2, bright);
          analogWrite(Led3, bright);
          analogWrite(Led4, bright);
        }
      }
    }
    if (results.value == 284148030) {
      if (bright > 0 && bright < 255) {
        bright += 50;
        switch (count) {
          case 1:
            analogWrite(Led1, bright);
            break;
          case 2:
            analogWrite(Led1, bright);
            break;
          case 3:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            break;
          case 4:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            analogWrite(Led3, bright);
            break;
          case 5:
            analogWrite(Led1, bright);
            analogWrite(Led2, bright);
            analogWrite(Led3, bright);
            analogWrite(Led4, bright);
            break;
        }
        if (count > 4) {
          analogWrite(Led1, bright);
          analogWrite(Led2, bright);
          analogWrite(Led3, bright);
          analogWrite(Led4, bright);
        }
      }
    }

    delay(500);
    irrecv.resume();  // Receive the next value
  }
}
