#include "registration.h"

QString Registration::tableName = "registrations";

Registration::Registration(QObject *parent):
    QObject(parent),
    _bddId(-1),
    _name(""),
    _licensedAdults(0),
    _unlicensedAdults(0),
    _licensedChildren(0),
    _unlicensedChildren(0),
    _childrenUnder7(0),
    _hasPayed(false),
    _paymentMethod(PaymentMethod::Value::NOT_PAYED)
{

}

Registration::Registration(const QString &name, const int licensedAdults, const int unlicensedAdults, const int licensedChildren, const int unlicensedChildren, const int childrenUnder7)
    : Registration()
{
    _name               = { name };
    _licensedAdults     = { licensedAdults };
    _unlicensedAdults   = { unlicensedAdults };
    _licensedChildren   = { licensedChildren };
    _unlicensedChildren = { unlicensedChildren };
    _childrenUnder7     = { childrenUnder7 };
}

Registration::Registration(const QVariantHash &record)
{
    if (!record.isEmpty()) {
        if (record.contains("id")) _bddId = record["id"].toInt();
        if (record.contains("name")) _name = record["name"].toString();
        if (record.contains("licensedAdults")) _licensedAdults = record["licensedAdults"].toInt();
        if (record.contains("unlicensedAdults")) _unlicensedAdults = record["unlicensedAdults"].toInt();
        if (record.contains("licensedChildren")) _licensedChildren = record["licensedChildren"].toInt();
        if (record.contains("unlicensedChildren")) _unlicensedChildren = record["unlicensedChildren"].toInt();
        if (record.contains("childrenUnder7")) _childrenUnder7 = record["childrenUnder7"].toInt();
        if (record.contains("hasPayed")) _hasPayed = record["hasPayed"].toInt() != 0;
        if (record.contains("paymentMethod")) _paymentMethod = PaymentMethod::Value(record["paymentMethod"].toInt());
    }
}

QVariantHash Registration::getHashValues() const
{
    return QVariantHash{
        { "id",                 QString::number( _bddId ) },
        { "name",               _name },
        { "licensedAdults",     QString::number( _licensedAdults ) },
        { "unlicensedAdults",   QString::number( _unlicensedAdults ) },
        { "licensedChildren",   QString::number( _licensedChildren ) },
        { "unlicensedChildren", QString::number( _unlicensedChildren ) },
        { "childrenUnder7",     QString::number( _childrenUnder7 ) },
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

#define CUSTOM_GETTER(type, name) \
    type Registration::name() const \
    {\
        return _##name;\
    }

#define CUSTOM_SETTER(type, name, setter) \
    void Registration::setter(type value) \
    { \
        if (_##name != value) { \
            _##name = value;\
            emit name##Changed(_##name);\
        }\
    }

#define CUSTOM_SETTER_REF(type, name, setter) \
    void Registration::setter(const type& value) \
    { \
        if (_##name != value) { \
            _##name = value;\
            emit name##Changed(_##name);\
        }\
    }

#define CUSTOM_GET_SET(type, name, setter) \
    CUSTOM_GETTER(type, name)\
    CUSTOM_SETTER(type, name, setter)

#define CUSTOM_GET_SET_REF(type, name, setter) \
    CUSTOM_GETTER(type, name)\
    CUSTOM_SETTER_REF(type, name, setter)

CUSTOM_GET_SET_REF(QString, name, setName)
CUSTOM_GET_SET(int, licensedAdults, setLicensedAdults)
CUSTOM_GET_SET(int, unlicensedAdults, setUnlicensedAdults)
CUSTOM_GET_SET(int, licensedChildren, setLicensedChildren)
CUSTOM_GET_SET(int, unlicensedChildren, setUnlicensedChildren)
CUSTOM_GET_SET(int, childrenUnder7, setChildrenUnder7)
CUSTOM_GET_SET(bool, hasPayed, setHasPayed)
CUSTOM_GET_SET_REF(PaymentMethod::Value, paymentMethod, setPaymentMethod)
