QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    main.cpp \
    menu_program.cpp \
    pcapworker.cpp \
    portadaproy.cpp

HEADERS += \
    CapturedPacket.h \
    MainWindow.h \
    menu_program.h \
    pcapworker.h \
    portadaproy.h

FORMS += \
    MainWindow.ui \
    menu_program.ui \
    portada.ui \
    portadaproy.ui

RC_ICONS = sniffalant.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/npcap-sdk-1.13 -lPacket
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/npcap-sdk-1.13/ -lPacket

INCLUDEPATH += C:/pcap/npcap-sdk-1.13/Include
DEPENDPATH += C:/pcap/npcap-sdk-1.13/Include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/npcap-sdk-1.13/Packet.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/npcap-sdk-1.13/Packet.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/npcap-sdk-1.13/release/Packet.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/npcap-sdk-1.13/debug/Packet.lib

win32: LIBS += -LC:/npcap-sdk-1.13/Lib/ -lwpcap

INCLUDEPATH += C:/npcap-sdk-1.13/Include
DEPENDPATH += C:/npcap-sdk-1.13/Include

win32:!win32-g++: PRE_TARGETDEPS += C:/npcap-sdk-1.13/Lib/wpcap.lib
else:win32-g++: PRE_TARGETDEPS += C:/npcap-sdk-1.13/Lib/wpcap.a

win32: LIBS += -LC:/npcap-sdk-1.13/ -lws2_32

INCLUDEPATH += C:/npcap-sdk-1.13/Include/pcap
DEPENDPATH += C:/npcap-sdk-1.13/Include/pcap

win32:!win32-g++: PRE_TARGETDEPS += C:/npcap-sdk-1.13/ws2_32.lib
else:win32-g++: PRE_TARGETDEPS += C:/npcap-sdk-1.13/libws2_32.a

DISTFILES += \
    Sniffalant_big.png
