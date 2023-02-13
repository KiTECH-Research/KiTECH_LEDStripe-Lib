#include "KiTECH_LEDStripe.h"

KiTECH_LEDStripe stripe;

bool stripeOn = false;
unsigned long prev_millis = 0;

void setup() {
    Serial.begin(9600);
    stripe.setup();

    pinMode(4, INPUT);
}

void loop() {
    if (stripeOn) {
        int r = stripe.get_color_value(stripe.Red);
        int g = stripe.get_color_value(stripe.Green);
        int b = stripe.get_color_value(stripe.Blue);
        stripe.show_color(r, g, b);
        Serial.print(r);
        Serial.print(" ");
        Serial.print(g);
        Serial.print(" ");
        Serial.println(b);
    } else {
        stripe.show_color(0, 0, 0);
    }

    if (digitalRead(4) == HIGH && (millis() - prev_millis > 250)) {
        prev_millis = millis();
        stripeOn = !stripeOn;
    }
}