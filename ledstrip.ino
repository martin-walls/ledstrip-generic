#include <FastLED.h>

#define LEDTYPE WS2812B
#define LEDPIN 6
#define NUMLEDS 7

// #define POTPIN A0

#define ROTARY_PINA 2
#define ROTARY_PINB 3

#define RAINBOW 0
#define SOLID 1

#define MODE SOLID

extern const uint8_t gamma[];

CRGB leds[NUMLEDS];

CHSV color = CHSV(0, 255, 255);

uint8_t startHue = 0;

uint8_t hue = 200;
uint8_t aState;
uint8_t aLastState;

void setup() {
    pinMode(ROTARY_PINA, INPUT);
    pinMode(ROTARY_PINB, INPUT);

    aLastState = digitalRead(ROTARY_PINA);

    FastLED.addLeds<LEDTYPE, LEDPIN, GRB>(leds, NUMLEDS);

    FastLED.setDither(0);

    FastLED.setBrightness(pgm_read_byte(&gamma[127]));

    fill_solid(&leds[0], NUMLEDS, CHSV(hue, 255, 255));
    FastLED.show();

    // Serial.begin(9600);
}

void loop() {

    aState = digitalRead(ROTARY_PINA);

    if (aState == 1 && aState != aLastState) {
        if (aState != digitalRead(ROTARY_PINB)) {
            hue += 2;
        } else {
            hue -= 2;
        }
        // Serial.println(counter);
        fill_solid(&leds[0], NUMLEDS, CHSV(hue, 255, 255));
        FastLED.show();
    }
    aLastState = aState;

    // if (MODE == RAINBOW) {
    //     // this is much smoother than using fill_rainbow
    //     for (uint16_t led = 0; led < NUMLEDS; led++) {
    //         color.hue = map(led, 0, NUMLEDS, 0, 255) + startHue;
    //         leds[led] = color;
    //     }

    //     FastLED.show();

    //     FastLED.delay(20);
    //     startHue--;
    // } else if (MODE == SOLID) {
    //     uint8_t hue = readPotHue();
    //     fill_solid(&leds[0], NUMLEDS, CHSV(hue, 255, 255));
    //     FastLED.show();
    //     FastLED.delay(20);
    // }
}

// uint8_t readPotHue() {
//     uint16_t rawVal = analogRead(POTPIN);
//     return map(rawVal, 0, 1023, 0, 255);
// }

const PROGMEM uint8_t gamma[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
    2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5,
    5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
    17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
    25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
    37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
    51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
    69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
    90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
    115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
    144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
    177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
    215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255};