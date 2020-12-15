void BT_inicio() {
  humidade = HT.readHumidity();
  tempC = HT.readTemperature();
  BTserial.print(tempC);
  BTserial.print(",");
  BTserial.print(humidade);
  BTserial.print(",");
  BTserial.print("DESATIVADO,");
  BTserial.print("DESATIVADO,");
  BTserial.print("DESATIVADO;");

}
void BT_intrusao() {
  humidade = HT.readHumidity();
  tempC = HT.readTemperature();
  BTserial.print(tempC);
  BTserial.print(",");
  BTserial.print(humidade);
  BTserial.print(",");
  BTserial.print("ATIVADO,");
  BTserial.print("DESATIVADO,");
  BTserial.print("DESATIVADO;");

}
void BT_movimento() {
  humidade = HT.readHumidity();
  tempC = HT.readTemperature();
  BTserial.print(tempC);
  BTserial.print(",");
  BTserial.print(humidade);
  BTserial.print(",");
  BTserial.print("DESATIVADO,");
  BTserial.print("ATIVADO,");
  BTserial.print("DESATIVADO;");

}
void BT_incendio() {
  humidade = HT.readHumidity();
  tempC = HT.readTemperature();
  BTserial.print(tempC);
  BTserial.print(",");
  BTserial.print(humidade);
  BTserial.print(",");
  BTserial.print("DESATIVADO,");
  BTserial.print("DESATIVADO,");
  BTserial.print("ATIVADO;");

}
