#include <SevSeg.h>
SevSeg sevseg;
int i = 0;
int b1 = A0; // for reset
int b2 = A1; // for ++
int b3 = A2; // for --

void setup() {
  // put your setup code here, to run once:
  byte numberDigits = 2;
  byte digitPins[] = {11, 12};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  sevseg.begin(COMMON_ANODE, numberDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(b2) == LOW)
  {
    delay(200);
    i++;
  }
  if (digitalRead(b3) == LOW)
{
  delay(200);
    i--;
  }
  if (digitalRead(b1) == LOW)
{
  delay(200);
    i = 0;
}
sevseg.setNumber(i);
sevseg.refreshDisplay();
}
