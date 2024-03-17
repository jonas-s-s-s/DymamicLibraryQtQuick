cmake_minimum_required(VERSION 3.16)

project(DymamicLibraryQtQuick VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

##############################################################################
# Include dirs so linker can find headers
include_directories(./LibLoader)
include_directories(./LibApi)
# Add the Libs subdirectory so compiler produces our DLLs
add_subdirectory(Libs)
##############################################################################

qt_add_executable(appDymamicLibraryQtQuick
    main.cpp
)

qt_add_qml_module(appDymamicLibraryQtQuick
    URI DymamicLibraryQtQuick
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES LibApi/ExampleApi.h
    SOURCES LibLoader/LibLoader.h
    SOURCES controller.cpp
    SOURCES controller.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDymamicLibraryQtQuick PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDymamicLibraryQtQuick
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDymamicLibraryQtQuick
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appDymamicLibraryQtQuick
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
