#include "maincontroller.h"

MainController::MainController(QObject *parent)
    : QObject(parent)
{
    _mainListModel = new MainListModel(this);
}

MainController::~MainController()
{
    if (_mainListModel != nullptr) {
        delete _mainListModel;
    }
}

MainListModel* MainController::mainListModel() const
{
    return _mainListModel;
}
