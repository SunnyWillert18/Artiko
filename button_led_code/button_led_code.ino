int redLED = 5;
int greenLED = 6;
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
  } else if (onOffButtonPressed && on){
    Serial.println("Turning off device!");
    blinkLED(redLED, 5);
    on = false;
    delay(1000);
  }

  bool heatButtonPressed = digitalRead(heatButton);
  if (heatButtonPressed && on){
   heat = true;  
  }
  Serial.println("State of heat button: ");
  Serial.println(heatButtonPressed);

  bool coolButtonPressed = digitalRead(coolButton);
  if (coolButtonPressed && on){
    heat = false;
  }
  //Serial.println("State of cool button: ");
  //Serial.println(coolButtonPressed);

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

