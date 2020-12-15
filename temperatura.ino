void temperatura()
{

  tempC = HT.readTemperature();
  if ( tempC > TEMP_INCENDIO ) {
    BT_incendio();
    falsealarm = true;
    lcd.setCursor(0, 0);
    alarmetemp();

  
  }

}
