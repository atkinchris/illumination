#include <FastLED.h>

#define TOWER_PIN 5
#define SPOTS_PIN 6
#define CLOCK_PIN 7

#define TOWER_LEDS 3
#define SPOTS_LEDS 1
#define CLOCK_LEDS 1
#define MAX_VAL 128
#define START_HUE 171

CRGB spotsLeds[SPOTS_LEDS];
CRGB towerLeds[TOWER_LEDS];
CRGB clockLeds[CLOCK_LEDS];

CHSV currentColour = CHSV(START_HUE, 196, 0);
CHSV clockColour = CHSV(50, 196, 96);

void setTower(CHSV colour) {
  fill_solid(towerLeds, TOWER_LEDS, colour);
}

void setSpots(CHSV colour) {
  fill_solid(spotsLeds, SPOTS_LEDS, colour);
}

void setClock(CHSV colour) {
  fill_solid(clockLeds, CLOCK_LEDS, colour);
}

void setup() {
  FastLED.addLeds<NEOPIXEL, TOWER_PIN>(towerLeds, TOWER_LEDS);
  FastLED.addLeds<NEOPIXEL, SPOTS_PIN>(spotsLeds, SPOTS_LEDS);
  FastLED.addLeds<NEOPIXEL, CLOCK_PIN>(clockLeds, CLOCK_LEDS);

  setTower(currentColour);
  setSpots(currentColour);
  setClock(clockColour);
}

void loop() {
  unsigned long ms = 200;

  if (currentColour.val < MAX_VAL) {
    currentColour.val += 2;
    ms = 10;
  } else {
    currentColour.hue += 2;
  }

  setTower(currentColour);
  setSpots(currentColour);

  FastLED.show();
  FastLED.delay(ms);
}
