///////////////////////////////////////////////////////////////////////
///  @file geo_decoder2_platform.h
///  @brief the file was used to define the platform dependent information.
///  @author ArronPJ
///  @date 2020/05/06
///  @copyright Copyright (c) 2020 GTDigital. All rights reserved.
///////////////////////////////////////////////////////////////////////

#ifndef geo_decoder2_platform_h
#define geo_decoder2_platform_h

#define GEO_DECODER2_PACKET_ALIGN_1 __attribute__ ((align(1)))
#define GEO_DECODER2_PACKET_ALIGN_2 __attribute__ ((align(2)))
#define GEO_DECODER2_PACKET_ALIGN_4 __attribute__ ((align(4)))
#define GEO_DECODER2_PACKET_ALIGN_8 __attribute__ ((align(8)))
#define GEO_DECODER2_PACKET_ALIGN_16 __attribute__ ((align(16)))

#define GEO_DECODER2_COMPILER_CLANG 1
#define GEO_DECODER2_COMPILER_GNUC 2
#define GEO_DECODER2_COMPILER_MSVC 3

// platform define
#define GEO_DECODER2_PLATFORM_APPLE 1
#define GEO_DECODER2_PLATFORM_APPLE_IOS 2
#define GEO_DECODER2_PLATFORM_WIN32 3
#define GEO_DECODER2_PLATFORM_LINUX 4
#define GEO_DECODER2_PLATFORM_ANDROID 5

#define GEO_DECODER2_ARCHITECTURE_32 1
#define GEO_DECODER2_ARCHITECTURE_64 2

// find compiler and version
#if defined(__clang__)
#   define GTD_COMPILER GEO_DECODER2_COMPILER_CLANG
#   define GTD_COMPILER_VERSION (((__clang_major__)*100) + (__clang_minor__*10) + __clang_patchlevel__)
#elif defined(__GNUC__)
#   define GTD_COMPILER GEO_DECODER2_COMPILER_GNUC
#   define GTD_COMPILER_VERSION (((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
#elif defined(_MSC_VER)
#   define GTD_COMPILER GEO_DECODER2_COMPILER_MSVC
#   define GTD_COMPILER_VERSION _MSC_VER
#else
#   error "could not auth compiler! medic! medic!"
#endif

// find platform
#if defined(__APPLE_CC__)
#   if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 40000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 40000
#       define GTD_PLATFORM GEO_DECODER2_PLATFORM_APPLE_IOS
#   else
#       define GTD_PLATFORM GEO_DECODER2_PLATFORM_APPLE
#   endif
#elif defined(__WIN32__) || defined(_WIN32)
#   define GTD_PLATFORM GEO_DECODER2_PLATFORM_WIN32
#   error "did not support windows platform yet! abort! abort!"
#elif defined(__ANDROID__)
#	define GTD_PLATFORM GEO_DECODER2_PLATFORM_ANDROID
#else
#   define GTD_PLATFORM GEO_DECODER2_PLATFORM_LINUX
#   error "did not support linux platform yet! abort! abort!"
#endif

// architecture
#if defined(__x86_64__) || defined(_M_X64) || defined(__ia64__)
#   define GTD_ARCHITECTURE_TYPE GEO_DECODER2_ARCHITECTURE_64
#else
#   define GTD_ARCHITECTURE_TYPE GEO_DECODER2_ARCHITECTURE_32
#endif

// visibility
#if GTD_PLATFORM == GEO_DECODER2_PLATFORM_WIN32
#   if defined(GTD_STATIC_LIBRARY)
#       define GEO_DECODER2_SYMBOL_EXPORT
#       define GEO_DECODER2_SYMBOL_PRIVATE
#   else
#       if defined(GTD_BUILD_LIBRARY)
#           define GEO_DECODER2_SYMBOL_EXPORT __attribute__((dllexport))
#       else
#           define GEO_DECODER2_SYMBOL_EXPORT __attribute__((dllimport))
#       endif
#       define GEO_DECODER2_SYMBOL_PRIVATE
#   endif
#else
#   define GEO_DECODER2_SYMBOL_EXPORT __attribute__((visibility("default")))
#   define GEO_DECODER2_SYMBOL_PRIVATE __attribute__((visibility("hidden")))
#endif

#if GTD_PLATFORM != GEO_DECODER2_PLATFORM_ANDROID
#   define GEO_DECODER2_RELEASE_MSG(fmt, ...) printf(fmt, ## __VA_ARGS__)
#else
#   include <android/log.h>
#   define GEO_DECODER2_RELEASE_MSG(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE, "geo_decoder2_platform", fmt, ## __VA_ARGS__)
#endif

#endif  //#ifndef geo_decoder2_platform_h
