include(../../config.pri)

QT += core
QT -= gui

QMAKE_STRIP = echo

TARGET = rri
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    RRI-bin.cpp \
    argumentmanager.cpp \
    filemanager.cpp \
    streamset.cpp

unix:!macx: LIBS += -L$$DESTDIR -lrri-csv
INCLUDEPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-csv
DEPENDPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-csv

unix:!macx: LIBS += -L$$DESTDIR -lrri
INCLUDEPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-core
DEPENDPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-core

unix:!macx: LIBS += -L$$DESTDIR -lrri-prv
INCLUDEPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-prv
DEPENDPATH += $$PROJECT_ROOT_DIRECTORY/src/RRI-prv

QMAKE_LFLAGS += '-Wl,-rpath,\'\$$ORIGIN/../lib\''

unix:!macx: LIBS += -llpaggreg
isEmpty( LPAGGREG_PATH ){
} else {
unix:!macx: LIBS +=-L$$LPAGGREG_PATH/lib
INCLUDEPATH += $$LPAGGREG_PATH/include
QMAKE_LFLAGS += -Wl,-rpath,$$LPAGGREG_PATH/lib
}

unix {
    target.path = $$TARGET_PATH/bin
    INSTALLS += target
    target_scripts.files += $$PROJECT_ROOT_DIRECTORY/scripts/rri.R
    target_scripts.files += $$PROJECT_ROOT_DIRECTORY/scripts/rri-pdf
    target_scripts.path = $$TARGET_PATH/bin
    postinstall.path = $$TARGET_PATH/bin
    postinstall.commands =  R --slave --vanilla < $$PROJECT_ROOT_DIRECTORY/scripts/rri-install.R
    INSTALLS += target_scripts\
                postinstall
}

HEADERS += \
    argumentmanager.h \
    filemanager.h \
    streamset.h \
    bin_constants.h

