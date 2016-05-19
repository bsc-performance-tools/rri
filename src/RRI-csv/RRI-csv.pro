include(../../config.pri)

QT       -= gui

TARGET = rri-csv
TEMPLATE = lib

DEFINES += RRICSV_LIBRARY

SOURCES += rricsv.cpp

HEADERS += rricsv.h\
        rri-csv_global.h \
    csv_constants.h


QMAKE_LFLAGS += '-Wl,-rpath,\'\$$ORIGIN/../lib\''



unix {
    target.path = $$PREFIX/lib
    header_files.files = $$HEADERS
    header_files.path = $$PREFIX/include/$$TARGET
    INSTALLS += target \
                header_files
}
