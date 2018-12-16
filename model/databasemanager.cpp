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
    _populateCache();
}

DatabaseManager::~DatabaseManager()
{
    qDeleteAll(_registrations);
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

void DatabaseManager::_populateCache()
{
    _registrations.clear();
    QSqlQuery query("SELECT " + Registration::getSqlColumns().join(",") + " FROM " + Registration::tableName);
    while(query.next()) {
        QVariantHash record;
        for (decltype(Registration::getSqlColumns().size()) i = 0 ; i < Registration::getSqlColumns().size(); ++i) {
            record.insert(Registration::getSqlColumns().at(i), query.value(i));
        }

        _registrations.push_back(new Registration(record));
    }

    qDebug() << _registrations.size() << "registrations retrieved from DB";
}
