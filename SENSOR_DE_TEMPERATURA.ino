/*Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Landon Francisco Alexander Reyes Baten
Carné: 2022012
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define LEDR 3
#define LEDB 4
#define LEDY 5
//Constructores
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);
LiquidCrystal_I2C LCD_LANDON(0x27,16,2);

void setup() {
  delay(1000);
  LCD_LANDON.init();
  LCD_LANDON.backlight();   //Inicio la comunicacion serial
  LCD_LANDON.begin();   //Se inicia el sensor
}

void loop() {
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temperatura = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  float temperatura1 = sensor.getTempFByIndex(0); //Se obtiene la temperatura en ºF

  LCD_LANDON.setCursor(0,0);
  LCD_LANDON.print("muestra: ");
  LCD_LANDON.setCursor(0,1);
  LCD_LANDON.print(temperatura);
  LCD_LANDON.println("C");
  LCD_LANDON.setCursor(6,1);
  LCD_LANDON.print(" ");
  LCD_LANDON.setCursor(7,1);
  LCD_LANDON.print(" ");
  LCD_LANDON.setCursor(8,1);
  LCD_LANDON.print(" ");
  LCD_LANDON.setCursor(9,1);
  LCD_LANDON.print(temperatura1);
  LCD_LANDON.println("F");
  LCD_LANDON.setCursor(15,1);
  LCD_LANDON.print("  ");
  delay(100);

  if (temperatura >= 30) {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDY, LOW);
  }
  if (temperatura <= 15) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDY, LOW);
  }
  if (temperatura > 15 && temperatura < 30) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDY, HIGH);
  }
}
