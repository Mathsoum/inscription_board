#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include<QSqlDatabase>

#include "model/registration.h"

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager() = default;

private: // Methods
    void _initDatabase();
    bool _tableExists(const QString& tableName) const;

private: // Attributes
    std::unique_ptr<QSqlDatabase> _database;
};

#endif // DATABASEMANAGER_H
