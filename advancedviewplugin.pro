QT += core network gui widgets

DBLIBS += dbcore zeiterfassungcore zeiterfassunggui zeiterfassungnetwork

TARGET = advancedviewplugin

HEADERS += advancedviewdialog.h \
           advancedviewplugin.h \
           advancedviewwidget.h \
           dialogs/bookingdialog.h \
           dialogs/timeassignmentdialog.h \
           models/bookingsmodel.h \
           models/timeassignmentsmodel.h

SOURCES += advancedviewdialog.cpp \
           advancedviewplugin.cpp \
           advancedviewwidget.cpp \
           dialogs/bookingdialog.cpp \
           dialogs/timeassignmentdialog.cpp \
           models/bookingsmodel.cpp \
           models/timeassignmentsmodel.cpp

FORMS += advancedviewdialog.ui \
         dialogs/bookingdialog.ui \
         dialogs/timeassignmentdialog.ui

RESOURCES += advancedviewplugin_resources.qrc

TRANSLATIONS += translations/advancedviewplugin_en.ts \
                translations/advancedviewplugin_de.ts

OTHER_FILES += advancedviewplugin.json

include(../plugin.pri)
