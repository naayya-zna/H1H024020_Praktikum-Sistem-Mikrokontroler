int timer = 100; // delay 100ms sesuai spec lab. Semakin tinggi angkanya, semakin lambat.
void setup() {
// gunakan loop for untuk menginisialisasi setiap pin sebagai output:

for (int ledPin = 2; ledPin < 8; ledPin++) {
  pinMode(ledPin, OUTPUT);
}
}
void loop() {
// looping dari pin rendah ke tinggi
  for (int ledPin = 2; ledPin < 8; ledPin++) {\n    // hidupkan LED pin nya:\n    digitalWrite(ledPin, HIGH);
  delay(timer);
// matikan pin LED nya:
    digitalWrite(ledPin, LOW);\n  }
  // looping dari pin yang tinggi ke yang rendah\n  for (int ledPin = 7; ledPin >= 2; ledPin--) {\n    // menghidupkan pin:\n    digitalWrite(ledPin, HIGH);
  delay(timer);
// mematikan pin:
    digitalWrite(ledPin, LOW);\n  }\n}
