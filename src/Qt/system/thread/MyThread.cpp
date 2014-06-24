
#include "MyThread.h"
#include "ThreadEngine.h"

struct TLS_Data {
    const void * data;
};

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

void CMyThread::sleep(unsigned long time)
{
    QThread::sleep(time);
}

void * CMyThread::TlsAlloc()
{
   QThreadStorage<TLS_Data> *stores = new QThreadStorage<TLS_Data>;

   return (void *)stores;
}

void CMyThread::TlsFree(void * tls_key)
{
    QThreadStorage<TLS_Data> *stores = (QThreadStorage<TLS_Data> *)tls_key;

    delete stores;
}

void * CMyThread::TlsGet(void * tls_key)
{
    QThreadStorage<TLS_Data> *stores = (QThreadStorage<TLS_Data> *)tls_key;

    return (void *)stores->localData().data;
}

void CMyThread::TlsSet(void * tls_key, const void * data)
{
    QThreadStorage<TLS_Data> *stores = (QThreadStorage<TLS_Data> *)tls_key;
    TLS_Data tls_data = {data};

    stores->setLocalData(tls_data);
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











