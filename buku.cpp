#include "buku.h"

Buku::Buku() : judul(""), penulis(""), penerbit(""), tahun(0) {
}

Buku::Buku(const QString& judul, const QString& penulis, const QString& penerbit, int tahun)
    : judul(judul), penulis(penulis), penerbit(penerbit), tahun(tahun) {
}
