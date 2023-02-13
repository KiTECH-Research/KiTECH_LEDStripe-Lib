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

void KiTECH_LEDStripe::clear() {
    pixels.clear();
}

void KiTECH_LEDStripe::vycisti() {
    clear();
}

int KiTECH_LEDStripe::get_color_value(Pin pin) {
    int pinNumber = get_pin_number(pin);
    int maxValue = get_max_potentiometer_value(pin);

    if (pinNumber == 0 || maxValue == 0)
        return 0;

    return map(analogRead(pinNumber), 0, maxValue, 0, 255);
}

void KiTECH_LEDStripe::show_color(int r, int g, int b) {
    for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(r, g, b));
    }
    pixels.show();
}

int KiTECH_LEDStripe::get_pin_number(Pin pin) {
    switch (pin)
    {
        case Red:
            return _pinR;
        case Green:
            return _pinG;
        case Blue:
            return _pinB;
        default:
            return 0;
    }
}

int KiTECH_LEDStripe::get_max_potentiometer_value(Pin pin) {
    switch (pin)
    {
        case Red:
            return _maxPotentiometerR;
        case Green:
            return _maxPotentiometerG;
        case Blue:
            return _maxPotentiometerB;
        default:
            return 0;
    }
}

void KiTECH_LEDStripe::night_lamp() {
    show_color(255, 105, 25);
}