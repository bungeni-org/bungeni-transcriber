######################################################################
# Automatically generated by qmake (2.01a) Wed Sep 23 10:23:10 2009
######################################################################

#INCLUDEPATH for libvlc on Ubuntu. May be different on other distros
INCLUDEPATH = /usr/include/vlc /usr/include/taglib
LIBS += -lvlc -ltag

HEADERS +=  src/transcribeWidget.hpp \
            src/controlsWidget.hpp \
            src/listViewDelegate.hpp \
            src/customTextEdit.hpp \
            src/inplaceEditor.hpp \
            src/playlistWidget.hpp \
            src/network/formpost.hpp \
            src/addToPlaylistWidget.hpp \
            src/qxtspanslider/qxtspanslider_p.h \
            src/qxtspanslider/qxtspanslider.h \
            src/about.hpp \
            src/hotkeyWidget.hpp \
            src/util/vlc_keys.h \
            src/util/util.hpp \
            src/settings.hpp \
            src/transcribeKeySelector.hpp
FORMS   +=  src/ui/transcribe.ui \
            src/ui/inplace_editor.ui \
            src/ui/uploadProgress.ui \
            src/ui/controls.ui \
            src/ui/addToPlaylist.ui \
            src/ui/about.ui \
            src/ui/serverSettings.ui
SOURCES +=  src/transcribeWidget.cpp \
            src/controlsWidget.cpp \
            src/main.cpp \
            src/listViewDelegate.cpp \
            src/customTextEdit.cpp \
            src/inplaceEditor.cpp \
            src/playlistWidget.cpp \
            src/network/formpost.cpp \
            src/addToPlaylistWidget.cpp \
            src/qxtspanslider/qxtspanslider.cpp \
            src/about.cpp \
            src/hotkeyWidget.cpp \
            src/util/util.cpp \
            src/settings.cpp \
            src/transcribeKeySelector.cpp 
UI_DIR      =  src/ui/
RESOURCES   =  src/resources.qrc           
CONFIG  +=  qt debug
QT += network xml
