#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "bike.h"
#include "vechile.h"
#include "scooter.h"
#include <ctime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_carRadio_clicked();

    void on_truckRadio_clicked();

    void on_bikeRadio_clicked();

    void on_scooterRadio_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void add (Vechile *v);
    Vechile *vech;
};

#endif // MAINWINDOW_H
