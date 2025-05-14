#ifndef HALAMANADMIN_H
#define HALAMANADMIN_H

#include <QMainWindow>
#include "manajerbuku.h"

namespace Ui {
class HalamanAdmin;
}

class HalamanAdmin : public QMainWindow {
    Q_OBJECT

public:
    explicit HalamanAdmin(ManajerBuku* manajer, QWidget *parent = nullptr);
    ~HalamanAdmin();

private slots:
    void tambahBuku();
    void tampilkanDaftarBuku();
    void updateBuku();
    void hapusBuku();

private:
    Ui::HalamanAdmin *ui;
    ManajerBuku* manajer;
};

#endif // HALAMANADMIN_H
