#include "mainlistmodel.h"

#include <QDebug>

MainListModel::MainListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int MainListModel::rowCount(const QModelIndex &/*parent*/) const
{
    return _dummyModelList.size();
}

QVariant MainListModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "Current role is:" << role;
    if (role == Qt::DisplayRole) {
        return _dummyModelList.at(index.row());
    }

    return QVariant();
}

QVariant MainListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
