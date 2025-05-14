#include "manajerbuku.h"

ManajerBuku::ManajerBuku(QObject* parent) : QObject(parent), jumlah(0) {}

ManajerBuku::~ManajerBuku() {
    clear();
}

void ManajerBuku::tambahBuku(const QString& judul, const QString& penulis, const QString& penerbit, int tahun) {
    if (jumlah >= MAX_BUKU) return;

    daftar[jumlah++] = Buku(judul, penulis, penerbit, tahun);
    urutkanJudul();
    emit dataBerubah();
}

// Implementasi fungsi publik yang memanggil binarySearch
int ManajerBuku::cariIndexBuku(const QString& judul) const {
    return binarySearch(judul);  // Memanggil binarySearch untuk mengembalikan indeks buku
}


Buku* ManajerBuku::cariBuku(const QString& judul) const {
    int index = binarySearch(judul);
    if (index != -1) {
        return const_cast<Buku*>(&daftar[index]);
    }
    return nullptr;
}

bool ManajerBuku::updateBuku(const QString& judulLama, const QString& judulBaru, const QString& penulis, const QString& penerbit, int tahun) {
    int index = binarySearch(judulLama);
    if (index != -1) {
        daftar[index].judul = judulBaru;
        daftar[index].penulis = penulis;
        daftar[index].penerbit = penerbit;
        daftar[index].tahun = tahun;
        urutkanJudul();
        emit dataBerubah();
        return true;
    }
    return false;
}

bool ManajerBuku::hapusBuku(const QString& judul) {
    int index = binarySearch(judul);
    if (index != -1) {
        for (int i = index; i < jumlah - 1; ++i) {
            daftar[i] = daftar[i + 1];
        }
        --jumlah;
        emit dataBerubah();
        return true;
    }
    return false;
}

void ManajerBuku::clear() {
    jumlah = 0;
    emit dataBerubah();
}

int ManajerBuku::jumlahBuku() const {
    return jumlah;
}

const Buku* ManajerBuku::daftarBuku(int index) const {
    if (index >= 0 && index < jumlah) {
        return &daftar[index];
    }
    return nullptr;
}

Buku* ManajerBuku::getBuku(int index) const {
    if (index >= 0 && index < jumlah) {
        return const_cast<Buku*>(&daftar[index]);
    }
    return nullptr;
}


void ManajerBuku::urutkanJudul() {
    // Selection sort (sederhana)
    for (int i = 0; i < jumlah - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < jumlah; ++j) {
            if (daftar[j].judul.toLower() < daftar[minIdx].judul.toLower()) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(daftar[i], daftar[minIdx]);
        }
    }
}

int ManajerBuku::binarySearch(const QString& judul) const {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        QString j = daftar[tengah].judul.toLower();
        if (j == judul.toLower()) return tengah;
        if (j < judul.toLower()) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}
