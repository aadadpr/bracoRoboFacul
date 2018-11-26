#include <Arduino.h>
#include <Servo.h> 
#include <metodos.h> 

void setup() 
{ 
    Serial.begin(9600);
    initServ();
} 

void loop() 
{   

moverServos(leStringSerial());

}

