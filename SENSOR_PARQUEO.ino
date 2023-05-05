/*Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Landon Francisco Alexander Reyes Baten
Carné: 2022012
*/
#include <LiquidCrystal.h>

// Configuro los pines 
LiquidCrystal LCD_LANDON(12, 11, 5, 4, 3, 2);

const int trigger = 7;
const int echo = 6;

void setup() {
  // configuro el LCD
  LCD_LANDON.begin(16, 2);

  // Configuro los pines de trigger y echo
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  int distance = getDistance();
  
  if (distance >= 50) {
    LCD_LANDON.clear();
    LCD_LANDON.setCursor(7, 0);
    LCD_LANDON.print("50");  
    LCD_LANDON.setCursor(6, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(5, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(4, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(9, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(10, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(11, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(6, 1);
    LCD_LANDON.print("Libre");
  }
  else if (distance >= 30 && distance <= 35) {
    LCD_LANDON.clear();
    LCD_LANDON.setCursor(7, 0);
    LCD_LANDON.print("30");
    LCD_LANDON.setCursor(6, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(5, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(4, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(3, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(2, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(9, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(10, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(11, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(12, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(13, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(5, 1);
    LCD_LANDON.print("Cuidado");
  }
  else if (distance >= 10 && distance <= 15) {
    LCD_LANDON.clear();
    LCD_LANDON.setCursor(7, 0);
    LCD_LANDON.print("10");
    LCD_LANDON.setCursor(6, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(5, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(4, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(3, 0);
    LCD_LANDON.write(1);
    LCD_LANDON.setCursor(2, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(9, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(10, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(11, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(12, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(13, 0);
LCD_LANDON.write(1);
LCD_LANDON.setCursor(0, 1);
LCD_LANDON.print("Peligro! Parar");
}
else {
LCD_LANDON.clear();
LCD_LANDON.setCursor(6, 0);
LCD_LANDON.print("Obstaculo");
LCD_LANDON.setCursor(5, 1);
LCD_LANDON.print("Detectado");
}

delay(500);
}

// Funcion que da la distancia usando el sensor ultrasonico
int getDistance() {
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

long duration = pulseIn(echo, HIGH);
int distance = duration * 0.034 / 2;

return distance;}
