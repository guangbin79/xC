/**
 * xC
 * @file xfont.h
 * @brief ����
 * @author yangxq <yangxq@tiros.com.cn>
 * @date 2014/03/13
 * @par �޸ļ�¼
 */

#ifndef _XFONT_H_
#define _XFONT_H_

#include "./xboolean.h"
#include "./ximage.h"
#include "./xinteger.h"
#include "./xcharacter.h"

/**
 * @brief ����ṹ��
 */
typedef struct _Font xFont_t;

/**
 * @brief ������ṹ��
 */
typedef enum _FontStyle
{
    XFS_MAP_1 = 100,                        ///<  ��׼�����С:��ͼ�������36
    XFS_MAP_2,                              ///<  ��׼�����С:
    XFS_MAP_3,                              ///<  ��׼�����С:
    XFS_MAP_4,                              ///<  ��׼�����С:
    XFS_MAP_5,                              ///<  ��׼�����С:
    XFS_MAP_6,                              ///<  ��׼�����С:
    XFS_MAP_7,                              ///<  ��׼�����С:
    XFS_MAP_8,                              ///<  ��׼�����С:
    XFS_MAP_9,                              ///<  ��׼�����С:
    XFS_MAP_10                              ///<  ��׼�����С:
} xFontStyle_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ��������
 * @param - ��
 * @return - ����ṹ��
 */
xFont_t * xfont_create();

/**
 * @brief ��������
 * @param[in] pft - ����ṹ��
 * @return - ��
 */
void xfont_destroy(xFont_t * pft);

/**
 * @brief ����������
 * @param[in] pft - ����ṹ��
 * @param[in] fst - ������
 * @return - ��
 */
void xfont_setstyle(xFont_t * pft, xFontStyle_t fst);

/**
 * @brief ��������
 * @param[in] pft - ����ṹ��
 * @param[in] pimg - Ŀ��ͼƬ�ṹ��
 * @param[in] x - Ŀ��λ�ã����Ͻ�x����
 * @param[in] y - Ŀ��λ�ã����Ͻ�y����
 * @param[in] pwszText - �����ַ���
 * @param[in] nChars - �����ַ�����
 * @param[in] r,g,b - ����������ɫ
 * @return - ��
 */
void xfont_drawtext(xFont_t * pft, xImage* pimg, xint16_t x, xint16_t y, const xwchar_t * pwszText, xuint32_t nChars, xuint8_t r, xuint8_t g, xuint8_t b);

/**
 * @brief ��ȡ�����С
 * @param[in] pft - ����ṹ��
 * @return - �����С
 */
xuint16_t xfont_getfontsize(xFont_t * pft);

/**
 * @brief ��ȡ����߶�
 * @param[in] pft - ����ṹ��
 * @return - ����߶�
 */
xuint16_t xfont_getheight(xFont_t * pft);

/**
 * @brief ��ȡ�ַ������
 * @param[in] pft - ����ṹ��
 * @param[in] pwszText - Ŀ���ַ���
 * @param[in] nChars - Ŀ���ַ����ִ��ַ�����,���Ϊ0�򳣳����ַ������ȵ�����,��ʾ����Ŀ���ַ���ȫ��
 * @param[in] nMaxWidth - �����ÿ��(����),���Ϊ0,���ʾ���û������
 * @param[out] pnFits - �������ÿ�ȵ���Ļ�п������ɵ��ַ���,�ò�������Ϊ��,��ֵ��ʾ����Ҫ������ֵ
 * @return - ���ÿռ��п������ɵ��ı��ַ����ܿ��(������Ϊ��λ)
 */
xuint16_t xfont_measuretext(xFont_t * pft, const xwchar_t * pwszText, xuint32_t nChars, xuint16_t nMaxWidth, xuint32_t * pnFits);

/**
 * @brief ׼����ͼ������
 * @param[in] pft - ����ṹ��
 * @param[in] pimg - Ŀ��ͼƬ�ṹ��
 * @return ��
*/
void xfont_drawbegin(xFont_t * pft, xImage* pimg);

/**
 * @brief ��ʼ��������
 * @param[in] pft - ����ṹ��
 * @param[in] x - Ŀ��λ�ã����Ͻ�x����
 * @param[in] y - Ŀ��λ�ã����Ͻ�y����
 * @param[in] pwszText - �����ַ���
 * @param[in] r,g,b - ����������ɫ
 * @return ��
*/
void xfont_drawtext2(xFont_t * pft, xint16_t x, xint16_t y, const xwchar_t * pwszText, xuint8_t r, xuint8_t g, xuint8_t b);

/**
 * @brief �ͷŻ�ͼ������
 * @param[in] pft - ����ṹ��
 * @return ��
*/
void xfont_drawend(xFont_t * pft);

#ifdef __cplusplus
}
#endif

#endif /* _XFONT_H_ */

