#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    matA(0),
    matB(0)
{
    ui->setupUi(this);
    ui->textEditSaidaMatA->setEnabled(false);
    ui->pushButtonApagar->setEnabled(false);
    ui->textEditSaidaMatB->setEnabled(false);
    ui->pushButtonApagarB->setEnabled(false);
}
MainWindow::~MainWindow()
{
    /*eu deleto antes do "delete ui" para ele ser deletado antes de deletar a ui */
    if(matA) delete matA;
    if(matB) delete matB;
    delete ui;
}

void MainWindow::on_pushButtonCriarMatA_clicked()
{
    try {
        /* a problema de eu criar ele na forma normal, é que o matA só vai existir aqui dentro do escopo, e para vazar
 o escopo só é permitido por ponteiro
o matA tem que ser visto por todos os botoes da mainwindow, por isso que criei ele como atributo*/

        int linha = ui->lineEditQuantidadeDeLinhasMatA->text().toInt();
        int coluna = ui->lineEditQuantidadeDeColunasMatA->text().toInt();
        matA = new TP2::Matriz(linha,coluna); /*acessei a namespace TP2 e acionei o construtor Matriz e passei a linha e coluna como parâmetro */
        for(int l=0; l<linha;l++){
            for(int c=0; c < coluna; c++){
                int elemento = QInputDialog::getInt(this, "Leitura",
                                                    "Matriz A ["+QString::number(l)+","+
                                                    QString::number(c) + "] = ");
                matA->setElemento(elemento,l,c);
            }
        }

        //IDENTIDADE
        QString saida1;
        if(matA->matrizIdentidade())
            saida1 = "Sim";
        else
            saida1 = "Não";

        //TRIANGULAR SUPERIOR
        QString saida3;
        if(matA->matrizTringSuperior())
            saida3 = "Sim";
        else
            saida3 = "Não";

        //TRIANGULAR INFERIOR
        QString saida5;
        if(matA->matrizTriangInferior())
            saida5 = "Sim";
        else
            saida5 = "Não";

        //SIMETRICA
        QString saida7;
        if(matA->matrizSimetrica())
            saida7 = "Sim";
        else
            saida7 = "nao";

        //ORTOGONAL
        QString saida9;
        if(matA->ortogonal())
            saida9 = "Sim";
        else
            saida9 = "Nao";

        //PERMUTAVEL
        QString saida11;
        if(matA->permutacao())
            saida11 = "Sim";
        else
            saida11 = "Nao";

        QTableWidgetItem *item3= new QTableWidgetItem(saida3);
        ui->tableWidgetResultado->setItem(0,0,item3);
        QTableWidgetItem *item5= new QTableWidgetItem(saida5);
        ui->tableWidgetResultado->setItem(1,0,item5);
        QTableWidgetItem *item7= new QTableWidgetItem(saida7);
        ui->tableWidgetResultado->setItem(2,0,item7);
        QTableWidgetItem *item1= new QTableWidgetItem(saida1);
        ui->tableWidgetResultado->setItem(3,0,item1);
        QTableWidgetItem *item9= new QTableWidgetItem(saida9);
        ui->tableWidgetResultado->setItem(4,0,item9);
        QTableWidgetItem *item11= new QTableWidgetItem(saida11);
        ui->tableWidgetResultado->setItem(5,0,item11);

        //DESATIVANDO TABELA
        item1->setFlags(Qt::ItemIsEnabled);
        item3->setFlags(Qt::ItemIsEnabled);
        item5->setFlags(Qt::ItemIsEnabled);
        item7->setFlags(Qt::ItemIsEnabled);
        item9->setFlags(Qt::ItemIsEnabled);
        item11->setFlags(Qt::ItemIsEnabled);



        ui->textEditSaidaMatA->setText(matA->getMatriz());
        ui->lineEditQuantidadeDeColunasMatA->setEnabled(false);
        ui->lineEditQuantidadeDeLinhasMatA->setEnabled(false);
        ui->pushButtonCriarMatA->setEnabled(false);
        ui->pushButtonApagar->setEnabled(true);



    } catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO NO SISTEMA", "Vai comprar memoria");
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonApagar_clicked()
{
    if(matA) delete matA;
    matA = 0;
    ui->lineEditQuantidadeDeLinhasMatA->clear();
    ui->lineEditQuantidadeDeColunasMatA->clear();
    ui->textEditSaidaMatA->clear();
    ui->lineEditQuantidadeDeColunasMatA->setEnabled(true);
    ui->lineEditQuantidadeDeLinhasMatA->setEnabled(true);
    ui->pushButtonCriarMatA->setEnabled(true);
    ui->pushButtonApagar->setEnabled(false);

}

void MainWindow::on_pushButtonCriarMatB_clicked()
{
    try {

        int linha = ui->lineEditQuantidadeDeLinhasMatB->text().toInt();
        int coluna = ui->lineEditQuantidadeDeColunasMatB->text().toInt();
        matB = new TP2::Matriz(linha,coluna);
        for(int l=0; l<linha;l++){
            for(int c=0; c < coluna; c++){
                int elemento = QInputDialog::getInt(this, "Leitura",
                                                    "Matriz B ["+QString::number(l)+","+
                                                    QString::number(c) + "] = ");
                matB->setElemento(elemento,l,c);
            }
        }

        //IDENTIDADE
        QString saida2;
        if(matB->matrizIdentidade())
            saida2 = "Sim";
        else
            saida2 = "Não";

        //TRIANGULAR SUPERIOR
        QString saida4;
        if(matB->matrizTringSuperior())
            saida4 = "Sim";
        else
            saida4 = "Não";

        //TRIANGULAR INFERIOR
        QString saida6;
        if(matB->matrizTriangInferior())
            saida6 = "Sim";
        else
            saida6 = "Não";

        //SIMETRICA
        QString saida8;
        if(matB->matrizSimetrica())
            saida8 = "Sim";
        else
            saida8 = "Não";

        //ORTOGONAL
        QString saida10;
        if(matB->ortogonal())
            saida10 = "Sim";
        else
            saida10 = "Nao";

        //PERMUTAVEL
        QString saida12;
        if(matB->permutacao())
            saida12 = "Sim";
        else
            saida12 = "Nao";

        QTableWidgetItem *item4= new QTableWidgetItem(saida4);
        ui->tableWidgetResultado->setItem(0,1,item4);
        QTableWidgetItem *item6= new QTableWidgetItem(saida6);
        ui->tableWidgetResultado->setItem(1,1,item6);
        QTableWidgetItem *item8= new QTableWidgetItem(saida8);
        ui->tableWidgetResultado->setItem(2,1,item8);
        QTableWidgetItem *item2= new QTableWidgetItem(saida2);
        ui->tableWidgetResultado->setItem(3,1,item2);
        QTableWidgetItem *item10= new QTableWidgetItem(saida10);
        ui->tableWidgetResultado->setItem(4,1,item10);
        QTableWidgetItem *item12= new QTableWidgetItem(saida12);
        ui->tableWidgetResultado->setItem(5,1,item12);

        //DESATIVANDO TABELA
        item4->setFlags(Qt::ItemIsEnabled);
        item6->setFlags(Qt::ItemIsEnabled);
        item8->setFlags(Qt::ItemIsEnabled);
        item2->setFlags(Qt::ItemIsEnabled);
        item10->setFlags(Qt::ItemIsEnabled);
        item12->setFlags(Qt::ItemIsEnabled);

        ui->textEditSaidaMatB->setText(matB->getMatriz());
        ui->lineEditQuantidadeDeColunasMatB->setEnabled(false);
        ui->lineEditQuantidadeDeLinhasMatB->setEnabled(false);
        ui->pushButtonCriarMatB->setEnabled(false);
        ui->pushButtonApagarB->setEnabled(true);



    } catch(std::bad_alloc&){
        QMessageBox::information(this,"ERRO NO SISTEMA", "Vai comprar memoria");
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonApagarB_clicked()
{
    if(ui->pushButtonCriarMatA)
        if(matB) delete matB;
    matB = 0;
    ui->lineEditQuantidadeDeLinhasMatB->clear();
    ui->lineEditQuantidadeDeColunasMatB->clear();
    ui->textEditSaidaMatB->clear();
    ui->lineEditQuantidadeDeColunasMatB->setEnabled(true);
    ui->lineEditQuantidadeDeLinhasMatB->setEnabled(true);
    ui->pushButtonCriarMatB->setEnabled(true);
    ui->pushButtonApagarB->setEnabled(false);

}

void MainWindow::on_pushButtonSubtracao_clicked()
{
    QStringList aux;
    aux<<"A - B";
    aux<<"B - A";
    QString aux2 = QInputDialog::getItem(this,"Acao","Selecione a formula ",aux,0,false);
    if(aux2 == "A - B"){
        try{
            if(matA==0) throw QString("Operacao de - nao pode ser executada");
            if(matB==0) throw QString("Operacao de - nao pode ser executada");
            TP2::Matriz *matC = (*matA)-matB;
            ui->textEditSaidaResultado->setText(matC->getMatriz());
            if(matC) delete matC;

        }catch(QString &erro){
            QMessageBox::information(this, "ERRO NO SISTEMA",erro);
        }
    }
    if(aux2 == "B - A"){
        try{
            if(matA==0) throw QString("Operacao de - nao pode ser executada");
            if(matB==0) throw QString("Operacao de - nao pode ser executada");
            TP2::Matriz *matC = (*matB)-matA;
            ui->textEditSaidaResultado->setText(matC->getMatriz());
            if(matC) delete matC;

        }catch(QString &erro){
            QMessageBox::information(this, "ERRO NO SISTEMA",erro);
        }
    }
}

void MainWindow::on_pushButtonAdicionar_clicked()
{
    try{
        if(matA==0) throw QString("Operacao de + nao pode ser executada");
        if(matB==0) throw QString("Operacao de + nao pode ser executada");
        TP2::Matriz *matC = (*matA)+matB; //pra quem o matA aponta e soma com o matB, o "+" tem como parâmetro um ponteiro, por isso ele não usa o (*matB)
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonMultiplicacao_clicked()
{
    QStringList aux;
    aux<< "A * B";
    aux<<"B * A";

    QString aux2 = QInputDialog::getItem(this,"Acao","Selecione a formula ",aux,0,false);
    if(aux2 == "A * B")
        try{
        if(matA==0) throw QString("Operacao * nao pode ser executada");
        if(matB==0) throw QString("Operacao * nao pode ser executada");
        TP2::Matriz *matC = (*matA) * matB;;
        //matC = matA->operator *(matB)
        ui->textEditSaidaResultado->setText(matC->getMatriz());

        if(matC) delete matC;
    }catch(QString erro){
        QMessageBox::information(this,"erro",erro);
    }

    if(aux2 == "B * A"){
        try{
            if(matA==0) throw QString("Operacao * nao pode ser executada");
            if(matB==0) throw QString("Operacao * nao pode ser executada");
            TP2::Matriz *matC = (*matB) * matA;
            //matC = matA->operator *(matB)
            ui->textEditSaidaResultado->setText(matC->getMatriz());
            if(matC) delete matC;
        }catch(QString erro){
            QMessageBox::information(this,"erro",erro);
        }

    }
}

void MainWindow::on_pushButtonIgualdade_clicked()
{
    try{
        if(matA==0) throw QString("Operacao == nao pode ser executada");
        if(matB==0) throw QString("Operacao == nao pode ser executada");

        if((*matA) == matB)
            QMessageBox::information(this, "Matrizes","Matrizes iguais");
        else
            QMessageBox::information(this, "Matrizes","Matrizes diferentes");

    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonDiferentes_clicked()
{
    try{
        if(matA==0) throw QString("Operacao == nao pode ser executada");
        if(matB==0) throw QString("Operacao == nao pode ser executada");

        if((*matA) != matB)
            QMessageBox::information(this, "Matrizes","Matrizes diferentes");
        else
            QMessageBox::information(this, "Matrizes","Matrizes iguais");
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}


void MainWindow::on_pushButton_clicked()
{
    QStringList aux;
    aux<< "A";
    aux<<"B";
    QString aux2 = QInputDialog::getItem(this,"Acao","Selecione",aux,0,false);

    if(aux2 == "A"){
        try{
            if(matA==0) throw QString("Operacao de 'Transposta' nao pode ser executada");
            TP2::Matriz *matC = matA->matrizTransp();
            ui->textEditSaidaResultado->setText(matC->getMatriz());

        }catch(QString erro){
            QMessageBox::information(this,"erro",erro);
        }
    }

    if(aux2 == "B"){
        try{
            if(matB==0) throw QString("Operacao de 'Transposta' nao pode ser executada");
            TP2::Matriz *matC = matB->matrizTransp();
            ui->textEditSaidaResultado->setText(matC->getMatriz());
        }catch(QString erro){
            QMessageBox::information(this,"erro",erro);
        }
    }

}



void MainWindow::on_pushButtonMultiplicarK_clicked()
{
    QStringList aux;
    aux<<"A";
    aux<<"B";
    QString aux2 = QInputDialog::getItem(this,"Acao","Selecione a matriz",aux,0,false);
    if(aux2 == "A"){
        try{
            int elemento = QInputDialog::getInt(this, "Leitura","K =");
            TP2::Matriz *matC = matA->multiplicarK(elemento);

            ui->textEditSaidaResultado->setText(matC->getMatriz());
            if(matC) delete matC;
        }catch(QString &erro){
            QMessageBox::information(this, "ERRO NO SISTEMA",erro);
        }
    }
    if(aux2 == "B"){
        try{
            int elemento = QInputDialog::getInt(this, "Leitura","K =");
            TP2::Matriz *matC = matB->multiplicarK(elemento);

            ui->textEditSaidaResultado->setText(matC->getMatriz());
            if(matC) delete matC;
        }catch(QString &erro){
            QMessageBox::information(this, "ERRO NO SISTEMA",erro);
        }
    }


}

void MainWindow::on_pushButtonPotencia_clicked()
{
    try{
        int elemento = QInputDialog::getInt(this, "Potencia","N =");
        TP2::Matriz *matC = matA->potencia(elemento);
        ui->textEditSaidaResultado->setText(matC->getMatriz());
        if(matC) delete matC;
    }catch(QString &erro){
        QMessageBox::information(this, "ERRO NO SISTEMA",erro);
    }
}
