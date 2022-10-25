int LED_Pin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pause = 250; pause >= 0; pause--) {
    Serial.println(pause);
    digitalWrite(LED_Pin, HIGH);
    digitalWrite(LED_Pin, LOW);
    delay(pause);
  }
}
