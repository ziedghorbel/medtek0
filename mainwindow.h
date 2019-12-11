#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "test.h"
#include "reponses.h"
#include <QMainWindow>
#include<QPropertyAnimation>
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
void on_pb_supprimer_3_clicked();
    void on_pb_supprimer_clicked();

    void on_pb_supprimer_2_clicked();
    void on_pb_ajouter_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void update_label();
private:
    Ui::MainWindow *ui;
    test tmptest;
    reponses tmpreponses ;
QPropertyAnimation *animation;
QByteArray data ;
arduino A;
};

#endif // MAINWINDOW_H
