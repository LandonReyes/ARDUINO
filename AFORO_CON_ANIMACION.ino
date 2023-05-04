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
#define trigger 9   
#define echo    10
#define RS  2
#define en  3
#define D4  4
#define D5  5
#define D6  6
#define D7  7
#define buzzer 11

byte de_pie[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B00100,
  B01110,
  B00100,
  B01010
};
byte de_rodillas[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B00111,
  B00100,
  B01110,
  B11010
};

int contar = 0;

//Constructor
LiquidCrystal lcd(RS, en, D4, D5, D6, D7); //Constructor que me permite usar la LCD
void setup()
{
  lcd.begin(16,2); //Objeto de una LCD de 16 columnas x 2 filas
  lcd.print("0");
  lcd.createChar(1,de_pie);
  lcd.createChar(2,de_rodillas);
  lcd.setCursor(0,0);
  pinMode(trigger, OUTPUT);
  pinMode(echo,INPUT);
}

void loop()
{
    int distancin=dis();
  
    if(distancin >= 6 && distancin <= 10){
     contar++;
     switch(contar){
      case 1:
       lcd.setCursor(0,0);
       lcd.print("1");
       break;
      case 2:
       lcd.setCursor(0,0);
       lcd.print("2");
       break;
      case 3:
       lcd.setCursor(0,0);
       lcd.print("3");
       break;
      case 4:
       lcd.setCursor(0,0);
       lcd.print("4");
       break;
      case 5:
       lcd.setCursor(0,0);
       lcd.print("5");
       break;
      case 6:
       lcd.setCursor(0,0);
       lcd.print("6");
       break;
      case 7:
       lcd.setCursor(0,0);
       lcd.print("7");
       break;
      case 8:
        lcd.setCursor(0,0);
        lcd.print("8");
       break;
      case 9:
       lcd.setCursor(0,0);
       lcd.print("9");
       break;
       case 10:
         lcd.setCursor(0,0);
         lcd.print("10");
       break;
       case 11:
         lcd.setCursor(0,0);
         lcd.print("11");
       break;
       case 12:
         lcd.setCursor(0,0);
         lcd.print("12");
       break;
       case 13:
         lcd.setCursor(0,0);
         lcd.print("13");
       break;
       case 14:
         lcd.setCursor(0,0);
         lcd.print("14");
       break;
       case 15:
         lcd.setCursor(0,0);
         lcd.print("15");
       break;
       case 16:
         lcd.setCursor(0,0);
         lcd.print("16");
       break;
     }
    }
    if(contar>=16){
      tone(buzzer,100);
      delay(250+50);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(1);
      delay(1000);
      lcd.setCursor(0,0);
      lcd.write(2);
      delay(1000);
    }
}

int dis(){
   long sensor, distancia; 
    delay(500);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(2);
    digitalWrite (trigger, LOW);
    delayMicroseconds(5);
    sensor = pulseIn(echo, HIGH);
    distancia = sensor/59;
    return distancia;
}
