#include "maincontroller.h"

MainController::MainController(QObject *parent)
    : QObject(parent),
      _databaseManager(std::make_shared<DatabaseManager>()),
      _mainListModel(std::make_unique<MainListModel>(_databaseManager, this))
{
}

MainListModel* MainController::mainListModel() const
{
    return _mainListModel.get();
}
