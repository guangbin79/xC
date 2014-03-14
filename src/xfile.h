/**
 * xC
 * @file xfile.h
 * @brief 文件
 * @author yangxq <yangxq@tiros.com.cn>
 * @date 2014/03/13
 * @par 修改记录
 */

#ifndef _XFILE_H_
#define _XFILE_H_

#include "./xinteger.h"
#include "./xboolean.h"

/**
 * @par ******** 注意 ******** <br>
 * 文件系统目前共有四种类型: <br>
 * fs0:/代表应用程序内部存储器 <br>
 * fs1:/代表扩展存储器,建议在操作系统扩展存储器(T卡)里建立tiros-com-cn-ext目录作为腾瑞万里扩展存储器 <br>
 * fs2:/应用程序缓存存储目录，主要用于存储缓存数据，此目录内文件有可能被系统清除（如ios5系统）
 * fs3:/系统媒体文件存储目录，其下又分为：
    fs3:/picture/ 映射到系统图片存储目录
    fs3:/audio/ 映射到系统的音频文件存储目录
    fs3:/video/ 映射到系统的视频文件存储目录
    备注：系统媒体文件存储目录暂时固定只支持为以上3种媒体目录
 * 如果路径没有fs0:/、fs1:/、fs2:/、fs3:\的前缀,则默认为fs0:/ <br>
 *
 * @par 代码示例
 * fs0:/first/test1.dat-->应用程序内部存储根目录下first目录中的test1.dat文件 <br>
 * fs1:/second/test2.dat-->扩展存储器根目录下second目录中的test2.dat文件 <br>
 * fs2:/img/navidog.png-->应用程序缓存存储目录根目录下img目录中的navidog.png文件 <br>
 * fs3:/picture/p1.png-->系统媒体目录的图片存储目录下p1.png文件
 * fs3:/audio/a1.mp3-->系统媒体目录的音频存储目录下a1.mp3文件
 * fs3:/video/v1.avi-->系统媒体目录的视频存储目录下v1.avi文件
 * fourth/test4.dat-->没有固定前缀，则默认指向应用程序内部存储根目录下fourth目录中的test4.dat文件 <br>
 */

/**
 * @brief 文件结构体
 */
typedef struct _File xFile_t;

/**
 * @brief 文件枚举结构体
 */
typedef struct _FileEnum xFileEnum_t;

/**
 * @brief 文件打开类型枚举
 */
typedef enum _OpenFileMode
{
    XOFM_READ,          ///< 只读
    XOFM_READWRITE,     ///< 读写
    XOFM_APPEND,        ///< 追加
    XOFM_CREATE         ///< 创建
} xOpenFileMode_t;

/**
 * @brief 文件定位类型枚举
 */
typedef enum _FileSeekType
{
    XFST_START,         ///< 文件开头
    XFST_END,           ///< 文件结尾
    XFST_CURRENT_DOWN,  ///< 当前位置向下
    XFST_CURRENT_UP     ///< 当前位置向上
} xFileSeekType_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 打开文件
 * @param[in] pszFilename - 文件名
 * @param[in] mode - 文件打开类型
 * @return - 文件结构体指针
 */
xFile_t * xfile_open(const char * pszFilename, xOpenFileMode_t mode);

/**
 * @brief 关闭文件
 * @param[in] pf - 文件结构体指针
 * @return - 无
 */
void xfile_close(xFile_t * pf);

/**
 * @brief 写文件
 * @param[in] pf - 文件结构体指针
 * @param[in] pvBuf - 准备写入文件的数据
 * @param[in] bufSize - 准备写入文件的数据长度
 * @return - 实际写入文件的数据长度
 */
xuint32_t xfile_write(xFile_t * pf, const void * pvBuf, xuint32_t bufSize);

/**
 * @brief 读文件
 * @param[in] pf - 文件结构体指针
 * @param[in] pvBuf - 指向存储从文件中读出数据地址的指针
 * @param[in] bufSize - 用于存储从文件中读出数据的空间的大小
 * @return - 实际从文件中读出的数据长度
 */
