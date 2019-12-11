#include "test.h"
#include <QDebug>
test::test()
{
id=0;
nom="";
q1="";
q2="";
q3="";
}
test::test(int id,QString nom,QString q1,QString q2 , QString q3 )
{
  this->id=id;
  this->nom=nom;
  this->q1=q1;
      this->q2=q2;
      this->q3=q3;
}
QString test::get_nom(){return  nom;}
QString test::get_q1(){return q1;}
QString test::get_q2(){return q2;}
QString test::get_q3(){return q3;}
int test::get_id(){return  id;}

bool test::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO test (ID, NOM, Q1, Q2, Q3) "
                    "VALUES (:id, :nom, :q1,:q2,:q3)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":q1", q1);
query.bindValue(":q2", q2);
query.bindValue(":q3", q3);

return    query.exec();
}

QSqlQueryModel * test::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from test");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("q1"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("q2"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("q3"));

    return model;
}

bool test::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from test where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel *test::afficher_personnel_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from test ORDER BY ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("q1"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("q2"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("q3"));
    return model;
}

QSqlQueryModel *test::rechercher_personnel(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from test where(ID LIKE '"+id+"%')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("q1"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("q2"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("q3"));
    return model;
}


bool test::modifier(int id,QString nom,QString q1,QString q2,QString q3)
{QSqlQuery query;
  QString res= QString::number(id);
   query.prepare("UPDATE TEST SET ID=:id,NOM=:nom,Q1=:q1,Q2=:q2,Q3=:q3 WHERE ID=:id ") ;
   query.bindValue(":id", res);
   query.bindValue(":nom", nom);
   query.bindValue(":q2",q2);
   query.bindValue(":q3",q3);
   query.bindValue(":q1",q1);

   return    query.exec();

}

