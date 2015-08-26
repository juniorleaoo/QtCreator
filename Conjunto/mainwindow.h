#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Conjunto.h"
#include "QMessageBox"
#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_pushButtonIncluirConjjuntoA_clicked();

    void on_pushButtonCriarConjuntoB_clicked();

    void on_pushButtonIncluirConjuntoB_clicked();

    void on_pushButtonUniao_clicked();

    void on_pushButtonIntersecao_clicked();

    void on_pushButtonDiferenca_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonDiferencaBA_clicked();

    void on_pushButtonSubConjuntoBA_clicked();

    void on_pushButtonIdenticoAB_clicked();

    void on_pushButtonDisjunto_clicked();

    void on_pushButtonAmplitude_clicked();

    void on_pushButtonAmplitudeB_clicked();

    void on_pushButtonProdutoEscalar_clicked();

    void on_pushButtonMaiorSubA_clicked();

    void on_pushButtonOrdenar_clicked();

    void on_pushButtonMaiorSubB_clicked();

    void on_pushButtonMediaA_clicked();

    void on_pushButtonMediaB_clicked();

private:
    Ui::MainWindow *ui;
    TP1::Conjunto *ObjCA;
    TP1::Conjunto *ObjCB;
};

#endif // MAINWINDOW_H
