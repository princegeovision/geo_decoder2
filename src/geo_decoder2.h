///////////////////////////////////////////////////////////////////////
///  @file geo_decoder2_.h
///  @brief the file was used to define functions.
///  @author ArronPJ
///  @date 2020/05/06
///  @copyright Copyright (c) 2020 GTDigital. All rights reserved.
///////////////////////////////////////////////////////////////////////

#ifndef geo_decoder2__function_h
#define geo_decoder2__function_h

#include "geo_decoder2__platform.h"
#include "geo_decoder2__type.h"

//#pragma GCC visibility push(default)
#ifdef __cplusplus
extern "C"
{
#endif // #ifdef __cplusplus
GEO_DECODER2_SYMBOL_EXPORT void geo_decoder2_version_log();

GEO_DECODER2_SYMBOL_EXPORT int geo_decoder2_init();

GEO_DECODER2_SYMBOL_EXPORT void geo_decoder2_shutdown();


GEO_DECODER2_SYMBOL_EXPORT int64_t geo_decoder2_request(const struct geo_decoder2_request_params* info);


#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

//#pragma GCC visibility pop

#endif // #ifndef geo_decoder2_function_h
