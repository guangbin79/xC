/**
 * xC
 * @file xfile.h
 * @brief �ļ�
 * @author yangxq <yangxq@tiros.com.cn>
 * @date 2014/03/13
 * @par �޸ļ�¼
 */

#ifndef _XFILE_H_
#define _XFILE_H_

#include "./xinteger.h"
#include "./xboolean.h"

/**
 * @par ******** ע�� ******** <br>
 * �ļ�ϵͳĿǰ������������: <br>
 * fs0:/����Ӧ�ó����ڲ��洢�� <br>
 * fs1:/������չ�洢��,�����ڲ���ϵͳ��չ�洢��(T��)�ｨ��tiros-com-cn-extĿ¼��Ϊ����������չ�洢�� <br>
 * fs2:/Ӧ�ó��򻺴�洢Ŀ¼����Ҫ���ڴ洢�������ݣ���Ŀ¼���ļ��п��ܱ�ϵͳ�������ios5ϵͳ��
 * fs3:/ϵͳý���ļ��洢Ŀ¼�������ַ�Ϊ��
    fs3:/picture/ ӳ�䵽ϵͳͼƬ�洢Ŀ¼
    fs3:/audio/ ӳ�䵽ϵͳ����Ƶ�ļ��洢Ŀ¼
    fs3:/video/ ӳ�䵽ϵͳ����Ƶ�ļ��洢Ŀ¼
    ��ע��ϵͳý���ļ��洢Ŀ¼��ʱ�̶�ֻ֧��Ϊ����3��ý��Ŀ¼
 * ���·��û��fs0:/��fs1:/��fs2:/��fs3:\��ǰ׺,��Ĭ��Ϊfs0:/ <br>
 *
 * @par ����ʾ��
 * fs0:/first/test1.dat-->Ӧ�ó����ڲ��洢��Ŀ¼��firstĿ¼�е�test1.dat�ļ� <br>
 * fs1:/second/test2.dat-->��չ�洢����Ŀ¼��secondĿ¼�е�test2.dat�ļ� <br>
 * fs2:/img/navidog.png-->Ӧ�ó��򻺴�洢Ŀ¼��Ŀ¼��imgĿ¼�е�navidog.png�ļ� <br>
 * fs3:/picture/p1.png-->ϵͳý��Ŀ¼��ͼƬ�洢Ŀ¼��p1.png�ļ�
 * fs3:/audio/a1.mp3-->ϵͳý��Ŀ¼����Ƶ�洢Ŀ¼��a1.mp3�ļ�
 * fs3:/video/v1.avi-->ϵͳý��Ŀ¼����Ƶ�洢Ŀ¼��v1.avi�ļ�
 * fourth/test4.dat-->û�й̶�ǰ׺����Ĭ��ָ��Ӧ�ó����ڲ��洢��Ŀ¼��fourthĿ¼�е�test4.dat�ļ� <br>
 */

/**
 * @brief �ļ��ṹ��
 */
typedef struct _File xFile_t;

/**
 * @brief �ļ�ö�ٽṹ��
 */
typedef struct _FileEnum xFileEnum_t;

/**
 * @brief �ļ�������ö��
 */
typedef enum _OpenFileMode
{
    XOFM_READ,          ///< ֻ��
    XOFM_READWRITE,     ///< ��д
    XOFM_APPEND,        ///< ׷��
    XOFM_CREATE         ///< ����
} xOpenFileMode_t;

/**
 * @brief �ļ���λ����ö��
 */
typedef enum _FileSeekType
{
    XFST_START,         ///< �ļ���ͷ
    XFST_END,           ///< �ļ���β
    XFST_CURRENT_DOWN,  ///< ��ǰλ������
    XFST_CURRENT_UP     ///< ��ǰλ������
} xFileSeekType_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ���ļ�
 * @param[in] pszFilename - �ļ���
 * @param[in] mode - �ļ�������
 * @return - �ļ��ṹ��ָ��
 */
xFile_t * xfile_open(const char * pszFilename, xOpenFileMode_t mode);

/**
 * @brief �ر��ļ�
 * @param[in] pf - �ļ��ṹ��ָ��
 * @return - ��
 */
void xfile_close(xFile_t * pf);

/**
 * @brief д�ļ�
 * @param[in] pf - �ļ��ṹ��ָ��
 * @param[in] pvBuf - ׼��д���ļ�������
 * @param[in] bufSize - ׼��д���ļ������ݳ���
 * @return - ʵ��д���ļ������ݳ���
 */
xuint32_t xfile_write(xFile_t * pf, const void * pvBuf, xuint32_t bufSize);

/**
 * @brief ���ļ�
 * @param[in] pf - �ļ��ṹ��ָ��
 * @param[in] pvBuf - ָ��洢���ļ��ж������ݵ�ַ��ָ��
 * @param[in] bufSize - ���ڴ洢���ļ��ж������ݵĿռ�Ĵ�С
 * @return - ʵ�ʴ��ļ��ж��������ݳ���
 */
