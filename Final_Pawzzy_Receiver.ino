#include <Servo.h> // Includes the servo library

// Sets pins for the ultrasonic sensor
#define echoPin 5 
#define trigPin 6

// Sets the servos to their correct pins
Servo followSensor; 
Servo armPoint;

int serialInput = 90; // Int for reading Serial input
int distance; // Int for reading distance input from the sensor
int react_counter = 2; // Int for position calculations

long duration; // Used to calculate distance using input from the sensor

void setup() {
  Serial.begin(115200); // Sets Serial communication to correct speed

  pinMode(13,OUTPUT); // LED output pin
  pinMode(trigPin, OUTPUT); // Trig pin for sensor
  pinMode(echoPin, INPUT); // Echo pin for sensor
  
  followSensor.attach(9); // Pin for directing the servo that turns the sensor
  armPoint.attach(10); // Pin for directing where the arm points and how the turntable turns

  // Setting starting positions
  followSensor.write(90);
  armPoint.write(90);

}

// Function used to find distance from sensor
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
  ult(); // Activate the ultrasonic sensor

  // If distance is less than 35, either go way to the left or way to the right depending on where you went last
  if (distance < 35){
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
  // If no cat is detected, set the arm point and sensor to point at the received input number
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

