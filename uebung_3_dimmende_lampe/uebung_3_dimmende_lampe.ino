int LED_Pin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 255; i >= 0; i *= 0.7) {
    Serial.println(i);
    analogWrite(LED_Pin, i);
    delay(200);
  }
}
