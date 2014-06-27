//
//  ThreadEngine.h
//  system_api
//
//  Created by Harry on 13-11-4.
//
//
#ifndef _LOCKENGINE_H_
#define _LOCKENGINE_H_

#include<QMutex>

/**************************************************/
/*                                                */
/*      线程互斥引擎API                             */
/*                                                */
/**************************************************/
class CMutexEngine
{
private:
    QMutex _Lock;

public:
    CMutexEngine(bool bRecursive);
    ~CMutexEngine();
    void lock();
    void unlock();
};

#endif /*_LOCKENGINE_H_*/



