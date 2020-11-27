void Alarme() {

  int previuosmillis = millis();
  while (millis() - previuosmillis  < 20000) {
    for (int i = 700; i < 800; i++) {
      tone(alarme, i);
      delay(15);
    }
    for (int i = 800; i > 700; i--) {
      tone(alarme, i);
      delay(15);
    }
  }
  tentativas = 4;
  IncorrectPass = 0;
}
