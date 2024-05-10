#include <IRremote.h>

const int Rec_pin = 3;
const int White1 = 5;
const int White2 = 6;
const int White3 = 9;
const int White4 = 10;
const int Red = 11;    // Define the pin for the red color of the RGB LED
const int Green = 12;  // Define the pin for the green color of the RGB LED
const int Blue = 13;  // Define the pin for the blue color of the RGB LED

int Count = 1;
int Bright = 255;
int RGBcount = 0;

IRrecv irrecv(Rec_pin);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(White1, OUTPUT);
  pinMode(White2, OUTPUT);
  pinMode(White3, OUTPUT);
  pinMode(White4, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if (results.value == 284099070) {

      if (Count == 1) {
        analogWrite(White1, Bright);  //First White Bulb
        Count++;
      } 
      else if (Count == 2) {
        analogWrite(White2, Bright);  //Second White Bulb
        Count++;
      } else if (Count == 3) {
        analogWrite(White3, Bright);  //Third White Bulb
        Count++;
      } else if (Count == 4) {
        analogWrite(White4, Bright);  //Fourth White Bulb
        Count++;
      } else if (Count == 5) {
        digitalWrite(Red, 1);    //Red Color
        digitalWrite(Green, 0);  
        digitalWrite(Blue, 0);   
        Count++;
        RGBcount++;
      } else if (Count == 6) {
        digitalWrite(Red, 0);    
        digitalWrite(Green, 1);  //Green Color
        digitalWrite(Blue, 0);   
        Count++;
        RGBcount++;
      } else if (Count == 7) {
        digitalWrite(Red, 0);    
        digitalWrite(Green, 0);  
        digitalWrite(Blue, 1);   //Blue Color
        Count++;
        RGBcount++;
         if (Count == 8) {
           Count = Count - 3;
         }
      } 
    }

    if (results.value == 284127630) {
      }if (Count == 8 && RGBcount % 3 == 3) {
        digitalWrite(Red, 0);
        digitalWrite(Green, 0);
        digitalWrite(Blue, 1);
        Count--;
        RGBcount--;
    }else if (Count == 7 && RGBcount % 3 == 2) {
        digitalWrite(Red, 0);    
        digitalWrite(Green, 1);  
        digitalWrite(Blue, 0);
        Count--;
        RGBcount--;
    }else if (Count == 6 && RGBcount % 3 == 1) {
        digitalWrite(Red, 1);
        digitalWrite(Green, 0);  
        digitalWrite(Blue, 0);   
        Count--;
        RGBcount--;
    }else if (Count == 6 && RGBcount % 3 == 0) {
          digitalWrite(Red, 0);
          digitalWrite(Green, 0);
          digitalWrite(Blue, 0);
          Count--;
          RGBcount--;
    }
    if (Count == 2) {
        analogWrite(White1, 0);
        Count--;
      } else if (Count == 3) {
        analogWrite(White2, 0);
        Count--;
      } else if (Count == 4) {
        analogWrite(White3, 0);
        Count--;
      } else if (Count == 5) {
        analogWrite(White4, 0);
        Count--;

    if (results.value == 284148030) {
      if (Bright > 0 && Bright < 255) {
        Bright += 25;
        switch (Count) {
          case 1:
            analogWrite(White1, Bright);
            break;
          case 2:
            analogWrite(White1, Bright);
            break;
          case 3:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            break;
          case 4:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            analogWrite(White3, Bright);
            break;
          case 5:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            analogWrite(White3, Bright);
            analogWrite(White4, Bright);
            break;
        }
        if (Count > 4) {
          analogWrite(White1, Bright);
          analogWrite(White2, Bright);
          analogWrite(White3, Bright);
          analogWrite(White4, Bright);
        }
      }
    }

    if (results.value == 284123550) {
      if (Bright >= 25 && Bright <= 255) {
        Bright -= 25;

        switch (Count) {
          case 1:
            analogWrite(White1, Bright);
            break;
          case 2:
            analogWrite(White1, Bright);
            break;
          case 3:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            break;
          case 4:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            analogWrite(White3, Bright);
            break;
          case 5:
            analogWrite(White1, Bright);
            analogWrite(White2, Bright);
            analogWrite(White3, Bright);
            analogWrite(White4, Bright);
            break;
        }
        if (Count > 4) {
          analogWrite(White1, Bright);
          analogWrite(White2, Bright);
          analogWrite(White3, Bright);
          analogWrite(White4, Bright);
        }
      }
    }
    
   }
   irrecv.resume();
  }
}