///////////////////////////////////////////////////////////////////////
///  @file geo_decoder2.c
///  @brief the file was used to define functions.
///  @author ArronPJ
///  @date 2019/12/06
///  @copyright Copyright (c) 2019 GTDigital. All rights reserved.
///////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

#include "geo_decoder2.h"


//Internal_macro
#if GTD_PLATFORM != GEO_DECODER2_PLATFORM_ANDROID
#   define GTD_IGNORE_SIGPIPE 1
#endif
//Internal_macro [end]

#if defined(_ANDROID_) || defined(ANDROID)
extern "C"
{
//FFMPEG future include
//#include "libavcodec/jni.h"
    
}
#endif

static const int32_t k_geo_decoder2_version_major = 0;
static const int32_t k_geo_decoder2_version_minor = 1;
static const int32_t k_geo_decoder2_version_patch = 0;

void* isInit = NULL;

///////////////////////////////////////////////////////////////////////
/// FUNCTION
///////////////////////////////////////////////////////////////////////

void geo_decoder2_version_log()
{
    GEO_DECODER2_RELEASE_MSG("\n");
    GEO_DECODER2_RELEASE_MSG("gtd_helper=version, %d.%d.%d\n", k_gtd_helper_version_major, k_gtd_helper_version_minor, k_gtd_helper_version_patch);
    GEO_DECODER2_RELEASE_MSG("\n");
}

int geo_decoder2_init()
{
    GEO_DECODER2_RELEASE_MSG("init>>\n");
#if defined(GTD_IGNORE_SIGPIPE)
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, 0);
#endif
    if(isInit)
    {
        //should be NULL
        return false;
    }
    GEO_DECODER2_RELEASE_MSG("init<<\n");
    //always return true.
    return true;
}

void geo_decoder2_shutdown()
{
    GEO_DECODER2_RELEASE_MSG("shutdown>>\n");
    if(isInit)
    {
        isInit = NULL;
    }
    GEO_DECODER2_RELEASE_MSG("shutdown<<\n");
}

int64_t geo_decoder2_request(const struct geo_decoder2_request_params* info)
{
    GEO_DECODER2_RELEASE_MSG("request>>\n");
    int64_t result = -1;
    if (!info )
    {
        GEO_DECODER2_RELEASE_MSG("request<<1\n");
        return result;
    }
    //do something internal
    result = 0;
    //then return result
    GEO_DECODER2_RELEASE_MSG("request<<2\n");
    return result;
}

