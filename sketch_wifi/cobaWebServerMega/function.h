// Get the data from the WiFi module and send it to the debug serial port
String GetResponse(String AT_Command, int wait) {
  String tmpData;

  espSerial.println(AT_Command);
  delay(10);
  while (espSerial.available() > 0 )  {
    char c = espSerial.read();
    tmpData += c;

    if ( tmpData.indexOf(AT_Command) > -1 )
      tmpData = "";
    else
      tmpData.trim();

  }
  return tmpData;
}



void clearSerialBuffer(void) {
  while ( espSerial.available() > 0 ) {
    espSerial.read();
  }
}


void clearBuffer(void) {
  for (int i = 0; i < BUFFER_SIZE; i++ ) {
    buffer[i] = 0;
  }
}

boolean connectWiFi(String NetworkSSID, String NetworkPASS) {
  String cmd = "AT+CWJAP=\"";
  cmd += NetworkSSID;
  cmd += "\",\"";
  cmd += NetworkPASS;
  cmd += "\"";

  dbgTerminal.println(cmd);
  dbgTerminal.println(GetResponse(cmd, 10));
}

void readTime(char pb[], int i) {
  tempor += pb[9];
  tempor += pb[10];
  dbgTerminal.println("tempor : " + tempor);
  
  interval[i] = tempor.toInt();
  previousMillis[i] = millis();
  tempor = "";
  Serial.println("interval[i] : " + String(interval[i]));
  Serial.println("previousMillis[i] : " + String(previousMillis[i],0));
}

void relayTimer() {
  float intervalInMS;
  float timePassed;
  for (int i = 0; i < (sizeof(previousMillis) / sizeof(float)); i++)
  {
    if (interval[i] != 0)
    {
      intervalInMS = interval[i]*60000;
      timePassed = millis() - previousMillis[i];
      Serial.println("time passed: " + String(timePassed));     
      if (timePassed > intervalInMS)
      {
        Serial.println("interval: " + String(intervalInMS));
        Serial.println("Passed");
        relayState[i] = HIGH;
        digitalWrite(relay[i], relayState[i]);
        interval[i] = 0;
      }
    }
  }
}
char getCharKeypad4x4() {
  char keypressed = myKeypad.getKey();
  return (keypressed != NO_KEY) ? keypressed : 'X';
}
void checkInput() {
  String temp = "";
  ch = getCharKeypad4x4();
  if (!ch.equals("X")) {
    temp = ch;
    while (!ch.equals("A")) {
      ch = getCharKeypad4x4();
      if (ch.equals("C")) {
        break;
      }
    }
    if (ch.equals("A")) {
      if (temp.equals("1")) {
        digitalWrite(relay[0], HIGH);
        dbgTerminal.println("relay" + temp + "off");
      }
      if (temp.equals("2")) {
        digitalWrite(relay[1], HIGH);
        dbgTerminal.println("relay" + temp + "off");
      }
      if (temp.equals("3")) {
        digitalWrite(relay[2], HIGH);
        dbgTerminal.println("relay" + temp + "off");
      }
    }
  }

}
