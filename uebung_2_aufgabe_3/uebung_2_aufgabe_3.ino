void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, digitalRead(7)); // Lies Wert vom Taster und setze Strom für Lampe
}
