#-------------------------------------------------
#
# Project created by QtCreator 2022-05-13T12:37:35
#
#-------------------------------------------------

QT       += core gui
QT    +=charts
QT       +=network
CONFIG += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHomeAssistant
TEMPLATE = app
QT += multimedia multimediawidgets

SOURCES += main.cpp\
        widget.cpp \
    weather.cpp \
    parlor.cpp \
    bashroom.cpp \
    kitchen.cpp \
    bedroom.cpp \
    setting.cpp \
    static.cpp \
    mode_select.cpp \
    spider.cpp \
    login.cpp

HEADERS  += widget.h \
    spider.h \
    login.h

FORMS    += widget.ui \
    login.ui

RESOURCES += \
    icon.qrc \
    qss.qrc

DISTFILES += \
    weather.py \
    icon/paizhao.png \
    weather.py


INCLUDEPATH +=D:\Programmingtools\Python\include   ############# python enviroment
LIBS += -LD:\Programmingtools\Python\libs\
-l_tkinter\
-lpython3\
-lpython37


