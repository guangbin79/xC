#ifndef _SYS_FILEDEF_H_
#define _SYS_FILEDEF_H_

#include <QFile>
#include <QDir>
#include <QFileInfoList>

typedef struct _xsys_file_t
{
    QFile qfile;
} xsys_file_t;

typedef struct _xsys_file_enum_t
{
    QDir qdir;
    QFileInfoList qFileInfoList;
    unsigned int pos;
    unsigned int count;
    bool isdir;
} xsys_file_enum_t;

#ifdef __cplusplus
extern "C" {
#endif

QString sys_fpathchange(const char * pszFilename);

#ifdef __cplusplus
}
#endif


#endif /* _SYS_FILEDEF_H_ */
