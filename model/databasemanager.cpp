#include "model/databasemanager.h"

#include <cassert>

#include <QStringList>
#include <QSqlQuery>

DatabaseManager::DatabaseManager()
    : _database(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE")))
{
    _database->setDatabaseName("inscription_board.sqlite");
    assert(_database->open());
}

void DatabaseManager::_initDatabase()
{
    if ( !_tableExists(Registration::tableName) ) {
        // TODO Create table

    }
}

bool DatabaseManager::_tableExists(const QString &tableName) const
{
    return _database->tables().contains(tableName);
}
