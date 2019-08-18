
void sendStatusKursiToVS() {
  Serial.write('K');
  for (int i = 0; i < (sizeof(pinKursi) / sizeof(int)); i++) {
    digitalRead(pinKursi[i]) ? Serial.write(48) : Serial.write(49);
  }
}

void sendDataToVS(String Id_stylist, char keypressed) {
  if (keypressed != 'X') {
    Serial.write('P');
    Serial.write(keypressed);
    Serial.write('Q');
    Serial.write('I');
    for (int i = 0; i < Id_stylist.length(); i++) {
      Serial.write(Id_stylist[i]);
    }
    Serial.write('.');
  }
}

void sendIDStylistToVS(String Id_stylist) {
  Serial.write('T');
  for (int i = 0; i < Id_stylist.length(); i++) {
    Serial.write(Id_stylist[i]);
  }
  Serial.write('.');
}

void sendTimeLeftToVS(int i, int waktuSisa) {
  Serial.write('Z');
  Serial.write(i);
  Serial.write(waktuSisa);
  Serial.write('.');
}

