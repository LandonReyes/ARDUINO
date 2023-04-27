#include <LiquidCrystal.h>
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7


LiquidCrystal digRs (RS, E, D4, D5, D6, D7);

void setup() {
   digRs.begin(2,16);
  digRs.print("Diego");
 digRs.setCursor(0,1);
  digRs.print("2019046");
 
}
void loop() {
}
