#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "maincontroller.h"

void qmlRegistration()
{
    // Register MainListModel* si QML can use it
    qRegisterMetaType<MainListModel*>("MainListModel*");

    // Register MainController as QML Singleton type
    qmlRegisterSingletonType<MainController>("inscription_board", 1, 0, "MainController", [](QQmlEngine* /*engine*/, QJSEngine* /*scriptEngine*/) -> QObject* {
        return new MainController();
    });
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegistration();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
