void matrixcode() {

  lcd.setCursor(0, 0);
  lcd.print("INSIRA A CHAVE:");


  customKey = customKeypad.getKey();


  if (customKey) {
    Pass[pass_count] = customKey;
    lcd.setCursor(pass_count, 1);
    lcd.print(Pass[pass_count]);
    pass_count++;                     //conta o numero de caracteres da password
    int j;
    for (j = 0; j <= pass_count; j++)
    {
      lcd.setCursor(j - 1, 1);
      lcd.print("*");
    }

  }


  if (pass_count == Password_Length - 1) {        //quando a password chega ao fim
    delay(500);                                   // da tempo para que apareca o ultimo caractere antes de limpar o ecra
    lcd.clear();

    if (!strcmp(Pass, Master_Pass)) { //compara com a password real
      lcd.print("CHAVE CORRETA");
      digitalWrite(RightCode, HIGH);
      digitalWrite(iluminacao, HIGH);
      chavecerta();
      porta_motor();
      digitalWrite(RightCode, LOW); //se for a certa aparece escrito correto e abre a porta por 5 segundos
      tentativas = TENTATIVAS-1;
      Pass[Password_Length] = NULL;


    }


    else{
      lcd.print("CHAVE ERRADA");
      lcd.setCursor(0, 1);
      digitalWrite(WrongCode, HIGH);
      lcd.print("TEM ");
      lcd.print(tentativas);
      lcd.print(" TENTATIVA");
      chaveerrada();
      Serial.println("else");
     
      // Password is incorrect

    if (tentativas == 0) {
      Serial.println("if");
     // digitalWrite(WrongCode, HIGH);
      BT_intrusao();
      Pass[Password_Length] = NULL;
      lcd.clear();
      Alarmeintrusao();

      tentativas = TENTATIVAS;
    }
tentativas--;
Serial.print("mamas");
    }

    // Clear data and LCD display
    lcd.clear();
    clearData();


  }

}







void chavecerta() {

  tone(alarme, 600);
  delay(400);
  tone(alarme, 800);
  delay(400);
  noTone(alarme);

}

void chaveerrada() {

  tone(alarme, 300);
  delay(1000);
  digitalWrite(WrongCode, LOW);
  noTone(alarme);


}
