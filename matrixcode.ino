void matrixcode() {

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");


  customKey = customKeypad.getKey();
  if (customKey) {
    Pass[pass_count] = customKey;
    lcd.setCursor(pass_count, 1);
    lcd.print(Pass[pass_count]);
    pass_count++;                     //conta o numero de caracteres da password


  }


  if (pass_count == Password_Length - 1) {        //quando a password chega ao fim
    delay(500);                                   // da tempo para que apareca o ultimo caractere antes de limpar o ecra
    lcd.clear();

    if (!strcmp(Pass, Master_Pass)) { //compara com a password real
      lcd.print("Correct");
      digitalWrite(RightCode, HIGH);
      porta_motor();
      digitalWrite(RightCode, LOW); //se for a certa aparece escrito correto e abre a porta por 5 segundos
      IncorrectPass = 0;
      Pass[Password_Length]= NULL;
      
    }
    else {
      // Password is incorrect
      lcd.print("Incorrect");
      lcd.setCursor(0, 1);
      lcd.print("Faltam : ");
      lcd.print(tentativas);
      tentativas--;        //se estiver errada diz que esta errada no lcd e volta ao inicio
      digitalWrite(WrongCode, HIGH);
      delay(1000);
      digitalWrite(WrongCode, LOW);
      IncorrectPass++;
     
     if (IncorrectPass==5) {
      lcd.clear();
      lcd.print("Alarme Intrusao");
      Alarme();
     }
    // Clear data and LCD display
    lcd.clear();
    clearData();
    
    
  }
}

}
