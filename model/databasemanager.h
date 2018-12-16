#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include<QSqlDatabase>

#include "model/registration.h"

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    QList<Registration *> registrations() const;
    const QList<Registration *>& registrationsCRef() const;

    Registration *getRegistrationAt(int index) const;

private: // Methods
    void _initDatabase();
    bool _tableExists(const QString& tableName) const;
    void _populateCache();

private: // Attributes
    std::unique_ptr<QSqlDatabase> _database;

    QList<Registration*> _registrations;
};

#endif // DATABASEMANAGER_H
