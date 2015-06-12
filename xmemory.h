/**
 * xC
 * @file xmemory.h
 * @brief 内存
 * @author guangbin <guangbin79@gmail.com>
 * @date 2014/03/14
 * @par 修改记录
 *
 */

#ifndef _XMEMORY_H_
#define _XMEMORY_H_

#include "./xinteger.h"
#include "./xpointer.h"
#include "./xcharacter.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 分配指定大小(以字节为单位)的空间
 * @param[in] size - 准备分配空间的大小
 * @return - 分配成功,返回分配空间首地址的指针,否则返回XNULL
 * @par 接口使用约定
 *      1.size不能等于0<br>
 *      2.分配的空间不使用后，需要调用free函数释放<br>
 */
void * xmemory_alloc(xsize_t size);

/**
 * @brief 分配多个指定大小(以字节为单位)的连续的内存空间
 * @param[in] nmemb - 准备分配空间的数据个数
 * @param[in] size - 准备分配空间的单个数据长度
 * @return - 分配成功,返回分配空间首地址的指针,否则返回XNULL
 * @par 接口使用约定
 *      1.nmemb\size都不能等于0<br>
 *      2.函数calloc()会将所分配的内存空间中的每一位都初始化为零<br>
 *      3.分配的空间不使用后，需要调用free函数释放<br>
 */
void * xmemory_calloc(xsize_t nmemb, xsize_t size);

/**
 * @brief 改变给定的内存指针所指的空间大小为size
 * @param[in] ptr - 指向准备改变大小的空间首地址的指针
 * @param[in] size - 改变后的大小(以字节为单位)
 * @return - 返回指向改变大小后空间首地址的指针,如果失败,返回XNULL
 * @par 接口使用约定
 *      1.size不能等于0<br>
 *      2.无论是扩张或是缩小,原有内存的中内容将保持不变,但对于缩小,则被缩小的那一部分的内容会丢失<br>
 *      3.返回值可能与ptr的值不同,如果是不同的话,那么realloc函数完成后,ptr指向的旧内存已被free掉了<br>
 *      4.如果返回XNULL值,则分配不成功,而原来的ptr指向的内存还没有被free掉,要求程序显式free<br>
 */
void * xmemory_realloc(void * ptr, xsize_t size);

/**
 * @brief 释放之前用malloc/calloc分配的空间
 * @param[in] ptr - 指向准备释放空间的指针
 * @return - 无
 * @par 接口使用约定
 *
 */
void xmemory_free(void * ptr);

/**
 * @brief 拷贝内存数据
 * @param[in] dptr - 目标内存首地址
 * @param[in] sptr - 源数据首地址
 * @param[in] size - 拷贝字节数
 * @return - 目标内存首地址
 * @par 接口使用约定
 *      1.dptr和sptr所指内存区域不能重叠<br>
 */
void * xmemory_copy(void * dptr, const void * sptr, xsize_t size);

/**
 * @brief 移动内存数据
 * @param[in] dptr - 目标内存首地址
 * @param[in] sptr - 源数据首地址
 * @param[in] size - 移动字节数
 * @return - 目标内存首地址
 * @par 接口使用约定
 *      1.dptr和sptr所指内存区域可以重叠,但复制后sptr内容会被更改<br>
 *      2.复制速度比memcpy慢<br>
 */
void * xmemory_move(void * dptr, const void * sptr, xsize_t size);

/**
 * @brief 设置目标内存数据
 * @param[in] ptr - 目标内存首地址
 * @param[in] c - 设置值
 * @param[in] count - 设置次数
 * @return - 目标内存首地址
 */
void * xmemory_set(void * ptr, xuint8_t c, xuint32_t count);

/**
 * @brief 比较内存区域buf1和buf2的前count个字节
 * @param[in] buf1 - 内存首地址
 * @param[in] buf2 - 内存首地址
 * @param[in] count - 比较字节个数
 * @return - 当buf1<buf2时，返回值<0,当buf1=buf2时，返回值=0,当buf1>buf2时，返回值>0
 */
xint32_t xmemory_compare(const void * buf1, const void * buf2, xuint32_t count);

/**
 * @brief 从buf所指内存区域的前count个字节查找字符ch
 * @param[in] ptr - 内存首地址
 * @param[in] c - 需要查找的字符
 * @param[in] count - 比较字节个数
 * @return - 当第一次遇到字符c时停止查找。如果成功，返回指向字符ch的指针;否则返回XNULL
 */
const void * xmemory_find(const void * ptr, xchar_t c, xuint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* _XMEMORY_H_ */

