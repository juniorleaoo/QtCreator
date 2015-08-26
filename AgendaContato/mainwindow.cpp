#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonEditar->setDisabled(true);
    ui->pushButtonExcluir->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();

        QString enderecoResidencialLogradouro =ui->lineEditEnderecoResidencialLogradouro->text();
        QString enderecoResidencialCEP = ui->lineEditEnderecoResidencialCEP->text();
        QString enderecoResidencialNumero =ui->lineEditEnderecoResidencialNumero->text();
        agenda::Endereco residencia(enderecoResidencialLogradouro,enderecoResidencialCEP,enderecoResidencialNumero);

        QString enderecoTrabalhoLogradouro = ui->lineEditEnderecoTrabalhoLogradouro->text();
        QString enderecoTrabalhoCEP = ui->lineEditEnderecoTrabalhoCEP->text();
        QString enderecoTrabalhoNumero = ui->lineEditEnderecoTrabalhoNumero->text();
        agenda::Endereco *ptETrabalho = new agenda::Endereco(enderecoTrabalhoLogradouro,enderecoTrabalhoCEP,enderecoTrabalhoNumero);

        int telefoneResidencialDDI = ui->lineEditTelefoneResidencialDDI->text().toInt();
        int telefoneResidencialDDD = ui->lineEditTelefoneResidencialDDD->text().toInt();
        long telefoneResidencialNumero = ui->lineEditTelefoneResidencialNumero->text().toLong();
        agenda::Telefone *ptResidencial = new agenda::Telefone(telefoneResidencialDDI,telefoneResidencialDDD,telefoneResidencialNumero);

        int telefoneTrabalhoDDI = ui->lineEditTelefoneTrabalholDDI->text().toInt();
        int telefoneTrabalhoDDD = ui->lineEditTelefoneTrabalhoDDD->text().toInt();
        long telefoneTrabalhoNumero = ui->lineEditTelefoneTrabalhoNumero->text().toLong();
        agenda::Telefone *ptTrabalho = new agenda::Telefone(telefoneTrabalhoDDI,telefoneTrabalhoDDD,telefoneTrabalhoNumero);

        int telefoneCelularDDI = ui->lineEditTelefoneCelularDDI->text().toInt();
        int telefoneCelularDDD = ui->lineEditTelefoneCelularlDDD->text().toInt();
        long telefoneCelularNumero = ui->lineEditTelefoneCelularNumero->text().toLong();
        agenda::Telefone *ptCelular = new agenda::Telefone(telefoneCelularDDI,telefoneCelularDDD,telefoneCelularNumero);

        QString email = ui->lineEditEmail->text();

        agenda::Telefone *ptTelefones[3];
        ptTelefones[0] = ptTrabalho;
        ptTelefones[1] = ptResidencial;
        ptTelefones[2] = ptCelular;

        agenda::Contato objetoContato(nome,ptTelefones,residencia,ptETrabalho,email);
        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.incluir(objetoContato);
        delete ptResidencial, ptCelular, ptTrabalho, ptETrabalho;

        limparTela();
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(std::bad_alloc&){
            throw QString("nao ha memoria suficiente.");
    }

}

