int Trig = 2;
int Echo = 3;
int Buzzer = 11;
int distancia;

int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 783;
int gSH = 830;
int aH = 880;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  distancia = HC();
  Serial.println(distancia);

      if (distancia >= 2 && distancia <= 5) {  // F (Fa)
        tone(Buzzer, f);
      } else if (distancia >= 6 && distancia <= 11) {  // G (Sol)
        tone(Buzzer, g);
      } else if (distancia >= 12 && distancia <= 17) {  // A (La)
        tone(Buzzer, a);
      } else if (distancia >= 18 && distancia <= 23) {  // B (Si)
        tone(Buzzer, b);
      } else if (distancia >= 24 && distancia <= 29) {  // C (Do)
        tone(Buzzer, c);
      } else if (distancia >= 30 && distancia <= 35) {  // D (Re)
        tone(Buzzer, d);
      } else if (distancia >= 36 && distancia <= 41) {  // E (Mi)
        tone(Buzzer, e);
      } else {
        noTone(Buzzer);  // Detener el sonido si la distancia no está en ninguno de los rangos especificados
      }
    }

int HC() {  // Funcion para hacer funcionar el ultrasonico y retornar el valor de distancia
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  int Tiempo = pulseIn(Echo, HIGH);
  int Distancia = Tiempo / 58.2;  // Calibración para obtener la distancia en centímetros
  return Distancia;
} 
