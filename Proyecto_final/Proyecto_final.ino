/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final  
   Dev: José Filiberto Hernandez De Paz
   Fecha: 26 de Mayo
*/

#include <Servo.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

//definir pines
#define filas_teclado 4
#define columnas_teclado 4
#define f1_teclado 9
#define f2_teclado 8
#define f3_teclado 7
#define f4_teclado 6
#define c1_teclado 5
#define c2_teclado 4
#define c3_teclado 3
#define c4_teclado 2
#define pin_servote 10
#define led_1 A3
#define led_2 A2
#define led_3 A1
#define led_4 A0
#define A A4
#define B A5
#define C 11
#define D 12

//directivas de preprocesador para la LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//otras directivas
#define ON(pin) digitalWrite(pin, HIGH)
#define OFF(pin) digitalWrite(pin, LOW)

//variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};

//keypad
Keypad teclado = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

//servo
Servo servo;

//autofantastico
void autofantastico() {
  ON(led_1); delay(500); OFF(led_1);
  ON(led_2); delay(500); OFF(led_2);
  ON(led_3); delay(500); OFF(led_3);
  ON(led_4); delay(500); OFF(led_4);
  ON(led_3); delay(500); OFF(led_3);
  ON(led_2); delay(500); OFF(led_2);
  ON(led_1); ON(led_2); ON(led_3); ON(led_4); delay(500);
  OFF(led_1); OFF(led_2); OFF(led_3); OFF(led_4); delay(500);
}
//display
void contador() {
  OFF(A);
  OFF(B);
  OFF(C);
  OFF(D);
  delay(500);

  ON(A);
  OFF(B);
  OFF(C);
  OFF(D);
  delay(500);

  OFF(A);
  ON(B);
  OFF(C);
  OFF(D);
  delay(500);

  ON(A);
  ON(B);
  OFF(C);
  OFF(D);
  delay(500);

  OFF(A);
  OFF(B);
  ON(C);
  OFF(D);
  delay(500);

  ON(A);
  OFF(B);
  ON(C);
  OFF(D);
  delay(500);

  OFF(A);
  ON(B);
  ON(C);
  OFF(D);
  delay(500);

  ON(A);
  ON(B);
  ON(C);
  OFF(D);
  delay(500);

  OFF(A);
  OFF(B);
  OFF(C);
  ON(D);
  delay(500);

  ON(A);
  OFF(B);
  OFF(C);
  ON(D);
  delay(500);


}
void setup() {
  Serial.begin(9600);
  Serial.println("Examen Final");
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jose Filiberto");
  lcd.setCursor(0, 1);
  lcd.print(" Proyecto Final");

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);

  servo.attach(pin_servote);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  char tecla = teclado.getKey(); 

  if (tecla == '1') { //contador 0-99
    for (int i = 0; i <= 99; i++) {
      Serial.println(i); 
      delay(100); 
    }
  }

  if (tecla == '2') { //contador 99-0
    for (int i = 99; i >= 0; i--) {
      Serial.println(i); 
      delay(100); 
    }
  }

  if (tecla == '3') { //sutofantastico
    for (int i = 0; i < 5; i++) { 
      autofantastico();
    }
  }

  if (tecla == '4') { //display
   contador();
  }

  if (tecla == '5') { //mover el servo de 0 a 180 grados
    for (int pos = 0; pos <= 180; pos++) { 
      servo.write(pos);
      delay(15); 
    }
  }
}
