QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fcfs_algorithm.cpp \
    main.cpp \
    mainwindow.cpp \
    preemative_sjf.cpp \
    priority_algorithm.cpp \
    process.cpp \
    round_robin.cpp \
    sjf_algorithm.cpp

HEADERS += \
    fcfs_algorithm.h \
    mainwindow.h \
    preemative_sjf.h \
    priority_algorithm.h \
    process.h \
    round_robin.h \
    sjf_algorithm.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
