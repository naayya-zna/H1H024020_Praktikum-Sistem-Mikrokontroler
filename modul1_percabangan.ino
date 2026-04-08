const int ledPin = 6; // sesuai spec lab pin 6
int timeDelay = 1000; // init sesuai spec lab
void setup() {\n  pinMode(ledPin, OUTPUT);\n}
void loop() {
// Nyalakan LED
  digitalWrite(ledPin, HIGH);\n  delay(timeDelay);
// Matikan LED
  digitalWrite(ledPin, LOW);\n  delay(timeDelay);
// Baru ubah delay (setelah 1 siklus kedip)
if (timeDelay <= 100) {
delay(3000); // jeda sebelum reset
timeDelay = 1000; // reset ke awal
} else {
timeDelay -= 100; // percepatan bertahap
}
}
