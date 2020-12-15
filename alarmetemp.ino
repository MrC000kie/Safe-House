void alarmetemp() {

  boolean L = false;
abrejanela();

  while (1) {
    for (int i = 800; i > 700; i--) {
      tone(alarme, i);
      delay(15);
      digitalWrite(RGBR, HIGH);
      digitalWrite(RGBB, LOW);
      lcd.setCursor(0, 0);
      lcd.print("ALARME INCENDIO");

      lcd.setCursor(0, 1);
      lcd.print("CHAVE:");


      if (i < 725 || (i > 750 && i < 775)) {
        //digitalWrite(iluminacao, HIGH);
        digitalWrite(RGBR, HIGH);
        digitalWrite(RGBB, LOW);
      }
      else {
        digitalWrite(RGBR, LOW);
        digitalWrite(RGBB, HIGH);
        //digitalWrite(iluminacao, LOW);
      }

      customKey = customKeypad.getKey();
      if (customKey) {
        Pass[pass_count] = customKey;
        lcd.setCursor(pass_count + 6, 1);
        lcd.print(Pass[pass_count]);
        pass_count++;                     //conta o numero de caracteres da password
        int j;
        for (j = 1; j <= pass_count; j++)
        {
          lcd.setCursor(j + 5, 1);
          lcd.print("*");
        }
      }


      if (pass_count == Password_Length - 1) {        //quando a password chega ao fim
        delay(100);                                   // da tempo para que apareca o ultimo caractere antes de limpar o ecra
        lcd.clear();

        if (!strcmp(Pass, Master_Pass)) { //compara com a password real
          lcd.print("CHAVE CORRETA");
          digitalWrite(RGBR, LOW);
          digitalWrite(RGBB, LOW);
          digitalWrite(RightCode, HIGH);
          chavecerta();
          fechajanela();
          digitalWrite(RightCode, LOW); 
          Pass[Password_Length] = NULL;
          L = true;
        }
        if (L == true) break;

        else {
         digitalWrite(RGBR, LOW);
         digitalWrite(RGBB, LOW);
          lcd.clear();
          clearData();
          lcd.setCursor(0, 0);

          digitalWrite(WrongCode, HIGH);
          lcd.print("CHAVE ERRADA");
          chaveerrada();
          digitalWrite(WrongCode, LOW);
          lcd.clear();
          clearData();
        }
      }
      if (L == true) break;
    }
    if (L == true) break;

  }
  


  intmov = false;
  lcd.clear();
}
