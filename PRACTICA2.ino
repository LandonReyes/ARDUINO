#define botonARRIBA 2 
#define botonABAJO 3
int LR=0;
struct productos {
char nombre[20];
float precio_unitario;
int stock;
float precio_por_lote;
int reserva;
};
productos producto1={"Lays",4.50,8,36,20};
productos producto2={"Doritos",3.50,8,28,20};
productos producto3={"Skittles",9.00,7,63,20};
productos producto4={"Manias Japonesas",2.00,10,20,20};
productos Rivas_factory[]={producto1,producto2,producto3,producto4};
//variables
void setup() {
Serial.begin(9600);
pinMode(botonARRIBA,INPUT);
pinMode(botonABAJO,INPUT);

Serial.println("Maquina de dulces");
Serial.println("Hecho por Landon");
//definir los pulsadores
}

void loop(){ 

  if(digitalRead(botonARRIBA)==HIGH)
  {
    delay(100);
    LR++;
     if(LR>3) LR=0;
 Serial.println(LR + 0);
 Serial.println("productos");
 Serial.println("Nombre del producto:");
 Serial.println(Rivas_factory[LR].nombre);
 Serial.println("precio unitario:");
 Serial.println(Rivas_factory[LR].precio_unitario);
 Serial.println("Stock:");
 Serial.println(Rivas_factory[LR].stock);
 Serial.println("Reserva:");
 Serial.println(Rivas_factory[LR].reserva);
 Serial.println("Prec_o por lote:");
 Serial.println(Rivas_factory[LR].precio_por_lote);
  }
  if(digitalRead(botonABAJO)==HIGH)
  {
    delay(100);
    LR--;
    if(LR<0) LR=3;
 Serial.println(LR + 0);
 Serial.println("productos");
 Serial.println("Nombre del producto:");
 Serial.println(Rivas_factory[LR].nombre);
 Serial.println("precio unitario:");
 Serial.println(Rivas_factory[LR].precio_unitario);
 Serial.println("Stock:");
 Serial.println(Rivas_factory[LR].stock);
 Serial.println("Reserva:");
 Serial.println(Rivas_factory[LR].reserva);
 Serial.println("Precio por lote:");
 Serial.println(Rivas_factory[LR].precio_por_lote);
  }

 delay(100);

}
