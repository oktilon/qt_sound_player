#-------------------------------------------------
#
# Project created by QtCreator 2013-02-13T15:38:23
#
#-------------------------------------------------

QT += core multimedia
QT += multimediawidgets
QT += multimedia-private

QMAKE_CXXFLAGS_RELEASE -= -g -O0

VERSION = 1.0.0

DEFINES += VERSION_STRING=\\\"$${VERSION}\\\"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = player
TEMPLATE = app

#Output
UI_DIR      = ui/
MOC_DIR     = build/moc/
OBJECTS_DIR = build/obj/
RCC_DIR     = build/qrc/

CONFIG += no_keywords
CONFIG += c++11
#CONFIG += use_lld_linker
CONFIG += use_gold_linker
CONFIG += link_pkgconfig
CONFIG += resources_big
CONFIG += sdk_no_version_check

SOURCES += \
    player.cpp \
    snd_player.cpp

HEADERS  += \
    player.h \
    snd_player.h

#ROOTFS for IMX8 Cross Compile
linux-imx8-g++ {
    CC_SYSROOT_DIR = $${PKG_CONFIG_SYSROOT_DIR}  #/home/imx8/InstallQt/sysroot
} else {
    CC_SYSROOT_DIR =
}

unix:!macx {
    DEFINES += _linux_
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/defigo
!isEmpty(target.path): INSTALLS += target

load(resolve_target)

message(Version: $${VERSION})