#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <TransformarDados.h>
#include <QMainWindow>
#include <Contato.h>
#include <QMessageBox>
#include <ContatoPersistencia.h>
#include <janela2.h>
#include <busca.h>



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
    void on_pushButtonIncluir_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonListagem_clicked();

    void on_pushButtonEditar_clicked();

    void on_pushButtonBuscar_clicked();

private:
    Ui::MainWindow *ui;
    void limparTela()const;
    };

#endif // MAINWINDOW_H
