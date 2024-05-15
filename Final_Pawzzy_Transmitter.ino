// Creates Identification for the Blynk system
#define BLYNK_TEMPLATE_ID "TMPL2SN2Sv__H"
#define BLYNK_TEMPLATE_NAME "PawzzyESP"
#define BLYNK_AUTH_TOKEN "Q0CI0nawhmAF8260h05qQLF5BY6Zh9Hb"

// Includes all necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Creates the name and password of the network the ESP needs to connect to
char ssid[] = "mechlab";
char pass[] = "etufh89959"; 

bool blynk_input = false; // bool for user input
bool arm_throw = false; // bool for knowing if the arm has thrown the toy or not

int blynk_input_LED = D7; // int for the output LED pin
int arm_pos = 90; // int for the position of the arm 
int arm_point_pos = 90; // int for the transmitted number used to determine direction of the arm
int move_time = 500;

Servo arm; // Sets up the Arm servo

void setup(){
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // Connects ESP to Internet
  Serial.begin(115200); // Sets up Serial communication

  pinMode(blynk_input_LED,OUTPUT); // Sets up LED 
  
  // Sets up control pins leading to the L289N board
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  
  arm.attach(D3); // Sets up servo to pin D3
  arm.write(100);
}

// Function based off of Blynk input
BLYNK_WRITE(V0){
  int i = param.asInt(); // local variable to check status of input
  
  // If user turns on button, light up LED and change bool to TRUE
  if (i == 1){
    digitalWrite(blynk_input_LED, HIGH);
    blynk_input = true; 
  }
  // Otherwise, turn off LED and set bool to FALSE
  else{
    digitalWrite(blynk_input_LED, LOW);
    blynk_input = false;
  }
}

// Function to activate the string reel
void reel_down(){
  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  analogWrite(D2,255);
  return;
}

void reel_up(){
  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH);
  analogWrite(D2,255);
  return;
}

// Function for turning off the motor when called
void reel_off(){
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  analogWrite(D2,0);
  return; // Stop/check function
}

void loop(){
  Blynk.run(); // Run all Blynk functions (connecting to internet, checking data)

  // If the user turns on the button, output a random value through the Serial communication
  if (blynk_input == true){
    if (arm_throw == false){
      arm.write(180);
      reel_down();
      delay(500);
      reel_off();
      arm_throw = true;
    }
    else{
      arm_point_pos = random(60,121);
      Serial.write(arm_point_pos);
    }
    
  }
  else{
    reel_off();
    Serial.write(20);
  }
}
