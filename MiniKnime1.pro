
#-------------------------------------------------
#
# Project created by QtCreator 2018-12-29T13:05:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniKnime1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mknode.cpp \
    mkinput.cpp \
    mkoutput.cpp \
    mkdata.cpp \
    mktestnode2_2.cpp \
    mknodespec.cpp \
    secondwindow.cpp \
    mkpartition.cpp \
    mknaivebayes.cpp \
    mkcsvreader.cpp \
    mkdialog.cpp \
    uicontroler.cpp \
    csvreaderdialog.cpp \
    mknormalization.cpp \
    mkline.cpp \
    mknormalizationdialog.cpp \
    mkneuraldialog.cpp \
    mkmlpregression.cpp \
    dlib-19.16/dlib-19.16/dlib/all/source.cpp \
    mkknn.cpp


HEADERS += \
        mainwindow.h \
    mknode.h \
    mkinput.h \
    mkoutput.h \
    mknodespec.h \
    mkdata.h \
    mktestnode2_2.h \
    secondwindow.h \
    mkpartition.h \
    mknaivebayes.h \
    mkcsvreader.h \
    mkdialog.h \
    uicontroler.h \
    csvreaderdialog.h \
    mknormalization.h \
    mkline.h \
    mknormalizationdialog.h \
    mkneuraldialog.h \
    mkmlpregression.h \
    mkknn.h


FORMS += \
        mainwindow.ui \
    mkdialog.ui \
    csvreaderdialog.ui \
    mknormalizationdialog.ui \
    mkneuraldialog.ui \
    mkknn.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    slike.qrc \
    slike.qrc

LIBS += -pthread -lX11

DISTFILES += \
    ../../auto-mpg.csv


