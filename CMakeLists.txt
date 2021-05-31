cmake_minimum_required(VERSION 3.5)

project(TextJokEditor LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "/Users/aleksandrakumyanskiy/Qt/5.13.0/clang_64")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        textjokeditor.cpp
        textjokeditor.h
        textjokeditor.ui
        resources/resources.qrc
        settingseditor.cpp
        settingseditor.h
        settingseditor.ui
        picturemap.cpp
        picturemap.h
        workplace.cpp
        workplace.h
        menubar.cpp
        menubar.h
        toolbar.cpp
        toolbar.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TextJokEditor
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(TextJokEditor SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(TextJokEditor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TextJokEditor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Установить исполняемый файл "Multiply" в директорию "bin":
#install(TARGETS TextJokEditor DESTINATION bin)

# Задать некоторые характеристики пакета:
#set(CPACK_PACKAGE_NAME "printMessage")
#set(CPACK_PACKAGE_VENDOR "MyCompany")
#set(CPACK_PACKAGE_CONTACT "https://test.ru")
#set(CPACK_DEBIAN_PACKAGE_MAINTAINER "test@gmail.com")
#set(CPACK_PACKAGE_DESCRIPTION "The most stupid program ever written")

# Задать используемый генератор пакетов:
#set(CPACK_GENERATOR "DragNDrop")

# Включить стандартный модуль "CPack":
#include(CPack)

