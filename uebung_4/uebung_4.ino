// LED Beschreibung:
int LED_Keller = 6;
int LED_Wohnbereich = 6;
int LED_Flur = 6;
int LED_Kueche = 6;
int LED_Haus = 6;
int LED_Treppenhaus = 7;

// Taster Beschreibung:
int TSTR_Treppenhaus = 2;
int TSTR_Notaus = 3;

// Zeit:
int Uhrzeit = 0;
int Wochentag = 1;

// LED Werte:
int Ein = HIGH;
int Aus = LOW;

bool Treppenhaus_ein = false;
bool Notaus_ein = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(TSTR_Treppenhaus, INPUT_PULLUP); // Taster Treppenhaus
  pinMode(TSTR_Notaus, INPUT_PULLUP); // Taster Treppenhaus
  pinMode(6,OUTPUT); // Lampen Haus
  pinMode(LED_Treppenhaus,OUTPUT); // Lampe Treppenhaus
  attachInterrupt(0, treppenhaus, FALLING);
  attachInterrupt(1, notaus, FALLING);
  Serial.begin(9600); // Ausgabe von Text
  Serial.println("Hausautomation Version 1.0 gestartet!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Notaus_ein) {
    return;
  }
  Serial.print("Wochentag: ");
  Serial.println(Wochentag);
  Serial.print("Uhrzeitzeit: ");
  Serial.println(Uhrzeit);
  if (Wochentag <= 5) {
    wochenmodus();
  } else {
    wochenendmodus();
  }
  
  Uhrzeit += 1;
  
  if (Uhrzeit > 23) {
    Uhrzeit = 0;
    Wochentag += 1;
  }

  if (Wochentag > 7) {
    Wochentag = 0;
  }

  delay(1000);
  Serial.print("\n\n\n\n");
}

void wochenmodus() {
  if (Uhrzeit >= 6 && Uhrzeit <= 22) {
    ledsteuerung(LED_Keller, Ein);
  } else {
    ledsteuerung(LED_Keller, Aus);
  }

  if ((Uhrzeit >= 6 && Uhrzeit <= 8) || (Uhrzeit >= 18 && Uhrzeit <= 22)) {
    ledsteuerung(LED_Wohnbereich, Ein);
  } else {
    ledsteuerung(LED_Wohnbereich, Aus);
  }

  if ((Uhrzeit >= 6 && Uhrzeit <= 9) || (Uhrzeit >= 17 && Uhrzeit <= 23)) {
    ledsteuerung(LED_Flur, Ein);
  } else {
    ledsteuerung(LED_Flur, Aus);
  }

  if (Uhrzeit >= 7 && Uhrzeit <= 20) {
    ledsteuerung(LED_Kueche, Ein);
  } else {
    ledsteuerung(LED_Kueche, Aus);
  }
}

void wochenendmodus() {
  ledsteuerung(LED_Keller, Ein);
  ledsteuerung(LED_Wohnbereich, Ein);
  ledsteuerung(LED_Flur, Ein);
  ledsteuerung(LED_Kueche, Ein);
}

void ledsteuerung(int led, int modus) {
  digitalWrite(led, modus);
  ausgabe(led, modus);
}

void treppenhaus() {
  if (!Treppenhaus_ein && !Notaus_ein) {
    digitalWrite(LED_Treppenhaus, Ein);
    Treppenhaus_ein = true;
  } else {
    digitalWrite(LED_Treppenhaus, Aus);
    Treppenhaus_ein = false;
  }
}

void notaus() {
  if (!Notaus_ein) {
    digitalWrite(LED_Haus, Aus);
    digitalWrite(LED_Treppenhaus, Aus);
    Notaus_ein = true;
  } else {
    Notaus_ein = false;
  }
}

void ausgabe(int led, int modus) {
  String ausgabe = "";
  switch(led) {
    case 4:
      ausgabe += "Status der Keller Lampe: ";
      break;
    case 5:
      ausgabe += "Status der Wohnbereich Lampe: ";
      break;
    case 6:
      ausgabe += "Status der Flur Lampe: ";
      break;
    case 7:
      ausgabe += "Status der Kueche Lampe: ";
      break;
  }

  if (modus == HIGH) {
    ausgabe += "Ein";
  } else {
    ausgabe += "Aus";
  }

  Serial.println(ausgabe);
}