xuint32_t xfile_read(xFile_t * pf, void * pvBuf, xuint32_t bufSize);

/**
 * @brief 定位文件读写位置
 * @param[in] pf - 文件结构体指针
 * @param[in] seekType - 文件定位类型
 * @param[in] moveDistance - 从定位类型约定位置的位移
 * @return - 当前文件读写位置,FST_START的偏移量
 */
xuint32_t xfile_seek(xFile_t * pf, xFileSeekType_t seekType, xuint32_t moveDistance);

/**
 * @brief 改变文件大小
 * @param[in] pf - 文件结构体指针
 * @param[in] size - 指定新的文件大小
 * @return uint32_t - 改变后的文件大小
 */
xuint32_t xfile_chsize(xFile_t * pf, xuint32_t size);

/**
 * @brief 重命名文件
 * @param[in] pszFilename1 - 改名前的文件名
 * @param[in] pszFilename2 - 改名后的文件名
 * @return - 改名成功返回true,否则返回false
 */
xbool_t xfile_rename(const char * pszFilename1, const char * pszFilename2);

/**
 * @brief 删除文件
 * @param[in] pszFilename - 文件名
 * @return - 文件删除成功返回true,否则返回false
 */
xbool_t xfile_remove(const char * pszFilename);

/**
 * @brief 检查文件是否存在
 * @param[in] pszFilename - 文件名
 * @return - 文件存在返回true,否则返回false
 */
xbool_t xfile_exist(const char * pszFilename);

/**
 * @brief 建立目录
 * @param[in] pszDir - 目录名
 * @return - 目录建立成功返回true,否则返回false
 */
xbool_t xfile_mkdir(const char * pszDir);

/**
 * @brief 删除目录
 * @param[in] pszDir - 目录名
 * @return - 目录删除成功返回true,否则返回false
 */
xbool_t xfile_rmdir(const char * pszDir);

/**
 * @brief 获取文件大小
 * @param[in] pszFilename - 文件名
 * @return - 文件大小
 */
xuint32_t xfile_getsize(const char * pszFilename);

/**
 * @brief 获取存储器空间
 * @param[in] pszDisk - 准备获取空间的存储器
 * @return - 存储器空间
 * @par 接口使用约定:
 * 	   1.参数pszDisk可以为 “fs0:/”、“fs1:/”或“fs2:/”<br>
 */
xuint32_t xfile_getspace(const char * pszDisk);

/**
 * @brief 获取存储器剩余空间
 * @param[in] pszDisk - 准备获取剩余空间的存储器
 * @return - 存储器剩余空间
 * @par 接口使用约定:
 * 	   1.参数pszDisk可以为 “fs0:/”、“fs1:/”或“fs2:/”<br>
 */
xuint32_t xfile_getfreespace(const char * pszDisk);

/**
 * @brief 开始枚举文件目录
 * @param[in] pszDir - 目录路径
 * @param[in] bDirs - true:只枚举该目录下的子目录  false:只枚举该目录下的文件
 * @return - 成功返回文件目录枚举指针,失败返回NULL
 */
xFileEnum_t * xfile_enumstart(const char * pszDir, xbool_t bDirs);

/**
 * @brief 枚举文件目录
 * @param[in] pfe - 文件目录枚举指针
 * @return - 枚举的文件名,枚举结束时返回NULL
 */
const char * xfile_enumnext(xFileEnum_t * pfe);

/**
 * @brief 结束枚举文件目录
 * @param[in] pfe - 文件目录枚举指针
 * @return - 无
 */
void xfile_enumend(xFileEnum_t * pfe);


/**
 * @brief 获取存储器是否存在
 * @param[in] pszDisk - 准备判断是否存在的存储器
 * @return - true：该存储器存在    false:该存储器不存在
 * @par 接口使用约定:
 * 	   1.参数pszDisk可以为 “fs0:/”、“fs1:/”或“fs2:/”<br>
 */
xbool_t xfile_diskexist(const char * pszDisk);

#ifdef __cplusplus
}
#endif

#endif /* _XFILE_H_ */

