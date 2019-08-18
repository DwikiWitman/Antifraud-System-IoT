void startUp() {
  dbgTerminal.println(F("BOSS Home Automation on ESP8266 & Arduino Mega."));

  clearSerialBuffer();  //Function to Clear the ESP8266 Buffer
  dbgTerminal.println("AT+RST :");
  dbgTerminal.println(GetResponse("AT+RST", 10));
  //connect to WIFI router
  dbgTerminal.println("AT+CWJAP=\"LENOVOPC1232\",\"CaliforniA\"\r\n");
  delay(15000);
  //test if the module is ready

  dbgTerminal.println("AT : ");
  dbgTerminal.println( GetResponse("AT", 10) );

  //Change to mode 1 (Client Mode)
  dbgTerminal.println("AT+CWMODE=3 : ");
  dbgTerminal.println( GetResponse("AT+CWMODE=1", 10) );

  //set the multiple connection mode
  dbgTerminal.println(F("AT+CIPMUX=1 : "));
  dbgTerminal.println( GetResponse("AT+CIPMUX=1", 10) );

  //set the server of port 8888 check "no change" or "OK",  it can be changed according to your configuration
  dbgTerminal.println(F("AT+CIPSERVER=1,8888 : "));
  dbgTerminal.println( GetResponse("AT+CIPSERVER=1,8888", 10) );


  //print the ip addr
  dbgTerminal.println(F("ip address : "));
  dbgTerminal.println( GetResponse("AT+CIFSR", 20) );
  delay(200);



  dbgTerminal.println();
  dbgTerminal.println(F("Start BOSS Arduino Webserver"));
}

void SetPinMode(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
   for (int i = 0; i < (sizeof(relay) / sizeof(int)); i++) {
    pinMode(relay[i], OUTPUT);
  }
}

void SetDigitalWrite(){
  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
  digitalWrite(led3, led3State);
  for (int i = 0; i < (sizeof(relay) / sizeof(int)); i++) {
    digitalWrite(relay[i], relayState[i]);
  }
}
