#define RED_LED 8       // Thick fog
#define YELLOW_LED 9    // Light fog  
#define BUZZER 10       // Audio alert

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.println("Smart Helmet - LED + Buzzer Mode");
}

void loop() {
  int visibility = map(analogRead(A0), 0, 1023, 0, 100);
  
  Serial.print("Visibility: "); Serial.print(visibility); Serial.println("%");
  
  if(visibility < 25) {
    // THICK FOG: Red LED + Beeping Buzzer
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    tone(BUZZER, 1000); // 1kHz beep
    Serial.println("DANGER: Thick Fog - BUZZER ON");
    delay(200);
    noTone(BUZZER); // Stop beep briefly
    delay(200);
  } 
  else if(visibility < 60) {
    // LIGHT FOG: Yellow LED only, no buzzer
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    noTone(BUZZER); // Buzzer OFF
    Serial.println("CAUTION: Light Fog");
    delay(1000);
  } 
  else {
    // CLEAR: Everything OFF
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    noTone(BUZZER);
    Serial.println("Clear Road");
    delay(1000);
  }
}