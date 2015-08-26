#ifndef JANELA2_H
#define JANELA2_H
#include <Contato.h>
#include <QDialog>
#include <QMessageBox>
#include <ContatoPersistencia.h>
#include <QTableWidgetItem>
#include <OrdenarPorNome.h>
#include <OrdenadorTemplateMethod.h>
#include <QInputDialog>
#include <OrdenarPorEndereco.h>
#include <OrdenarPorCepENome.h>


namespace Ui {
class janela2;
}

class janela2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit janela2(QWidget *parent = 0);
    ~janela2();
    
private slots:
    void on_pushButtonJListar_clicked();

    void on_pushButtonVoltarPrincipal_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::janela2 *ui;
};

#endif // JANELA2_H
