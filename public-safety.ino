#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

// The background color of the LCD screen can be adjusted by changing "colorR", "colorG" and "colorB"
const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

// New action fields can be added.
// If new action fields are added, it is important to change the random value range in "getField" function
//  e.g. if "Supermarket" is added to "afields", set "lcd.print("Field:" + afields[random(0, 7)]);"
String afields[] = {"University", "Park", "Job", "Sport", "Party", "Transport"};

// "pin" variables specify the number of digital pins of the Arduino board
// The cables of the LED and the given buttons should be connected to these numbers
const int ledPin = 13;
const int fieldButtonPin = 1;
const int diceButtonPin = 3;
const int cardButtonPin = 5;

int fieldButtonState = 0;
int diceButtonState = 0;
int cardButtonState = 0;

// Clears the given LCD line
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

    // set up the LCD's number of columns and rows
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
    lcd.print("Card: " + String(random(1, 5)));
}

// This function runs in a loop to detect button presses
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