#include "reponses.h"
#include <QDebug>
reponses::reponses()
{
idtest=0;
idr=0;
reponse="";
point=0;
nomq="";

}
reponses::reponses(int idr,int idtest ,QString nomq , QString reponse,int point )
{

  this->idr=idr;
  this->idtest=idtest;
    this->reponse=reponse;
    this->nomq=nomq;

      this->point=point;


}
int reponses::get_idr(){return  idr;}
QString reponses::get_reponse(){return reponse;}
int reponses::get_point(){return point;}
QString reponses::get_nomq(){return nomq;}
int reponses::get_idtest(){return  idtest;}

bool reponses::ajouter()
{
QSqlQuery query;
QString res= QString::number(idr);
query.prepare("INSERT INTO reponses (IDR,ID,NOMQ,REPONSE,POINT) "
                    "VALUES (:idr,:idtest,:nomq, :reponse, :point)");
query.bindValue(":idr", res);
query.bindValue(":reponse", reponse);
query.bindValue(":point", point);
query.bindValue(":idtest", idtest);
query.bindValue(":nomq", nomq);
return    query.exec();
}

QSqlQueryModel * reponses::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reponses");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMQ"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("REPONSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("POINT"));
    return model;
}
bool reponses::modifier(int idr,int idtest,QString nomq,QString reponse,int point)
{QSqlQuery query;
  QString res= QString::number(idr);
   query.prepare("UPDATE reponses SET IDR=:idr,ID=:idtest,NOMQ=:nomq,REPONSE=:reponse,POINT=:point WHERE IDR=:idr ") ;
   query.bindValue(":idr", res);
   query.bindValue(":idtest", idtest);
   query.bindValue(":nomq",nomq);
   query.bindValue(":reponse",reponse);
   query.bindValue(":point",point);

   return    query.exec();

}


bool reponses::supprimer(int idr)
{
QSqlQuery query;
QString res= QString::number(idr);
query.prepare("Delete from reponses where IDR = :idr ");
query.bindValue(":idr", res);
return    query.exec();
}
QSqlQueryModel *reponses::rechercher_personnel(const QString &id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   model->setQuery("select * from reponses where(IDR LIKE '"+id+"')");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDR"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMQ"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("REPONSE"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("POINT"));
    return model;
}
