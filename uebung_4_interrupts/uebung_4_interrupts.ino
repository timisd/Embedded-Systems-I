// LED Beschreibung:
int LED = 7;

// Taster Beschreibung:
int TSTR_PullUp = 2;
int TSTR_PullDown = 3;

// Variablen:
bool Notaus = false;
bool PullUp = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(TSTR_PullUp, INPUT_PULLUP);
  pinMode(TSTR_PullDown, INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  attachInterrupt(0, notaus_pullup, FALLING);
  attachInterrupt(1, notaus_pulldown, RISING);
  Serial.begin(9600); // Ausgabe von Text
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Notaus) {
    digitalWrite(LED, LOW);
    return;
  } else {
    digitalWrite(LED, HIGH);
  }

  if (PullUp) {
    Serial.println("PullUp Taster wurde benutzt!\n");
  } else {
    Serial.println("PullDown Taster wurde benutzt!\n");
  }
}

void notaus_pullup() {
  if (Notaus) {
    Notaus = false;
  } else {
    Notaus = true;
  }

  PullUp = true;

  // delay(10000); hat keine Auswirkung, da delay auch interrupts benutzt aber diese durch den Taster interrupt überschrieben werden
}

void notaus_pulldown() {
  if (Notaus) {
    Notaus = false;
  } else {
    Notaus = true;
  }

  PullUp = false;
}
