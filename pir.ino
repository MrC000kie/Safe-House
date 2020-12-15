void PIR() {

  int val;
  val = digitalRead(PIRPin);
  if (val == HIGH) {
    intmov = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALARME MOVIMENTO");
    Serial.println("Movimento!");
    BT_movimento();

    Alarmeintrusao();
    /* lcd.setCursor(4, 0);
      lcd.print("                   ");
      lcd.setCursor(3, 1);
      lcd.print("              ");*/
  }
  else {

    //Serial.println("0");
    noTone(alarme);

  }
intmov = false;
}
