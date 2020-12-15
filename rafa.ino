#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#define Password_Length 5
#define Type DHT11
#define RightCode 13
#define alarme 41
#define WrongCode 12
#define DHTsensor A0
#define portapin 53
#define PIRPin 33
#define RGBR 46
#define RGBB 47
#define iluminacao 37
#define TEMP_INCENDIO 30
#define TENTATIVAS 2
#define janelapin 35


SoftwareSerial BTserial(A1, A2); // RX, TX
Servo porta;
Servo janela;
LiquidCrystal lcd(22, 23, 27, 26, 25, 24);

void alarmetemp();
void matrixcode();
void clearData();
void Alarmeintrusao();
void porta_motor();
void temperatura();
void PIR();
void incendio_abre();
void incendio_fecha();
void BT();
void chavecerta();
void chaveerrada();
void abrejanela();
void fechajanla();



DHT HT(DHTsensor, Type);
int portaaberta = 0;
int porta_aberta_incendio = 0;
int IncorrectPass = 0;
int tentativas = 1;
char Pass[Password_Length];
char Master_Pass[Password_Length] = "2330";
byte pass_count = 0;
boolean intmov = false;
boolean falsealarm = false;
char customKey;
float tempC = 0;
float humidade = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}

};

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  //BTserial.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  porta.attach(portapin);
  janela.attach(janelapin);
  pinMode(RightCode, OUTPUT);
  pinMode(WrongCode, OUTPUT);
  porta.write(0);
  janela.write(90);
  HT.begin();
  pinMode(RGBR, OUTPUT);
  pinMode(RGBB, OUTPUT);
  pinMode(iluminacao, OUTPUT);

}



void loop() {
  BT_inicio();
  if (falsealarm == true) {

    unsigned long t = millis();

    while ( millis()-t <= 30000) {

      matrixcode();
      noTone(alarme);
      if (portaaberta == 0) {
        PIR();
        Serial.println("if");
      }
    }
    falsealarm=false;
  }
  
  else {
    matrixcode();
    noTone(alarme);
    
    if (portaaberta == 0) {
      PIR();
    }
    
    temperatura();
    //Serial.print(tempC); Serial.println("ºC");
  }
}
