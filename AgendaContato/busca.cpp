#include "busca.h"
#include "ui_busca.h"

Busca::Busca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busca)
{
    ui->setupUi(this);
    ui->tableWidgetSaida->resizeColumnsToContents();
}

Busca::~Busca()
{
    delete ui;
}

void Busca::on_pushButtonBuscar_clicked()
{
    try{
            QString nome = ui->lineEditBuscaNome->text();
            if(nome == "") throw QString("Campo vazio");
            if(ui->tableWidgetSaida->rowCount() > 0) ui->tableWidgetSaida->setRowCount(0);
            agenda::ContatoPersistencia agendaObj("dados.txt");
            std::list<agenda::Contato> *lista = agendaObj.buscar(nome);
            while (!lista->empty()) {
                agenda::Contato* contato;
                contato = &lista->front();
                nome = contato->getNome();

                QString enderecoResidencial = contato->getEnderecoResidencial().getLogradouro()
                 + " " + contato->getEnderecoResidencial().getCEP()
                 + " " + contato->getEnderecoResidencial().getNumero();

                QString enderecoTrabalho = contato->getEnderecoTrabalho()->getLogradouro()
                 + " " + contato->getEnderecoTrabalho()->getCEP()
                 + " " + contato->getEnderecoTrabalho()->getNumero();

                QString telefoneResidencial = QString::number(contato->getTelefoneResidencial()->getDDI())
                 + " " + QString::number(contato->getTelefoneResidencial()->getDDD())
                 + " " + QString::number(contato->getTelefoneResidencial()->getNumero());

                QString telefoneTrabalho = QString::number(contato->getTelefoneTrabalho()->getDDI())
                 + " " + QString::number(contato->getTelefoneTrabalho()->getDDD())
                 + " " + QString::number(contato->getTelefoneTrabalho()->getNumero());

                QString telefoneCelular = QString::number(contato->getTelefoneCelular()->getDDI())
                 + " " + QString::number(contato->getTelefoneCelular()->getDDD())
                 + " " + QString::number(contato->getTelefoneCelular()->getNumero());

                QString email = contato->getEmail();

                QTableWidgetItem *item1 = new QTableWidgetItem(nome);
                QTableWidgetItem *item2 = new QTableWidgetItem(enderecoResidencial);
                QTableWidgetItem *item3 = new QTableWidgetItem(enderecoTrabalho);
                QTableWidgetItem *item4 = new QTableWidgetItem(telefoneResidencial);
                QTableWidgetItem *item5 = new QTableWidgetItem(telefoneTrabalho);
                QTableWidgetItem *item6 = new QTableWidgetItem(telefoneCelular);
                QTableWidgetItem *item7 = new QTableWidgetItem(email);
                lista->pop_front();

                int linha = ui->tableWidgetSaida->rowCount();
                ui->tableWidgetSaida->insertRow(linha);
                ui->tableWidgetSaida->setItem(linha,0,item1);
                ui->tableWidgetSaida->setItem(linha,1,item2);
                ui->tableWidgetSaida->setItem(linha,2,item3);
                ui->tableWidgetSaida->setItem(linha,3,item4);
                ui->tableWidgetSaida->setItem(linha,4,item5);
                ui->tableWidgetSaida->setItem(linha,5,item6);
                ui->tableWidgetSaida->setItem(linha,6,item7);
            }
            delete lista;

        }catch(QString &erro){
            QMessageBox::information(this, "error", erro);
        }
}
