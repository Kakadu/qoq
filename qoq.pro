

TEMPLATE = app

QT += qml quick widgets

include(ocaml.pri)
qoq.depends = camltarget
QMAKE_EXTRA_TARGETS += camltarget echotarget

SOURCES += main.cpp \
    documenthandler.cpp \
    highlighter.cpp

RESOURCES += qml.qrc

HEADERS += \
    documenthandler.h \
    highlighter.h \
    kamlo.h

INCLUDEPATH += $$system(opam config var lib)/ocaml
LIBS += -L$$system(opam config var lib)/ocaml

TARGETDEPS += ocaml/code.a
LIBS += -Locaml ocaml/code.a
