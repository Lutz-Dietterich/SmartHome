int counter = 0; // Counter Variable

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  counter++; // Counter erhöhen

  Serial.print("Counter: ");
  Serial.println(counter); // Counter-Wert im seriellen Monitor ausgeben

  if (counter >= 30) {
    return; // Beende die loop()-Funktion
  }
}
