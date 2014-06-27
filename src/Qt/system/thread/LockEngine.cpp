//
//  ThreadEngine.m
//  system_api
//
//  Created by Harry on 13-11-4.
//
//

#include "LockEngine.h"

/**************************************************/
/*                                                */
/*      线程互斥引擎API                             */
/*                                                */
/**************************************************/
CMutexEngine::CMutexEngine(bool bRecursive) :
    _Lock(bRecursive ? QMutex::Recursive: QMutex::NonRecursive)
{
}

CMutexEngine::~CMutexEngine()
{
}

void CMutexEngine::lock()
{
    _Lock.lock();
}

void CMutexEngine::unlock()
{
    _Lock.unlock();
}
