#include "../../include/sys_http.h"
#include "../include/sys_httpdef.h"
#include <stdlib.h>
#include <QUrl>

class MyQHttp : public QHttp
{
    Q_OBJECT
public:
    MyQHttp(SYS_Http * pHttp): m_pHttp(pHttp) {}

    void connectSlots() {
        connect(this, SIGNAL(done(bool error)), this, SLOT(done_Slot(bool error)));
        connect(this, SIGNAL(readyRead(const QHttpResponseHeader & resp)), this, SLOT(readyRead_Slot(const QHttpResponseHeader & resp)));
        connect(this, SIGNAL(responseHeaderReceived(const QHttpResponseHeader & resp)), this, SLOT(responseHeaderReceived_Slot(const QHttpResponseHeader & resp)));
        connect(m_pHttp->pTimer, SIGNAL(timeout()), this, SLOT(timeout_Slot()));
    }

    void disconnectSlots() {
        disconnect(this, SIGNAL(done(bool error)), this, SLOT(done_Slot(bool error)));
        disconnect(this, SIGNAL(readyRead(const QHttpResponseHeader & resp)), this, SLOT(readyRead_Slot(const QHttpResponseHeader & resp)));
        disconnect(this, SIGNAL(responseHeaderReceived(const QHttpResponseHeader & resp)), this, SLOT(responseHeaderReceived_Slot(const QHttpResponseHeader & resp)));
        disconnect(m_pHttp->pTimer, SIGNAL(timeout()), this, SLOT(timeout_Slot()));
    }

private:
    SYS_Http * m_pHttp;

public slots:
    void done_Slot(bool error) {
        SYS_Http_Error sherr = SHE_NO_ERROR;

        m_pHttp->pTimer->stop();

        if (error) {
            Q_ASSERT(this->error() != NoError);

            switch (this->error()) {
            case UnknownError:
            case HostNotFound:
                sherr = SHE_NET_USELESS;
                break;
            case ConnectionRefused:
            case UnexpectedClose:
            default:
                sherr = SHE_SERVER_USELESS;
                break;
            }
        }

        if (m_pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST]) {
            ((SYS_HttpFinishedFunc)m_pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST])(m_pHttp->pv[SHCB_FINISHED - SHCB_REQUEST], sherr);
        }
    }

    void readyRead_Slot(const QHttpResponseHeader &) {
        if (bytesAvailable()) {
            m_pHttp->pTimer->stop();

            QByteArray data = readAll();

            if (m_pHttp->pfn[SHCB_BODY - SHCB_REQUEST]) {
                ((SYS_HttpBodyFunc)m_pHttp->pfn[SHCB_BODY - SHCB_REQUEST])(m_pHttp->pv[SHCB_BODY - SHCB_REQUEST], data.data(), (uint32_t)data.size());
            }

            m_pHttp->isConnecting = false;
            m_pHttp->pTimer->start(m_pHttp->responseTimeout);
        }
    }

    void responseHeaderReceived_Slot(const QHttpResponseHeader & resp) {
        m_pHttp->pTimer->stop();

        if (m_pHttp->pfn[SHCB_RESPONSE - SHCB_REQUEST]) {
             ((SYS_HttpResponseFunc)m_pHttp->pfn[SHCB_RESPONSE - SHCB_REQUEST])(m_pHttp->pv[SHCB_RESPONSE - SHCB_REQUEST], (uint16_t)resp.statusCode());
        }

        if (m_pHttp->pfn[SHCB_HEADER - SHCB_REQUEST]) {
            QList<QPair<QString, QString> > headerList = resp.values();
            QPair<QString, QString> header;

            for (int i = 0; i < headerList.size(); ++i) {
                header = headerList[i];

                ((SYS_HttpHeaderFunc)m_pHttp->pfn[SHCB_HEADER - SHCB_REQUEST])(m_pHttp->pv[SHCB_HEADER - SHCB_REQUEST], header.first.toLatin1().data(), header.second.toLatin1().data());
            }
        }

        m_pHttp->isConnecting = false;
        m_pHttp->pTimer->start(m_pHttp->responseTimeout);
    }

    void timeout_Slot() {
        ((MyQHttp *)m_pHttp->pQHttp)->disconnectSlots();
        m_pHttp->pTimer->stop();
        m_pHttp->pQHttp->abort();
        m_pHttp->isRunning = false;

        if (m_pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST]) {
            SYS_Http_Error sherr = m_pHttp->isConnecting? SHE_CONNECT_TIMEOUT: SHE_RESPONSE_TIMEOUT;

            ((SYS_HttpFinishedFunc)m_pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST])(m_pHttp->pv[SHCB_FINISHED - SHCB_REQUEST], sherr);
        }
    }
};

