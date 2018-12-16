#ifndef REGISTEREDPERSON_H
#define REGISTEREDPERSON_H

#include <QString>
#include <QVariantHash>

class Registration
{
public:
    Registration() = default;
    Registration(const QString& name, const int licensedAdults, const int unlicensedAdults, const int licensedChildren, const int unlicensedChildren, const int childrenUnder7);

    QVariantHash getHashValues() const;

    static QStringList getSqlColumns();

    static QString tableName;
    static QString tableCreationQuery();

private:
    int _bddId;
    QString _name;

    int _numberOfLicencedAdults;
    int _numberOfUnlicencedAdults;

    int _numberOfLicencedChildren;
    int _numberOfUnlicencedChildren;
    int _numberOfChildrenUnder7;

};

#endif // REGISTEREDPERSON_H
