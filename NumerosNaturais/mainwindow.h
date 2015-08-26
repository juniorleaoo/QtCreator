#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <NNatural.h>

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
    void on_pushButtonCalcular_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
