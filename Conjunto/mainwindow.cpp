#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ObjCA(0),
    ObjCB(0)
{
    ui->setupUi(this);

    //A
    ui->lineEditIncluirConjjuntoA->setEnabled(false);
    ui->pushButtonIncluirConjjuntoA->setEnabled(false);
    ui->lineEditConjuntoA->setEnabled(false);

    //B
    ui->lineEditIncluirConjuntoB->setEnabled(false);
    ui->pushButtonIncluirConjuntoB->setEnabled(false);
    ui->lineEditConjuntoB->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(ObjCA) delete ObjCA;
    if(ObjCB) delete ObjCB;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    try{

    int tamanho = ui->lineEditTamanhoConjuntoA->text().toInt();
    ObjCA = new TP1::Conjunto(tamanho);

    ui->lineEditIncluirConjjuntoA->setEnabled(true);
    ui->pushButtonIncluirConjjuntoA->setEnabled(true);
    ui->lineEditTamanhoConjuntoA->setEnabled(false);
    ui->pushButton->setEnabled(false);


    }catch(QString &erro){
        QMessageBox::information (this,"Erro no sistema",erro);
    }catch(std::bad_alloc&){
        QMessageBox::information(this,"Erro nosistema","Conjunto nao foi criado");
    }
}

void MainWindow::on_pushButtonIncluirConjjuntoA_clicked()
{
    try{
        int elemento = ui->lineEditIncluirConjjuntoA->text().toInt();
        ObjCA->setElemento(elemento);
        ui->lineEditConjuntoA->setText(ObjCA->getConjunto());

        ui->lineEditIncluirConjjuntoA->clear();

    }catch(QString &erro){
        QMessageBox::information (this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonCriarConjuntoB_clicked()
{
    try{
        int tamanho = ui->lineEditTamanhoConjuntoB->text().toInt();
        ObjCB = new TP1::Conjunto(tamanho);

        ui->lineEditIncluirConjuntoB->setEnabled(true);
        ui->pushButtonIncluirConjuntoB->setEnabled(true);
        ui->lineEditTamanhoConjuntoB->setEnabled(false);
        ui->pushButtonCriarConjuntoB->setEnabled(false);

    }catch(QString &erro){
        QMessageBox::information (this,"Erro no sistema",erro);
    }catch(std::bad_alloc&){
        QMessageBox::information(this,"Erro nosistema","Conjunto nao foi criado");
    }
}

void MainWindow::on_pushButtonIncluirConjuntoB_clicked()
{
    try{
        int elemento = ui->lineEditIncluirConjuntoB->text().toInt();
        ObjCB->setElemento(elemento);
        ui->lineEditConjuntoB->setText(ObjCB->getConjunto());

        ui->lineEditIncluirConjuntoB->clear();

    }catch(QString &erro){
        QMessageBox::information (this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonUniao_clicked()
{
    try{
        if(ObjCA==0) throw QString ("Uniao - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("Uniao - Conjunto B nao foi criado");
        TP1::Conjunto *C=ObjCA->calcularUniao(ObjCB);
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Uniao dos conjuntos A e B");
        //QMessageBox::information(this,"UNIAO",aux->getConjunto());
        delete C;
    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonIntersecao_clicked()
{
    try{
        if(ObjCA==0) throw QString ("Intersecao - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("Intersecao - Conjunto B nao foi criado");
        TP1::Conjunto *C=ObjCA->calcularIntersecao(ObjCB);
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Intersecao entre A e B");
        delete C;
    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonDiferenca_clicked()
{
    try{
        if(ObjCA==0) throw QString ("Diferenca A-B - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("Diferenca A-B - Conjunto B nao foi criado");
        TP1::Conjunto *C=ObjCA->calcularDiferenca(ObjCB);
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Diferenca de A - B");
    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
    }


void MainWindow::on_pushButtonDiferencaBA_clicked()
{
    try{
        if(ObjCA==0) throw QString ("Diferenca B-A - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("Diferenca B-A - Conjunto B nao foi criado");
        TP1::Conjunto *C=ObjCB->calcularDiferenca(ObjCA);
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Diferenca de B - A");
    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}



void MainWindow::on_pushButton_2_clicked()
{
    try{
        if(ObjCA==0) throw QString ("SubConjunto A C B - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("SubConjunto A C B - Conjunto B nao foi criado");
        QString saida;
        if(ObjCA->eSubConjunto(ObjCB)) saida="Sim";
        else saida = "Nao";
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("SubConjunto A C B");

    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonSubConjuntoBA_clicked()
{
    try{
        if(ObjCA==0) throw QString ("SubConjunto B C A - Conjunto A nao foi criado");
        if(ObjCB==0) throw QString ("SubConjunto B C A - Conjunto B nao foi criado");
        QString saida;
        if(ObjCB->eSubConjunto(ObjCA)) saida="Sim";
        else saida = "Nao";
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("SubConjunto B C A");

    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonIdenticoAB_clicked()
{
    try {
        if(ObjCA==0)   throw QString("Identico - Conjunto A nao foi criado");
        if(ObjCB==0)   throw QString("Identico - Conjunto B nao foi criado");
        QString saida;
        if  (ObjCA->eIdentico(ObjCB)) saida = "Sim";
        else saida =  "Nao";
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Identicos?");

    } catch (QString &erro) {
        QMessageBox::information(this,"erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonDisjunto_clicked()
{
    try{
        if(ObjCA==0)   throw QString("Disjunto - Conjunto A nao foi criado");
        if(ObjCB==0)   throw QString("Disjunto - Conjunto B nao foi criado");
        QString saida;
        if(ObjCA->eDisjunto(ObjCB)) saida = "Sim";
        else saida = "Nao";
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Disjuntos?");

    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonAmplitude_clicked()
{
    try{
        if(ObjCA==0)   throw QString("Amplitude - Conjunto A nao foi criado");

        QString saida = QString::number(ObjCA->calculaAmplitude());
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Amplitude de A");

    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
}
}

void MainWindow::on_pushButtonAmplitudeB_clicked()
{
    try{
        if(ObjCB==0)   throw QString("Amplitude - Conjunto B nao foi criado");

        QString saida = QString::number(ObjCB->calculaAmplitude());
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Amplitude de B");
    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
}
}




void MainWindow::on_pushButtonProdutoEscalar_clicked()
{
    try{
        if(ObjCA==0)   throw QString("Produto Escalar - Conjunto A nao foi criado");
        if(ObjCB==0)   throw QString("Produto Escalar - Conjunto B nao foi criado");

        QString saida = QString::number(ObjCA->calcularProdutoEscalar(ObjCB));
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Produto escalar");
    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
}

}

void MainWindow::on_pushButtonMaiorSubA_clicked()
{
    try{
        if(ObjCA==0)   throw QString("Maior Sub cadeia de A - Conjunto A nao foi criado");

        TP1::Conjunto *C=ObjCA->maiorSubCadeiaCrescente();
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Maior Sub Cadeia de A");
        delete C;

    } catch(std::bad_alloc&){
        throw QString("Conjunto Uniao nao pode ser criado - Memoria");

    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
    }

}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    try{
        if(ObjCA==0)   throw QString("Ordenar - Conjunto A nao foi criado");
        if(ObjCB==0)   throw QString("Ordenar - Conjunto A nao foi criado");

        TP1::Conjunto *C=ObjCA->ordenar(ObjCB);
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Ordenação de A e B");


    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}


void MainWindow::on_pushButtonMaiorSubB_clicked()
{
    try{
        if(ObjCB==0)   throw QString("Maior Sub cadeia de B - Conjunto A nao foi criado");

        TP1::Conjunto *C=ObjCB->maiorSubCadeiaDecrescente();
        ui->lineEditResultado->setText(C->getConjunto());
        ui->labelResultado->setText("Maior Sub Cadeia B");
    } catch(std::bad_alloc&){
        throw QString("Conjunto Uniao nao pode ser criado - Memoria");

    }catch(QString &erro) {
        QMessageBox::information(this,"Erro no sistema",erro);
    }

}

void MainWindow::on_pushButtonMediaA_clicked()
{
    try{
        if(ObjCA==0) throw QString("Media Aritimetica - Conjunto A nao foi criado");


        QString saida = QString::number(ObjCA->calcularMedia());
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Media Aritimetica");

    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}

void MainWindow::on_pushButtonMediaB_clicked()
{
    try{
        if(ObjCB==0) throw QString("Media Aritimetica - Conjunto B nao foi criado");


        QString saida = QString::number(ObjCB->calcularMedia());
        ui->lineEditResultado->setText(saida);
        ui->labelResultado->setText("Media Aritimetica");

    }catch(QString &erro){
        QMessageBox::information(this,"Erro no sistema",erro);
    }
}
