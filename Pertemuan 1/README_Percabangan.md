Percobaan 1A: Percabangan 

1. Pada kondisi apa program masuk ke blok if?
Program akan masuk ke blok if ketika kondisi yang diperiksa bernilai benar (true).

2. Pada kondisi apa program masuk ke blok else?
ketika kondisi pada if tidak terpenuhi atau bernilai salah (false). jika syarat pada if tidak tercapai, maka secara otomatis program akan menjalankan perintah yang ada di dalam blok else sebagai alternatif.

3. Apa fungsi dari perintah delay(timeDelay)?
Perintah delay(timeDelay) berfungsi untuk memberikan jeda waktu dalam eksekusi program dengan satuan milidetik. Fungsi ini digunakan untuk mengatur kecepatan nyala dan mati LED. Semakin besar nilai timeDelay, maka LED akan berkedip semakin lambat, sedangkan semakin kecil nilainya, LED akan berkedip semakin cepat.

4.  Program LED: Lambat → Cepat → Sedang → Mati
## Kode Program

```cpp
int ledPin = 2;        // pin LED
int timeDelay = 1000;  // delay awal (lambat)

void setup() {
  pinMode(ledPin, OUTPUT); // set pin sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED ON
  delay(timeDelay);           // tunggu sesuai delay
  digitalWrite(ledPin, LOW);  // LED OFF
  delay(timeDelay);           // tunggu lagi

  // Percabangan untuk mengatur perubahan kecepatan
  if (timeDelay > 300) {
    timeDelay -= 200; // dari lambat → cepat
  } 
  else if (timeDelay > 100) {
    timeDelay -= 100; // dari cepat → sedang
  } 
  else {
    timeDelay = 0;    // kondisi mati
  }

  // Jika sudah mati, reset ke awal
  if (timeDelay == 0) {
    digitalWrite(ledPin, LOW); // pastikan LED mati
    delay(1000);               // jeda sebelum ulang
    timeDelay = 1000;          // kembali ke lambat
  }
}
```

---

## Penjelasan Kode

* `int ledPin = 2;`
  Menentukan pin yang digunakan untuk LED.

* `int timeDelay = 1000;`
  Nilai awal delay (LED berkedip lambat).

* `pinMode(ledPin, OUTPUT);`
  Mengatur pin LED sebagai output.

* `digitalWrite(HIGH/LOW);`
  Menyalakan dan mematikan LED.

* `delay(timeDelay);`
  Mengatur kecepatan kedip LED.

* `if (timeDelay > 300)`
  Mengurangi delay besar → LED makin cepat.

* `else if (timeDelay > 100)`
  Transisi dari cepat → sedang (tidak langsung mati).

* `else`
  Menentukan kondisi LED menuju mati.

* `if (timeDelay == 0)`
  Mengecek apakah sudah mati, lalu reset ke awal.
