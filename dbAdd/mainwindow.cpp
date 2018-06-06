#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time_t thetime;
    struct tm* timeinfo;
    time( &thetime );
    timeinfo = localtime( &thetime );
    int time = (timeinfo->tm_year + 1900);

    for(int i=time; i>=1980;--i)
    {
        ui->yearCombo->addItem(QString::number(i));
    }

    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->maxText->setEnabled(false);

    mydb = QSqlDatabase::addDatabase("QSQLITE");    //connection to db
    mydb.setDatabaseName("C:/temp/database.db");

    if(mydb.open())
    {
        qDebug() << "Opened";
    }
    else
        qDebug() << "Error =" << mydb.lastError().text();


    if(mydb.isOpen())
    {
        QSqlQuery qry;
        qry.exec("CREATE TABLE vechile "
                 "(vid INTEGER PRIMARY KEY AUTOINCREMENT, "    //creating tables
                 "brand STRING NOT NULL,"
                 "model STRING NOT NULL,"
                 "prodYear INTEGER NOT NULL,"
                 "color STRING NOT NULL)");
 //       qry.exec("INSERT INTO vechile (Brand, Model, ProdYear, Color)"
 //                "VALUES ('Volvo', 'ASD', '1999', 'Red')");
        qry.exec("CREATE TABLE scooter"
                 "(sid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "range INT NOT NULL,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vechile(vid) )");
        qry.exec("CREATE TABLE bike"
                 "(bid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "type STRING NOT NULL,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vechile(vid))");
    }
    else
        qDebug() << "Error =" << mydb.lastError().text();  

}

void MainWindow::add (Vechile *v)
{
  if(mydb.isOpen())
  {
    QSqlQuery qry;
    qDebug() << qry.exec(v ->dbAdd1());
    //qDebug() << v ->dbAdd1();
    qry.exec("SELECT last_insert_rowid()");
    qry.first();
    qry.exec(v->dbAdd2(qry.value(0).toInt()));
  }
  else
      qDebug() << "Error =" << mydb.lastError().text();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->bikeRadio->isChecked())
    {
        Bike v(ui->brandText->text(),
                ui->modelText->text(),
                ui->colorText->text(),
                ui->yearCombo->currentText().toInt(),
                ui->typeText->text());
        vech = &v;
        add(vech);
    }
    else if(ui->scooterRadio->isChecked())
    {
        Scooter v(ui->brandText->text(),
                  ui->modelText->text(),
                  ui->colorText->text(),
                  ui->yearCombo->currentText().toInt(),
                  ui->rangeText->text().toInt());
        vech = &v;
        add(vech);
    }

}

void MainWindow::on_carRadio_clicked()
{
    ui->engText->setEnabled(true);
    ui->doorsText->setEnabled(true);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->maxText->setEnabled(false);
}

void MainWindow::on_truckRadio_clicked()
{
    ui->engText->setEnabled(true);
    ui->doorsText->setEnabled(false);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->maxText->setEnabled(true);
}

void MainWindow::on_bikeRadio_clicked()
{
    ui->engText->setEnabled(false);
    ui->doorsText->setEnabled(false);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(true);
    ui->maxText->setEnabled(false);
}

void MainWindow::on_scooterRadio_clicked()
{
    ui->engText->setEnabled(false);
    ui->doorsText->setEnabled(false);
    ui->rangeText->setEnabled(true);
    ui->typeText->setEnabled(false);
    ui->maxText->setEnabled(false);
}
