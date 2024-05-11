#define BLYNK_TEMPLATE_ID "TMPL2SN2Sv__H"
#define BLYNK_TEMPLATE_NAME "PawzzyESP"
#define BLYNK_AUTH_TOKEN "Q0CI0nawhmAF8260h05qQLF5BY6Zh9Hb"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "Llamas";
char pass[] = "Momknows2!"; 

bool LEDvar = false;
bool arm_throw = false;

int testLED = D7;

int pos = 90;
int changeTime = 1000;

Servo arm;

void setup(){
  Serial.begin(115200);
  pinMode(testLED,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  arm.attach(D3);
  //launch() = false;
}

BLYNK_WRITE(V0){
  int i=param.asInt();
  if (i==1){
    Serial.println("On");
    digitalWrite(testLED, HIGH);
    LEDvar = true; 
  }
  else{
    digitalWrite(testLED, LOW);
    Serial.println("Off");
    LEDvar = false;
  }
}

void reel(){
  if (LEDvar == true){
    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
    analogWrite(D2,150);
  }
  else{
    return;
  }
}

void launch(){
  if (LEDvar == true){
    for (pos = 90; pos < 170; pos++){
      arm.write(pos);
    }
    delay(100);
    arm.write(35);
    arm_throw = true;
  }
  else{
    return;
  }
}

void loop(){
  Blynk.run();
  
  if (LEDvar == true){

    if (arm_throw == false){
      launch(); 
      reel();
      arm.write(30);
    }
  
    else{
      reel();
    }
 
    pos = random(30,151);
    Serial.write(pos);
    delay(changeTime);
      
   }
  else{
    Serial.write(20);
  }
  
}

