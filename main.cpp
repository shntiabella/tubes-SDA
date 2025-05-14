// Memasukkan header HalamanUtama yang berisi definisi class HalamanUtama
#include "halamanutama.h"
// Memasukkan header QApplication untuk aplikasi Qt
#include <QApplication>

// Fungsi utama aplikasi Qt
int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Membuat instance QApplication untuk menangani aplikasi Qt

    HalamanUtama w; // Membuat instance HalamanUtama, yang akan menjadi window utama aplikasi
    w.show(); // Menampilkan jendela utama aplikasi

    return a.exec(); // Memulai event loop aplikasi (perintah yang akan menjalankan aplikasi Qt)
}