SYS_Http* sys_HttpCreate(uint32_t dwConnectTimeout, uint32_t dwResponseTimeout) {
    SYS_Http * pHttp = (SYS_Http *)malloc(sizeof(SYS_Http));

    if (!pHttp) return NULL;

    pHttp->pHeaderList = new QList<QPair<QString, QString> >;

    if (!pHttp->pHeaderList) {
        free(pHttp);
        return NULL;
    }

    pHttp->pQHttp = new MyQHttp(pHttp);

    if (!pHttp->pQHttp) {
        delete pHttp->pHeaderList;
        free(pHttp);
        return NULL;
    }

    pHttp->pTimer = new QTimer();

    if (!pHttp->pTimer) {
        delete pHttp->pQHttp;
        delete pHttp->pHeaderList;
        free(pHttp);
        return NULL;
    }

    pHttp->isRunning = false;
    pHttp->isConnecting = true;
    pHttp->connectTimeout = dwConnectTimeout > 0? dwConnectTimeout: 1000;
    pHttp->responseTimeout = dwResponseTimeout > 0? dwResponseTimeout: 2000;

    for (int i = 0; i < HTTP_CALLBACK_COUNT; ++i) {
        pHttp->pfn[i] = NULL;
        pHttp->pv[i] = NULL;
    }

    return pHttp;
}

void sys_HttpDestroy(SYS_Http* pHttp) {
    sys_HttpCancel(pHttp);

    delete pHttp->pTimer;
    delete pHttp->pQHttp;
    delete pHttp->pHeaderList;
    free(pHttp);
}

void sys_HttpRegisterCallback(SYS_Http* pHttp, SYS_Http_Callback type, void * pfnCallback, void * pvUser) {
    pHttp->pfn[type - SHCB_REQUEST] = pfnCallback;
    pHttp->pv[type - SHCB_REQUEST] = pvUser;
}

bool sys_HttpAddHeader(SYS_Http* pHttp, const char * pszHeader, const char * pszValue) {
    Q_ASSERT(pszHeader != NULL && pszValue != NULL);

    for (int i = 0; i < pHttp->pHeaderList->count(); i++) {
        QString& str = (*pHttp->pHeaderList)[i].first;

        if (str.compare(pszHeader) == 0) return false;
    }

    QPair<QString, QString> header;

    header.first.append(pszHeader);
    header.second.append(pszValue);
    pHttp->pHeaderList->append(header);

    return true;
}

void sys_HttpRemoveHeader(SYS_Http* pHttp, const char * pszHeader) {
    Q_ASSERT(pszHeader != NULL);

    for (int i = 0; i < pHttp->pHeaderList->count(); i++) {
        QString& str = (*pHttp->pHeaderList)[i].first;

        if (str.compare(pszHeader) == 0) {
            pHttp->pHeaderList->removeAt(i);
            break;
        }
    }
}

bool sys_HttpIsRunning(SYS_Http* pHttp) {
    return pHttp->isRunning;
}

bool sys_HttpGet(SYS_Http* pHttp, const char * pszUrl) {
    Q_ASSERT(pszUrl != NULL);

    if (sys_HttpIsRunning(pHttp)) return false;

    sys_HttpCancel(pHttp);

    QUrl url(pszUrl);

    pHttp->pQHttp->setHost(url.host(), url.port() > 0? url.port(): 0);

    QHttpRequestHeader header;

    header.setValues(*pHttp->pHeaderList);
    header.setRequest("GET", url.encodedPath());

    ((MyQHttp *)pHttp->pQHttp)->connectSlots();

    pHttp->isRunning = true;

    pHttp->pQHttp->request(header);

    if (pHttp->pfn[SHCB_REQUEST - SHCB_REQUEST]) {
        ((SYS_HttpRequestFunc)pHttp->pfn[SHCB_REQUEST - SHCB_REQUEST])(pHttp->pv[SHCB_REQUEST - SHCB_REQUEST], pszUrl);
    }

    pHttp->isConnecting = true;
    pHttp->pTimer->start(pHttp->connectTimeout);

    return true;
}

bool sys_HttpPost(SYS_Http* pHttp, const char * pContentType, const char * pszUrl, const void * pvData, uint32_t dwSize) {
    Q_ASSERT(pszUrl != NULL);

    if (sys_HttpIsRunning(pHttp)) return false;

    sys_HttpCancel(pHttp);

    QUrl url(pszUrl);

    pHttp->pQHttp->setHost(url.host(), url.port() > 0? url.port(): 0);

    QHttpRequestHeader header;

    header.setValues(*pHttp->pHeaderList);
    header.setContentType(QString(pContentType));
    header.setContentLength((int)dwSize);
    header.setRequest("POST", url.encodedPath());

    ((MyQHttp *)pHttp->pQHttp)->connectSlots();

    pHttp->isRunning = true;

    pHttp->pQHttp->request(header, QByteArray((const char *)pvData, (int)dwSize));

    if (pHttp->pfn[SHCB_REQUEST - SHCB_REQUEST]) {
        ((SYS_HttpRequestFunc)pHttp->pfn[SHCB_REQUEST - SHCB_REQUEST])(pHttp->pv[SHCB_REQUEST - SHCB_REQUEST], pszUrl);
    }

    pHttp->isConnecting = true;
    pHttp->pTimer->start(pHttp->connectTimeout);

    return true;
}

void sys_HttpCancel(SYS_Http* pHttp) {
    ((MyQHttp *)pHttp->pQHttp)->disconnectSlots();
    pHttp->pTimer->stop();
    pHttp->pQHttp->abort();

    if (pHttp->isRunning) {
        pHttp->isRunning = false;

        if (pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST]) {
            ((SYS_HttpFinishedFunc)pHttp->pfn[SHCB_FINISHED - SHCB_REQUEST])(pHttp->pv[SHCB_FINISHED - SHCB_REQUEST], SHE_CANCELED);
        }
    }
}
