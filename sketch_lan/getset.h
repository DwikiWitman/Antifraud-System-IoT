String getSerial() {
  String output;
  while (Serial.available()) {
    delay(5);
    output += char(Serial.read());
  }
  return output;
}

bool kursi_IsAvailable() {
  for (int i = 0; i < (sizeof(pinKursi) / sizeof(int)); i++) {
    if (digitalRead(pinKursi[i])) {
      return true;
    }
  }
  return false;
}

bool kursi_IsAvailable(int pin) {
  int jumlah = (sizeof(pinKursi) / sizeof(int));
  if ( (pin <= jumlah) && (pin > 0) ){
    if(digitalRead(pinKursi[pin - 1]))
      return true;
    else
      return false;
  }
  else{
    return false;
  }
  //return (digitalRead(pinKursi[pin - 1]) && ((pin) <= (sizeof(pinKursi) / sizeof(int)))) ? true : false;
}

void setLed(int pin, bool state) {
  digitalWrite(pin, state);
}

char getCharKeypad4x4() {
  char keypressed = myKeypad.getKey();
  return (keypressed != NO_KEY) ? keypressed : 'X';
}

void setRelay(int pin, bool state) {
  digitalWrite(pin, state);
}

void setIdStylistByKeypad(String ch) {
  for (int i = 0; i < (sizeof(keymapNumber) / sizeof(char)); i++)  {
    if (strcmp(keymapNumber[i], ch[0]) == 0) {
      id_stylist += ch[0];
      break;
    }
  }
}

bool inputIsNumber(char ch) {
  for (int i = 0; i < (sizeof(keymapNumber) / sizeof(keymapNumber[0])); i++)  {
    if (keymapNumber[i] == ch) {
      return true;
    }
  }
  return false;
}

void delIdStylistByKeypad() {
  //  int i = id_stylist.length()-1;
  //  id_stylist[i] = '\0';
  id_stylist.remove(id_stylist.length() - 1);
}

void interruptKeypad() {
  sendDataToVS( id_stylist, getCharKeypad4x4());
}

void relayTimer() {
  unsigned long currentMillis = millis() / 1000;
  //Serial.println(currentMillis);
  for (int i = 0; i < (sizeof(previousMillis) / sizeof(long)); i++)
  {
    if (interval[i] != 0)
    {
      if ((unsigned long)(currentMillis - previousMillis[i]) >= interval[i])
      {
        setRelay(pinKursi[i], true);
        setLed(pinLed[i], false);
        previousMillis[i] = currentMillis;
        interval[i] = 0;
      }
      //timeLeft[i] = interval[i] - currentMillis + previousMillis[i];
      //sendTimeLeftToVS(i, timeLeft[i]);
    }
  }
}
