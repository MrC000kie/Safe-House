void porta_motor() {
  int i;
  for (i = 0; i <= 90; i++) {
    porta.write(i);
    delay(10);
  }
  delay(5000);
  for (i; i >= 0; i--) {
    porta.write(i);
    delay(10);
    portaaberta=1;
  }
}
