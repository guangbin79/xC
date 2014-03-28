
#include "MyThread.h"
#include "ThreadEngine.h"


CMyThread::CMyThread(QObject *parent) :
    QThread(parent)
{
   _pThreadHandle = 0;
   _pThreadNotify = 0;
}

CMyThread::~CMyThread()
{
    if (_pThreadHandle)
    {
        _pThreadHandle = 0;
    }
}

void CMyThread::SetNotify(CThreadEngine* _pNotify)
{
    _pThreadNotify = _pNotify;
}

void CMyThread::run()
{
    if (_pThreadNotify)
    {
        _pThreadNotify->RunOnThread();
    }
}











