#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10,11); // tx, rx (bluetooth)

int sensor = 0;
int state = 0;
int ledPin = 7;
int cont = 0;
int ledState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Bluetooth.begin(9600);
}

void loop() {
  
  state = analogRead(sensor);
  
  if (state < 53) {
    Bluetooth.write("1\r\n");
    digitalWrite(ledPin, HIGH); 
    ledState = 1;
  }
  else {
    if ( ledState == 1){
      if (cont > 100){
        digitalWrite(ledPin, LOW); 
        cont = -1;
        ledState = 0;
      }
      cont++;
    }
    
  }
}
