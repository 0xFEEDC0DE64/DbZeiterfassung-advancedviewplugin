set(HEADERS
    advancedviewdialog.h
    advancedviewplugin.h
    advancedviewwidget.h
    dialogs/bookingdialog.h
    dialogs/timeassignmentdialog.h
    models/bookingsmodel.h
    models/timeassignmentsmodel.h
)

set(SOURCES
    advancedviewdialog.cpp
    advancedviewplugin.cpp
    advancedviewwidget.cpp
    dialogs/bookingdialog.cpp
    dialogs/timeassignmentdialog.cpp
    models/bookingsmodel.cpp
    models/timeassignmentsmodel.cpp
)

set(RESOURCES
    advancedviewplugin_resources.qrc
)

set(FORMS
    advancedviewdialog.ui
    dialogs/bookingdialog.ui
    dialogs/timeassignmentdialog.ui
)

add_library(zeiterfassung-plugins-advancedviewplugin SHARED ${HEADERS} ${SOURCES} ${RESOURCES} ${FORMS})

target_link_libraries(zeiterfassung-plugins-advancedviewplugin Qt5::Core Qt5::Gui Qt5::Widgets zeiterfassungguilib zeiterfassungnetworklib)

add_dependencies(zeiterfassung-plugins zeiterfassung-plugins-advancedviewplugin)
