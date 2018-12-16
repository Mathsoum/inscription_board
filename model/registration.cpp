#include "registration.h"

QString Registration::tableName = "registrations";

Registration::Registration():
    _bddId(-1),
    _name(""),
    _numberOfLicencedAdults(0),
    _numberOfUnlicencedAdults(0),
    _numberOfLicencedChildren(0),
    _numberOfUnlicencedChildren(0),
    _numberOfChildrenUnder7(0),
    _hasPayed(false),
    _paymentMethod(PaymentMethod::NOT_PAYED)
{

}

Registration::Registration(const QString &name, const int licensedAdults, const int unlicensedAdults, const int licensedChildren, const int unlicensedChildren, const int childrenUnder7)
    : Registration()
{
    _name                       = { name };
    _numberOfLicencedAdults     = { licensedAdults };
    _numberOfUnlicencedAdults   = { unlicensedAdults };
    _numberOfLicencedChildren   = { licensedChildren };
    _numberOfUnlicencedChildren = { unlicensedChildren };
    _numberOfChildrenUnder7     = { childrenUnder7 };
}

#define RECORD_LOOKUP(entry, attr) if(record.contains(entry)) attr = record[entry]
Registration::Registration(const QVariantHash &record)
{
    if (!record.isEmpty()) {
        if (record.contains("id")) _bddId = record["id"].toInt();
        if (record.contains("name")) _name = record["name"].toString();
        if (record.contains("licensedAdults")) _numberOfLicencedAdults = record["licensedAdults"].toInt();
        if (record.contains("unlicensedAdults")) _numberOfUnlicencedAdults = record["unlicensedAdults"].toInt();
        if (record.contains("licensedChildren")) _numberOfLicencedChildren = record["licensedChildren"].toInt();
        if (record.contains("unlicensedChildren")) _numberOfUnlicencedChildren = record["unlicensedChildren"].toInt();
        if (record.contains("childrenUnder7")) _numberOfChildrenUnder7 = record["childrenUnder7"].toInt();
        if (record.contains("hasPayed")) _hasPayed = record["hasPayed"].toInt() != 0;
        if (record.contains("paymentMethod")) _paymentMethod = PaymentMethod(record["paymentMethod"].toInt());
    }
}

QVariantHash Registration::getHashValues() const
{
    return QVariantHash{
        { "id",                 QString::number( _bddId ) },
        { "name",               _name },
        { "licensedAdults",     QString::number( _numberOfLicencedAdults ) },
        { "unlicensedAdults",   QString::number( _numberOfUnlicencedAdults ) },
        { "licensedChildren",   QString::number( _numberOfLicencedChildren ) },
        { "unlicensedChildren", QString::number( _numberOfUnlicencedChildren ) },
        { "childrenUnder7",     QString::number( _numberOfChildrenUnder7 ) },
        { "hasPayed",           ( _hasPayed ? "1" : "0" ) },
        { "paymentMethod",      QString::number( int(_paymentMethod) ) }
    };
}

QStringList Registration::getSqlColumns()
{
    return QStringList() << "id"
                         << "name"
                         << "licensedAdults"
                         << "unlicensedAdults"
                         << "licensedChildren"
                         << "unlicensedChildren"
                         << "childrenUnder7"
                         << "hasPayed"
                         << "paymentMethod";
}

QString Registration::tableCreationQuery()
{
    return QString("CREATE TABLE " + Registration::tableName + " ("
                      "id INT PRIMARY KEY NOT NULL,"
                      "name VARCHAR(100),"
                      "licensedAdults INT DEFAULT 0,"
                      "unlicensedAdults INT DEFAULT 0,"
                      "licensedChildren INT DEFAULT 0,"
                      "unlicensedChildren INT DEFAULT 0,"
                      "childrenUnder7 INT DEFAULT 0,"
                      "hasPayed INT DEFAULT 0,"
                      "paymentMethod INT DEFAULT 0"
                   ");");
}
