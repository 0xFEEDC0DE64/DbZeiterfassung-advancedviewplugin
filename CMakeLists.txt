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

set(RESOURCES
    advancedviewplugin_resources.qrc
)

set(OTHER_FILES
    advancedviewplugin.json
)

set(TRANSLATIONS
    translations/advancedviewplugin_en.ts
    translations/advancedviewplugin_de.ts
)

set_source_files_properties(${TRANSLATIONS} PROPERTIES OUTPUT_LOCATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/translations)
QT5_CREATE_TRANSLATION(TRANSLATIONS_C ${TRANSLATIONS} ${HEADERS} ${SOURCES} ${FORMS} OPTIONS -no-obsolete)
#QT5_ADD_TRANSLATION(TRANSLATIONS_C ${TRANSLATIONS})

add_library(zeiterfassung-plugins-advancedviewplugin SHARED ${HEADERS} ${SOURCES} ${FORMS} ${RESOURCES} ${OTHER_FILES} ${TRANSLATIONS_C})

set_target_properties(zeiterfassung-plugins-advancedviewplugin PROPERTIES OUTPUT_NAME advancedviewplugin PREFIX "")

target_link_libraries(zeiterfassung-plugins-advancedviewplugin Qt5::Core Qt5::Gui Qt5::Widgets zeiterfassungguilib zeiterfassungnetworklib)

add_dependencies(zeiterfassung-plugins zeiterfassung-plugins-advancedviewplugin)
