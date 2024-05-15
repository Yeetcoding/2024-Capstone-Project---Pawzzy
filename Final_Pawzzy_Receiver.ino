#include <Servo.h> // Includes the servo library

// Sets pins for the ultrasonic sensor
#define echoPin 5 
#define trigPin 6

// Sets the servos to their correct pins
Servo followSensor; 
Servo armPoint;

int serialInput = 90; // Int for reading Serial input
int distance; // Int for reading distance input from the sensor
int react_counter = 2;

long duration; // Used to calculate distance using input from the sensor

void setup() {
  Serial.begin(115200);
  
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
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
  ult();

  if (distance < 20){
    react_counter += 1;
    if (react_counter % 2 == 0){
      followSensor.write(60);
      armPoint.write(60);
    }
    else{
      followSensor.write(120);
      armPoint.write(120);
    }
  }
  else {
    serialInput = Serial.read();
    
    if (serialInput != 20 and serialInput != -1 and serialInput != 1){
      followSensor.write(serialInput);
      armPoint.write(serialInput);
    }
    else if (serialInput == 20 or serialInput == -1 or serialInput == 1){
      digitalWrite(13,LOW);
    }
  }
}

