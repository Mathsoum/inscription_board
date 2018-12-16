#ifndef MAINLISTMODEL_H
#define MAINLISTMODEL_H

#include <memory>

#include <QAbstractListModel>
#include <QtQml>

#include "model/registration.h"

class DatabaseManager;

class MainListModel : public QAbstractListModel
{
public:
    MainListModel(std::shared_ptr<DatabaseManager> databaseManager, QObject* parent = nullptr);
    ~MainListModel() = default;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QHash<int, QByteArray> roleNames() const;

private:
//    QList<QString> _dummyModelList = { "Alpha", "Bravo", "Charlie", "Delta", "Echo" }; //TODO Use SQLite input source once it's been set up
    std::shared_ptr<DatabaseManager> _databaseManager;
};

#endif // MAINLISTMODEL_H
