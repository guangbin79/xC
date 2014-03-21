#include "../../http.h"
#include "../../debug.h"
#include "../../pointer.h"
#include "../../memory.h"
#include "../../boolean.h"
#include "./netManager/http_def.h"
#include "./netManager/comm_netManager.h"
#include "../../../universal/string.h"
#include "../../BasePlugin.h"

Http * tr_httpcreate()
{
    //return (Http*)sys_httpcreate();
    Http* pHttp = (Http*)malloc(sizeof(Http));
    if (pHttp)
    {
        memset(pHttp, 0, sizeof(Http));
    }
    return pHttp;
}

void tr_httpdestroy(Http * pHttp)
{
    assert(pHttp != NULL);
    //sys_httpdestroy((SYS_Http*)pHttp);
    if ( pHttp )
    {
        netManager_cancel(pHttp);
        if ( pHttp->_pHeaders )
        {
            RemoveHeadersFromVector(pHttp->_pHeaders);
            DestroyVector(pHttp->_pHeaders);
        }
        if( pHttp->_sUrl )
            free(pHttp->_sUrl);
        if( pHttp->_sContent_Type )
            free(pHttp->_sContent_Type);
        if( pHttp->_pBody )
            free(pHttp->_pBody);
        if (pHttp->_pNetPlugin_HttpCommHeaders)
            (*pHttp->_pNetPlugin_HttpCommHeaders->_Release)(pHttp->_pNetPlugin_HttpCommHeaders);
        if (pHttp->_pNetPlugin_ErrorTry)
            (*pHttp->_pNetPlugin_ErrorTry->_Release)(pHttp->_pNetPlugin_ErrorTry);
        if (pHttp->_pNetPlugin_PmAnalysis)
            (*pHttp->_pNetPlugin_PmAnalysis->_Release)(pHttp->_pNetPlugin_PmAnalysis);
        if (pHttp->_sModuleType)
            free(pHttp->_sModuleType);
        if (pHttp->_sServiceType)
            free(pHttp->_sServiceType);
        free(pHttp);
    }
}

void tr_httpregisternotify(Http * pHttp, PFNHTTPEVENT pfnNotify, void * pvUser)
{
    assert(pHttp != NULL && pfnNotify != NULL);
    pHttp->_pFun = pfnNotify;
    pHttp->_pUser = pvUser;
}

bool tr_httpaddheader(Http * pHttp, const char * pszHeader, const char * pszValue)
{
    assert(pHttp != NULL && pszHeader != NULL && pszValue != NULL);
    if (strcmp(pszHeader, "Range") == 0)
        pHttp->_bHaveRanged = true;
    return AddHeaderToVector(&pHttp->_pHeaders, pszHeader, pszValue);
}

void tr_httpremoveheader(Http * pHttp, const char * pszHeader)
{
    assert(pHttp != NULL && pszHeader != NULL);
    if (strcmp(pszHeader, "Range") == 0)
        pHttp->_bHaveRanged = false;
    RemoveHeaderFromVector(pHttp->_pHeaders, pszHeader);
}

bool tr_httpget(Http * pHttp, const char * pszUrl)
{
    assert(pHttp != NULL && pszUrl != NULL);
    const char* _sHttpFlag = "http://";
    if (pszUrl == 0 || strstr(pszUrl, _sHttpFlag) != pszUrl )
    {//如果是非正常http地址，则直接返回失败
        dbgprintf("tr_httpget------------>url = NULL");
        return false;
    }
    if ( pHttp )
    {
        if (pHttp->_sContent_Type)
        {
            free(pHttp->_sContent_Type);
            pHttp->_sContent_Type = NULL;
        }
        if ( pHttp->_pBody )
        {
            free(pHttp->_pBody);
            pHttp->_pBody = NULL;
            pHttp->_iDatalen = 0;
        }
        if (pHttp->_sUrl)
            free(pHttp->_sUrl);
        pHttp->_sUrl = (char*)malloc(sizeof(char)*(strlen(pszUrl)+1));
        strcpy(pHttp->_sUrl, pszUrl);
        netManager_request(pHttp);
        return 1;
    }
    return 0;
}

bool tr_httppost(Http * pHttp, const char * pContentType, const char * pszUrl, const void * pvData, uint32_t dwSize)
{
    assert(pHttp != NULL && pContentType != NULL && pszUrl != NULL && pvData != NULL );
    const char* _sHttpFlag = "http://";
    if (pszUrl == 0 || strstr(pszUrl, _sHttpFlag) != pszUrl )
    {//如果是非正常http地址，则直接返回失败
        dbgprintf("tr_httppost------------>url = NULL");
        return false;
    }
    if ( pHttp )
    {
        if (pHttp->_sUrl)
            free(pHttp->_sUrl);
        pHttp->_sUrl = (char*)malloc(sizeof(char)*(strlen(pszUrl)+1));
        strcpy(pHttp->_sUrl, pszUrl);
        if (pHttp->_sContent_Type)
            free(pHttp->_sContent_Type);
        pHttp->_sContent_Type = (char*)malloc(sizeof(char)*(strlen(pContentType)+1));
        strcpy(pHttp->_sContent_Type, pContentType);
        if ( pHttp->_pBody )
            free(pHttp->_pBody);
        pHttp->_pBody = (uint8_t*)malloc(dwSize+1);
        memset(pHttp->_pBody, 0, dwSize+1);
        memcpy(pHttp->_pBody, pvData, dwSize);
        pHttp->_iDatalen = dwSize;
        netManager_request(pHttp);
        return true;
    }
    return false;
}

