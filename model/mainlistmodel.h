#ifndef MAINLISTMODEL_H
#define MAINLISTMODEL_H

#include <QAbstractListModel>

class MainListModel : public QAbstractListModel
{

public:
    MainListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<QString> _dummyModelList = { "Alpha", "Bravo", "Charlie", "Delta", "Echo" }; //TODO Use SQLite input source once it's been set up
};

#endif // MAINLISTMODEL_H