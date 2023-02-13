#ifndef KiTECH_LEDStripe_h
#define KiTECH_LEDStripe_h

#include "Arduino.h"

class KiTECH_LEDStripe
{
private:
    int _pinR = 34;
    int _pinG = 35;
    int _pinB = 32;
    int _pinStripe = 15;
    int _stripeLen = 18;
    int _maxPotentiometerR = 4095;
    int _maxPotentiometerG = 4095;
    int _maxPotentiometerB = 4095;


public:
    KiTECH_LEDStripe();
    KiTECH_LEDStripe(int r, int g, int b);

    enum Pin {Red, Green, Blue};

    bool setup();
    bool nastav();

    void clear();
    void vycisti();

    int get_color_value(Pin pin);
    void show_color(int r, int g, int b);
    int get_pin_number(Pin pin);
    int get_max_potentiometer_value(Pin pin);
};

#endif