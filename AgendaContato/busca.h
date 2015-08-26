#ifndef BUSCA_H
#define BUSCA_H
#include <mainwindow.h>
#include <QDialog>

namespace Ui {
class Busca;
}

class Busca : public QDialog
{
    Q_OBJECT

public:
    explicit Busca(QWidget *parent = 0);
    ~Busca();

private slots:
    void on_pushButtonBuscar_clicked();

private:
    Ui::Busca *ui;
};

#endif // BUSCA_H
