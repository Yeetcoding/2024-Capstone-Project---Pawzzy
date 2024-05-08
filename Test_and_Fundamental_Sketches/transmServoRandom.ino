#define BLYNK_TEMPLATE_ID "TMPL2SN2Sv__H"
#define BLYNK_TEMPLATE_NAME "PawzzyESP"
#define BLYNK_AUTH_TOKEN "Q0CI0nawhmAF8260h05qQLF5BY6Zh9Hb"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "mechlab";
char pass[] = "etufh89959"; 

bool LEDvar = false;

int pos = 0;
int changeTime = 1000;

Servo armPoint;

void setup(){
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  armPoint.attach(D1);
}

BLYNK_WRITE(V0){
  int i=param.asInt();
  if (i==1){
    Serial.println("On");
    digitalWrite(13, HIGH);
    LEDvar = true; 
  }
  else{
    digitalWrite(13, LOW);
    Serial.println("Off");
    LEDvar = false;
  }
}

void loop(){
  Blynk.run();
  
  if (LEDvar == true){
    pos = random(30,151);
    Serial.write(pos);
    armPoint.write(pos);
    delay(changeTime);
    
  }
  else{
    Serial.write(20);
  }
}
