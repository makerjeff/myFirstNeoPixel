/* == First NeoPixel Sketch ==
Built for Arduino, distilled from C.
2015.DEC.04:
  - adding serial input functionality.
    - set brightness with 1-9.
*/

#include <Adafruit_NeoPixel.h>

int PIN = 7;
int speet = 3;

int red = 100;
int green = 10;
int blue = 100;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN);

void setup() {
  
  Serial.begin(9600);  //fire up a bowl of serial
  
  strip.begin();
  strip.show();
  strip.setBrightness(100);
}

void loop() {
  //fade(0, 50, 255);
  
//  fade(0, 50, 255);
//  fade(1, 50, 255);
//  fade(2, 50, 255);
//  fade(3, 50, 255);
//  fade(4, 50, 255);
//  fade(5, 50, 255);
//  fade(6, 50, 255);
//  fade(7, 50, 255);
//  fade(8, 50, 255);

  //kittScanner(2);
  //karrScanner(2);
  
  customScanner(2);
  

}


//custom functions

// KITT scanner
void kittScanner(int repeat) {
  
  for(int i = 0; i < repeat; i++) {
    forwardColorWipe(strip.Color(255,0,0), 50);
    forwardColorWipe(strip.Color(0,0,0), 50);
    
    backwardColorWipe(strip.Color(255,0,0), 50);
    backwardColorWipe(strip.Color(0,0,0), 50);
  }
}

//KARR scanner
void karrScanner(int repeat) {
  
  for(int i = 0; i < repeat; i++) {
    forwardColorWipe(strip.Color(140,255,0), 50);
    forwardColorWipe(strip.Color(0,0,0), 50);
    
    backwardColorWipe(strip.Color(140,255,0), 50);
    backwardColorWipe(strip.Color(0,0,0), 50);
  }
}

//custom serial input color
void customScanner(int repeat) {
  
    forwardColorWipe(strip.Color(red, green, blue),50);
    forwardColorWipe(strip.Color(0,0,0),50);
    
    backwardColorWipe(strip.Color(red,green,blue),50);
    backwardColorWipe(strip.Color(0,0,0), 50);
  
  while (Serial.available() > 0) {
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    
          Serial.print(red);
          Serial.print(green);
          Serial.println(blue);
    
    //if 'carriage return key' is entered...
    if(Serial.read() == '\r') {
//      red = 255-constrain(red, 0, 255);
//      green = 255-constrain(green, 0, 255);
//      blue = 255-constrain(green, 0, 255);

      

      
      forwardColorWipe(strip.Color(red, green, blue),50);
      forwardColorWipe(strip.Color(0,0,0),50);
      
      backwardColorWipe(strip.Color(red,green,blue),50);
      backwardColorWipe(strip.Color(0,0,0), 50);
    }
  }
}

//UTILITIY FUNCTIONS
//Color wipe forward
void forwardColorWipe(uint32_t color, int wait) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void backwardColorWipe(uint32_t color, int wait) {
  for(uint16_t i = 9; i > 0; i--) {
    strip.setPixelColor(i-1, color);
    strip.show();
    delay(wait);
  }
}

