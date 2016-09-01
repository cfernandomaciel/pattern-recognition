TEMPLATE = app
CONFIG += console
CONFIG += staticlib
CONFIG += debug
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += code/main.cpp \
    code/sources/Blocks.cpp \
    code/sources/Document.cpp \
    code/sources/Point.cpp \
    code/sources/Filters.cpp \
    code/sources/Output.cpp


INCLUDEPATH += "/usr/local/include/opencv"

LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_imgcodecs \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_video \
    -lopencv_videoio \
    -lopencv_objdetect \
    -lncurses


HEADERS += \
    headers/Blocks.h \
    headers/Document.h \
    headers/Filters.h \
    headers/Point.h \
    headers/Output.h
