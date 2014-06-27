#ifndef _MYTHREAD_H_
#define _MYTHREAD_H_

#include<QThread>
#include<QThreadStorage>

class CThreadEngine;

class CMyThread : public QThread
{
    Q_OBJECT
public:
    explicit CMyThread(QObject *parent = 0);
    ~CMyThread();
    static void sleep(unsigned long);
    static void * TlsAlloc();
    static void TlsFree(void * tls_key);
    static void * TlsGet(void * tls_key);
    static void TlsSet(void * tls_key, const void * data);

private:
    void* _pThreadHandle;
    CThreadEngine* _pThreadNotify;

signals:
    void sigMainThread();

public:
    void SetNotify(CThreadEngine* _pNotify);
    void run();

};

#endif // _MYTHREAD_H_
