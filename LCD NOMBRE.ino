/*Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Landon Francisco Alexander Reyes Baten
Carné: 2022012
*/
//definir pines de lcd
#include <LiquidCrystal.h>
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LiquidCrystal lcd (RS, E, D4, D5, D6, D7);

void setup(){
lcd.begin(16,2);
lcd.print("Landon");//poner en la columna 1 fila 1 
lcd.setCursor(0,1);
lcd.print("2022012");//poner en la columna 2 fila 1
}
void loop (){
  
}
