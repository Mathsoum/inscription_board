#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "model/mainlistmodel.h"

class MainController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(MainListModel mainListModel READ mainListModel CONSTANT)

public:
    MainController(QObject* parent = nullptr);
    virtual ~MainController();

    MainListModel* mainListModel() const;

private:
    MainListModel* _mainListModel; //FIXME Use smart pointers
};

#endif // MAINCONTROLLER_H
