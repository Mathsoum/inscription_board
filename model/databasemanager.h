#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include<QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager() = default;

private:
    std::unique_ptr<QSqlDatabase> _database;
};

#endif // DATABASEMANAGER_H
