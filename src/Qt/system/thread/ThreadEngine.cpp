#include "ThreadEngine.h"
#include <QUrl>
#include <QDebug>
#include"../include/sys_threaddef.h"

CThreadEngine::CThreadEngine(QObject *parent) :
    QObject(parent)
{
   _pThreadNotify = NULL;
   _pThreadHandle = new CMyThread;
   _pThreadHandle->SetNotify(this);
}

CThreadEngine::~CThreadEngine()
{
    if (_pThreadHandle)
    {
        if (_pThreadHandle->isRunning())
            _pThreadHandle->terminate();
        delete _pThreadHandle;
        _pThreadHandle = NULL;
    }
}

void CThreadEngine::SetNotify(SYS_Thread* _pNotify)
{
    _pThreadNotify = _pNotify;
}

void CThreadEngine::RunOnThread()
{
    qDebug()<<"RunOnThread!!";
    if (_pThreadNotify && _pThreadNotify->_pThreadProcFunc)
    {
        (*_pThreadNotify->_pThreadProcFunc)(_pThreadNotify->_pvUser);
    }
}

void CThreadEngine::Start()
{
    if (_pThreadHandle)
    {
        if (_pThreadHandle->isRunning())
        {
                qDebug()<<"Current thread is already running!!";
        }
        else
        {
            qDebug()<<"Current thread is restart!!";
            _pThreadHandle->start();
        }
    }
    else
    {
            _pThreadHandle = new CMyThread;
            _pThreadHandle->SetNotify(this);
            _pThreadHandle->start();
    }
}

void CThreadEngine::Cancel()
{
    if (_pThreadHandle)
    {
        if (_pThreadHandle->isRunning())
        {
            _pThreadHandle->terminate();
        }
    }
}

bool CThreadEngine::IsExecuting()
{
    if (_pThreadHandle)
        return _pThreadHandle->isRunning();
    return false;
}













