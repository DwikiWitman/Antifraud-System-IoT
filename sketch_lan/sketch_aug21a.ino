#include <Keypad.h>
#include <LiquidCrystal.h>
#include "variable.h"
#include "display.h"
#include "sendtovs.h"
#include "getset.h"
#include "case.h"

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < (sizeof(pinKursi) / sizeof(int)); i++) {
    pinMode(pinKursi[i], OUTPUT);
    setRelay(pinKursi[i], true);
  }
  for (int i = 0; i < (sizeof(pinLed) / sizeof(int)); i++) {
    pinMode(pinLed[i], OUTPUT);
    setLed(pinLed[i], false);
  }
  lcd.begin(16, 2);
  display_PleaseScanTicket();
  //pinMode(led, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), interruptKeypad, CHANGE);
}

void loop() {
  delay(10);
  relayTimer();
  str = getSerial();
  //Serial.write("Start");
  ch = (String) getCharKeypad4x4();
  if (ch == "#") caseH();
  else if(ch == "*") caseI();
  switch (str[0]) {
    //Case tiket tidak valid.
    case 'A':
      caseA();
      break;
    //Case input id stylist (case B), Case id stylist tidak valid (case C), Case pilih kursi (case D), Case hidupkan kursi (case E).
    case 'B':
      caseB();
      break;
    //Case send status kursi ke VS.
    case 'F':
      caseF();
      break;
    //Case matikan kursi.
    case 'G':
      caseG();
      break;
    //Case beri extra time.
    case 'H':
      caseH();
      break;
    default:
      break;
  }
}
