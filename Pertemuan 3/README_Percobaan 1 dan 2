Jawaban Pertanyaan Percobaan 3A:
1.	Proses dari input keyboard hingga LED menyala/mati: pengguna mengetik karakter di Serial Monitor lalu klik Send, karakter dikirim via USB ke pin RX Arduino dan masuk ke buffer UART. Setiap iterasi loop() memeriksa buffer dengan Serial.available(). Jika ada data, Serial.read() mengambil karakter tersebut. Jika karakter adalah ‘1’, program memanggil digitalWrite(PIN_LED, HIGH) sehingga LED menyala; jika ‘0’ maka digitalWrite(PIN_LED, LOW) dan LED padam.
2.	Serial.available() digunakan untuk memeriksa jumlah byte di buffer penerima sebelum membaca. Jika baris ini dihilangkan, Serial.read() dipanggil terus-menerus meskipun tidak ada data, mengembalikan nilai -1 yang diinterpretasikan sebagai karakter tidak dikenal, sehingga pesan error “Perintah tidak dikenal” akan muncul berulang kali tanpa henti dan mengacaukan Serial Monitor.
3.	Untuk modifikasi LED berkedip saat menerima input ‘2’: ditambahkan variabel boolean blinkMode dan variabel unsigned long lastBlinkTime. Ketika karakter ‘2’ diterima, blinkMode diaktifkan. Selama blinkMode aktif, program memeriksa selisih millis() dengan lastBlinkTime setiap iterasi loop(); jika sudah melewati interval (misal 500 ms), status LED dibalik. Ketika ‘1’ atau ‘0’ diterima, blinkMode dinonaktifkan dan LED dikontrol sesuai perintah.Hasil Percobaan 2: Counter dengan Push Button
4.	Sebaiknya menggunakan millis() daripada delay(). Fungsi delay() memblokir seluruh eksekusi program selama durasinya sehingga Arduino tidak dapat memproses input serial apapun selama LED berkedip, membuat sistem tidak responsif. Millis() mengembalikan waktu tanpa memblokir loop(), sehingga program dapat terus memeriksa input serial baru di setiap iterasi [3].

Pertanyaan percobaan 3B:
1.	Komunikasi I2C antara Arduino dan LCD: Arduino (master) mengirim sinyal START pada SDA saat SCL HIGH. Master mengirimkan 7-bit alamat (0x27) ditambah bit Write (0). LCD merespons dengan sinyal ACK. Setelah terbentuk koneksi, master mengirimkan byte perintah atau karakter. Modul backpack PCF8574 mengkonversi data I2C menjadi sinyal parallel 4-bit untuk kontroler LCD HD44780. Akhirnya master mengirimkan STOP untuk mengakhiri sesi [5].
2.	Pin potensiometer harus dikonfigurasi tepat. Kaki kiri ke GND sebagai referensi tegangan bawah (0V), kaki kanan ke 5V sebagai referensi atas, dan kaki tengah ke A0 sebagai output pembagi tegangan. Jika kaki kiri dan kanan tertukar, arah putaran potensiometer akan terbalik: memutar ke kanan menurunkan ADC dan ke kiri menaikkannya, sehingga bar bergerak
3.	berlawanan dengan ekspektasi meski LCD tetap berfungsi.
3.	Modifikasi menggabungkan UART dan I2C dilakukan dengan menambahkan Serial.print() pada setiap iterasi loop() untuk menampilkan nilai ADC, tegangan (nilai/1023.0 * 5.0 V), dan persentase (nilai/1023.0 * 100 %) ke Serial Monitor. LCD tetap menampilkan bar seperti sebelumnya. Kedua protokol berjalan bersamaan tanpa konflik karena beroperasi pada jalur hardware yang berbeda.
4.	Tabel pengamatan nilai ADC pada Serial Monitor:
| ADC | Volt (V) | Persen (%) |
|-----|---------|-----------|
| 16  | 0.00    | 1%        |
| 21  | 0.10    | 2%        |
| 49  | 0.24    | 4%        |
| 74  | 0.36    | 7%        |
| 96  | 0.47    | 9%        |
