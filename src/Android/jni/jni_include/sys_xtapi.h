#ifndef _TR_SYS_TAPI_H_
#define _TR_SYS_TAPI_H_

#include <jni.h>
#include "../jni_include/jni_tapi.h"
#include "../../../../xtapi.h"



#ifdef __cplusplus
extern "C"
{
#endif



xsys_tapi_t * sys_tapicreate();
void sys_tapidestroy(xsys_tapi_t* ptapi);
unsigned char sys_tapigetbscount(xsys_tapi_t* ptapi);
const xbase_station_info_t* sys_tapigetbsbyindex(xsys_tapi_t* ptapi, const unsigned char aIndex);
const xwifi_info_t* sys_tapigetconnwifiinfo(xsys_tapi_t* ptapi);
const char* sys_tapigetmobileid(xsys_tapi_t* ptapi);
const char* sys_tapigetimsi(xsys_tapi_t* ptapi);
int sys_tapigetnettype(xsys_tapi_t* ptapi);
const xdevice_info_t* sys_tapigetdeviceinfo(xsys_tapi_t* ptapi);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_TAPI_H_ */
