#include <Servo.h> // servo library

Servo scanner; //name and identify servo

const int out = 5; // set ultrasonic sensor Pin 
const int in = 6; // set ultrasonic sensor pin
int pos = 0; // starting value of servo pin
long dur; 
long dis;
long tocm;
bool returningToZero;

void setup() {
  Serial.begin(9600); //begin serial monitor for output
  pinMode(in, INPUT); // setup input pin on sensor
  pinMode(out, OUTPUT); // setup output pin on sensor
  scanner.attach(9); // servo pin setup
  scanner.write(0); // starting position of servo
}

bool objectDetected(long tocm) //function to detect object that gives a value
{
  if (tocm < 20)
  {
    return true;
  } else {
    return false;
  }
}

void loop() 
{
  digitalWrite(out, LOW); // send out sound from sensor
  delayMicroseconds(2);
  digitalWrite(out, HIGH);
  delayMicroseconds(10);
  digitalWrite(out, LOW);
  dur = pulseIn(in, HIGH);// read the electric signals from the sensor
  tocm = microsecondsToCentimeters(dur); // change input to a distance value
  if (objectDetected(tocm)) // if object is detected, stop the servo and display value
  {
    Serial.print("Object detected. Object's distance: ");
    Serial.print(tocm);
    Serial.print(". Servo's angle: ");
    Serial.println(pos);
  } else {
    if (pos < 180 && returningToZero == false) // otherwise, continue to rotate servo
    {
      scanner.write(pos);
      pos += 10;
      Serial.print("Searching for object. Servo's angle: ");
      Serial.println(pos);
      if (pos == 180)
        returningToZero = true;
    } else if (returningToZero == true) {
      pos -= 10;
      Serial.print("Searching for object. Servo's angle: ");
      Serial.println(pos);
      scanner.write(pos);
      if (pos == 0)
        returningToZero = false;
    }
  }
  delay(200);
}

long microsecondsToCentimeters(long microseconds) // convert signal to distance
{
  return microseconds / 29.155 / 2;
}
