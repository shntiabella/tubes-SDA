#ifndef MANAJERBUKU_H
#define MANAJERBUKU_H

#include <QObject>
#include "buku.h"

const int MAX_BUKU = 100;

class ManajerBuku : public QObject {
    Q_OBJECT

    // Di bawah deklarasi kelas ManajerBuku, tambahkan fungsi publik untuk akses binarySearch:
public:
    int cariIndexBuku(const QString& judul) const;  // Menambahkan getter untuk akses binarySearch


public:
    explicit ManajerBuku(QObject* parent = nullptr);
    ~ManajerBuku();

    void tambahBuku(const QString& judul, const QString& penulis, const QString& penerbit, int tahun);
    Buku* cariBuku(const QString& judul) const;
    bool updateBuku(const QString& judulLama, const QString& judulBaru, const QString& penulis, const QString& penerbit, int tahun);
    bool hapusBuku(const QString& judul);
    void clear();
    int jumlahBuku() const;
    const Buku* daftarBuku(int index) const;
    Buku* getBuku(int index) const; // Mengambil buku berdasarkan indeks

signals:
    void dataBerubah();

private:
    Buku daftar[MAX_BUKU];
    int jumlah;
    void urutkanJudul(); // untuk binary search
    int binarySearch(const QString& judul) const;
};

#endif // MANAJERBUKU_H
