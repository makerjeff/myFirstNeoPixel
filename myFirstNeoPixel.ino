/* == First NeoPixel Sketch ==
Built for Arduino, distilled from C.
*/

#include <Adafruit_NeoPixel.h>

int PIN = 6;
int speet = 3;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN);

void setup() {
  strip.begin();
  strip.show();
  
  strip.setBrightness(25);
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

  kittScanner(2);
  karrScanner(2);

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
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

