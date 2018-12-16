#include "registration.h"

QString Registration::tableName = "registrations";

Registration::Registration(const QString &name, const int licensedAdults, const int unlicensedAdults, const int licensedChildren, const int unlicensedChildren, const int childrenUnder7)
    : _bddId(-1),
      _name(name),
      _numberOfLicencedAdults(licensedAdults),
      _numberOfUnlicencedAdults(unlicensedAdults),
      _numberOfLicencedChildren(licensedChildren),
      _numberOfUnlicencedChildren(unlicensedChildren),
      _numberOfChildrenUnder7(childrenUnder7)
{
}

QVariantHash Registration::getHashValues() const
{
    return QVariantHash{
        { "id",                 QString::number(_bddId) },
        { "name",               _name },
        { "licensedAdults",     QString::number(_numberOfLicencedAdults) },
        { "unlicensedAdults",   QString::number(_numberOfUnlicencedAdults) },
        { "licensedChildren",   QString::number(_numberOfLicencedChildren) },
        { "unlicensedChildren", QString::number(_numberOfUnlicencedChildren) },
        { "childrenUnder7",     QString::number(_numberOfChildrenUnder7) }
    };
}

QStringList Registration::getSqlColumns()
{
    return QStringList() << "id"
                         << "name"
                         << "category"
                         << "membership";
}

QString Registration::tableCreationQuery()
{
    //FIXME Not tested yet !!
    return QString("CREATE TABLE " + Registration::tableName + " ("
                      "id INT PRIMARY KEY NOT NULL,"
                      "name VARCHAR(100),"
                      "licensedAdults INT DEFAULT 0,"
                      "unlicensedAdults INT DEFAULT 0,"
                      "licensedChildren INT DEFAULT 0,"
                      "unlicensedChildren INT DEFAULT 0,"
                      "childrenUnder7 INT DEFAULT 0"
                   ");");
}
