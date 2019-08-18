void caseA() {
  display_TicketNotValid();
  delay(2000);
  display_PleaseScanTicket();
}

void caseB() {
CaseB:
  display_PleaseScanIdStylist();
  //Serial.write("sini");
  isActiveKeypad = 1;
  display_YourIdStylist();
  while (isActiveKeypad != 0) {
    //Serial.write("sono");
    relayTimer();
    ch = (String) getCharKeypad4x4();
    if (ch.equals("X")) {
      str3 = getSerial();
      if (!str3.equals("")) {
        id_stylist = str3;
        str3 = "";
        ch = "A";
      }
    }
    switch (ch[0]) {
      case 'A':
        display_YourIdStylist();
        sendIDStylistToVS(id_stylist);
        //Serial.println(str3);
        isActiveKeypad = 0;
        display_PleaseWait();
        delay(1000);

        //Perintah desktop taruh disini...
        while ( !(str2.equals("C") || str2.equals("D")) ) {
          relayTimer();
          str2 = (char) Serial.read();
          //Serial.write(str2[0]);
        }

        //Case C atau D...
        //Serial.println(str2);
        switch (str2[0])
        {
          case 'C':
            display_IdStylistNotValid();
            id_stylist = "";
            str2 = "";
            delay(2000);
            goto CaseB;
            break;
          case 'D':
            if (kursi_IsAvailable()) {
              isActiveKeypad = 1;
              display_InputNomorKursi();
              while (isActiveKeypad != 0) {
                relayTimer();
                ch = "X";
                while (ch.equals("X")) {
                  relayTimer();
                  ch = (String) getCharKeypad4x4();
                  if (!ch.equals("X")) {
                    display_NomorKursiYangDipilih(ch);
                  }
                }
                if (inputIsNumber(ch[0])) {
                  if (kursi_IsAvailable(ch.toInt())) {
                    sendDataToVS( id_stylist, ch[0]);   //digitalWrite(pinKursi[ch.toInt()], false);
                    isActiveKeypad = 0;
                    id_stylist = "";
                    str2 = "";
                    display_NomorKursiYangDipilih(ch);
                    delay(1000);
                    display_PleaseWait();
                    delay(1000);
                    display_Terimakasih();

                    //Begin Case E disini..
                    setRelay(pinKursi[ch.toInt() - 1], false);
                    setLed(pinLed[ch.toInt() - 1], true);
                    interval[ch.toInt() - 1] = fraud_time;
                    previousMillis[ch.toInt() - 1] = millis() / 1000;
                    ch = (String) 'X';
                    delay(2000);
                    display_PleaseScanTicket();
                    //End Case E disini..
                  }
                  else {
                    display_InputKursiLagi();
                    delay(1000);
                    display_InputNomorKursi();
                    ch = (String) 'X';
                  }
                }
                else if (ch.equals("C"))
                {
                  display_PleaseScanTicket();
                  isActiveKeypad = 0;
                  break;
                }
              }
            }
            else {
              isActiveKeypad = 0;
              display_KursiPenuh();
            }
            break;
          default:
            break;
        }

        break;
      case 'C':
        isActiveKeypad = 0;
        id_stylist = "";
        display_PleaseScanTicket();
        ch = "X";
        break;
      case 'D':
        delIdStylistByKeypad();
        ch = (String) 'X';
        display_YourIdStylist();
        break;
      default:
        if (!ch.equals("X")) {
          setIdStylistByKeypad(ch);
          display_YourIdStylist();
          ch = (String) 'X';
        }
        break;
    }
  }
}

void caseF() {
  sendStatusKursiToVS();
}

void caseG() {
  setRelay(pinKursi[(str[1] - '0') - 1], true);
  setLed(pinLed[(str[1] - '0') - 1], false);
  interval[(str[1] - '0') - 1] = 0;
}

