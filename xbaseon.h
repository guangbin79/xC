/**
 * xC
 * @file xostypes.h
 * @brief 操作系统类型
 * @author guangbin <guangbin79@gmail.com>
 * @date 2015/05/06
 * @par 修改记录
 *
 */

#ifndef _XBASEON_H_
#define _XBASEON_H_

#if defined(QT_VERSION)

    #define XBASEON_QT           1

#elif defined(__ANDROID__)

    #define XBASEON_ANDROID      1

#elif defined(IOS_VERSION)

    #define XBASEON_IOS          1

#endif

#endif /* _XBASEON_H_ */

