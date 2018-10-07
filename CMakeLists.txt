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

set(FORMS
    advancedviewdialog.ui
    dialogs/bookingdialog.ui
    dialogs/timeassignmentdialog.ui
)

add_library(advancedviewplugin SHARED ${HEADERS} ${SOURCES} ${FORMS})

target_link_libraries(advancedviewplugin Qt5::Core Qt5::Gui Qt5::Widgets zeiterfassungguilib)