void tr_httpcancel(Http * pHttp)
{
    assert(pHttp != NULL);
    if( pHttp )
    {
        pHttp->_bHaveRanged = false;
        netManager_cancel(pHttp);
        RemoveHeadersFromVector(pHttp->_pHeaders);
    }
}

void tr_httpsettimeout(Http * pHttp, uint32_t dwMSecs1, uint32_t dwMSecs2)
{
    assert(pHttp != NULL);
    if(pHttp)
    {
        pHttp->_iConnectingTime = dwMSecs1;
        pHttp->_iPieceDataRecvedTime = dwMSecs2;
    }
}

void tr_httpaddplugin(Http * pHttp, void* plugin)
{
    assert(pHttp != NULL && plugin != NULL);
    BasePlugin* _newplugin = (BasePlugin*)plugin;
    BasePlugin* _plugin = 0;
    if (_newplugin->_type == ENetPlugin_HttpCommHeaders)
    {
        _plugin = pHttp->_pNetPlugin_HttpCommHeaders;
        pHttp->_pNetPlugin_HttpCommHeaders = _newplugin;
    }
    else if (_newplugin->_type == ENetPlugin_ErrorTry)
    {
        _plugin = pHttp->_pNetPlugin_ErrorTry;
        pHttp->_pNetPlugin_ErrorTry = _newplugin;
    }
    else if (_newplugin->_type == ENetPlugin_PmAnalysis)
    {
        _plugin = pHttp->_pNetPlugin_PmAnalysis;
        pHttp->_pNetPlugin_PmAnalysis = _newplugin;
    }
    if (_plugin)
    {
        (*_plugin->_Release)(_plugin);
    }
}

void tr_httpsetservicetype(Http * pHttp, const char* moduletype, const char* servicetype)
{
    int len = 0;
    assert(pHttp != NULL && moduletype != NULL && servicetype != NULL);
    if ( pHttp->_sModuleType )
    {
        free(pHttp->_sModuleType);
    }
    len = strlen(moduletype);
    pHttp->_sModuleType = (char*)malloc(sizeof(char)*(len+1));
    strcpy(pHttp->_sModuleType, moduletype);
    pHttp->_sModuleType[len] = '\0';
    if ( pHttp->_sServiceType )
    {
        free(pHttp->_sServiceType);
    }
    len = strlen(servicetype);
    pHttp->_sServiceType = (char*)malloc(sizeof(char)*(len+1));
    strcpy(pHttp->_sServiceType, servicetype);
    pHttp->_sServiceType[len] = '\0';
}

bool AddHeaderToVector(CVector** pVector, const char* pszHeader, const char* pszValue)
{
    HttpHeader* pHeader = 0;
    CVector* pHeaders = 0;
    int len = 0;
    assert(pVector != NULL && pszHeader != NULL && pszValue != NULL);
    pHeaders = *pVector;
    if (pHeaders)
    {
        int i = 0;
        for (i = 0; i < pHeaders->m_iSize; i++)
        {
            pHeader = GetElement(pHeaders, i);
            if ( pHeader && (strcmp(pHeader->_sField, pszHeader)==0 ) )
            {
                if (pHeader->_sValue)
                    free(pHeader->_sValue);
                len = strlen(pszValue);
                pHeader->_sValue = (char*)malloc(sizeof(char)*(len+1));
                strcpy(pHeader->_sValue, pszValue);
                pHeader->_sValue[len] = '\0';
                return true;
            }
        }
    }
    pHeader = (HttpHeader*)malloc(sizeof(HttpHeader));
    if ( pHeader )
    {
        len = strlen(pszHeader);
        pHeader->_sField = (char*)malloc(sizeof(char)*(len+1));
        strcpy(pHeader->_sField, pszHeader);
        pHeader->_sField[len]='\0';
        len = strlen(pszValue);
        pHeader->_sValue = (char*)malloc(sizeof(char)*(len+1));
        strcpy(pHeader->_sValue, pszValue);
        pHeader->_sValue[len]='\0';
        if ( !pHeaders )
            *pVector = CreateVector();
        AppendElement(*pVector, pHeader);
        return true;
    }
    return false;
}

bool RemoveHeaderFromVector(CVector* pVector, const char* pszHeader)
{
    HttpHeader* pHeader =0;
    int i = 0;
    if (pVector)
    {
        for (i = 0; i < pVector->m_iSize; i++)
        {
            pHeader = GetElement(pVector, i);
            if ( pHeader && (strcmp(pHeader->_sField, pszHeader)==0 ) )
            {
                free(pHeader->_sField);
                free(pHeader->_sValue);
                RemoveElement(pVector, pHeader);
                free(pHeader);
                return true;
            }
        }
    }
    return false;
}

void RemoveHeadersFromVector(CVector* pVector)
{
    if ( pVector )
    {
        if (pVector->m_iSize > 0)
        {
            HttpHeader* pHeader = (HttpHeader*)RemoveTailerElement(pVector);
            while(pHeader)
            {
                free(pHeader->_sField);
                free(pHeader->_sValue);
                free(pHeader);
                pHeader = (HttpHeader*)RemoveTailerElement(pVector);
            }
        }
    }
}
