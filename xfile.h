/**
 * @file xfile.h
 * @brief 文件
 * @author guangbin <guangbin79@gmail.com>
 * @date 2015/01/30
 * @par 修改记录
 */

#ifndef _XFILE_H_
#define _XFILE_H_

#include "./xinteger.h"
#include "./xboolean.h"
#include "./xcharacter.h"

/**
 * @brief 文件结构体
 */
typedef struct _xfile xfile_t;

/**
 * @brief 文件枚举结构体
 */
typedef struct _xfile_enum xfile_enum_t;

/**
 * @brief 文件系统访问前缀
 */
#define XFS_DEFAULT ""              //默认私有,随机读写文件系统
#define XFS_ASSET   "asset:/"       //私有资源,随机只读文件系统
#define XFS_SHARE   "share:/"       //扩展共享,随机读写文件系统
/* #define XFS_COLUD   "colud:/"       //私有云同步,随机读写文件系统 */

/**
 * @brief 文件打开类型枚举
 */
typedef enum _xopen_file_mode {
    XOFM_READ,          ///< 只读
    XOFM_READWRITE,     ///< 读写
    XOFM_APPEND,        ///< 追加
    XOFM_CREATE         ///< 创建
} xopen_file_mode_t;

/**
 * @brief 文件定位类型枚举
 */
typedef enum _xfile_seek_type {
    XFST_START,         ///< 文件开头
    XFST_END,           ///< 文件结尾
    XFST_CURRENT_DOWN,  ///< 当前位置向下
    XFST_CURRENT_UP     ///< 当前位置向上
} xfile_seek_type_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 打开文件
 * @param[in] filename - 文件名
 * @param[in] mode - 文件打开类型
 * @return - 文件结构体指针
 */
xfile_t * xfile_open(const xchar_t * filename, xopen_file_mode_t mode);

/**
 * @brief 关闭文件
 * @param[in] pFile - 文件结构体指针
 * @return - 无
 */
void xfile_close(xfile_t * file);

/**
 * @brief 写文件
 * @param[in] file - 文件结构体指针
 * @param[in] buf - 准备写入文件的数据
 * @param[in] bufSize - 准备写入文件的数据长度
 * @return - 实际写入文件的数据长度
 */
xuint32_t xfile_write(xfile_t * file, const void * buf, xuint32_t bufSize);

/**
 * @brief 读文件
 * @param[in] file - 文件结构体指针
 * @param[in] pvBuf - 指向存储从文件中读出数据地址的指针
 * @param[in] bufSize - 用于存储从文件中读出数据的空间的大小
 * @return - 实际从文件中读出的数据长度
 */
xuint32_t xfile_read(xfile_t * file, void * buf, xuint32_t bufSize);

/**
 * @brief 定位文件读写位置
 * @param[in] file - 文件结构体指针
 * @param[in] seekType - 文件定位类型
 * @param[in] moveDistance - 从定位类型约定位置的位移
 * @return - 当前文件读写位置,FST_START的偏移量
 */
xuint32_t xfile_seek(xfile_t * file, xfile_seek_type_t seekType, xuint32_t moveDistance);

/**
 * @brief 改变文件大小
 * @param[in] file - 文件结构体指针
 * @param[in] size - 指定新的文件大小
 * @return uint32_t - 改变后的文件大小
 */
xuint32_t xfile_changeSize(xfile_t * file, xuint32_t size);

/**
 * @brief 重命名文件
 * @param[in] filename1 - 改名前的文件名
 * @param[in] filename2 - 改名后的文件名
 * @return - 改名成功返回XTRUE,否则返回XFALSE
 */
xbool_t xfile_rename(const xchar_t * filename1, const xchar_t * filename2);

/**
 * @brief 删除文件
 * @param[in] filename - 文件名
 * @return - 文件删除成功返回XTRUE,否则返回XFALSE
 */
xbool_t xfile_remove(const xchar_t * filename);

/**
 * @brief 检查文件是否存在
 * @param[in] filename - 文件名
 * @return - 文件存在返回XTRUE,否则返回XFALSE
 */
xbool_t xfile_exist(const xchar_t * filename);

/**
 * @brief 建立目录
 * @param[in] dir - 目录名
 * @return - 目录建立成功返回XTRUE,否则返回XFALSE
 */
xbool_t xfile_mkDir(const xchar_t * dir);

/**
 * @brief 删除目录
 * @param[in] dir - 目录名
 * @return - 目录删除成功返回XTRUE,否则返回XFALSE
 */
xbool_t xfile_removeDir(const xchar_t * dir);

/**
 * @brief 获取文件大小
 * @param[in] filename - 文件名
 * @return - 文件大小
 */
xuint32_t xfile_getSize(const xchar_t * filename);

/**
 * @brief 获取目录占用空间
 * @param[in] dir - 指定目录
 * @return - 占用空间
 */
xuint32_t xfile_getSpace(const xchar_t * dir);

/**
 * @brief 获取存储器剩余空间
 * @param[in] fs - 准备获取剩余空间的存储器
 * @return - 剩余空间
 */
xuint32_t xfile_getFreeSpace(const xchar_t * xfs);

/**
 * @brief 开始枚举文件目录
 * @param[in] dir - 目录路径
 * @param[in] bDirs - XTRUE:只枚举该目录下的子目录  XFALSE:只枚举该目录下的文件
 * @return - 成功返回文件目录枚举指针,失败返回NULL
 */
xfile_enum_t * xfile_enumStart(const xchar_t * dir, xbool_t bDirs);

/**
 * @brief 枚举文件目录
 * @param[in] fileEnum - 文件目录枚举指针
 * @return - 枚举的文件名/目录名,枚举结束时返回NULL
 */
const xchar_t * xfile_enumNext(xfile_enum_t * fileEnum);

/**
 * @brief 结束枚举文件目录
 * @param[in] pfe - 文件目录枚举指针
 * @return - 无
 */
void xfile_enumEnd(xfile_enum_t * fileEnum);

#ifdef __cplusplus
}
#endif

#endif /* _XFILE_H_ */

