#ifndef REGISTEREDPERSON_H
#define REGISTEREDPERSON_H

#include <QtQml>
#include <QString>
#include <QVariantHash>

#include "model/enums.h"

class Registration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int licensedAdults READ licensedAdults WRITE setLicensedAdults NOTIFY licensedAdultsChanged)
    Q_PROPERTY(int unlicensedAdults READ unlicensedAdults WRITE setUnlicensedAdults NOTIFY unlicensedAdultsChanged)
    Q_PROPERTY(int licensedChildren READ licensedChildren WRITE setLicensedChildren NOTIFY licensedChildrenChanged)
    Q_PROPERTY(int unlicensedChildren READ unlicensedChildren WRITE setUnlicensedChildren NOTIFY unlicensedChildrenChanged)
    Q_PROPERTY(int childrenUnder7 READ childrenUnder7 WRITE setChildrenUnder7 NOTIFY childrenUnder7Changed)
    Q_PROPERTY(bool hasPayed READ hasPayed WRITE setHasPayed NOTIFY hasPayedChanged)
    Q_PROPERTY(PaymentMethod::Value paymentMethod READ paymentMethod WRITE setPaymentMethod NOTIFY paymentMethodChanged)

public:
    Registration(QObject* parent = nullptr);
    Registration(const QString& name, const int licensedAdults, const int unlicensedAdults, const int licensedChildren, const int unlicensedChildren, const int childrenUnder7);
    Registration(const QVariantHash& record);

    QVariantHash getHashValues() const;

    static QStringList getSqlColumns();

    static QString tableName;
    static QString tableCreationQuery();

    QString name() const;
    void setName(const QString &name);

    int licensedAdults() const;
    void setLicensedAdults(int licensedAdults);

    int unlicensedAdults() const;
    void setUnlicensedAdults(int unlicensedAdults);

    int licensedChildren() const;
    void setLicensedChildren(int licensedChildren);

    int unlicensedChildren() const;
    void setUnlicensedChildren(int unlicensedChildren);

    int childrenUnder7() const;
    void setChildrenUnder7(int childrenUnder7);

    bool hasPayed() const;
    void setHasPayed(bool hasPayed);

    PaymentMethod::Value paymentMethod() const;
    void setPaymentMethod(const PaymentMethod::Value &paymentMethod);

signals:
    void nameChanged(const QString& value);
    void licensedAdultsChanged(const int& value);
    void unlicensedAdultsChanged(const int& value);
    void licensedChildrenChanged(const int& value);
    void unlicensedChildrenChanged(const int& value);
    void childrenUnder7Changed(const int& value);
    void hasPayedChanged(const bool& value);
    void paymentMethodChanged(PaymentMethod::Value value);

private:
    int _bddId;
    QString _name;

    int _licensedAdults;
    int _unlicensedAdults;

    int _licensedChildren;
    int _unlicensedChildren;
    int _childrenUnder7;

    bool _hasPayed;
    PaymentMethod::Value _paymentMethod;
};

Q_DECLARE_METATYPE(Registration *)

#endif // REGISTEREDPERSON_H
