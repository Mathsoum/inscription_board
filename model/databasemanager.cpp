#include "model/databasemanager.h"

#include <cassert>

DatabaseManager::DatabaseManager()
    : _database(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE")))
{

    _database->setDatabaseName("inscription_board.sqlite");
    assert(_database->open());
}
