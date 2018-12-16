#include "registration.h"

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
