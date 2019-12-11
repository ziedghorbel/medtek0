#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include "reponses.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include "arduino.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabtest->setModel(tmptest.afficher());
  ui->tableView_3->setModel(tmptest.afficher_personnel_trier());
  ui->tabr->setModel(tmpreponses.afficher());
int ret=A.connect_arduino();
switch(ret){
case(0):qDebug()<<"arduino is available and connected to" << A.getarduino_port_name();
break;
case(1):qDebug()<<"arduino is available and not connected to "<<A.getarduino_port_name() ;
break;
case(-1):qDebug()<<"arduino is not available";
break;
}
QObject::connect(A.getserial(),SIGNAL(readyread()),this,SLOT(update_label()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString q1= ui->lineEdit_q1->text();
    QString q2= ui->lineEdit_q2->text();
    QString q3= ui->lineEdit_q3->text();
    test e(id,nom,q1,q2,q3);
  bool tests=e.ajouter();
  if(tests)
{ui->tabtest->setModel(tmptest.afficher());
      ui->tableView_3->setModel(tmptest.afficher_personnel_trier());

QMessageBox::information(nullptr, QObject::tr("Ajouter un test"),
                  QObject::tr("Test ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un test"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_ajouter_4_clicked()
{QString nom= ui->lineEdit_nom_2->text();
    int id= ui->lineEdit_id_4->text().toInt();
    QString q1=ui->lineEdit_q1_2->text();
QString q2=ui->lineEdit_q2_2->text();
QString q3=ui->lineEdit_q3_2->text();
    bool test=tmptest.modifier(id,nom,q1,q2,q3);

    if(test)
    {
        ui->tabtest->setModel(tmptest.afficher());
          ui->tableView_3->setModel(tmptest.afficher_personnel_trier());

  QMessageBox::information(nullptr, QObject::tr("modifier un test"),
                    QObject::tr("test modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un test"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

  }
void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id1->text().toInt();
bool test=tmptest.supprimer(id);
if(test)
{ui->tabtest->setModel(tmptest.afficher());
    ui->tableView_3->setModel(tmptest.afficher_personnel_trier());

    QMessageBox::information(nullptr, QObject::tr("Supprimer un test"),
                QObject::tr("test supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Close);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un test"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QString id = ui->lineEdit_id1_2->text();
       ui->tableView->setModel(tmptest.rechercher_personnel(id));
       ui->tabtest->setModel(tmptest.afficher());


}












void MainWindow::on_pushButton_clicked()
{
    int idr = ui->lineEdit_id_3->text().toInt();
    QString nomq= ui->lineEdit_nom->text();
     int idtest = ui->lineEdit_reponse->text().toInt();
    int point = ui->lineEdit_2->text().toInt();
    QString reponse= ui->lineEdit->text();
    reponses e(idr,idtest,nomq,reponse,point);
  bool tests=e.ajouter();
  if(tests)
{  ui->tabr->setModel(tmpreponses.afficher());


QMessageBox::information(nullptr, QObject::tr("Ajouter une reponse"),
                  QObject::tr("Test ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Close);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reponse"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Close);


}

void MainWindow::on_pushButton_2_clicked()
{int idr = ui->lineEdit_id_5->text().toInt();
    QString nomq= ui->lineEdit_1->text();
     int idtest = ui->lineEdit_reponse_2->text().toInt();
    int point = ui->lineEdit_4->text().toInt();
    QString reponse= ui->lineEdit_3->text();
    bool test=tmpreponses.modifier(idr,idtest,nomq,reponse,point);

    if(test)
    {
        ui->tabr->setModel(tmpreponses.afficher());


  QMessageBox::information(nullptr, QObject::tr("modifier une reponse"),
                    QObject::tr("test modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une reponse"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

  }


void MainWindow::on_pushButton_3_clicked()
{
int id = ui->lineEdit_id_6->text().toInt();
bool test=tmpreponses.supprimer(id);
if(test)
{ui->tabr->setModel(tmpreponses.afficher());

    QMessageBox::information(nullptr, QObject::tr("Supprimer une reponse"),
                QObject::tr("test supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Close);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une reponse"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_supprimer_3_clicked()
{
    QString id = ui->lineEdit_id1_3->text();
       ui->tableView_2->setModel(tmpreponses.rechercher_personnel(id));



}
void MainWindow::update_label()
{ data=A.read_from_arduino();
    if(data=="1")
    ui->label_30->setText("khra");
            else

    ui->label_30->setText("fuck");




}

