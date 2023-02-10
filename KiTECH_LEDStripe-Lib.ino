#include "KiTECH_LEDStripe.h"
#include "KiTECH_OLED.h"

KiTECH_LEDStripe stripe;
KiTECH_OLED oled;

void setup() {
    Serial.begin(9600);
    stripe.setup();

    if (oled.setup()) {
        oled.print("setup OK");
    } else {
        oled.print("setup FAIL");
    }
    oled.clear();
}

void loop() {
    int r = stripe.get_color_value(stripe.Red);
    int g = stripe.get_color_value(stripe.Green);
    int b = stripe.get_color_value(stripe.Blue);
    oled.print_rgb_values(r, g, b);
}