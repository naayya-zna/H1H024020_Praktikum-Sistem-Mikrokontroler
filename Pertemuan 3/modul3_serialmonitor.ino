const int PIN_LED = 12;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  Serial.println("Ketik 1 ON, 0 OFF");
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();

    if (data == '1') {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED ON");
    } 
    else if (data == '0') {
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED OFF");
    } 
    else if (data != '\n' && data != '\r') {
      Serial.println("Perintah tidak dikenal");
    }
  }
}