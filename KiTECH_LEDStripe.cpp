#include <Adafruit_NeoPixel.h>
#include "KiTECH_LEDStripe.h"

KiTECH_LEDStripe::KiTECH_LEDStripe() {}

KiTECH_LEDStripe::KiTECH_LEDStripe(int r, int g, int b) {
    _pinR = r;
    _pinG = g;
    _pinB = b;
}

#define STRIPEPIN 15
#define NUMPIXELS 18

Adafruit_NeoPixel pixels(NUMPIXELS, STRIPEPIN, NEO_GRB + NEO_KHZ800);

bool KiTECH_LEDStripe::setup() {
    pinMode(_pinR, INPUT);
    pinMode(_pinG, INPUT);
    pinMode(_pinB, INPUT);

    pixels.begin();

    return true;
}

bool KiTECH_LEDStripe::nastav() {
    return setup();
}

int KiTECH_LEDStripe::get_color_value(Pin pin) {
    switch (pin)
    {
        case Red:
            return map(analogRead(_pinR), 0, 4095, 0, 255);
        case Green:
            return map(analogRead(_pinG), 0, 4095, 0, 255);
        case Blue:
            return map(analogRead(_pinB), 0, 4095, 0, 255);
        default:
            return 0;
    }
}

void KiTECH_LEDStripe::show_color(int r, int g, int b) {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(r, g, b));
    }
    pixels.show();
}

void KiTECH_LEDStripe::clear() {
    pixels.clear();
}

void KiTECH_LEDStripe::vycisti() {
    clear();
}