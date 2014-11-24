#include "../include/sys_xfiledef.h"
#include <QString>
#include <QDir>
#include <QDesktopServices>
#include <QCoreApplication>

#define XFS_DEFAULT    ""              //默认私有,随机读写文件系统
#define XFS_ASSET      "asset:/"       //私有资源,随机只读文件系统
#define XFS_COLUD      "colud:/"       //私有云同步,随机读写文件系统
#define XFS_SHARE      "share:/"       //扩展共享,随机读写文件系统

#define XFS_DEFAULT_QT "xcpi_default/"
#define XFS_ASSET_QT   "xcpi_asset/"
#define XFS_COLUD_QT   "xcpi_colud/"
#define XFS_SHARE_QT   "xcpi_share/"

QString sys_fpathchange(const char * pszFilename, bool * bAsset)
{
    QString path(pszFilename);
    int index;

    if (bAsset != NULL) *bAsset = false;

    if ((index = path.indexOf(XFS_ASSET)) == 0)
    {
        if (bAsset != NULL) *bAsset = true;

        path.replace(0, strlen(XFS_ASSET), QString(XFS_ASSET));
    }
    else if ((index = path.indexOf(XFS_COLUD)) == 0)
    {
        path.replace(0, strlen(XFS_COLUD), QString(XFS_COLUD_QT));
    }
    else if ((index = path.indexOf(XFS_SHARE)) == 0)
    {
        path.replace(0, strlen(XFS_SHARE), QString(XFS_SHARE_QT));
    }
    else
    {
           path = QString(XFS_DEFAULT_QT) + path;
    }

#ifdef Q_OS_MAC
   path = QCoreApplication::applicationDirPath() + "/" + path;
#endif

    return QString(path);
}

