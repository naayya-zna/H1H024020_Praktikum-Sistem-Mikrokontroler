Pertanyaan Percobaan 1
1. Fungsi analogRead() pada rangkaian ini:
Fungsi analogRead(potensioPin) membaca tegangan analog pada pin A0 yang dihubungkan ke wiper potensiometer, lalu mengonversinya menjadi nilai digital integer menggunakan ADC 10-bit internal Arduino. Hasilnya adalah nilai antara 0 (saat tegangan = 0V) hingga 1023 (saat tegangan = 5V). Nilai ini merepresentasikan posisi sudut poros potensiometer yang kemudian digunakan sebagai input untuk mengendalikan posisi servo motor. Tanpa analogRead(), mikrokontroler tidak dapat membaca sinyal analog dari potensiometer karena Arduino Uno hanya memproses sinyal digital secara native.
2. Alasan diperlukan fungsi map():
Fungsi map() diperlukan karena rentang nilai ADC (0–1023) tidak sesuai dengan rentang sudut servo (0–180°). Jika nilai ADC langsung dikirim ke myservo.write() tanpa konversi, maka nilai seperti 500 atau 1023 akan melebihi batas maksimum sudut servo (180°), yang dapat menyebabkan kerusakan mekanis atau perilaku tidak terduga. Fungsi map(val, 0, 1023, 0, 180) melakukan pemetaan linear sehingga setiap nilai ADC memiliki pasangan sudut yang tepat dan proporsional dalam rentang yang valid.
3. Modifikasi program agar servo bergerak 30°–150°:
Untuk membatasi pergerakan servo pada rentang 30° hingga 150°, hanya perlu mengubah parameter output pada fungsi map(). Berikut modifikasi pada baris konversi:
// Sebelum (rentang penuh 0-180 derajat):
pos = map(val, 0, 1023, 0, 180);

// Sesudah (dibatasi 30-150 derajat):
pos = map(val, 0, 1023, 30, 150);
Dengan perubahan ini, ketika potensiometer berada di posisi minimum (ADC = 0), servo akan berada di 30°, dan ketika maksimum (ADC = 1023), servo berhenti di 150°. Rentang ADC tetap 0–1023 (tidak berubah), hanya output-nya yang dibatasi. Pembatasan ini berguna untuk melindungi mekanik yang terpasang pada servo agar tidak berbenturan pada posisi ekstrem. 


Pertanyaan Percobaan 2
1. Mengapa LED dapat diatur kecerahannya menggunakan analogWrite():
LED dapat diatur kecerahannya menggunakan analogWrite() karena fungsi ini menghasilkan sinyal PWM — sinyal kotak yang menyala dan mati dengan sangat cepat (≈490 Hz atau sekitar 490 kali per detik). Mata manusia memiliki persistensi penglihatan sehingga tidak mampu mendeteksi kedipan di atas ≈60 Hz; yang dirasakan hanyalah rata-rata intensitas cahaya. Ketika duty cycle 50% (analogWrite nilai 127), LED menyala selama setengah periode dan mati selama setengahnya, sehingga terlihat menyala dengan kecerahan 50%. Semakin besar nilai yang diberikan ke analogWrite(), semakin lama LED dalam kondisi ON per siklus, sehingga semakin terang. Secara fisik, rata-rata arus yang mengalir melalui LED sebanding dengan duty cycle, yang menentukan kecerahan optiknya.
2. Hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255):
Nilai ADC merupakan hasil konversi 10-bit (rentang 0–1023) dari tegangan analog potensiometer, sedangkan nilai PWM merupakan parameter 8-bit (rentang 0–255) yang menentukan duty cycle sinyal PWM. Keduanya dihubungkan melalui fungsi map(nilaiADC, 0, 1023, 0, 255) yang melakukan pemetaan linear. Hubungan matematisnya adalah:
PWM = (nilaiADC / 1023) × 255 ≈ nilaiADC × 0,249
Artinya setiap kenaikan ≈4 unit ADC akan menaikkan nilai PWM sebesar 1. Keduanya merepresentasikan hal yang sama (posisi potensiometer), hanya dengan skala yang berbeda: ADC dalam resolusi 10-bit dan PWM dalam resolusi 8-bit. Perbedaan resolusi ini menyebabkan sedikit kehilangan presisi, namun tidak berpengaruh signifikan secara visual.
3. Modifikasi program agar LED hanya menyala pada rentang PWM 50–200:
Untuk membatasi kecerahan LED hanya pada rentang PWM 50–200, digunakan fungsi constrain() setelah map() untuk membatasi nilai, atau cukup mengubah parameter map() agar output langsung berada pada rentang yang diinginkan. Pendekatan yang lebih tepat adalah menggunakan constrain() agar rentang ADC tetap penuh:
void loop() {
  nilaiADC = analogRead(potPin);
  pwm = map(nilaiADC, 0, 1023, 0, 255);

  // Batasi PWM hanya pada rentang 50-200
  pwm = constrain(pwm, 50, 200);

  analogWrite(ledPin, pwm);
  Serial.print("ADC: ");
  Serial.print(nilaiADC);
  Serial.print(" | PWM: ");
  Serial.println(pwm);
  delay(50);
}
Fungsi constrain(pwm, 50, 200) memastikan nilai PWM tidak pernah di bawah 50 (LED selalu menyala minimal redup) dan tidak pernah melebihi 200 (LED tidak pernah mencapai kecerahan penuh). Hasilnya, saat potensiometer di posisi minimum, LED tetap menyala redup (PWM = 50), dan saat maksimum, LED tidak mencapai kecerahan penuh (PWM = 200).

