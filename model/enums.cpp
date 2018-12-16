#include "enums.h"

PaymentMethod::PaymentMethod(QObject *parent) : QObject(parent)
{

}

void PaymentMethod::fillWithAllEnumValue()
{
    _valueNameHash[NOT_PAYED] = "Pas payé";
    _valueNameHash[CASH] = "Espèces";
    _valueNameHash[CHECK] = "Chèque";
}

QList<QString> PaymentMethod::valueNames() const
{
    return _valueNameHash.values();
}
