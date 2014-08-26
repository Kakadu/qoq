#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickWindow>

#include "documenthandler.h"
#include "kamlo.h"

int main(int argc, char *argv[])
{
    caml_main(argv);
    QApplication app(argc, argv);

    qmlRegisterType<DocumentHandler>("net.khertan.documenthandler", 1, 0, "DocumentHandler");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

#if 0
    QList<QObject*> xs = engine.rootObjects();
    if (xs.count() == 0) {
      Q_ASSERT_X(false, "Creating C++ runtime", "Your QML file seems buggy");
    }
    QQuickWindow *window = qobject_cast<QQuickWindow*>(xs.at(0) );
    window->showMaximized();
#endif

    return app.exec();
}
