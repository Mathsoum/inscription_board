#ifndef ENUMS_H
#define ENUMS_H

#include <QtQml>
#include <QObject>

class PaymentMethod : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QString> valueNames READ valueNames CONSTANT)

public:
    enum Value {
        NOT_PAYED = 0,
        CASH,
        CHECK
    };

    explicit PaymentMethod(QObject *parent = nullptr);

    void fillWithAllEnumValue();

    QList<QString> valueNames() const;

private:
    QHash<PaymentMethod::Value, QString> _valueNameHash;
};

QML_DECLARE_TYPE(PaymentMethod)

#endif // ENUMS_H
