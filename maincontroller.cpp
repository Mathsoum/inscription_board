#include "maincontroller.h"

MainController::MainController(QObject *parent)
    : QObject(parent),
      _mainListModel(std::make_unique<MainListModel>(this)),
      _databaseManager(std::make_unique<DatabaseManager>())
{
}

MainListModel* MainController::mainListModel() const
{
    return _mainListModel.get();
}
