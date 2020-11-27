#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#define Password_Length 5

Servo porta;
void matrixcode();
void clearData();
void Alarme();
void porta_motor();




char Pass[Password_Length];
char Master_Pass[Password_Length] = "2330";
int alarme = 28;
int RightCode = 13;
int WrongCode = 12;
byte pass_count = 0;
char customKey;
int IncorrectPass = 0;
int tentativas = 4;




LiquidCrystal lcd(27, 26, 25, 24, 23, 22);




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
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  porta.attach(29);
  pinMode(RightCode, OUTPUT);
  pinMode(WrongCode, OUTPUT);
  porta.write(0);
}





void loop() {

  matrixcode();
  noTone(alarme);

}
