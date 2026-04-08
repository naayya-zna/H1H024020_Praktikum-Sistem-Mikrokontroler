Percobaan 1A: Percabangan 

1. Pada kondisi apa program masuk ke blok if?
Program akan masuk ke blok if ketika kondisi yang diperiksa bernilai benar (true). Misalnya, jika terdapat kondisi timeDelay ≤ 100, maka blok if akan dijalankan ketika nilai timeDelay lebih kecil atau sama dengan 100. Dengan kata lain, blok if digunakan untuk menangani kondisi tertentu yang sudah ditentukan sebelumnya.

2. Pada kondisi apa program masuk ke blok else?
Program akan masuk ke blok else ketika kondisi pada if tidak terpenuhi atau bernilai salah (false). Artinya, jika syarat pada if tidak tercapai, maka secara otomatis program akan menjalankan perintah yang ada di dalam blok else sebagai alternatif.

3. Apa fungsi dari perintah delay(timeDelay)?
Perintah delay(timeDelay) berfungsi untuk memberikan jeda waktu dalam eksekusi program dengan satuan milidetik. Fungsi ini digunakan untuk mengatur kecepatan nyala dan mati LED. Semakin besar nilai timeDelay, maka LED akan berkedip semakin lambat, sedangkan semakin kecil nilainya, LED akan berkedip semakin cepat.

4. Jika alur awal program adalah mati → lambat → cepat → reset (mati), maka dapat dimodifikasi menjadi mati → lambat → cepat → sedang → mati. Pada alur baru ini, perubahan tidak terjadi secara langsung ke kondisi mati, tetapi melalui tahap sedang terlebih dahulu.
Penjelasan: LED awalnya mati, lalu menyala lambat (delay besar), kemudian menjadi cepat saat delay dikurangi. Setelah itu diperlambat ke kecepatan sedang, dan akhirnya mati secara bertahap ketika delay mencapai batas tertentu.
