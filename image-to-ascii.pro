TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        asciiart.cpp \
        imageconverter.cpp \
        main.cpp

DISTFILES +=

HEADERS += \
    CImg.h \
    asciiart.hpp \
    imageconverter.hpp

LIBS += -pthread
LIBS += -lX11