xuint32_t xfile_read(xFile_t * pf, void * pvBuf, xuint32_t bufSize);

/**
 * @brief ��λ�ļ���дλ��
 * @param[in] pf - �ļ��ṹ��ָ��
 * @param[in] seekType - �ļ���λ����
 * @param[in] moveDistance - �Ӷ�λ����Լ��λ�õ�λ��
 * @return - ��ǰ�ļ���дλ��,FST_START��ƫ����
 */
xuint32_t xfile_seek(xFile_t * pf, xFileSeekType_t seekType, xuint32_t moveDistance);

/**
 * @brief �ı��ļ���С
 * @param[in] pf - �ļ��ṹ��ָ��
 * @param[in] size - ָ���µ��ļ���С
 * @return uint32_t - �ı����ļ���С
 */
xuint32_t xfile_chsize(xFile_t * pf, xuint32_t size);

/**
 * @brief �������ļ�
 * @param[in] pszFilename1 - ����ǰ���ļ���
 * @param[in] pszFilename2 - ��������ļ���
 * @return - �����ɹ�����true,���򷵻�false
 */
xbool_t xfile_rename(const char * pszFilename1, const char * pszFilename2);

/**
 * @brief ɾ���ļ�
 * @param[in] pszFilename - �ļ���
 * @return - �ļ�ɾ���ɹ�����true,���򷵻�false
 */
xbool_t xfile_remove(const char * pszFilename);

/**
 * @brief ����ļ��Ƿ����
 * @param[in] pszFilename - �ļ���
 * @return - �ļ����ڷ���true,���򷵻�false
 */
xbool_t xfile_exist(const char * pszFilename);

/**
 * @brief ����Ŀ¼
 * @param[in] pszDir - Ŀ¼��
 * @return - Ŀ¼�����ɹ�����true,���򷵻�false
 */
xbool_t xfile_mkdir(const char * pszDir);

/**
 * @brief ɾ��Ŀ¼
 * @param[in] pszDir - Ŀ¼��
 * @return - Ŀ¼ɾ���ɹ�����true,���򷵻�false
 */
xbool_t xfile_rmdir(const char * pszDir);

/**
 * @brief ��ȡ�ļ���С
 * @param[in] pszFilename - �ļ���
 * @return - �ļ���С
 */
xuint32_t xfile_getsize(const char * pszFilename);

/**
 * @brief ��ȡ�洢���ռ�
 * @param[in] pszDisk - ׼����ȡ�ռ�Ĵ洢��
 * @return - �洢���ռ�
 * @par �ӿ�ʹ��Լ��:
 * 	   1.����pszDisk����Ϊ ��fs0:/������fs1:/����fs2:/��<br>
 */
xuint32_t xfile_getspace(const char * pszDisk);

/**
 * @brief ��ȡ�洢��ʣ��ռ�
 * @param[in] pszDisk - ׼����ȡʣ��ռ�Ĵ洢��
 * @return - �洢��ʣ��ռ�
 * @par �ӿ�ʹ��Լ��:
 * 	   1.����pszDisk����Ϊ ��fs0:/������fs1:/����fs2:/��<br>
 */
xuint32_t xfile_getfreespace(const char * pszDisk);

/**
 * @brief ��ʼö���ļ�Ŀ¼
 * @param[in] pszDir - Ŀ¼·��
 * @param[in] bDirs - true:ֻö�ٸ�Ŀ¼�µ���Ŀ¼  false:ֻö�ٸ�Ŀ¼�µ��ļ�
 * @return - �ɹ������ļ�Ŀ¼ö��ָ��,ʧ�ܷ���NULL
 */
xFileEnum_t * xfile_enumstart(const char * pszDir, xbool_t bDirs);

/**
 * @brief ö���ļ�Ŀ¼
 * @param[in] pfe - �ļ�Ŀ¼ö��ָ��
 * @return - ö�ٵ��ļ���,ö�ٽ���ʱ����NULL
 */
const char * xfile_enumnext(xFileEnum_t * pfe);

/**
 * @brief ����ö���ļ�Ŀ¼
 * @param[in] pfe - �ļ�Ŀ¼ö��ָ��
 * @return - ��
 */
void xfile_enumend(xFileEnum_t * pfe);


/**
 * @brief ��ȡ�洢���Ƿ����
 * @param[in] pszDisk - ׼���ж��Ƿ���ڵĴ洢��
 * @return - true���ô洢������    false:�ô洢��������
 * @par �ӿ�ʹ��Լ��:
 * 	   1.����pszDisk����Ϊ ��fs0:/������fs1:/����fs2:/��<br>
 */
xbool_t xfile_diskexist(const char * pszDisk);

#ifdef __cplusplus
}
#endif

#endif /* _XFILE_H_ */

