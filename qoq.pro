TEMPLATE = app

QT += qml quick widgets

include(ocaml.pri)
QMAKE_EXTRA_TARGETS += camltarget echotarget

SOURCES += main.cpp \
    documenthandler.cpp \
    highlighter.cpp

RESOURCES += qml.qrc

HEADERS += \
    documenthandler.h \
    highlighter.h

