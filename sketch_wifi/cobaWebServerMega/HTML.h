void homepage1(int ch_id) {
  String Header;


  Header =  "HTTP/1.1 200 OK\r\n";
  Header += "Content-Type: text/html\r\n";
  Header += "Connection: close\r\n";
  //Header += "Refresh: 5\r\n";

  String Content;

  Content = "<HTML>\r\n";
  Content += "<HEAD>\r\n";
  Content += "<meta name='apple-mobile-web-app-capable' content='yes' />\r\n";
  Content += "<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />\r\n";
  Content += "<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />\r\n";
  Content += "<TITLE>SAM's Home Automation Web Server</TITLE>\r\n";
  Content += "</HEAD>\r\n";
  Content += "<BODY>\r\n";
  Content += "<H1>Home Automation Web Server Arduino</H1>\r\n";
  Content += "<hr />\r\n";
  Content += "<br />\r\n";
  Content += "<H2>Arduino WIFI </H2>\r\n";
  Content += "<br />\r\n";
  if (led1State == LOW)
    Content += "<a href=\"/?button1\"\">LED 1</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?button1\"\">LED 1</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  if (led2State == LOW)
    Content += "<a href=\"/?button2\"\">LED 2</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?button2\"\">LED 2</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  if (led3State == LOW)
    Content += "<a href=\"/?button3\"\">LED 3</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?button3\"\">LED 3</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  if (relayState[0] == HIGH)
    Content += "<a href=\"/?relay1\"\">RELAY 1</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?relay1\"\">RELAY 1</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  if (relayState[1] == HIGH)
    Content += "<a href=\"/?relay2\"\">RELAY 2</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?relay2\"\">RELAY 2</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  if (relayState[2] == HIGH)
    Content += "<a href=\"/?relay3\"\">RELAY 3</a><br />\r\n";
  else
    Content += "<a style='color:red;' href=\"/?relay3\"\">RELAY 3</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?on1\"\">ON 1</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?on2\"\">ON 2</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?on3\"\">ON 3</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?off1\"\">OFF 1</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?off2\"\">OFF 2</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<a href=\"/?off3\"\">OFF 3</a><br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "<br />\r\n";
  Content += "</BODY>\r\n";
  Content += "</HTML>\r\n";

  Header += "Content-Length: ";
  Header += (int)(Content.length());
  Header += "\r\n\r\n";


  espSerial.print("AT+CIPSEND=");
  espSerial.print(ch_id);
  espSerial.print(",");
  espSerial.println(Header.length() + Content.length());
  delay(10);


  if (espSerial.find(">")) {
    espSerial.print(Header);
    espSerial.print(Content);
    delay(10);

  }

}

bool feedbackOn(int ch_id, int i) {
  String Header;
  bool answer;

  Header =  "HTTP/1.1 200 OK\r\n";
  Header += "Content-Type: text/JSON\r\n";
  Header += "Connection: close\r\n";
  //Header += "Refresh: 5\r\n";

  String Content;
  if (relayState[i] == LOW) {
    Content = "Error";
    Content += String(i + 1);
    Content += "on";
  }
  else {
    relayState[i] = LOW;
    clearSerialBuffer();
    answer = true;
    digitalWrite(relay[i], relayState[i]);
    Serial.println("On " + String(i));
    Serial.println(relayState[i]);

    Content += "Okay";
    Content += String(i + 1);
    Content += "on";
  }
  Header += "Content-Length: ";
  Header += (int)(Content.length());
  Header += "\r\n\r\n";


  espSerial.print("AT+CIPSEND=");
  espSerial.print(ch_id);
  espSerial.print(",");
  espSerial.println(Header.length() + Content.length());
  delay(10);


  if (espSerial.find(">")) {
    espSerial.print(Header);
    espSerial.print(Content);
    delay(10);
  }
  if(answer) return true;
}

void feedbackOff(int ch_id, int i) {
  String Header;

  Header =  "HTTP/1.1 200 OK\r\n";
  Header += "Content-Type: text/JSON\r\n";
  Header += "Connection: close\r\n";
  //Header += "Refresh: 5\r\n";

  String Content;
  relayState[i] = HIGH;
  clearSerialBuffer();
  interval[i] = 0;
  digitalWrite(relay[i], relayState[i]);
  Serial.println("Off " + String(i+1));
  Serial.println(relayState[i]);

  Content += "Okay";
  Content += String(i + 1);
  Content += "off";

  Header += "Content-Length: ";
  Header += (int)(Content.length());
  Header += "\r\n\r\n";


  espSerial.print("AT+CIPSEND=");
  espSerial.print(ch_id);
  espSerial.print(",");
  espSerial.println(Header.length() + Content.length());
  delay(10);


  if (espSerial.find(">")) {
    espSerial.print(Header);
    espSerial.print(Content);
    delay(10);
  }
}
