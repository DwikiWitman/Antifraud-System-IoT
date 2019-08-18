HardwareSerial & dbgTerminal = Serial;
HardwareSerial & espSerial = Serial1;
#include <Keypad.h>
#include "variable.h";
#include "function.h";
#include "HTML.h";
#include "startUp.h";


void setup() {
  SetPinMode();

  dbgTerminal.begin(115200); // Serial monitor
  espSerial.begin(115200); // ESP8266

  startUp();

  SetDigitalWrite();
}

void loop() {
  relayTimer();
  checkInput();
  int ch_id, packet_len;
  char *pb;
  espSerial.readBytesUntil('\n', buffer, BUFFER_SIZE);

  if (strncmp(buffer, "+IPD,", 5) == 0) {
    // request: +IPD,ch,len:data
    sscanf(buffer + 5, "%d,%d", &ch_id, &packet_len);
    if (packet_len > 0) {
      // read serial until packet_len character received
      // start from :
      pb = buffer + 5;
      while (*pb != ':') {
        checkInput();
        pb++;
      }
      pb++;

      if (strncmp(pb, "GET /?button1", 13) == 0) {
        if (led1State == LOW)
          led1State = HIGH;
        else
          led1State = LOW;
        clearSerialBuffer();

        digitalWrite(led1, led1State);
        Serial.println("LED 1");
        Serial.println(led1State);
        homepage1(ch_id);

      }


      else   if (strncmp(pb, "GET /?button2", 13) == 0) {
        if (led2State == LOW)
          led2State = HIGH;
        else
          led2State = LOW;
        clearSerialBuffer();

        digitalWrite(led2, led2State);
        Serial.println("LED 2");
        Serial.println(led2State);
        homepage1(ch_id);

      }

      else   if (strncmp(pb, "GET /?button3", 13) == 0) {
        if (led3State == LOW)
          led3State = HIGH;
        else
          led3State = LOW;
        clearSerialBuffer();

        digitalWrite(led3, led3State);
        Serial.println("LED 3");
        Serial.println(led3State);
        homepage1(ch_id);

      }


      else   if (strncmp(pb, "GET /?relay1", 12) == 0) {
        if (relayState[0] == LOW) {
          relayState[0] = HIGH;
          relayState[0] = LOW;
        }
        else {

          interval[0] = 0;
        }
        clearSerialBuffer();

        digitalWrite(relay[0], relayState[0]);
        Serial.println("Relay 1");
        Serial.println(relayState[0]);
        homepage1(ch_id);

      }

      else   if (strncmp(pb, "GET /?relay2", 12) == 0) {
        if (relayState[1] == LOW) {
          relayState[1] = HIGH;
          interval[1] = 0;
        }
        else
          relayState[1] = LOW;

        delay(100);
        clearSerialBuffer();

        digitalWrite(relay[1], relayState[1]);
        Serial.println("Relay 2");
        Serial.println(relayState[1]);
        homepage1(ch_id);

      }

      else   if (strncmp(pb, "GET /?relay3", 12) == 0) {
        if (relayState[2] == LOW) {
          interval[2] = 0;
          relayState[2] = HIGH;
        }
        else
          relayState[2] = LOW;
        clearSerialBuffer();

        digitalWrite(relay[2], relayState[2]);
        Serial.println("Relay 3");
        Serial.println(relayState[2]);
        homepage1(ch_id);
      }

      else   if (strncmp(pb, "GET /?on1", 9) == 0) {

        if (feedbackOn(ch_id,0))
          readTime(pb, 0);
      }

      else   if (strncmp(pb, "GET /?on2", 9) == 0) {

        if (feedbackOn(ch_id,1))
          readTime(pb, 1);
      }

      else   if (strncmp(pb, "GET /?on3", 9) == 0) {
        if (feedbackOn(ch_id,2))
          readTime(pb, 2);
      }

      else   if (strncmp(pb, "GET /?off1", 10) == 0) {
        feedbackOff(ch_id,0);
      }

      else   if (strncmp(pb, "GET /?off2", 10) == 0) {
        feedbackOff(ch_id,1);
      }

      else   if (strncmp(pb, "GET /?off3", 10) == 0) {

        feedbackOff(ch_id,2);
      }

      else if (strncmp(pb, "GET / ", 6) == 0) {
        dbgTerminal.print(millis());
        dbgTerminal.print(" : ");
        dbgTerminal.println(buffer);
        dbgTerminal.print( "get Status from ch:" );
        dbgTerminal.println(ch_id);
        clearSerialBuffer();
        homepage1(ch_id);
      }
    }
  }
  clearBuffer();
}
