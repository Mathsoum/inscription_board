#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <memory>

#include <QObject>
#include <QtQml>

#include "viewModel/mainlistmodel.h"
#include "model/databasemanager.h"

class MainController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(MainListModel* mainListModel READ mainListModel CONSTANT)

public:
    MainController(QObject* parent = nullptr);
    virtual ~MainController() = default;

    MainListModel *mainListModel() const;

private:
    std::shared_ptr<DatabaseManager> _databaseManager;
    std::unique_ptr<MainListModel>   _mainListModel; //FIXME Use smart pointers
};

QML_DECLARE_TYPE(MainController)

#endif // MAINCONTROLLER_H
