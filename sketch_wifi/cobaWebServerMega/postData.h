void Send2Server()
{
  dbgTerminal.println("AT+CIPSTART=\"TCP\",\"www.reqres.in\",\"80\"");//start up the connection
  delay(2000); 
  
  dbgTerminal.println("AT+CIPSEND");//begin send data to remote server
  delay(4500);

  dbgTerminal.print("PUT /api/users/2");//here is the feed you apply from pachube
  delay(500);
  
  dbgTerminal.print("name=");   //DATA feed name
  dbgTerminal.print("morpheus");   //DATA to send
  delay(10);

  dbgTerminal.print("&job=");   //DATA feed name
  dbgTerminal.print("zion resident");   //DATA to send
  delay(10);
    
  dbgTerminal.print(" HTTP/1.1\r\n");
  delay(500);
  
  dbgTerminal.print("Host: www.reqres.in\r\n");
  delay(500);
  

  //mySerial.print("Connection: keep-alive");  //working
  dbgTerminal.print("Connection: close");         //working as well
  dbgTerminal.print("\r\n");
  dbgTerminal.print("\r\n");
  //mySerial.println();
  delay(500);


  //mySerial.println((char)26);//sending
  dbgTerminal.print(0x1A,BYTE);
  delay(500);//waitting for reply, important! the time is base on the condition of internet 
  dbgTerminal.println(); 

  mySerial.println("AT+CIPCLOSE");//close the connection
  delay(100);
  
  mySerial.println("AT+CIPSHUT=0");
  delay(100); 

}
