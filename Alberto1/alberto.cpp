#include "alberto.h"
#include "ui_alberto.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QDirIterator>

Alberto::Alberto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alberto)
{
    ui->setupUi(this);
}

Alberto::~Alberto()
{
    delete ui;
}

void Alberto::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->statusBar->showMessage("Specifica la cartella Epatemp");
        ui->lineEdit->setFocus();
        return;
    }

    QDir epatempFolder(ui->lineEdit->text());

    if(!epatempFolder.exists()){
        ui->statusBar->showMessage("La cartella Epatemp specificata non esiste");
        ui->lineEdit->setFocus();
        return;
    }

    if(ui->lineEdit_2->text().isEmpty()){
        ui->statusBar->showMessage("Specifica la cartella Log");
        ui->lineEdit_2->setFocus();
        return;
    }

    QDir logFolder(ui->lineEdit_2->text());

    if(!logFolder.exists()){
        ui->statusBar->showMessage("La cartella Log specificata non esiste");
        ui->lineEdit_2->setFocus();
        return;
    }

    //ui->statusBar->showMessage("La cartella specificata esiste!");
    QDirIterator it(epatempFolder.absolutePath(), QStringList() << "epatemp.txt", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        qDebug() << it.next();
}
