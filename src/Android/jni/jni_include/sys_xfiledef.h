#ifndef _SYS_FILEDEF_H_
#define _SYS_FILEDEF_H_



struct _xsys_file_t
{
	jobject fileObject;
};

struct _xsys_file_enum_t
{
	char * cstr;
	jobject fileObject;
};



//QString sys_fpathchange(const char * pszFilename);

#endif /* _SYS_FILEDEF_H_ */
