#ifndef _MYTHREAD_H_
#define _MYTHREAD_H_

#include<QThread>

class CThreadEngine;

class CMyThread : public QThread
{
    Q_OBJECT
public:
    explicit CMyThread(QObject *parent = 0);
    ~CMyThread();
    static void sleep(unsigned long);

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
