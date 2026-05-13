Percobaan 1
1. Apakah ketiga task berjalan secara bersamaan atau bergantian?
Ketiga task tidak berjalan benar-benar bersamaan secara fisik, melainkan berjalan secara concurrent (bergantian sangat cepat). FreeRTOS menggunakan preemptive scheduler berbasis time-slicing yang mengalokasikan CPU kepada setiap task sesuai prioritas dan kondisi task. Pada percobaan ini, ketiga task memiliki prioritas sama (level 1), sehingga scheduler memberikan giliran CPU secara round-robin. Saat satu task memanggil vTaskDelay(), task tersebut masuk ke state Blocked dan CPU diberikan ke task berikutnya

2. Bagaimana cara menambahkan task keempat?
Langkah menambahkan task keempat adalah: (1) Deklarasikan prototipe fungsi task, misalnya void TaskFour(void *pvParameters); (2) Tambahkan pemanggilan xTaskCreate() di dalam setup() dengan parameter nama task, stack size, prioritas, dan handle; (3) Implementasikan fungsi TaskFour() dengan loop while(1) dan vTaskDelay() agar task dapat berjalan concurrent. Pastikan total stack yang dialokasikan tidak melebihi RAM Arduino Uno (2 KB).

3. Modifikasi dengan potensiometer untuk kontrol kecepatan LED
https://wokwi.com/projects/463324503432867841

Percobaan 2
1. Apakah kedua task berjalan secara bersamaan atau bergantian?
Kedua task berjalan secara concurrent dan saling bergantung melalui mekanisme queue. Task read_data mengirim data ke queue dengan xQueueSend(), lalu melakukan vTaskDelay(100ms) sehingga masuk ke state Blocked. Selama itu, scheduler memberikan CPU kepada task display yang menunggu data dari queue via xQueueReceive() dengan timeout portMAX_DELAY. Ketika data tersedia, task display berjalan menampilkan nilai ke serial, kemudian kembali menunggu. Mekanisme ini memastikan sinkronisasi dan tidak terjadi kehilangan data

2. Apakah program berpotensi mengalami race condition?
Program ini tidak berpotensi mengalami race condition karena FreeRTOS Queue secara internal menggunakan mekanisme mutual exclusion (mutex). Akses ke queue di-serialize oleh kernel sehingga hanya satu task yang dapat menulis atau membaca pada satu waktu. Berbeda jika menggunakan variabel global biasa tanpa proteksi, yang sangat rentan terhadap race condition pada sistem multitask.

3. Modifikasi dengan sensor DHT sesungguhnya
https://wokwi.com/projects/463731278524133377

Pertanyaan Praktikum
1. Perbedaan loop() Arduino biasa vs RTOS
Pada Arduino biasa, loop() adalah superloop utama yang menjalankan semua logika program secara sekuensial. Satu fungsi yang lambat (misal: delay(1000)) akan memblokir seluruh program. Pada RTOS, loop() dibiarkan kosong karena logika program dipecah ke dalam task-task independen yang dikelola scheduler. Setiap task memiliki konteks eksekusi sendiri, sehingga satu task yang sedang delay tidak mengganggu task lain

2. Mengapa loop() dibiarkan kosong?
Fungsi loop() pada Arduino berjalan sebagai task idle di RTOS dengan prioritas 0. Karena semua fungsionalitas telah dipindahkan ke task-task yang dibuat dengan xTaskCreate(), tidak ada kode yang perlu dijalankan di loop(). Jika kode diletakkan di loop(), ia akan berkompetisi sebagai task idle dan berpotensi mengganggu scheduling task prioritas lebih tinggi

3. Insight utama dari percobaan ini
Insight utama yang diperoleh adalah bahwa RTOS mengubah paradigma pemrograman embedded dari sequential menjadi concurrent. Dengan FreeRTOS, kompleksitas multitasking dan sinkronisasi dapat dikelola secara terstruktur menggunakan abstraksi task, queue, dan delay berbasis tick. Hal ini memungkinkan pengembangan sistem embedded yang lebih modular, mudah di-debug, dan skalabel untuk aplikasi IoT dan sistem kendali real-time.

