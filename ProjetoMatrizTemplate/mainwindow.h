#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Matriz.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonCriarMatA_clicked();

    void on_pushButtonApagarMatA_clicked();

    void on_pushButtonCriarMatB_clicked();

    void on_pushButtonApagarMatB_clicked();

    void on_pushButtonAdicionar_clicked();

    void on_pushButtonSubtracao_clicked();

    void on_pushButtonMultiplicacao_clicked();

    void on_pushButtonIgualdade_clicked();

    void on_pushButtonDiferentes_clicked();

    void on_pushButtonTransposta_clicked();

    void on_pushButtonMultiplicarK_clicked();

    void on_pushButtonPotencia_clicked();

private:
    Ui::MainWindow *ui;
                //
    TP2::Matriz<int> *matA;
    TP2::Matriz<int> *matB;
};

#endif // MAINWINDOW_H
