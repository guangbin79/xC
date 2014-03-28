#include "../include/sys_xfiledef.h"
#include <QString>
#include <QDir>
#include <QDesktopServices>
#include <QCoreApplication>

static const char * TIROS_FS0 = "fs0:/";
static const char * TIROS_FS1 = "fs1:/";
static const char * TIROS_FS2 = "fs2:/";
static const char * TIROS_FS3_P = "fs3:/picture/";
static const char * TIROS_FS3_A = "fs3:/audio/";
static const char * TIROS_FS3_V = "fs3:/video/";
static const char * TIROS_FS4 = "fs4:/";
static const char * TIROS_FS0_APP = "tiros-com-cn-app";
static const char * TIROS_FS1_EXT = "tiros-com-cn-ext";
static const char * TIROS_FS2_CACHE = "tiros-com-cn-cache";
static const char * TIROS_FS4_CLOUD = "Cloud";
//static const char * TIROS_FS3_PICTURE = "/home/administrator/Pictures";
//static const char * TIROS_FS3_AUDIO = "/home/administrator/Music";
//static const char * TIROS_FS3_VIDEO = "/home/administrator/Videos";

QString sys_fpathchange(const char * pszFilename)
{
    QString path(pszFilename);
    int index;

   if ((index = path.indexOf(TIROS_FS0)) == 0)
    {
        path.replace(0, strlen(TIROS_FS0), QString(TIROS_FS0_APP) + "/");
    }
    else if ((index = path.indexOf(TIROS_FS1)) == 0)
    {
        path.replace(0, strlen(TIROS_FS1), QString(TIROS_FS1_EXT) + "/");
    }
    else if ((index = path.indexOf(TIROS_FS2)) == 0)
    {
        path.replace(0, strlen(TIROS_FS2), QString(TIROS_FS2_CACHE) + "/");
    }
    else if ((index = path.indexOf(TIROS_FS3_P)) == 0)
    {
        //QString sPath = QDesktopServices::storageLocation(QDesktopServices::PicturesLocation)+ "/";
        QString sPath = QDir::homePath()+ QLatin1String("/Pictures/");
        //path.replace(0, strlen(TIROS_FS3_P), QString(TIROS_FS3_PICTURE) + "/");
        path.replace(0, strlen(TIROS_FS3_P), sPath);
    }
    else if ((index = path.indexOf(TIROS_FS3_A)) == 0)
    {
        //path.replace(0, strlen(TIROS_FS3_A), QString(TIROS_FS3_AUDIO) + "/");
        //QString sPath = QDesktopServices::storageLocation(QDesktopServices::MusicLocation)+ "/";
        QString sPath = QDir::homePath()+ QLatin1String("/Music/");
        path.replace(0, strlen(TIROS_FS3_A), sPath);
    }
    else if ((index = path.indexOf(TIROS_FS3_V)) == 0)
    {
        //path.replace(0, strlen(TIROS_FS3_V), QString(TIROS_FS3_VIDEO) + "/");
        //QString sPath = QDesktopServices::storageLocation(QDesktopServices::MoviesLocation)+ "/";
        QString sPath = QDir::homePath()+ QLatin1String("/Videos/");
        path.replace(0, strlen(TIROS_FS3_V), sPath);
    }
    else if ((index = path.indexOf(TIROS_FS4)) == 0)
    {
       path.replace(0, strlen(TIROS_FS4), QString(TIROS_FS4_CLOUD) + "/");
    }
    else if ((index = path.indexOf("./")) == 0)
    {
       path = QString(TIROS_FS0_APP) + "/" + path.right(path.length()-2);
    }
   else if ((index = path.indexOf("/home/")) == 0)
    {

    }
   else
    {
           path = QString(TIROS_FS0_APP) + "/" + path;
    }

#ifdef Q_OS_MAC
   path = QCoreApplication::applicationDirPath() + "/" + path;
#endif

    return QString(path);
}

