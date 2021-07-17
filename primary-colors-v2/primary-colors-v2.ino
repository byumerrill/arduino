#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 100 // Popular NeoPixel ring size

#define STEPDELAY 10 // Time (in milliseconds) to pause between pixels
#define ENJOYDELAY 3000 // Time (in milliseconds) to pause between pixels


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(45);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

//slowly fade to blue
  for( int colorStep=0; colorStep<256; colorStep++ ) {

      int r = 0;  
      int b = colorStep;  // Blue starts at zero and goes up to full
      int g = 0;              

      // Set each LED to the current color
      strip.fill(strip.Color(r, g, b));

      // Display the colors we just set on the actual LEDs
      strip.show();

      // Pause for effect
      delay(STEPDELAY); 
  }


      // Pause to enjoy this color before starting the transition to a new color
      delay(ENJOYDELAY); 


// fade from blue to red
  for( int colorStep=0; colorStep<256; colorStep++ ) {

      int r = colorStep;  // Redness starts at zero and goes up to full
      int b = 255-colorStep;  // Blue starts at full and goes down to zero
      int g = 0;              // No green needed to go from blue to red

      // Set each LED to the current color
      strip.fill(strip.Color(r, g, b));

      // Display the colors we just set on the actual LEDs
      strip.show();

      // Pause for effect
      delay(STEPDELAY); 
  }


      // Pause to enjoy this color before starting the transition to a new color
      delay(ENJOYDELAY); 



  // fade from red to yellow (205, 70, 0)
      // Set each LED to the current color
      strip.fill(strip.Color(205, 70, 0));
  
      // Display the colors we just set on the actual LEDs
      strip.show();


  // fade from red to yellow (205, 70, 0)
//  for( int colorStep=0; colorStep<50; colorStep++ ) {
//  
//      int r = 255-colorStep;  // Redness starts at full and goes down to yellow 205
//      int b = 0; // initialize b
//
//        // if colorstep > 70 then stay at 70
//        if (colorStep<70) {
//          int b = colorStep;  // start at 0 and go up to 70;
//        } else {
//          int b = 70;  // start at 0 and go up to 70;
//        }
//      
//      int g = 0; // set green             
//  
//      // Set each LED to the current color
//      strip.fill(strip.Color(r, g, b));
//  
//      // Display the colors we just set on the actual LEDs
//      strip.show();
//  
//      // Pause for effect
//      delay(STEPDELAY); 
//  }




      // Pause to enjoy this color before starting the transition to a new color
      delay(ENJOYDELAY); 




  // fade from red to off
  for( int colorStep=0; colorStep<256; colorStep++ ) {
  
      int r = 255-colorStep;  // Redness starts at full and goes down to zero
      int b = 0;  
      int g = 0;              
  
      // Set each LED to the current color
      strip.fill(strip.Color(r, g, b));
  
      // Display the colors we just set on the actual LEDs
      strip.show();
  
      // Pause for effect
      delay(STEPDELAY); 
  }




//    strip.fill(strip.Color(205, 70, 0)); //YELLOW1
//    strip.show();
//    delay(DELAYVAL); // Pause before next pass through loop
//
//    strip.fill(strip.Color(255, 255, 0)); //YELLOW2
//    strip.show();
//    delay(DELAYVAL); // Pause before next pass through loop
//
//    strip.fill(strip.Color(255, 0, 0)); //RED
//    strip.show();
//    delay(DELAYVAL); // Pause before next pass through loop
//
//    strip.fill(strip.Color(0, 255, 0)); //GREEN
//    strip.show();
//    delay(DELAYVAL); // Pause before next pass through loop
//
//    strip.fill(strip.Color(0, 0, 255), 0, 100); //BLUE
//    strip.show();
//    delay(DELAYVAL); // Pause before next pass through loop


//  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//  colorWipe(strip.Color(205, 70, 255), 50); // Yellow



  
  // Some example procedures showing how to display to the pixels:
//  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//  colorWipe(strip.Color(205, 70, 255), 50); // Yellow
  
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW

  // Send a theater pixel chase in...
//  theaterChase(strip.Color(127, 127, 127), 50); // White
//  theaterChase(strip.Color(127, 0, 0), 50); // Red
//  theaterChase(strip.Color(0, 0, 127), 50); // Blue
//
//  rainbow(20);
//  rainbowCycle(20);
//  theaterChaseRainbow(50);
}
