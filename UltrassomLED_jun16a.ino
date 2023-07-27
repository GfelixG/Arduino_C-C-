#include <NewPing.h>

#define TRIGGER_PIN  9 
#define ECHO_PIN     8
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
void setup() {
  Serial.begin(115200);
  pinMode(7,OUTPUT); 
  pinMode(2,OUTPUT);
  }

void loop() {
  delay(100);
  Serial.print("Distancia: ");Serial.print(sonar.ping_cm());Serial.println("cm");
  if(sonar.ping_cm()<5){
    digitalWrite(7,HIGH);
    digitalWrite(2,HIGH);
    delay(50);
    }
  else if(sonar.ping_cm()<10){
    digitalWrite(7,LOW);
    digitalWrite(2,HIGH);
    delay(100);}
  else if(sonar.ping_cm()<20){
    digitalWrite(7,HIGH);
    delay(200);
    digitalWrite(2,LOW);
    }
  else if(sonar.ping_cm()<40){
      digitalWrite(7, HIGH);
      delay(400);
      digitalWrite(2,LOW);
      }
  else(sonar.ping_cm()>40);{
    digitalWrite(7,LOW);
    digitalWrite(2,LOW);
    }
}
