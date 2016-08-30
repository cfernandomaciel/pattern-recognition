TEMPLATE = app
CONFIG += console
CONFIG += debug
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += code/main.cpp \
    code/sources/Blocks.cpp \
    code/sources/Document.cpp \
    code/sources/Point.cpp \
    code/sources/Filters.cpp

#TODO: ja vou arrumar essa bagunça aqui
INCLUDEPATH += "/home/cfernandomaciel/OpenCV/include"

LIBS += -L/home/cfernandomaciel/OpenCV/build/lib \
    -lopencv_core \
    -lopencv_imgcodecs \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_video \
    -lopencv_videoio \
    -lopencv_objdetect

HEADERS += \
    headers/Blocks.h \
    headers/Document.h \
    headers/Filters.h \
    headers/Point.h

