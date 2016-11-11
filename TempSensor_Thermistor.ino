#include <math.h>

double Thermistor(int Bravo) {
 double Alpha;
 Alpha = log(10000.0*((1024.0/Bravo-1))); 
 Alpha = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Alpha * Alpha ))* Alpha );
 Alpha = Alpha - 273.15;          
 return Alpha;
}

void setup() {
 Serial.begin(9600);
}

void loop() {             
  int val;                
  double Alpha;            
  val=analogRead(0);      
  Alpha=Thermistor(val);   
  Serial.print("Temperature = ");
  Serial.print(Alpha);   
  Serial.println(" C");
  delay(1000);            
}

