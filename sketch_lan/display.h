void display_Clear() {
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(" ");
    lcd.setCursor(i, 1);
    lcd.print(" ");
  }
}

void display_Terimakasih() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Ixobox");
  lcd.setCursor(0, 1);
  lcd.print("Terimakasih!");
}

void display_ExtendTime() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Waktu bertambah");
  lcd.setCursor(0, 1);
  unsigned long ext = extend_time ;
  lcd.print((String) ext + " detik.");
}

void display_ErrorExtendTime() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Gagal! Cek");
  lcd.setCursor(0, 1);
  lcd.print("waktu kursi!");
}

void display_ErrorMatikanRelayKursi() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Tdk mati! Cek");
  lcd.setCursor(0, 1);
  lcd.print("waktu kursi!");
}

void display_PleaseWait() {
  display_Clear();
  //lcd.setCursor(0, 0);
  //lcd.print("Ixobox");
  lcd.setCursor(0, 1);
  lcd.print("Please Wait...");
}

void display_PleaseScanTicket() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Ixobox");
  lcd.setCursor(0, 1);
  lcd.print("Scan ticket.");
}

void display_PleaseScanIdStylist() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Ixobox");
  lcd.setCursor(0, 1);
  lcd.print("Scan stylist.");
}

void display_TicketNotValid() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Ticket sudah");
  lcd.setCursor(0, 1);
  lcd.print("kadaluarsa.");
  //Serial.write("Ticket tidak valid.");  //lcd.noDisplay(); //delay(500); //lcd.display(); //delay(500);
}

void display_YourIdStylist() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Your id stylist: ");
  lcd.setCursor(0, 1);
  lcd.print(id_stylist);
  //Serial.write("Silahkan Tap Stylist Card.");
}

void display_IdStylistNotValid() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Nomor stylist");
  lcd.setCursor(0, 1);
  lcd.print("tidak valid.");
  //Serial.write("Stylist tidak valid.");
}

void display_KursiPenuh() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Maaf, kursi penuh.");
  //Serial.write("Kursi penuh, silahkan tunggu customer lain.");
}

void display_InputNomorKursi() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Input kursi:");
  //Serial.write("Input nomor kursi.");
}

void display_InputKursiLagi() {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.print("Maaf, pilih");
  lcd.setCursor(0, 1);
  lcd.print("kursi lain.");
  //Serial.write("Silahkan input nomor kursi yang benar.");
}

void display_NomorKursiYangDipilih(String kursi) {
  display_Clear();
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Input kursi: " + kursi);
  //Serial.write("Silahkan input nomor kursi yang benar.");
}
