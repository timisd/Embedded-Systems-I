int LED_PIN = 9;
int PHOTO_PIN = A0;

bool lampe_an = false;
int tick = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT); // LED
  Serial.begin(9600); // Ausgabe von Text
}

void loop() {
  // put your main code here, to run repeatedly:
  int helligkeit = analogRead(PHOTO_PIN);
  Serial.println(helligkeit);
  // photolicht(helligkeit);
  // daemmerung(helligkeit);
  zusatz(helligkeit);
  Serial.println(tick);
  Serial.println("\n");
}

void photolicht(int helligkeit) {
  analogWrite(LED_PIN, 254 - (helligkeit * 2.5));
}

void daemmerung(int helligkeit) {
  if (helligkeit < 40)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}

void zusatz(int helligkeit) {
  if (lampe_an == true) {
    if (helligkeit > 50)
      tick++;
    else
      tick = 0;
    
    if (tick == 100) {
      digitalWrite(LED_PIN, LOW);
      lampe_an = false;
      tick = 0;
    }
  } else {
    if (helligkeit < 50)
      tick++;
    else
      tick = 0;
    
    if (tick == 100) {
      digitalWrite(LED_PIN, HIGH);
      lampe_an = true;
      tick = 0;
    }
  }
}
