#include <Adafruit_NeoPixel.h>

#define TOWER_PIN 6
#define SPOTS_PIN 5

Adafruit_NeoPixel tower = Adafruit_NeoPixel(3, TOWER_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel spots = Adafruit_NeoPixel(1, SPOTS_PIN, NEO_GRB + NEO_KHZ800);

uint32_t RED = tower.Color(255, 0, 0);
uint32_t GRN = tower.Color(0, 255, 0);
uint32_t BLU = tower.Color(0, 0, 255);

uint32_t colour = tower.Color(255, 0, 128);

void setup() {
  tower.begin();
  tower.setBrightness(64);
  tower.setPixelColor(0, colour);
  tower.setPixelColor(1, colour);
  tower.setPixelColor(2, colour);
  tower.show();

  spots.begin();
  spots.setBrightness(64);
  spots.setPixelColor(0, colour);
  spots.show();
}

void loop() {}
