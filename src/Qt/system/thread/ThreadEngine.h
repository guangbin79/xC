#ifndef _THREADENGINE_H_
#define _THREADENGINE_H_

#include <QObject>
#include "MyThread.h"

typedef struct _SYS_ThreadStr SYS_Thread;


class CThreadEngine : public QObject
{
    Q_OBJECT
public:
    explicit CThreadEngine(QObject *parent = 0);
    ~CThreadEngine();

private:
    CMyThread* _pThreadHandle;
    SYS_Thread* _pThreadNotify;


public slots:
    void NotifyToMainThread();    

public:
    void RunOnThread();

public:
    void SetNotify(SYS_Thread* _pNotify);
    void Start();
    void Cancel();
    bool IsExecuting();
    
};

#endif // _THREADENGINE_H_
