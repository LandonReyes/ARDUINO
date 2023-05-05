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

#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define led5 8
#define led6 9
#define led7 10
#define led8 12
#define led9 13
#define led10 A1
#define buzzers 11
#define trigger 2  
#define echo    3

LiquidCrystal_I2C LCD_LANDON(0x27,16,2);

void setup() {
  LCD_LANDON.init();
  LCD_LANDON.backlight();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzers, OUTPUT);
}
 
void loop() {
    int distans=dis();
    if(distans >=45){
      LCD_LANDON.clear();
      LCD_LANDON.setCursor(0,0);
      LCD_LANDON.print("Fuera de alcance");
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);      
    }
    else if(distans >=30 && distans <=40){
      LCD_LANDON.clear();
      LCD_LANDON.setCursor(0,0);
      LCD_LANDON.print("Persona objeto");
      LCD_LANDON.setCursor(0,1);
      LCD_LANDON.print("Acercandose");
      LCD_LANDON.setCursor(0,1);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);
     
    }
     else if(distans >=15 && distans <=25){
      LCD_LANDON.clear();
      LCD_LANDON.setCursor(0,0);
      LCD_LANDON.print("Cuidado espacio");
      LCD_LANDON.setCursor(0,1);
      LCD_LANDON.print("Privado");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,LOW);
      digitalWrite(led7,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);
      tone(buzzers, 100);
      delay(500);
      noTone(buzzers);
    }
    else if(distans >=5 && distans   <=10){
      LCD_LANDON.clear();
      LCD_LANDON.setCursor(0,0);
      LCD_LANDON.print("Invadiendo");
      LCD_LANDON.setCursor(0,1);
      LCD_LANDON.print("Espacio Privado");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,HIGH);
      digitalWrite(led7,HIGH);
      digitalWrite(led8,HIGH);
      digitalWrite(led9,HIGH);
      digitalWrite(led10,HIGH);
      tone(buzzers, 500);
      delay(500);
      noTone(buzzers);  
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
