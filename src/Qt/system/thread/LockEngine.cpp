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
CMutexEngine::CMutexEngine()
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
