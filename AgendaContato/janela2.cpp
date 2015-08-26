#include "janela2.h"
#include "ui_janela2.h"

janela2::janela2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janela2)
{
    ui->setupUi(this);
    ui->tableWidgetSaida->resizeColumnsToContents();

}

janela2::~janela2()
{
    delete ui;
}

void janela2::on_pushButtonJListar_clicked()
{
    try {
        if(ui->tableWidgetSaida->rowCount() > 0)  ui->tableWidgetSaida->setRowCount(0);
        agenda::ContatoPersistencia agendaContato("dados.txt");
        std::list<agenda::Contato>* objetoContato2 = agendaContato.listagem();

        while(!objetoContato2->empty()){
            agenda::Contato *contato;
            contato = &objetoContato2->front();
            QString nome = contato->getNome();

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
            objetoContato2->pop_front();

            int linha = ui->tableWidgetSaida->rowCount();
            ui->tableWidgetSaida->insertRow(linha);
            ui->tableWidgetSaida->setItem(linha,0,item1);
            ui->tableWidgetSaida->setItem(linha,1,item2);
            ui->tableWidgetSaida->setItem(linha,2,item3);
            ui->tableWidgetSaida->setItem(linha,3,item4);
            ui->tableWidgetSaida->setItem(linha,4,item5);
            ui->tableWidgetSaida->setItem(linha,5,item6);
            ui->tableWidgetSaida->setItem(linha,6,item7);

            ui->tableWidgetSaida->resizeColumnsToContents();
            }
        delete objetoContato2;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void janela2::on_pushButtonVoltarPrincipal_clicked()
{
    this->close();
}


void janela2::on_comboBox_activated(const QString &arg1)
{
    try {
        if(ui->tableWidgetSaida->rowCount() > 0)  ui->tableWidgetSaida->setRowCount(0);
        agenda::ContatoPersistencia agendaContato("dados.txt");
        std::list<agenda::Contato>* objetoContato2 = agendaContato.listagem();
        if(arg1 == "Nome"){
            agenda::OrdenarPorNome listaPorNome;
            listaPorNome.ordenar(*objetoContato2);
        }
        if(arg1 == "Endereco Residencial"){
            agenda::OrdenarPorEndereco listaPorEndereco;
            listaPorEndereco.ordenar(*objetoContato2);
        }
        if(arg1 == "CEP/Nome"){
            agenda::OrdenarPorCepENome listaPorCepENome;
            listaPorCepENome.ordenar(*objetoContato2);
        }
        while(!objetoContato2->empty()){
            agenda::Contato *contato;
            contato = &objetoContato2->front();
            QString nome = contato->getNome();

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
            objetoContato2->pop_front();

            int linha = ui->tableWidgetSaida->rowCount();
            ui->tableWidgetSaida->insertRow(linha);
            ui->tableWidgetSaida->setItem(linha,0,item1);
            ui->tableWidgetSaida->setItem(linha,1,item2);
            ui->tableWidgetSaida->setItem(linha,2,item3);
            ui->tableWidgetSaida->setItem(linha,3,item4);
            ui->tableWidgetSaida->setItem(linha,4,item5);
            ui->tableWidgetSaida->setItem(linha,5,item6);
            ui->tableWidgetSaida->setItem(linha,6,item7);

            ui->tableWidgetSaida->resizeColumnsToContents();

            }
        delete objetoContato2;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
