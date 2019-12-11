#ifndef TEST_H
#define TEST_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class test
{public:
    test();
    test(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_q1();
    QString get_q2();
    QString get_q3();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_personnel_trier();
    QSqlQueryModel *rechercher_personnel(const QString &id);
    bool modifier(int,QString,QString,QString,QString);
    bool supprimer(int);

private:
    QString nom,q1,q2,q3;
    int id;
};

#endif // _H
