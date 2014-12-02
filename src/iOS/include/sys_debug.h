#ifndef _TR_SYS_DEBUG_H_
#define _TR_SYS_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif
    
    void sys_assert(unsigned char exp);
    void sys_dbgprintf(const char * format, void * ap);
    
#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_DEBUG_H_ */
