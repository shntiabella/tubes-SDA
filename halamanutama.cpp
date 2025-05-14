// Memasukkan header class HalamanUtama
#include "halamanutama.h"
// Memasukkan UI hasil generate Qt Designer untuk HalamanUtama
#include "ui_halamanutama.h"
// Untuk menampilkan dialog pesan seperti peringatan
#include <QMessageBox>

// Konstruktor HalamanUtama
HalamanUtama::HalamanUtama(QWidget *parent)
    : QWidget(parent), ui(new Ui::HalamanUtama) { // Inisialisasi QWidget dan buat objek ui
    ui->setupUi(this); // Set up elemen-elemen UI dari file .ui

    manajerBuku = new ManajerBuku(this); // Buat instance ManajerBuku dan pastikan terikat ke objek induk agar tidak terjadi memory leak

    // Hubungkan tombol "pushLogin" ke fungsi handleLogin()
    connect(ui->pushLogin, &QPushButton::clicked, this, &HalamanUtama::handleLogin);
}

// Destruktor HalamanUtama
HalamanUtama::~HalamanUtama() {
    delete ui; // Hapus UI untuk membersihkan memori
}

// Fungsi untuk menangani aksi login ketika tombol ditekan
void HalamanUtama::handleLogin() {
    // Ambil teks yang dimasukkan di QLineEdit username
    QString username = ui->lineEditUsername->text();
    // Ambil teks yang dimasukkan di QLineEdit password
    QString password = ui->lineEditPassword->text();

    // Jika username dan password cocok untuk admin
    if (username == "adminuman" && password == "ngawi") {
        auto* admin = new HalamanAdmin(manajerBuku); // Buat halaman admin, kirimkan pointer manajerBuku
        admin->setAttribute(Qt::WA_DeleteOnClose);   // Hapus objek admin saat jendelanya ditutup
        admin->show(); // Tampilkan jendela admin
    }
    // Jika username dan password cocok untuk user biasa
    else if (username == "bukanadmin" && password == "syanum") {
        auto* user = new HalamanUser(manajerBuku); // Buat halaman user, kirimkan pointer manajerBuku
        user->setAttribute(Qt::WA_DeleteOnClose);  // Hapus objek user saat jendelanya ditutup
        user->show(); // Tampilkan jendela user
    }
    // Jika login gagal (username atau password salah)
    else {
        QMessageBox::warning(this, "Login Gagal", "Username atau password salah."); // Tampilkan pesan kesalahan
    }
}
