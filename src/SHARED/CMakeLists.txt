cmake_minimum_required(VERSION 3.15)

# About use Connan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

# Step00: Android
if(CONAN_SETTINGS_OS STREQUAL "Android")
    set(CMAKE_SYSTEM_NAME "Android")
    set(CMAKE_ANDROID_NDK ${CONAN_ANDROID_NDK_INSTALLER_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "${CONAN_ANDROID_NDK_INSTALLER_ROOT}/build/cmake/android.toolchain.cmake")
    set(ANDROID_PLATFORM ${CONAN_SETTINGS_OS_API_LEVEL})
endif()

# Step01: set project name
project(geo_decoder2)

# Step02: set conan setup 
conan_basic_setup()

# Step02-1: set output
set(GDHANDLER_OUTPUT_NAME "geo_decoder2")

# Step03: use C++11 (This library use C)
#set(CMAKE_CXX_STANDARD 11)

# Step04: Source code and target
set(LIBSRC geo_decoder2.c geo_decoder2.h geo_decoder2_platform.h geo_decoder2_type.h) 
add_library(geo_decoder2 SHARED ${LIBSRC}) 
add_library(geo_decoder2-static STATIC ${LIBSRC}) 
set_target_properties(geo_decoder2-static PROPERTIES OUTPUT_NAME geo_decoder2) 
target_link_libraries(geo_decoder2 ${CONAN_LIBS} android log)
# target_link_libraries(geo_decoder2 ${CONAN_LIBS})

if(NOT CMAKE_CROSSCOMPILING)
    if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
        if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")
            set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/windows64")
        elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")
            set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/windows32")
        else()
            set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/windows")
        endif()
    else()
        set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/${CMAKE_SYSTEM_NAME}")
    endif()
endif()

# Step05a: CP-iOS
## About iOS
if(IOS)
    # sanity checks
    include(CheckCXXSymbolExists)
    check_cxx_symbol_exists(kqueue sys/event.h HAVE_KQUEUE)
    if(NOT HAVE_KQUEUE)
        message(FATAL_ERROR "kqueue NOT found.")
    endif()
    find_library(HAVE_UIKIT UIKit)
    if (NOT HAVE_UIKIT)
        message(FATAL_ERROR "UIKit.framework NOT found.")
    endif()
    
    find_package(XCTest)
    find_host_package(XCTest REQUIRED)
    
    include(CheckTypeSize)
    check_type_size(time_t SIZEOF_TIME_T)
    
    # add debug symbols
    set_xcode_property(geo_decoder2 GCC_GENERATE_DEBUGGING_SYMBOLS YES "All")
    
    # installation
    set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/ios")
endif()

# Step05b: CP-Android
if(ANDROID)
    set(CMAKE_INSTALL_PREFIX "${geo_decoder2_SOURCE_DIR}/install/android")
endif()

# Step06: Install
install (TARGETS geo_decoder2 DESTINATION lib)
install (FILES geo_decoder2.h DESTINATION include)
