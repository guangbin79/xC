#ifndef _TR_SYS_MEMORY_H_
#define _TR_SYS_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif
    
    void * sys_malloc(unsigned int size);
    void * sys_calloc(unsigned int nmemb, unsigned int size);
    void * sys_realloc(void * ptr, unsigned int size);
    void sys_free(void * ptr);
    
    void * sys_memcpy(void * dptr, const void * sptr, unsigned int size);
    void * sys_memmove(void * dptr, const void * sptr, unsigned int size);
    void * sys_memset(void * ptr, int c, unsigned int size);
    int sys_memcmp(const void * buf1, const void * buf2, unsigned int count);
    const void * sys_find(const void* ptr, char c, unsigned int count);
    
#ifdef __cplusplus
}
#endif

#endif /* _TR_SYS_MEMORY_H_ */
