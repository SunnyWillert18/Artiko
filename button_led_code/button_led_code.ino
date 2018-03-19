int redLED = 11;
int greenLED = 8;
int blueLED_1 = 10;
int blueLED_2 = 9;
int onOffButton = 2;
int heatButton = 4;
int coolButton = 3;
int heating = 16;
bool on = false;
bool heat = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED_1, OUTPUT);
  pinMode(blueLED_2, OUTPUT);
  pinMode(onOffButton, OUTPUT);
  pinMode(heatButton, OUTPUT);
  pinMode(coolButton, OUTPUT);
  pinMode(heating, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool onOffButtonPressed = digitalRead(onOffButton);
  //Serial.println("State of on/off button: ");
  //Serial.println(onOffButtonPressed);
  if (onOffButtonPressed && !on){
    Serial.println("Turning on device!");
    blinkLED(greenLED, 5);  
    on = true;
    delay(1000);
  } 
  else if (onOffButtonPressed && on){
    Serial.println("Turning off device!");
    blinkLED(redLED, 5);
    on = false;
    delay(1000);
  }

  bool heatButtonPressed = digitalRead(heatButton);
  if (heatButtonPressed && on){
    heat = true;
    for (int i=0; i<4; i++) {
      blinkLED(blueLED_1, 1);
      blinkLED(blueLED_2, 1);
    } 
  }
  Serial.println("State of heat button: ");
  Serial.println(heatButtonPressed);

  bool coolButtonPressed = digitalRead(coolButton);
  if (coolButtonPressed && on){
    heat = false;
    for (int i=0; i<2; i++) {
      blinkLED(blueLED_2, 1);
      blinkLED(blueLED_1, 1);
    }
  }
  Serial.println("State of cool button: ");
  Serial.println(coolButtonPressed);

  //bool stationaryDetected = detectStationary();
  if (heat && on){ //&& stationaryDetected
    Serial.println("turning on heating");
    digitalWrite(heating, HIGH); 
    delay(500);
  }
}

void blinkLED(int pin, int repeat){
  for(int i = 0; i < repeat; ++i){
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);  
    delay(200);
  }
}

