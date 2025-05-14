#include "halamanuser.h"
#include "ui_halamanuser.h"

HalamanUser::HalamanUser(ManajerBuku* manajer, QWidget *parent)
    : QWidget(parent), ui(new Ui::HalamanUser), manajerBuku(manajer)
{
    ui->setupUi(this);

    // Tampilkan data saat ini
    tampilkanData();

    // Hubungkan sinyal agar data diperbarui otomatis saat berubah
    connect(manajerBuku, &ManajerBuku::dataBerubah, this, &HalamanUser::tampilkanData);

    // Hubungkan pencarian dengan slot untuk mencari buku
    connect(ui->cariButton, &QPushButton::clicked, this, &HalamanUser::cariBuku);
}

HalamanUser::~HalamanUser() {
    delete ui;
}

void HalamanUser::tampilkanData() {
    ui->tabelHasil->clearContents();
    ui->tabelHasil->setRowCount(manajerBuku->jumlahBuku());

    for (int i = 0; i < manajerBuku->jumlahBuku(); ++i) {
        const Buku* buku = manajerBuku->daftarBuku(i);
        if (!buku) continue;

        ui->tabelHasil->setItem(i, 0, new QTableWidgetItem(buku->judul));
        ui->tabelHasil->setItem(i, 1, new QTableWidgetItem(buku->penulis));
        ui->tabelHasil->setItem(i, 2, new QTableWidgetItem(buku->penerbit));
        ui->tabelHasil->setItem(i, 3, new QTableWidgetItem(QString::number(buku->tahun)));
    }
}

// Slot pencarian buku berdasarkan judul
void HalamanUser::cariBuku() {
    QString judul = ui->inputCari->text();  // Mengambil input judul dari LineEdit

    int index = manajerBuku->cariIndexBuku(judul);  // Menggunakan fungsi publik cariIndexBuku
    if (index != -1) {
        // Buku ditemukan, tampilkan data
        const Buku* buku = manajerBuku->daftarBuku(index);
        ui->tabelHasil->clearContents();
        ui->tabelHasil->setRowCount(1);  // Hanya satu buku yang ditemukan
        ui->tabelHasil->setItem(0, 0, new QTableWidgetItem(buku->judul));
        ui->tabelHasil->setItem(0, 1, new QTableWidgetItem(buku->penulis));
        ui->tabelHasil->setItem(0, 2, new QTableWidgetItem(buku->penerbit));
        ui->tabelHasil->setItem(0, 3, new QTableWidgetItem(QString::number(buku->tahun)));
    } else {
        // Buku tidak ditemukan
        ui->tabelHasil->clearContents();
        ui->tabelHasil->setRowCount(0);  // Tidak ada hasil
    }
}
