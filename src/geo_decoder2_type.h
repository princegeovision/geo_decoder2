///////////////////////////////////////////////////////////////////////
///  @file geo_decoder2_type.h
///  @brief the file was used to define data structures.
///  @author ArronPJ
///  @date 2020/05/06
///  @copyright Copyright (c) 2020 GTDigital. All rights reserved.
///////////////////////////////////////////////////////////////////////
#ifndef geo_decoder2_lib_type_h
#define geo_decoder2_lib_type_h

#include <stdint.h>
#include <stdbool.h>
//include xxx_other.h

#ifdef __cplusplus
extern "C"
{
#endif // #ifdef __cplusplus

enum geo_decoder2_status
{
    k_geo_decoder2_status_none        = 0,
    k_geo_decoder2_status_inited      = 1,
    k_geo_decoder2_status_error       = 2,
};

enum geo_decoder2_request_types
{
    k_geo_decoder2_request_types_none     = 0,
    k_geo_decoder2_request_types_token    = 1,
    k_geo_decoder2_request_types_config   = 2,
};

//1,2,4,8, 10,20,40,80, 100, 200, 400, 800
enum geo_decoder2_error_flags
{
    geo_decoder2_error_flags_login_fai          = 0x00000001,
    geo_decoder2_error_flags_connect_fail       = 0x00000002,
};

//p1
typedef struct geo_decoder2_request_info
{
    int64_t request_id;
    bool    request_result;
} geo_decoder2_request_info;

//Callback, name, p1, p_arg
typedef void (*geo_decoder2_on_request_callback)(const geo_decoder2_request_info *info, void* user_arg);

//params
typedef struct geo_decoder2_request_params
{
    int64_t                             request_type;
    //geo_object*                         search_info;
    geo_decoder2_on_request_callback      on_request_callback;
    void*                               on_request_callback_user_arg;

} geo_decoder2_request_params;


#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef geo_decoder2_lib_type_h
