
#define BLYNK_TEMPLATE_ID "TMPL2SN2Sv__H"
#define BLYNK_TEMPLATE_NAME "PawzzyESP"
#define BLYNK_AUTH_TOKEN "Q0CI0nawhmAF8260h05qQLF5BY6Zh9Hb"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "mechlab";
char pass[] = "etufh89959"; 

bool LEDvar = false;

void setup(){
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
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
    Serial.write(20);
    LEDvar = false;
  }
}

void loop(){
  Blynk.run();
  if (LEDvar == true){
    Serial.write(45);
  }
  else{
    Serial.write(20);
  }
}
