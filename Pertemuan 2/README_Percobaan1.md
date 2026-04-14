# Modul 2 – Pemrograman GPIO
**Nama:** Kaira Meilasya Nayada
**NIM:** H1H024020
**Shift Akhir:** C  

## Percobaan 2A – Seven Segment Counter
### 2.5.4 Pertanyaan Praktikum 2A
#### 1. Gambarkan rangkaian schematic yang digunakan pada percobaan!
![Rangkaian Arduino](![simulasi percobaan 1](https://github.com/user-attachments/assets/19ec8442-ae30-4a4e-82b4-bf480f9ca273)
)

---
#### 2. Apa yang terjadi jika nilai `num` lebih dari 15?
Jika fungsi `displayHex()` dipanggil dengan `num > 15`, terjadi **array out-of-bounds access**.
**Penjelasan:**  
Array `hexPatterns` didefinisikan dengan ukuran `[16][7]`, artinya indeks yang valid hanya **0 sampai 15**. Jika `num = 16` misalnya, program akan mengakses `hexPatterns[16][x]` yang **tidak dialokasikan** dalam memori array tersebut.
**Dampak pada Arduino (AVR/ATmega328P):**  
Bahasa C/C++ pada Arduino tidak memiliki bounds checking otomatis. Akibatnya:
- Program membaca data dari lokasi memori yang berada di luar array — yaitu data apa pun yang kebetulan ada di memori setelahnya (bisa berisi variabel lain, kode program, atau sampah memori).
- Seven Segment Display akan menampilkan **pola acak dan tidak terdefinisi** — segmen menyala/mati secara tidak beraturan.
- Dalam skenario terburuk, jika data yang terbaca sangat besar atau memori yang diakses adalah bagian dari stack/program, bisa menyebabkan **perilaku tidak terduga (undefined behavior)** seperti program hang atau restart.
**Dalam program ini hal tersebut tidak terjadi** karena perulangan `for (int i = 0; i < 16; i++)` membatasi nilai `i` maksimal 15, sehingga `displayHex()` tidak pernah dipanggil dengan argumen > 15.
---
#### 3. Apakah program ini menggunakan Common Cathode atau Common Anode? Jelaskan alasannya!
Program ini menggunakan **Common Anode (CA)**.
**Bukti dari kode:**
```cpp
digitalWrite(pinA, hexPatterns[num][0] ? LOW : HIGH);
```
Logika ternary `? LOW : HIGH` menunjukkan:
- Bila nilai di `hexPatterns` = **1 (ON)** → pin diberi sinyal **LOW (0V)**
- Bila nilai di `hexPatterns` = **0 (OFF)** → pin diberi sinyal **HIGH (5V)**

**Penjelasan prinsip kerja:**
Pada Seven Segment **Common Anode**, semua **anoda** LED dalam satu display dihubungkan menjadi satu titik dan disambungkan ke **VCC (5V)**. Agar sebuah LED (segmen) menyala, arus harus mengalir dari anoda (VCC) melalui LED menuju katoda. Ini hanya terjadi jika katoda berada pada potensial yang **lebih rendah dari anoda**, yaitu ketika pin Arduino mengeluarkan **LOW (GND/0V)**. Sebaliknya, pada **Common Cathode**, semua katoda terhubung ke GND dan segmen menyala dengan sinyal **HIGH**.
**Perbandingan:**
| Kondisi       | Common Anode | Common Cathode |
|---------------|-------------|----------------|
| Segmen ON     | LOW (0V)    | HIGH (5V)      |
| Segmen OFF    | HIGH (5V)   | LOW (0V)       |
| COM terhubung ke | VCC (5V) | GND (0V)       |
---
#### 4. Modifikasi program agar tampilan berjalan dari F ke 0
```cpp
#include <Arduino.h>
// Mapping pin segmen: a  b  c   d   e  f  g  dp
const int segmentPins[8] = {7, 6, 5, 10, 11, 8, 9, 4};
// Mendefinisikan 8 pin Arduino yang terhubung ke setiap segmen Seven Segment Display.
// Urutan: a=7, b=6, c=5, d=10, e=11, f=8, g=9, dp=4

// Alias nama pin agar kode lebih mudah dibaca
#define pinA  segmentPins[0]   // Pin untuk segmen a (atas)
#define pinB  segmentPins[1]   // Pin untuk segmen b (kanan atas)
#define pinC  segmentPins[2]   // Pin untuk segmen c (kanan bawah)
#define pinD  segmentPins[3]   // Pin untuk segmen d (bawah)
#define pinE  segmentPins[4]   // Pin untuk segmen e (kiri bawah)
#define pinF  segmentPins[5]   // Pin untuk segmen f (kiri atas)
#define pinG  segmentPins[6]   // Pin untuk segmen g (tengah)
#define pinDP segmentPins[7]   // Pin untuk segmen dp (titik)

// Pola bit untuk setiap karakter heksadesimal (urutan: a b c d e f g)
// Nilai 1 = segmen ON, nilai 0 = segmen OFF
// Perangkat: Common Anode → ON = LOW, OFF = HIGH
byte hexPatterns[16][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0 → a,b,c,d,e,f menyala; g mati
  {0, 1, 1, 0, 0, 0, 0}, // 1 → hanya b,c menyala
  {1, 1, 0, 1, 1, 0, 1}, // 2 → a,b,d,e,g menyala
  {1, 1, 1, 1, 0, 0, 1}, // 3 → a,b,c,d,g menyala
  {0, 1, 1, 0, 0, 1, 1}, // 4 → b,c,f,g menyala
  {1, 0, 1, 1, 0, 1, 1}, // 5 → a,c,d,f,g menyala
  {1, 0, 1, 1, 1, 1, 1}, // 6 → a,c,d,e,f,g menyala
  {1, 1, 1, 0, 0, 0, 0}, // 7 → a,b,c menyala
  {1, 1, 1, 1, 1, 1, 1}, // 8 → semua segmen menyala
  {1, 1, 1, 1, 0, 1, 1}, // 9 → a,b,c,d,f,g menyala
  {1, 1, 1, 0, 1, 1, 1}, // A → a,b,c,e,f,g menyala
  {0, 0, 1, 1, 1, 1, 1}, // b → c,d,e,f,g menyala
  {1, 0, 0, 1, 1, 1, 0}, // C → a,d,e,f menyala
  {0, 1, 1, 1, 1, 0, 1}, // d → b,c,d,e,g menyala
  {1, 0, 0, 1, 1, 1, 1}, // E → a,d,e,f,g menyala
  {1, 0, 0, 0, 1, 1, 1}  // F → a,e,f,g menyala
};

// Deklarasi fungsi displayHex sebelum digunakan
void displayHex(int num);

void setup() {
  // Inisialisasi semua pin sebagai OUTPUT
  // Dilakukan satu kali saat Arduino dinyalakan
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    // Gunakan loop agar lebih efisien daripada menulis 8 baris pinMode
  }
  
  // Matikan semua segmen di awal (HIGH = mati pada Common Anode)
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }
}

void loop() {
  // *** MODIFIKASI: Loop berjalan dari 15 (F) turun ke 0 ***
  // Menggunakan decrement (i--) agar urutan terbalik dibanding versi asli
  for (int i = 15; i >= 0; i--) {
    // i dimulai dari 15 (F) dan berkurang setiap iterasi hingga 0
    
    displayHex(i);    // Tampilkan karakter ke-i pada Seven Segment Display
    delay(1000);      // Tunda 1000ms (1 detik) sebelum menampilkan karakter berikutnya
  }
  // Setelah i mencapai 0 dan loop selesai, fungsi loop() dipanggil ulang
  // → counter otomatis kembali ke F dan mulai hitung mundur lagi
}

void displayHex(int num) {
  // Fungsi untuk menampilkan satu karakter heksadesimal pada Seven Segment Display
  // Parameter num: indeks karakter (0–15) yang ingin ditampilkan

  // Tulis pola bit ke setiap pin segmen (a sampai g)
  // Operator ternary: jika hexPatterns[num][x] == 1 → tulis LOW (ON)
  //                   jika hexPatterns[num][x] == 0 → tulis HIGH (OFF)
  // Ini karena display bertipe Common Anode: segmen menyala ketika pin LOW
  digitalWrite(pinA, hexPatterns[num][0] ? LOW : HIGH); // Segmen a
  digitalWrite(pinB, hexPatterns[num][1] ? LOW : HIGH); // Segmen b
  digitalWrite(pinC, hexPatterns[num][2] ? LOW : HIGH); // Segmen c
  digitalWrite(pinD, hexPatterns[num][3] ? LOW : HIGH); // Segmen d
  digitalWrite(pinE, hexPatterns[num][4] ? LOW : HIGH); // Segmen e
  digitalWrite(pinF, hexPatterns[num][5] ? LOW : HIGH); // Segmen f
  digitalWrite(pinG, hexPatterns[num][6] ? LOW : HIGH); // Segmen g

  // Segmen dp (titik desimal) selalu dimatikan karena tidak digunakan
  // HIGH = mati pada Common Anode
  digitalWrite(pinDP, HIGH);
}
```