void MainWindow::limparTela()const{
    ui->lineEditNome->clear();
    ui->lineEditEmail->clear();
    ui->lineEditEnderecoResidencialCEP->clear();
    ui->lineEditEnderecoResidencialLogradouro->clear();
    ui->lineEditEnderecoResidencialNumero->clear();
    ui->lineEditEnderecoTrabalhoCEP->clear();
    ui->lineEditEnderecoTrabalhoLogradouro->clear();
    ui->lineEditEnderecoTrabalhoNumero->clear();
    ui->lineEditTelefoneCelularDDI->clear();
    ui->lineEditTelefoneCelularlDDD->clear();
    ui->lineEditTelefoneCelularNumero->clear();
    ui->lineEditTelefoneResidencialDDD->clear();
    ui->lineEditTelefoneResidencialDDI->clear();
    ui->lineEditTelefoneResidencialNumero->clear();
    ui->lineEditTelefoneTrabalhoDDD->clear();
    ui->lineEditTelefoneTrabalholDDI->clear();
    ui->lineEditTelefoneTrabalhoNumero->clear();
}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try{
        QString nome = ui->lineEditNome->text();
        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.excluir(nome);
        this->limparTela();
        ui->pushButtonIncluir->setDisabled(false);
        ui->pushButtonExcluir->setDisabled(true);
        ui->pushButtonEditar->setDisabled(true);

    }catch(QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonListagem_clicked()
{
    janela2 j2;
    j2.setModal(true);//gestor da janela
    j2.exec();
}

void MainWindow::on_pushButtonEditar_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();
        if(nome == "") throw QString("Campo nome vazio");

        QString enderecoResidencialLogradouro =ui->lineEditEnderecoResidencialLogradouro->text();
        QString enderecoResidencialCEP = ui->lineEditEnderecoResidencialCEP->text();
        QString enderecoResidencialNumero =ui->lineEditEnderecoResidencialNumero->text();
        agenda::Endereco residencia(enderecoResidencialLogradouro,enderecoResidencialCEP,enderecoResidencialNumero);

        QString enderecoTrabalhoLogradouro = ui->lineEditEnderecoTrabalhoLogradouro->text();
        QString enderecoTrabalhoCEP = ui->lineEditEnderecoTrabalhoCEP->text();
        QString enderecoTrabalhoNumero = ui->lineEditEnderecoTrabalhoNumero->text();
        agenda::Endereco *ptETrabalho = new agenda::Endereco(enderecoTrabalhoLogradouro,enderecoTrabalhoCEP,enderecoTrabalhoNumero);

        int telefoneResidencialDDI = ui->lineEditTelefoneResidencialDDI->text().toInt();
        int telefoneResidencialDDD = ui->lineEditTelefoneResidencialDDD->text().toInt();
        long telefoneResidencialNumero = ui->lineEditTelefoneResidencialNumero->text().toLong();
        agenda::Telefone *ptResidencial = new agenda::Telefone(telefoneResidencialDDI,telefoneResidencialDDD,telefoneResidencialNumero);

        int telefoneTrabalhoDDI = ui->lineEditTelefoneTrabalholDDI->text().toInt();
        int telefoneTrabalhoDDD = ui->lineEditTelefoneTrabalhoDDD->text().toInt();
        long telefoneTrabalhoNumero = ui->lineEditTelefoneTrabalhoNumero->text().toLong();
        agenda::Telefone *ptTrabalho = new agenda::Telefone(telefoneTrabalhoDDI,telefoneTrabalhoDDD,telefoneTrabalhoNumero);

        int telefoneCelularDDI = ui->lineEditTelefoneCelularDDI->text().toInt();
        int telefoneCelularDDD = ui->lineEditTelefoneCelularlDDD->text().toInt();
        long telefoneCelularNumero = ui->lineEditTelefoneCelularNumero->text().toLong();
        agenda::Telefone *ptCelular = new agenda::Telefone(telefoneCelularDDI,telefoneCelularDDD,telefoneCelularNumero);

        QString email = ui->lineEditEmail->text();

        agenda::Telefone *ptTelefones[3];
        ptTelefones[0] = ptTrabalho;
        ptTelefones[1] = ptResidencial;
        ptTelefones[2] = ptCelular;

        agenda::Contato objetoContato(nome,ptTelefones,residencia,ptETrabalho,email);

        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.editar(objetoContato);
        delete ptResidencial, ptCelular, ptTrabalho, ptETrabalho;
        limparTela();
        /*ui->pushButtonIncluir->setDisabled(false);
        ui->pushButtonExcluir->setDisabled(true);
        ui->pushButtonEditar->setDisabled(true);*/

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(std::bad_alloc&){
        throw QString("nao ha memoria suficiente.");
    }
}

void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        /*Busca j3;
    j3.setModal(true);//gestor da janela
    j3.exec();*/
        QString nome = QInputDialog::getText(this,"Leitura","Nome: ");
        if(nome == "") throw QString("Campo nome vazio");

        agenda::ContatoPersistencia agendaObj("dados.txt");
        std::list<agenda::Contato> *objeto = agendaObj.buscar(nome);
        //agenda::Contato contato = objeto->front();

        agenda::Contato *contato = new agenda::Contato(objeto->front());

        ui->lineEditNome->setText(contato->getNome());
        ui->lineEditEnderecoResidencialLogradouro->setText(contato->getEnderecoResidencial().getLogradouro());
        ui->lineEditEnderecoResidencialCEP->setText(contato->getEnderecoResidencial().getCEP());
        ui->lineEditEnderecoResidencialNumero->setText(contato->getEnderecoResidencial().getNumero());

        ui->lineEditEnderecoTrabalhoLogradouro->setText(contato->getEnderecoTrabalho()->getLogradouro());
        ui->lineEditEnderecoTrabalhoCEP->setText(contato->getEnderecoTrabalho()->getCEP());
        ui->lineEditEnderecoTrabalhoNumero->setText(contato->getEnderecoTrabalho()->getNumero());

        ui->lineEditTelefoneResidencialDDI->setText(QString::number(contato->getTelefoneResidencial()->getDDI()));
        ui->lineEditTelefoneResidencialDDD->setText(QString::number(contato->getTelefoneResidencial()->getDDD()));
        ui->lineEditTelefoneResidencialNumero->setText(QString::number(contato->getTelefoneResidencial()->getNumero()));

        ui->lineEditTelefoneTrabalholDDI->setText(QString::number(contato->getTelefoneTrabalho()->getDDI()));
        ui->lineEditTelefoneTrabalhoDDD->setText(QString::number(contato->getTelefoneTrabalho()->getDDD()));
        ui->lineEditTelefoneTrabalhoNumero->setText(QString::number(contato->getTelefoneTrabalho()->getNumero()));

        ui->lineEditTelefoneCelularDDI->setText(QString::number(contato->getTelefoneCelular()->getDDI()));
        ui->lineEditTelefoneCelularlDDD->setText(QString::number(contato->getTelefoneCelular()->getDDD()));
        ui->lineEditTelefoneCelularNumero->setText(QString::number(contato->getTelefoneCelular()->getNumero()));

        ui->lineEditEmail->setText(contato->getEmail());

        delete contato;

        ui->pushButtonEditar->setDisabled(false);
        ui->pushButtonExcluir->setDisabled(false);
        ui->pushButtonIncluir->setDisabled(true);
    }catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(std::bad_alloc&){
        throw QString("nao ha memoria suficiente.");
    }
}
