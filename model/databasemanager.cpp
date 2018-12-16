#include "model/databasemanager.h"

#include <cassert>

#include <QStringList>
#include <QSqlQuery>
#include <QDebug>

DatabaseManager::DatabaseManager()
    : _database(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE")))
{
    _database->setDatabaseName("inscription_board.sqlite");
    assert(_database->open());
    _initDatabase();
}

void DatabaseManager::_initDatabase()
{
    if ( !_tableExists(Registration::tableName) ) {
        // Create table
        QSqlQuery query(Registration::tableCreationQuery());
        if (query.isActive()) {
            qDebug() << "Table" << Registration::tableName << "created successfully!";
        } else {
            qDebug() << "Failed to create table" << Registration::tableName;
        }
    } else {
        qDebug() << "Table" << Registration::tableName << "already exists";
    }
}

bool DatabaseManager::_tableExists(const QString &tableName) const
{
    return _database->tables().contains(tableName);
}
