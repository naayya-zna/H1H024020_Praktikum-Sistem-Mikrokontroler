1. Gambarkan rangkaian schematic 5 LED running yang digunakan pada percobaan!
   https://www.tinkercad.com/things/73wYC7mVshq-praktikum-sismik-p1perulangan

2. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan!
   Efek LED berjalan dari kiri ke kanan dibuat menggunakan loop yang mengakses pin LED secara berurutan dari pin terkecil ke terbesar. Pada setiap iterasi, LED dinyalakan, diberi delay, lalu dimatikan sebelum berpindah ke LED berikutnya, sehingga terlihat seperti cahaya bergerak ke kanan.

3. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri!
Untuk membuat LED bergerak dari kanan ke kiri, program menggunakan perulangan terbalik, yaitu dari pin terbesar ke pin terkecil. Prosesnya sama seperti sebelumnya: LED dinyalakan satu per satu, diberi delay, lalu dimatikan, sehingga menciptakan efek gerakan ke arah sebaliknya.

4. penjelasan kode
* 3 LED kiri
* 3 LED kanan

## Kode Program

```cpp
int ledKiri[]  = {2, 3, 4};   // LED kiri
int ledKanan[] = {5, 6, 7};   // LED kanan
int delayTime = 500;          // waktu delay

void setup() {
  // Inisialisasi semua pin sebagai OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledKiri[i], OUTPUT);
    pinMode(ledKanan[i], OUTPUT);
  }
}

void loop() {
  // Nyalakan LED kiri, matikan LED kanan
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledKiri[i], HIGH);   // LED kiri ON
    digitalWrite(ledKanan[i], LOW);   // LED kanan OFF
  }
  delay(delayTime); // jeda

  // Nyalakan LED kanan, matikan LED kiri
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledKiri[i], LOW);    // LED kiri OFF
    digitalWrite(ledKanan[i], HIGH);  // LED kanan ON
  }
  delay(delayTime); // jeda
}
```

---

## Penjelasan Kode

* `int ledKiri[] = {2, 3, 4};`
  Menyimpan pin untuk 3 LED sisi kiri.

* `int ledKanan[] = {5, 6, 7};`
  Menyimpan pin untuk 3 LED sisi kanan.

* `int delayTime = 500;`
  Menentukan lama jeda (500 ms).

* `setup()`
  Digunakan untuk mengatur semua pin sebagai OUTPUT agar bisa mengontrol LED.

* `for (int i = 0; i < 3; i++)`
  Perulangan untuk mengakses semua LED dalam satu kelompok.

* `digitalWrite(..., HIGH)`
  Menyalakan LED.

* `digitalWrite(..., LOW)`
  Mematikan LED.

* `loop()`
  Program utama yang berjalan terus-menerus.

* Bagian pertama loop
  LED kiri menyala, LED kanan mati.

* `delay(delayTime)`
  Memberi jeda agar perubahan terlihat.

* Bagian kedua loop
  LED kanan menyala, LED kiri mati.
