#include <FastLED.h>

#define TOWER_PIN 6
#define SPOTS_PIN 5
#define TOWER_LEDS 3
#define SPOTS_LEDS 1
#define MAX_VAL 128
#define START_HUE 171

CRGB leds[TOWER_LEDS + SPOTS_LEDS];
CHSV currentColour = CHSV(START_HUE, 196, 0);

void setTower(CHSV colour) {
  fill_solid(leds, TOWER_LEDS, colour);
}

void setSpots(CHSV colour) {
  fill_solid(leds + TOWER_LEDS, SPOTS_LEDS, currentColour);
}

void setup() {
  FastLED.addLeds<NEOPIXEL, TOWER_PIN>(leds, 0, TOWER_LEDS);
  FastLED.addLeds<NEOPIXEL, SPOTS_PIN>(leds, TOWER_LEDS, SPOTS_LEDS);

  setTower(currentColour);
  setSpots(currentColour);
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
