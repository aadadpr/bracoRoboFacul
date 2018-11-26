#include <Servo.h> 
#include <Arduino.h>
#include <string.h>

Servo sBase;
Servo sPulso;
Servo sGarra;
Servo sBraco;

int pSBase = 8;
int pSPulso = 9;
int pSGarra = 10;
int pSBraco = 11;

int angBase = 0;
int angPulso = 0;
int angGarra = 15;
int angBraco = 0;

int angBaseMax = 0;
int angPulsoMax = 85;
int angGarraMax = 100;
int angBracoMax = 0;

int angBaseMin = 0;
int angPulsoMin = 0;
int angGarraMin = 15;
int angBracoMin = 0;

int valSoma = 1;
int velocidade = 15;

void initServ(){
    sBase.attach(pSBase);  
    sPulso.attach(pSPulso);
    sGarra.attach(pSGarra);
}

void moverServos(String input){

    

    if(velocidade <= 5){
        velocidade = 5;
    }

    if(input == "RR" || input == "rught0"){
        angBase = angBase + valSoma;
    }else if(input == "LL" || input == "left0"){
        angBase = angBase - valSoma;
    }else if(input == "FF"){      
        angPulso = angPulso + valSoma;
        if(angPulso >= angPulsoMax){
            angPulso = angPulsoMax;
        }
    }else if(input == "BB" || input == "down0"){
            angPulso = angPulso - valSoma;
            if(angPulso <= angPulsoMin){
                angPulso = angPulsoMin;
        }
    }else if(input == "W" || input == "qua0"){

            angGarra = angGarraMax;

    }else if(input == "w" || input == "x0"){

            angGarra = angGarraMin;

    }

    if(input == "" || input == ""){

    }else if(input == "1" || input == "11"){
        valSoma = 1;
    }else if(input == "2" || input == "22"){
        valSoma = 2;
    }else if(input == "3" || input == "33"){
        valSoma = 3;
        velocidade = 10;
    }else if(input == "4" || input == "44"){
        valSoma = 4;
    }else if(input == "5" || input == "55"){
        valSoma = 5;
        velocidade = 7;
    }else if(input == "6" || input == "66"){
        valSoma = 7;
    }else if(input == "7" || input == "77"){
        valSoma = 10;
    }else if(input == "8" || input == "88"){
        valSoma = 15;
        velocidade = 5;
    }else if(input == "9" || input == "99"){

    }

    if(input == "func1" || input == "func10"){
        velocidade = velocidade + 2;
        Serial.println("Velocidade: " + velocidade);
    } else if(input == "func2" || input == "func20"){
        valSoma = valSoma + 2;
        Serial.println("ValSoma: " + valSoma);
    }

    sBase.write(angBase);
    sPulso.write(angPulso);
    sGarra.write(angGarra);

delay(velocidade);
    
 
}

String leStringSerial(){
  String conteudo = "";
  char caractere;
  if(Serial.available() > 0){
            // Enquanto receber algo pela serial
    while(Serial.available() > 0) {
        // Lê byte da serial
        caractere = Serial.read();
        // Ignora caractere de quebra de linha
        if (caractere != '\n'){
        // Concatena valores
        if(caractere != 'S'){
            conteudo.concat(caractere);
        }
       
        }
        // Aguarda buffer serial ler próximo caractere
        delay(10);
    }
    if(conteudo != ""){
        Serial.print("Recebi: ");   
        Serial.println(conteudo);
    }
    
        
  }

  return conteudo;
}