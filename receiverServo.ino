
#include <Servo.h>
Servo scanner;

int var = 0;

void setup() {
  Serial.begin(115200);
  scanner.attach(9);
  scanner.write(0);
  pinMode(8,OUTPUT);

}

void loop() {
  var = Serial.read();
  Serial.println(var,DEC);

  if (var == 45){
    scanner.write(90);
    digitalWrite(8,HIGH);
  }
  else{
    scanner.write(180);
    delay(100);
    scanner.write(0);
    delay(100);
    digitalWrite(8,LOW);
    delay(100);
  }
}
