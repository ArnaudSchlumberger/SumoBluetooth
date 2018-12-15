#include <ZumoMotors.h>
ZumoMotors motors;

#include <SoftwareSerial.h>
SoftwareSerial BTserial(12, 11); // RX | TX
 
const long baudRate = 9600; 
char c;
boolean NL = true;


void setup() {
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(baudRate);  
    Serial.print("BTserial started at "); Serial.println(baudRate);
    Serial.println(" ");
  

}

void loop() {
  //Serial.println("AH");
  if (BTserial.available())
    {
      
        c = BTserial.read();
        Serial.println(' ');
        Serial.print("c : ");
        Serial.println(c);
        if(c == '1' || c == '2' || c == '3' || c=='4' || c=='5'){
          Serial.println("YAY");
          digitalWrite(13,HIGH);
        }
        if(c == '1'){
          avancer();
        }
        else if(c == '0'){
          arret();
        }
        else if(c == '3'){
          droite();
        }
        else if(c == '4'){  
          gauche();
        }
        else if(c == '2'){
          arriere();
        }
    }
}

void avancer(){
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400);
}
void arret(){
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
}
void droite(){
    motors.setLeftSpeed(400);
    motors.setRightSpeed(-400);
}
void gauche(){
    motors.setLeftSpeed(-400);
    motors.setRightSpeed(400);
}
void arriere(){
  motors.setLeftSpeed(-400);
  motors.setRightSpeed(-400);
}

