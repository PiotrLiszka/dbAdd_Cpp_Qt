#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDate>
#include <string>

#include "bike.h"
#include "vehicle.h"
#include "scooter.h"
#include "car.h"
#include "truck.h"
#include "errordialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    void showErrorDialog();

private slots:
    void on_pushButton_clicked();

    void on_carRadio_clicked();

    void on_truckRadio_clicked();

    void on_bikeRadio_clicked();

    void on_scooterRadio_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void addToDb (IVehicle *v);
    bool dbExists(QString path);
    void createTables();
    void databaseConnection();
    bool dataValidation(const std::string data, int &result);
};

#endif // MAINWINDOW_H
