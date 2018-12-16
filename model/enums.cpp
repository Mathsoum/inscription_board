#include "enums.h"

PaymentMethod::PaymentMethod(QObject *parent) : QObject(parent)
{

}

void PaymentMethod::fillWithAllEnumValue()
{
    _valueNameHash[Value::NOT_PAYED] = "Pas payé";
    _valueNameHash[Value::CASH] = "Espèces";
    _valueNameHash[Value::CHECK] = "Chèque";
}

QList<QString> PaymentMethod::valueNames() const
{
    return _valueNameHash.values();
}
