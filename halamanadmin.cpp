#include "halamanadmin.h"
#include "ui_halamanadmin.h"
#include <QMessageBox>
#include <QTableWidgetItem>

HalamanAdmin::HalamanAdmin(ManajerBuku* manajer, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::HalamanAdmin),
    manajer(manajer)
{
    ui->setupUi(this);
    connect(manajer, &ManajerBuku::dataBerubah, this, &HalamanAdmin::tampilkanDaftarBuku);
    connect(ui->tambahButton, &QPushButton::clicked, this, &HalamanAdmin::tambahBuku);
    connect(ui->tampilkanButton, &QPushButton::clicked, this, &HalamanAdmin::tampilkanDaftarBuku);
    connect(ui->updateButton, &QPushButton::clicked, this, &HalamanAdmin::updateBuku);
    connect(ui->hapusButton, &QPushButton::clicked, this, &HalamanAdmin::hapusBuku);
    tampilkanDaftarBuku();
}

HalamanAdmin::~HalamanAdmin() {
    delete ui;
}

void HalamanAdmin::tambahBuku() {
    QString judul = ui->judulEdit->text().trimmed();
    QString penulis = ui->penulisEdit->text().trimmed();
    QString penerbit = ui->penerbitEdit->text().trimmed();
    int tahun = ui->tahunEdit->text().toInt();

    if (judul.isEmpty() || penulis.isEmpty() || penerbit.isEmpty() || tahun == 0) {
        QMessageBox::warning(this, "Input Tidak Valid", "Semua kolom harus diisi.");
        return;
    }

    manajer->tambahBuku(judul, penulis, penerbit, tahun);
}

void HalamanAdmin::tampilkanDaftarBuku() {
    ui->tabelBuku->setRowCount(0);

    for (int i = 0; i < manajer->jumlahBuku(); ++i) {
        Buku* b = manajer->getBuku(i);
        if (!b) continue;
        int row = ui->tabelBuku->rowCount();
        ui->tabelBuku->insertRow(row);
        ui->tabelBuku->setItem(row, 0, new QTableWidgetItem(b->judul));
        ui->tabelBuku->setItem(row, 1, new QTableWidgetItem(b->penulis));
        ui->tabelBuku->setItem(row, 2, new QTableWidgetItem(b->penerbit));
        ui->tabelBuku->setItem(row, 3, new QTableWidgetItem(QString::number(b->tahun)));
    }
}

void HalamanAdmin::updateBuku() {
    QString judulLama = ui->judulEdit->text().trimmed();
    QString judulBaru = ui->judulEdit->text().trimmed();
    QString penulis = ui->penulisEdit->text().trimmed();
    QString penerbit = ui->penerbitEdit->text().trimmed();
    int tahun = ui->tahunEdit->text().toInt();

    if (manajer->updateBuku(judulLama, judulBaru, penulis, penerbit, tahun)) {
        QMessageBox::information(this, "Update", "Buku berhasil diperbarui.");
    } else {
        QMessageBox::warning(this, "Update Gagal", "Buku tidak ditemukan.");
    }
}

void HalamanAdmin::hapusBuku() {
    QString judul = ui->judulEdit->text().trimmed();

    if (manajer->hapusBuku(judul)) {
        QMessageBox::information(this, "Hapus", "Buku berhasil dihapus.");
    } else {
        QMessageBox::warning(this, "Hapus Gagal", "Buku tidak ditemukan.");
    }
}
