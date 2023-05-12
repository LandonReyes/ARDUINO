/*Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Landon Francisco Alexander Reyes Baten
Carné: 2022012
*/
#define triggerPin  2
#define echoPin  3

#define APin  5
#define BPin  6
#define CPin  7
#define DPin  8
#define EPin  9
#define FPin  10
#define GPin  11

#define relePin  4

int contador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW);
  pinMode(APin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(CPin, OUTPUT);
  pinMode(DPin, OUTPUT);
  pinMode(EPin, OUTPUT);
  pinMode(FPin, OUTPUT);
  pinMode(GPin, OUTPUT);
}

void loop() {
  long sensor, distancia;
  delay(500);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);  
  sensor = pulseIn(echoPin, HIGH);
  distancia = sensor / 59;

  if (distancia >= 6 && distancia <= 10) {
    contador++;
    Serial.println(contador);
    MostrarNumeroEnDisplay(contador);
  }
  if (contador >= 10) {
    digitalWrite(relePin, LOW);
  }
}

void MostrarNumeroEnDisplay(int numero) {
  switch(numero) {
    case 0:
      MostrarDigitoEnDisplay(0);
      break;
    case 1:
      MostrarDigitoEnDisplay(1);
      break;
    case 2:
      MostrarDigitoEnDisplay(2);
      break;
    case 3:
      MostrarDigitoEnDisplay(3);
      break;
    case 4:
      MostrarDigitoEnDisplay(4);
      break;
    case 5:
      MostrarDigitoEnDisplay(5);
      break;
    case 6:
      MostrarDigitoEnDisplay(6);
      break;
    case 7:
      MostrarDigitoEnDisplay(7);
      break;
    case 8:
      MostrarDigitoEnDisplay(8);
      break;
    case 9:
      MostrarDigitoEnDisplay(9);
      break;
    default:
      break;
  }
}

void MostrarDigitoEnDisplay(int digito) {
  digitalWrite(APin, LOW);
  digitalWrite(BPin, LOW);
  digitalWrite(CPin, LOW);
  digitalWrite(DPin, LOW);
  digitalWrite(EPin, LOW);
  digitalWrite(FPin, LOW);
  digitalWrite(GPin, LOW);

  switch(digito) {
    case 0:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(FPin, HIGH);
      break;
    case 1:
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      break;
    case 2:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(EPin, HIGH);
      digitalWrite(GPin, HIGH);
      break;
    case 3:
      digitalWrite(APin, HIGH);
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(DPin, HIGH);
      digitalWrite(GPin, HIGH);
      break;
    case 4:
      digitalWrite(BPin, HIGH);
      digitalWrite(CPin, HIGH);
      digitalWrite(FPin, HIGH);
      digitalWrite(GPin, HIGH);
      break;
      case 5:
  digitalWrite(APin, HIGH);
  digitalWrite(CPin, HIGH);
  digitalWrite(DPin, HIGH);
  digitalWrite(EPin, HIGH);
  digitalWrite(GPin, HIGH);
  break;
case 6:
  digitalWrite(APin, HIGH);
  digitalWrite(CPin, HIGH);
  digitalWrite(DPin, HIGH);
  digitalWrite(EPin, HIGH);
  digitalWrite(FPin, HIGH);
  digitalWrite(GPin, HIGH);
  break;
case 7:
  digitalWrite(APin, HIGH);
  digitalWrite(BPin, HIGH);
  digitalWrite(CPin, HIGH);
  break;
case 8:
  digitalWrite(APin, HIGH);
  digitalWrite(BPin, HIGH);
  digitalWrite(CPin, HIGH);
  digitalWrite(DPin, HIGH);
  digitalWrite(EPin, HIGH);
  digitalWrite(FPin, HIGH);
  digitalWrite(GPin, HIGH);
  break;
case 9:
  digitalWrite(APin, HIGH);
  digitalWrite(BPin, HIGH);
  digitalWrite(CPin, HIGH);
  digitalWrite(DPin, HIGH);
  digitalWrite(GPin, HIGH);
  break;
default:
  break;
}
}
