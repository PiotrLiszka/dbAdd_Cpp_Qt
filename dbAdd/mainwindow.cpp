#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



void MainWindow::createTables()
{
    if(mydb.isOpen())
    {
        QSqlQuery qry;
        if(!mydb.tables().contains(QLatin1String("vehicle")))
        {
            qry.exec("CREATE TABLE vehicle "
                 "(vid INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "brand STRING,"
                 "model STRING,"
                 "prodYear DATE FORMAT 'YYYY',"
                 "color STRING NOT NULL)");
        }
        if(!mydb.tables().contains(QLatin1String("scooter")))
        {
            qry.exec("CREATE TABLE scooter"
                 "(sid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "range INT,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vehicle(vid) )");
        }
        if(!mydb.tables().contains(QLatin1String("bike")))
        {
            qry.exec("CREATE TABLE bike"
                 "(bid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "type STRING,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vehicle(vid))");
        }
        if(!mydb.tables().contains(QLatin1String("car")))
        {
            qry.exec("CREATE TABLE car "
                 "(cid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "engine VARCHAR(30),"
                 "doors INTEGER,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vehicle(vid))");
        }
        if(!mydb.tables().contains(QLatin1String("truck")))
        {
            qry.exec("CREATE TABLE truck"
                 "(tid INTEGER PRIMARY KEY AUTOINCREMENT,"
                 "engine VARCHAR(30),"
                 "capacity INTEGER,"
                 "vid INTEGER, FOREIGN KEY (vid) REFERENCES vehicle(vid))");
        }

    }
    else
        qDebug() << "Error =" << mydb.lastError().text();
}

bool MainWindow::dataValidation(const std::string data, int &result )
{
    try
    {
        std::size_t lastChar;
        result = std::stoi(data, &lastChar, 10);
        return lastChar == data.size();
    }
    catch (std::invalid_argument&)
    {
        return false;
    }
    catch (std::out_of_range&)
    {
        return false;
    }
}

void MainWindow::addToDb (IVehicle *v)
{
  if(mydb.isOpen())
  {
    QSqlQuery qry;
    qry.exec(v ->createBaseQuery());
    qry.exec("SELECT last_insert_rowid()");
    qry.first();
    qry.exec(v->createDetailsQuery(qry.value(0).toInt()));
  }
  else
      qDebug() << "Error =" << mydb.lastError().text();
}

bool MainWindow::dbExists(QString path)
{
    QFileInfo check(path);
    if(check.exists() && check.isFile())
        return true;
    else
        return false;
}



void MainWindow::databaseConnection()
{
    QString dbDir = QDir::tempPath();
    QString dbName = "vehicledb.db";
    qDebug() << dbExists(dbDir+"/"+dbName);
    mydb = QSqlDatabase::addDatabase("QSQLITE");                //connection parameters
    mydb.setDatabaseName(dbDir+"/"+dbName);
    if(!dbExists(dbDir+"/"+dbName))
    {
        mydb.open();
        if(mydb.isOpen())
        {
            createTables();
        }
        else
            qDebug() << "Error =" << mydb.lastError().text();
    }
    else
    {
        mydb.open();
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int year = QDate::currentDate().year();

    for(int i=year; i>=1980;--i)
    {
        ui->yearCombo->addItem(QString::number(i));
    }

    ui->doorsCombo->addItem("4");
    ui->doorsCombo->addItem("2");
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->capacityText->setEnabled(false);

    databaseConnection();
    createTables();
}


MainWindow::~MainWindow()
{
    delete ui;
    mydb.close();
}

void MainWindow::showErrorDialog()
{
    ErrorDialog eDialog;
    eDialog.setModal(true);
    eDialog.exec();
    eDialog.show();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->brandText->text().isEmpty() || ui->colorText->text().isEmpty() || ui->modelText->text().isEmpty())
    {
        showErrorDialog();
    }
    else
    {
        QDate year =  QDate::fromString(ui->yearCombo->currentText(),"yyyy");

        if(ui->bikeRadio->isChecked())
        {
            if(ui->typeText->text().isEmpty())
            {
                showErrorDialog();
            }
            else
            {
                Bike v(ui->brandText->text(),
                     ui->modelText->text(),
                     ui->colorText->text(),
                     year,
                     ui->typeText->text());
                addToDb(&v);
            }
        }
        else if(ui->scooterRadio->isChecked())
        {

            int range;
            if(!dataValidation(ui->rangeText->text().toStdString(),range) || range <=0 || ui->rangeText->text().isEmpty())
            {
                showErrorDialog();
            }
            else
            {
            Scooter v(ui->brandText->text(),
                      ui->modelText->text(),
                      ui->colorText->text(),
                     year,
                     ui->rangeText->text().toInt());
            addToDb(&v);
            }
        }
        else if(ui->carRadio->isChecked())
        {
            if(ui->engText->text().isEmpty())
            {
                showErrorDialog();
            }
            else
            {
                Car v(ui->brandText->text(),
                    ui->modelText->text(),
                    ui->colorText->text(),
                    year,
                    ui->engText->text(),
                    ui->doorsCombo->currentText().toInt());
                addToDb(&v);
            }
        }
        else
        {
            int capacity;
            if(!dataValidation(ui->capacityText->text().toStdString(),capacity) || capacity <=0 || ui->engText->text().isEmpty())
            {
                showErrorDialog();
            }
            else
            {
                Truck v(ui->brandText->text(),
                        ui->modelText->text(),
                        ui->colorText->text(),
                        year,
                        ui->engText->text(),
                        capacity);
                addToDb(&v);
            }
        }
    }

}

void MainWindow::on_carRadio_clicked()
{
    ui->engText->setEnabled(true);
    ui->doorsCombo->setEnabled(true);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->capacityText->setEnabled(false);
}

void MainWindow::on_truckRadio_clicked()
{
    ui->engText->setEnabled(true);
    ui->doorsCombo->setEnabled(false);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(false);
    ui->capacityText->setEnabled(true);
}

void MainWindow::on_bikeRadio_clicked()
{
    ui->engText->setEnabled(false);
    ui->doorsCombo->setEnabled(false);
    ui->rangeText->setEnabled(false);
    ui->typeText->setEnabled(true);
    ui->capacityText->setEnabled(false);
}

void MainWindow::on_scooterRadio_clicked()
{
    ui->engText->setEnabled(false);
    ui->doorsCombo->setEnabled(false);
    ui->rangeText->setEnabled(true);
    ui->typeText->setEnabled(false);
    ui->capacityText->setEnabled(false);
}
