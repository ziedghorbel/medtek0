#ifndef REPONSES_H
#define REPONSES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reponses
{public:
    reponses();
    reponses(int,int,QString,QString,int);
    int get_idtest();
    int get_idr();
    QString get_reponse();
    int get_point();
        QString get_nomq();
    bool ajouter();
bool modifier(int ,int ,QString ,QString ,int );
    bool supprimer(int);
    QSqlQueryModel * afficher();

    QSqlQueryModel *rechercher_personnel(const QString &id);
    bool modifier(int,int,QString,QString,QString,int);
private:
    QString reponse,nomq;
    int idtest,point,idr;
};

#endif // _H
