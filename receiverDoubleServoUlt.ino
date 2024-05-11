#include <Servo.h>

#define echoPin 5
#define trigPin 6

Servo followSensor; 
Servo armPoint;

int serialInput = 90;  
bool returningToZero;
long duration;
int distance;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  followSensor.attach(9); 
  armPoint.attach(10);
  followSensor.write(90);
  armPoint.write(90);

}

void ult(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void loop() {
  serialInput = Serial.read();
  Serial.println(serialInput);
  ult();
  
  if (serialInput != 20 and serialInput != -1 and serialInput != 1){
    
    if (distance >= 10){
      followSensor.write(serialInput);
      armPoint.write(serialInput);
    }
    else {
      digitalWrite(13,HIGH);
      followSensor.write(90);
      armPoint.write(90);
    }
  }
  else if (serialInput == 20 or serialInput == -1 or serialInput == 1){
    digitalWrite(13,LOW);
  }
}

