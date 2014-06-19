#include "../../../xhttp.h"
#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../../../xmemory.h"
#include "../../../xboolean.h"
#include "../jni_include/sys_xhttp.h"
#include "../jni_include/jni_http.h"
//#include "./netManager/http_def.h"
//#include "./netManager/comm_netManager.h"
//#include "../../../universal/string.h"
//#include "../../BasePlugin.h"


xhttp_t * xhttp_create(xuint32_t dwConnectTimeout, xuint32_t dwResponseTimeout)
{
    return (xhttp_t*)sys_httpcreate(dwConnectTimeout,dwResponseTimeout);
}

void xhttp_destroy(xhttp_t * pHttp)
{
    sys_httpdestroy((SYS_Http*)pHttp);
}


void xhttp_registerCallback(xhttp_t * pHttp, xhttp_callback_t type, void * pfnCallback, void * pvUser)
{
	sys_httpregisternotify((SYS_Http*)pHttp, (SYS_HttpEvent)type, (SYS_PFNHTTPEVENT)pfnCallback, pvUser);
}

xbool_t xhttp_addHeader(xhttp_t * pHttp, const xchar_t * pszHeader, const xchar_t * pszValue)
{
	return  sys_httpaddheader((SYS_Http*)pHttp, pszHeader, pszValue);
}

void xhttp_removeHeader(xhttp_t * pHttp, const xchar_t * pszHeader)
{
	xsys_xdebug_assert(pHttp != XNULL && pszHeader != XNULL);
    sys_httpremoveheader((SYS_Http*) pHttp, pszHeader);
}

xbool_t xhttp_get(xhttp_t * pHttp, const xchar_t * pszUrl)
{
	xsys_xdebug_assert(pHttp != XNULL && pszUrl != XNULL);
	return sys_httpget((SYS_Http*)pHttp, pszUrl);
}


xbool_t xhttp_post(xhttp_t * pHttp, const xchar_t * pContentType, const xchar_t * pszUrl, const void * pvData, xuint32_t dwSize)
{
	xsys_xdebug_assert(pHttp != XNULL && pContentType != XNULL && pszUrl != XNULL && pvData != XNULL);
	return sys_httppost((SYS_Http*) pHttp, pContentType, pszUrl, pvData, dwSize);
}

void xhttp_cancel(xhttp_t * pHttp)
{
	xsys_xdebug_assert(pHttp != XNULL);
	sys_httpcancel((SYS_Http*) pHttp);

}

xbool_t xhttp_isRunning(xhttp_t * pHttp)
{
	return sys_httpisRunning((SYS_Http*) pHttp);
}

