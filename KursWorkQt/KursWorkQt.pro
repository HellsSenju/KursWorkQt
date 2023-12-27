QT       += core gui charts printsupport opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT_QPA_PLATFORM= wayland

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arraylist.cpp \
    deque.cpp \
    dequelist.cpp \
    doublelinkedlist.cpp \
    linkedlist.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Node.h \
    arraylist.h \
    deque.h \
    dequelist.h \
    doublelinkedlist.h \
    linkedlist.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
