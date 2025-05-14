#ifndef HALAMANUSER_H
#define HALAMANUSER_H

#include <QWidget>
#include "manajerbuku.h"

namespace Ui {
class HalamanUser;
}

class HalamanUser : public QWidget {
    Q_OBJECT

public:
    explicit HalamanUser(ManajerBuku* manajer, QWidget *parent = nullptr);
    ~HalamanUser();

private slots:
    void tampilkanData();  // Untuk menampilkan semua buku
    void cariBuku();  // Untuk mencari buku berdasarkan judul

private:
    Ui::HalamanUser *ui;
    ManajerBuku* manajerBuku;
};

#endif // HALAMANUSER_H
