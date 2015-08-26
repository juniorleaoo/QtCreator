#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MODIFICAÇÃO DA LINEEDIT
    QPalette teste,teste2;
    teste.setColor(QPalette::Text,Qt::white);
    ui->lineEditNumero1->setPalette(teste);
    ui->lineEditNumero2->setPalette(teste);
    ui->lineEditNumero1->setStyleSheet("QLineEdit{background: transparent;}");
    ui->lineEditNumero2->setStyleSheet("QLineEdit{background: transparent;}");


}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
FUNCIONAMENTO DA TECLA ENTER
1º Criei o metodo na mainwindow.h ***void keyPressEvent(QKeyEvent *event);***
na classe da MainWindow
2º Fiz a operação dele na mainwindow.cpp
3º Inclui a biblioteca <QKeyEvent>

EXPLICAÇÃO DO IF
if(event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
quando acontecer o evento que a tecla enter(enter do teclado numerico)
funcionar ou a tecla return(enter do teclado
de letras) ele vai fazer a operação
A operação é ***this->on_pushButtonCalcular_clicked();***
ele vai lá na classe mainwindow e pega o metodo que faz o botão ser clicado
*/
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)
    this->on_pushButtonCalcular_clicked();
}

void MainWindow::on_pushButtonCalcular_clicked()
{
    try{
        long N1 = ui->lineEditNumero1->text().toLong();
        long N2 = ui->lineEditNumero2->text().toLong();
        TP1::NNatural num1;
        TP1::NNatural num2;
        num1.set(N1);
        num2.set(N2);

        //TP1::NNatural aux = num1.calcularFatoria();
        //TP1::NNatural aux2 = num2.calcularFatorial();
        //QString saida1 = QString::number(aux.get());
        //QString saida2 = QString::number(aux2.get());

        //FATORIAL
        QString saida1 = QString::number(num1.calcularFatoria().get());
        QString saida2 = QString::number(num2.calcularFatoria().get());
        QTableWidgetItem *item1= new QTableWidgetItem(saida1);
        QTableWidgetItem *item2= new QTableWidgetItem(saida2);
        ui->tableWidgetTeste->setItem(0,0,item1);
        ui->tableWidgetTeste->setItem(0,1,item2);

        //QUADRADO PERFEITO
        QString saida3;
        if(num1.eQuadradoPerfeito()) saida3 = "Sim";
        else saida3 = "Nao";
        QString saida4;
        if(num2.eQuadradoPerfeito()) saida4 = "Sim";
        else saida4 = "Nao";
        QTableWidgetItem *item3= new QTableWidgetItem(saida3);
        QTableWidgetItem *item4= new QTableWidgetItem(saida4);
        ui->tableWidgetTeste->setItem(1,0,item3);
        ui->tableWidgetTeste->setItem(1,1,item4);

        //CAPICUA
        QString saida5;
        if(num1.eCapicua()) saida5 = "Sim";
        else saida5 = "Nao";
        QString saida6;
        if(num2.eCapicua()) saida6 = "Sim";
        else saida6 = "Nao";
        QTableWidgetItem *item5= new QTableWidgetItem(saida5);
        QTableWidgetItem *item6= new QTableWidgetItem(saida6);
        ui->tableWidgetTeste->setItem(2,0,item5);
        ui->tableWidgetTeste->setItem(2,1,item6);

        //NUMERO PERFEITO
        QString saida7;
        if(num1.eNumeroPerfeito()) saida7= "Sim";
        else saida7="Nao";
        QString saida8;
        if(num2.eNumeroPerfeito()) saida8= "Sim";
        else saida8 = "Nao";
        QTableWidgetItem *item7= new QTableWidgetItem(saida7);
        QTableWidgetItem *item8= new QTableWidgetItem(saida8);
        ui->tableWidgetTeste->setItem(3,0,item7);
        ui->tableWidgetTeste->setItem(3,1,item8);

        //NUMERO PRIMO
        QString saida9;
        if(num1.eNumeroPrimo()) saida9="Sim";
        else saida9 = "Nao";
        QString saida10;
        if(num2.eNumeroPrimo()) saida10="Sim";
        else saida10 = "Nao";
        QTableWidgetItem *item9= new QTableWidgetItem(saida9);
        QTableWidgetItem *item10= new QTableWidgetItem(saida10);
        ui->tableWidgetTeste->setItem(4,0,item9);
        ui->tableWidgetTeste->setItem(4,1,item10);

        //MMC
        TP1::NNatural aux;
        aux=num1.MMC(num2);
        QString saida11 = QString::number(aux.get());
        QString saida12 = QString::number(aux.get());
        QTableWidgetItem *item11= new QTableWidgetItem(saida11);
        QTableWidgetItem *item12= new QTableWidgetItem(saida12);
        ui->tableWidgetTeste->setItem(5,0,item11);
        ui->tableWidgetTeste->setItem(5,1,item12);

        //MDC
        TP1::NNatural aux2;
        aux2=num1.MDC(num2);
        QString saida13 = QString::number(aux2.get());
        QString saida14 = QString::number(aux2.get());
        QTableWidgetItem *item13= new QTableWidgetItem(saida13);
        QTableWidgetItem *item14= new QTableWidgetItem(saida14);
        ui->tableWidgetTeste->setItem(6,0,item13);
        ui->tableWidgetTeste->setItem(6,1,item14);

        //PRIMOS ENTRE SI
        QString saida15;
        if(num1.ePrimoSi(num2)) saida15="Sim";
        else saida15 = "Nao";
        QString saida16;
        if(num2.ePrimoSi(num1)) saida16="Sim";
        else saida16 = "Nao";
        QTableWidgetItem *item15= new QTableWidgetItem(saida15);
        QTableWidgetItem *item16= new QTableWidgetItem(saida16);
        ui->tableWidgetTeste->setItem(7,0,item15);
        ui->tableWidgetTeste->setItem(7,1,item16);

        //BASE 2
        QString saida17 = QString::number(num1.Base2().get());
        QString saida18 = QString::number(num2.Base2().get());
        QTableWidgetItem *item17= new QTableWidgetItem(saida17);
        QTableWidgetItem *item18= new QTableWidgetItem(saida18);
        ui->tableWidgetTeste->setItem(8,0,item17);
        ui->tableWidgetTeste->setItem(8,1,item18);

        //BASE 8
        QString saida19 = QString::number(num1.Base8().get());
        QString saida20 = QString::number(num2.Base8().get());
        QTableWidgetItem *item19= new QTableWidgetItem(saida19);
        QTableWidgetItem *item20= new QTableWidgetItem(saida20);
        ui->tableWidgetTeste->setItem(9,0,item19);
        ui->tableWidgetTeste->setItem(9,1,item20);

        //BASE 16
        QString saida21 = num1.base16();
        QString saida22 = num2.base16();
        QTableWidgetItem *item21= new QTableWidgetItem(saida21);
        QTableWidgetItem *item22= new QTableWidgetItem(saida22);
        ui->tableWidgetTeste->setItem(10,0,item21);
        ui->tableWidgetTeste->setItem(10,1,item22);



        //DESATIVAÇÃO DAS CELULAS
        item1->setFlags(Qt::ItemIsEnabled);
        item2->setFlags(Qt::ItemIsEnabled);
        item3->setFlags(Qt::ItemIsEnabled);
        item4->setFlags(Qt::ItemIsEnabled);
        item5->setFlags(Qt::ItemIsEnabled);
        item6->setFlags(Qt::ItemIsEnabled);
        item7->setFlags(Qt::ItemIsEnabled);
        item8->setFlags(Qt::ItemIsEnabled);
        item9->setFlags(Qt::ItemIsEnabled);
        item10->setFlags(Qt::ItemIsEnabled);
        item11->setFlags(Qt::ItemIsEnabled);
        item12->setFlags(Qt::ItemIsEnabled);
        item13->setFlags(Qt::ItemIsEnabled);
        item14->setFlags(Qt::ItemIsEnabled);
        item15->setFlags(Qt::ItemIsEnabled);
        item16->setFlags(Qt::ItemIsEnabled);
        item17->setFlags(Qt::ItemIsEnabled);
        item18->setFlags(Qt::ItemIsEnabled);
        item19->setFlags(Qt::ItemIsEnabled);
        item20->setFlags(Qt::ItemIsEnabled);
        item21->setFlags(Qt::ItemIsEnabled);
        item22->setFlags(Qt::ItemIsEnabled);

        //ALINHAMENTO DAS CELULAS
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item6->setTextAlignment(Qt::AlignCenter);
        item7->setTextAlignment(Qt::AlignCenter);
        item8->setTextAlignment(Qt::AlignCenter);
        item9->setTextAlignment(Qt::AlignCenter);
        item10->setTextAlignment(Qt::AlignCenter);
        item11->setTextAlignment(Qt::AlignCenter);
        item12->setTextAlignment(Qt::AlignCenter);
        item13->setTextAlignment(Qt::AlignCenter);
        item14->setTextAlignment(Qt::AlignCenter);
        item15->setTextAlignment(Qt::AlignCenter);
        item16->setTextAlignment(Qt::AlignCenter);
        item17->setTextAlignment(Qt::AlignCenter);
        item18->setTextAlignment(Qt::AlignCenter);
        item19->setTextAlignment(Qt::AlignCenter);
        item20->setTextAlignment(Qt::AlignCenter);
        item21->setTextAlignment(Qt::AlignCenter);
        item22->setTextAlignment(Qt::AlignCenter);

        //COR DAS FONTES
        item1->setForeground(Qt::white);
        item2->setForeground(Qt::white);
        item3->setForeground(Qt::white);
        item4->setForeground(Qt::white);
        item5->setForeground(Qt::white);
        item6->setForeground(Qt::white);
        item7->setForeground(Qt::white);
        item8->setForeground(Qt::white);
        item9->setForeground(Qt::white);
        item10->setForeground(Qt::white);
        item11->setForeground(Qt::white);
        item12->setForeground(Qt::white);
        item13->setForeground(Qt::white);
        item14->setForeground(Qt::white);
        item15->setForeground(Qt::white);
        item16->setForeground(Qt::white);
        item17->setForeground(Qt::white);
        item18->setForeground(Qt::white);
        item19->setForeground(Qt::white);
        item20->setForeground(Qt::white);
        item21->setForeground(Qt::white);
        item22->setForeground(Qt::white);



    }catch(QString &erro){
        QMessageBox::information (this,"Erro no sistema",erro);
    }
}