//void tr_httpsettimeout(Http * pHttp, uint32_t dwMSecs1, uint32_t dwMSecs2)
//{
//    assert(pHttp != NULL);
//    if(pHttp)
//    {
//        pHttp->_iConnectingTime = dwMSecs1;
//        pHttp->_iPieceDataRecvedTime = dwMSecs2;
//    }
//}
//
//void tr_httpaddplugin(Http * pHttp, void* plugin)
//{
//    assert(pHttp != NULL && plugin != NULL);
//    BasePlugin* _newplugin = (BasePlugin*)plugin;
//    BasePlugin* _plugin = 0;
//    if (_newplugin->_type == ENetPlugin_HttpCommHeaders)
//    {
//        _plugin = pHttp->_pNetPlugin_HttpCommHeaders;
//        pHttp->_pNetPlugin_HttpCommHeaders = _newplugin;
//    }
//    else if (_newplugin->_type == ENetPlugin_ErrorTry)
//    {
//        _plugin = pHttp->_pNetPlugin_ErrorTry;
//        pHttp->_pNetPlugin_ErrorTry = _newplugin;
//    }
//    else if (_newplugin->_type == ENetPlugin_PmAnalysis)
//    {
//        _plugin = pHttp->_pNetPlugin_PmAnalysis;
//        pHttp->_pNetPlugin_PmAnalysis = _newplugin;
//    }
//    if (_plugin)
//    {
//        (*_plugin->_Release)(_plugin);
//    }
//}
//
//void tr_httpsetservicetype(Http * pHttp, const char* moduletype, const char* servicetype)
//{
//    int len = 0;
//    assert(pHttp != NULL && moduletype != NULL && servicetype != NULL);
//    if ( pHttp->_sModuleType )
//    {
//        free(pHttp->_sModuleType);
//    }
//    len = strlen(moduletype);
//    pHttp->_sModuleType = (char*)malloc(sizeof(char)*(len+1));
//    strcpy(pHttp->_sModuleType, moduletype);
//    pHttp->_sModuleType[len] = '\0';
//    if ( pHttp->_sServiceType )
//    {
//        free(pHttp->_sServiceType);
//    }
//    len = strlen(servicetype);
//    pHttp->_sServiceType = (char*)malloc(sizeof(char)*(len+1));
//    strcpy(pHttp->_sServiceType, servicetype);
//    pHttp->_sServiceType[len] = '\0';
//}
//
//bool AddHeaderToVector(CVector** pVector, const char* pszHeader, const char* pszValue)
//{
//    HttpHeader* pHeader = 0;
//    CVector* pHeaders = 0;
//    int len = 0;
//    assert(pVector != NULL && pszHeader != NULL && pszValue != NULL);
//    pHeaders = *pVector;
//    if (pHeaders)
//    {
//        int i = 0;
//        for (i = 0; i < pHeaders->m_iSize; i++)
//        {
//            pHeader = GetElement(pHeaders, i);
//            if ( pHeader && (strcmp(pHeader->_sField, pszHeader)==0 ) )
//            {
//                if (pHeader->_sValue)
//                    free(pHeader->_sValue);
//                len = strlen(pszValue);
//                pHeader->_sValue = (char*)malloc(sizeof(char)*(len+1));
//                strcpy(pHeader->_sValue, pszValue);
//                pHeader->_sValue[len] = '\0';
//                return true;
//            }
//        }
//    }
//    pHeader = (HttpHeader*)malloc(sizeof(HttpHeader));
//    if ( pHeader )
//    {
//        len = strlen(pszHeader);
//        pHeader->_sField = (char*)malloc(sizeof(char)*(len+1));
//        strcpy(pHeader->_sField, pszHeader);
//        pHeader->_sField[len]='\0';
//        len = strlen(pszValue);
//        pHeader->_sValue = (char*)malloc(sizeof(char)*(len+1));
//        strcpy(pHeader->_sValue, pszValue);
//        pHeader->_sValue[len]='\0';
//        if ( !pHeaders )
//            *pVector = CreateVector();
//        AppendElement(*pVector, pHeader);
//        return true;
//    }
//    return false;
//}
//
//bool RemoveHeaderFromVector(CVector* pVector, const char* pszHeader)
//{
//    HttpHeader* pHeader =0;
//    int i = 0;
//    if (pVector)
//    {
//        for (i = 0; i < pVector->m_iSize; i++)
//        {
//            pHeader = GetElement(pVector, i);
//            if ( pHeader && (strcmp(pHeader->_sField, pszHeader)==0 ) )
//            {
//                free(pHeader->_sField);
//                free(pHeader->_sValue);
//                RemoveElement(pVector, pHeader);
//                free(pHeader);
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//void RemoveHeadersFromVector(CVector* pVector)
//{
//    if ( pVector )
//    {
//        if (pVector->m_iSize > 0)
//        {
//            HttpHeader* pHeader = (HttpHeader*)RemoveTailerElement(pVector);
//            while(pHeader)
//            {
//                free(pHeader->_sField);
//                free(pHeader->_sValue);
//                free(pHeader);
//                pHeader = (HttpHeader*)RemoveTailerElement(pVector);
//            }
//        }
//    }
//}
