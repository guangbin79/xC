#ifndef _TR_SYS_DEBUG_H_
#define _TR_SYS_DEBUG_H_

#include "../../../xcharacter.h"

#ifdef __cplusplus
extern "C" {
#endif

void sys_assert(xchar_t exp);
void sys_dbgprintf(const xchar_t * format, void * ap);

#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_DEBUG_H_ */
