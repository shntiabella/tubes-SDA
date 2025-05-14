#ifndef HALAMANUTAMA_H
#define HALAMANUTAMA_H

#include <QWidget>
#include "manajerbuku.h"     // Untuk mengelola data buku
#include "halamanadmin.h"    // Header untuk halaman admin
#include "halamanuser.h"     // Header untuk halaman user

// Namespace Qt untuk mendeklarasikan class dari file UI yang di-generate
QT_BEGIN_NAMESPACE
namespace Ui { class HalamanUtama; }
QT_END_NAMESPACE

// HalamanUtama adalah halaman login utama aplikasi
class HalamanUtama : public QWidget {
    Q_OBJECT  // Makro Qt untuk mendukung signals & slots

public:
    // Konstruktor utama, membuat instance baru dari halaman login
    HalamanUtama(QWidget *parent = nullptr);
    ~HalamanUtama();  // Destruktor

private slots:
    // Fungsi slot untuk menangani aksi login saat tombol ditekan
    void handleLogin();

private:
    Ui::HalamanUtama *ui;         // Pointer ke UI hasil generate dari Qt Designer
    ManajerBuku* manajerBuku;     // Pointer ke instance ManajerBuku yang digunakan bersama seluruh aplikasi
};

#endif
