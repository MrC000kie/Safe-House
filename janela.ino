void abrejanela() {

  for (int k = 90; k >= 0; k--) {
    janela.write(k);
    porta.write(90-k);
    delay(10);
  }
  
}

void fechajanela() {

  for (int k = 0; k <= 90; k++) {
    janela.write(k);
    porta.write(90-k);
    delay(10);
  }
}