void caseH() {
  //input id stylist yg akan extend waktu
CaseH:
  isActiveKeypad = 1;
  display_PleaseScanIdStylist();
  display_YourIdStylist();
  while (isActiveKeypad != 0) {
    relayTimer();
    ch = (String) getCharKeypad4x4();
    //jika tdk ada input dari keypad maka masuk if untuk menerima data dari vs..
    if (ch.equals("X")) {
      str3 = getSerial();
      if (!str3.equals("")) {
        id_stylist = str3;
        str3 = "";
        ch = "A";
      }
    }

    switch (ch[0]) {
      case 'A':
        display_YourIdStylist();
        sendIDStylistToVS(id_stylist);

        str2="";
        //Perintah desktop taruh disini...
        while ( !(str2.equals("C") || str2.equals("D")) ) {
          //Serial.print("Disini");
          relayTimer();
          str2 = (char) Serial.read();  
        }

        switch (str2[0])
        {
          case 'C':
            display_IdStylistNotValid();
            id_stylist = "";
            str2 = "";
            str3 = "";
            delay(2000);
            goto CaseH;
            break;
          case 'D':
            display_PleaseWait();
            ch = (String) 'X';
            delay(2000);

            //input kursi yg di extend waktunya
            display_InputNomorKursi();
            delay(1000);
            while (ch.equals("X")) {
              relayTimer();
              ch = (String) getCharKeypad4x4();
              switch (ch[0]) {
                case 'C':
                  isActiveKeypad = 0;
                  id_stylist = "";
                  display_PleaseScanTicket();
                  break;
                default:
                  if (inputIsNumber(ch[0])) {
                    display_NomorKursiYangDipilih(ch);
                    delay(1000);
                    if (kursi_IsAvailable(ch.toInt())) {
                      //sendDataToVS( id_stylist, ch[0]);   //digitalWrite(pinKursi[ch.toInt()], false);
                      isActiveKeypad = 0;
                      id_stylist = "";
                      display_PleaseWait();

                      //Begin Case H disini..
                      if (interval[ch.toInt() - 1] == 0) {
                        //Begin Case E disini..
                        setRelay(pinKursi[ch.toInt() - 1], false);
                        setLed(pinLed[ch.toInt() - 1], true);
                        interval[ch.toInt() - 1] = extend_time;
                        previousMillis[ch.toInt() - 1] = millis() / 1000;

                        delay(1000);
                        display_ExtendTime();
                        delay(1000);
                        display_Terimakasih();
                        delay(2000);
                        display_PleaseScanTicket();
                        //End Case E disini..
                      }
                      else {
                        delay(1000);
                        display_ErrorExtendTime();
                        delay(2000);
                        display_PleaseScanTicket();
                      }
                      //End Case H disini..
                    }
                    else {
                      display_InputKursiLagi();
                      delay(1000);
                      display_InputNomorKursi();
                      delay(1000);
                      ch = (String) 'X';
                    }
                  }
                  else {
                    ch = (String) 'X';
                  }
                  break;
              }
            }
            break;
        }

        break;
      case 'C':
        isActiveKeypad = 0;
        id_stylist = "";
        display_PleaseScanTicket();
        break;
      case 'D':
        delIdStylistByKeypad();
        ch = (String) 'X';
        display_YourIdStylist();
        break;
      default:
        if (!ch.equals("X")) {
          setIdStylistByKeypad(ch);
          display_YourIdStylist();
          ch = (String) 'X';
        }
        break;
    }
  }
}

void caseI() {
  //input id stylist yg akan extend waktu
  isActiveKeypad = 1;
  display_PleaseScanIdStylist();
  display_YourIdStylist();
  while (isActiveKeypad != 0) {
    relayTimer();
    ch = (String) getCharKeypad4x4();
    //jika tdk ada input dari keypad maka masuk if untuk menerima data dari vs..
    if (ch.equals("X")) {
      str3 = getSerial();
      if (!str3.equals("")) {
        id_stylist = str3;
        str3 = "";
        ch = "A";
      }
    }
    switch (ch[0]) {
      case 'A':
        display_YourIdStylist();
        //sendIDStylistToVS(id_stylist);
        display_PleaseWait();
        ch = (String) 'X';
        delay(2000);

        //input kursi yg akan dimatikan
        display_InputNomorKursi();
        delay(1000);
        while (ch.equals("X")) {
          relayTimer();
          ch = (String) getCharKeypad4x4();
          switch (ch[0]) {
            case 'C':
              isActiveKeypad = 0;
              id_stylist = "";
              display_PleaseScanTicket();
              break;
            default:
              if (inputIsNumber(ch[0])) {
                display_NomorKursiYangDipilih(ch);
                delay(1000);
                if (!kursi_IsAvailable(ch.toInt())) {
                  //sendDataToVS( id_stylist, ch[0]);   //digitalWrite(pinKursi[ch.toInt()], false);
                  isActiveKeypad = 0;
                  id_stylist = "";
                  display_PleaseWait();

                  //Begin Case G disini..
                  if (interval[ch.toInt() - 1] > 0) {
                    setRelay(pinKursi[ch.toInt() - 1], true);
                    setLed(pinLed[ch.toInt() - 1], false);
                    interval[ch.toInt() - 1] = 0;
                    delay(1000);
                    display_Terimakasih();
                    delay(2000);
                    display_PleaseScanTicket();
                  }
                  else {
                    delay(1000);
                    display_ErrorMatikanRelayKursi();
                    delay(2000);
                    display_PleaseScanTicket();
                  }
                  //End Case G disini..
                }
                else {
                  display_InputKursiLagi();
                  delay(1000);
                  display_InputNomorKursi();
                  delay(1000);
                  ch = (String) 'X';
                }
              }
              else {
                ch = (String) 'X';
              }
              break;
          }
        }
        break;
      case 'C':
        isActiveKeypad = 0;
        id_stylist = "";
        display_PleaseScanTicket();
        break;
      case 'D':
        delIdStylistByKeypad();
        ch = (String) 'X';
        display_YourIdStylist();
        break;
      default:
        if (!ch.equals("X")) {
          setIdStylistByKeypad(ch);
          display_YourIdStylist();
          ch = (String) 'X';
        }
        break;
    }
  }
}
