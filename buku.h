#ifndef BUKU_H
#define BUKU_H

#include <QString>

class Buku {
public:
    QString judul;
    QString penulis;
    QString penerbit;
    int tahun;

    Buku();
    Buku(const QString& judul, const QString& penulis, const QString& penerbit, int tahun);
};

#endif // BUKU_H
