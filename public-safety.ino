#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

String afields[] = {"University", "Park", "Job", "Sport", "Party", "Transport"};

const int ledPin = 13;
const int fieldButtonPin = 1;
const int diceButtonPin = 3;
const int cardButtonPin = 5;
int fieldButtonState = 0;
int diceButtonState = 0;
int cardButtonState = 0;

void clearLCDLine(int line)
{
    for(int n = 0; n < 16; n++)
    {
        lcd.setCursor(n, line);
        lcd.print(" ");
    }
    lcd.setCursor(0, line);
}

void setup()
{
    // initialize the LED pin as an output
    pinMode(ledPin, OUTPUT);
    // initialize the button pins as an input
    pinMode(fieldButtonPin, INPUT_PULLUP);
    pinMode(diceButtonPin, INPUT_PULLUP);
    pinMode(cardButtonPin, INPUT_PULLUP);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
}

void getField()
{
    lcd.setCursor(0, 0);
    clearLCDLine(0);
    // Print result of selected action field
    randomSeed(analogRead(0));
    lcd.print("Field:" + afields[random(0, 6)]);
}

void getDice()
{
    lcd.setCursor(0, 1);
    clearLCDLine(1);
    // Print result of rolled dice
    randomSeed(analogRead(0));
    lcd.print("NPC Rolls: " + String(random(1, 7)));
}

void getCard()
{
    lcd.setCursor(0, 1);
    clearLCDLine(1);
    // Print result of selected card
    randomSeed(analogRead(0));
    lcd.print("Card: " + String(random(1, 4)));
}

void loop() 
{
    fieldButtonState = digitalRead(fieldButtonPin);
    if (fieldButtonState == LOW)
    {
        getField();
    }

    diceButtonState = digitalRead(diceButtonPin);
    if (diceButtonState == LOW)
    {
        getDice();
    }

    cardButtonState = digitalRead(cardButtonPin);
    if (cardButtonState == LOW)
    {
        getCard();
    }
}