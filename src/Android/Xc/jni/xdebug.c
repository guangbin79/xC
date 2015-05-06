#include "../../../../xdebug.h"
#include "../../../../xvarargs.h"
#include <assert.h>
#include<android/log.h>

void xdebug_assert(xbool_t exp) 
{
    assert(exp);
  
}
 
void xdebug_printf(const xchar_t * format, ...) 
{
 	va_list ap;
    va_start(ap, format);
	__android_log_print(ANDROID_LOG_DEBUG, "NDKlog=",  format,  ap);
	va_end (ap);
}