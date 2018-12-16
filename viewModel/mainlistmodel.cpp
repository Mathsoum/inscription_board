#include "mainlistmodel.h"

#include <QDebug>

#include "model/databasemanager.h"

MainListModel::MainListModel(std::shared_ptr<DatabaseManager> databaseManager, QObject *parent)
    : QAbstractListModel(parent), _databaseManager(std::move(databaseManager))
{
}

int MainListModel::rowCount(const QModelIndex &/*parent*/) const
{
    return _databaseManager->registrationsCRef().size();
}

QVariant MainListModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "Current role is:" << role;
    if (role == Qt::UserRole) {
        return qVariantFromValue(_databaseManager->getRegistrationAt(index.row()));
//        return QString("TODO %1").arg(index.row());
    }

    return QVariant();
}

QVariant MainListModel::headerData(int /*section*/, Qt::Orientation /*orientation*/, int /*role*/) const
{
    return QVariant();
}

QHash<int, QByteArray> MainListModel::roleNames() const
{
    return QHash<int, QByteArray> {
        { Qt::UserRole, "QtObject" }
    };
}
