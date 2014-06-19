#include "xc_api_testclass.h"
#include <stdio.h> 
#include "../../jni_include/sys_xfile.h"
#include "../../jni_include/sys_xmemory.h"
#include "../../jni_include/jni_system.h"
#include "../../include/xinteger.h"
#include "../../../xfile.h"
#include "../../../xfont.h"
#include "../../../xtimer.h"
#include "../../../xtapi.h"
#include "../../../xdebug.h"
#include <time.h>
#include "../../jni_include/sys_xtapi.h"
#include "../../jni_include/sys_xhttp.h"
#include "../../jni_include/sys_xdebug.h"



//本文件仅用于开发中测试，后期会删除，不用审核。


JNIEXPORT jint JNICALL Java_xc_api_testclass_filetest
  (JNIEnv * env, jclass cls)
{


	mylog("assert",1);

	xdebug_assert(1);

	mylog("assert",0);

	xdebug_assert(0);

	//xfile_t *FileTest = (xfile_t *)xfile_open("fs0:/123.txt",1);
//	char * p = "12345678";
//
//	int a = xfile_write(FileTest, p, 10);
//
//	xfile_close(FileTest);
//
//	sys_fclose(FileTest);
//
//	SYS_File *FileTest2 = sys_fopen("fs0:/123.txt",SYS_OFM_READWRITE);
//	void *q = malloc(5);
//	memset(q,0,5);
//	sys_fseek(FileTest2, SYS_FST_START, 1);
//	int c = sys_fread(FileTest2,q,4);
//	mylog(q);

//	sys_fmkdir("contra");
//	sys_fmkdir("contra/contra");
//
//	mylog("xxxxxxxxxxxxxx1");
//
//	SYS_FileEnum * test = sys_fenumstart("contra", 1);
//	mylog("xxxxxxxxxxxxxx2");
//	const char *p = sys_fenumnext(test);
//	mylog("xxxxxxxxxxxxxx3");
//	mylog(p);

//	jstring fileName = 0;
//	if(q){
//		fileName = (*env)->NewStringUTF(env, q);
//	}
//
//	sys_fremove("123.txt");
//
//	sys_fclose(FileTest2);
	//sys_fmkdir("fs0:/abc");
//	sys_frename("fs0:/456.txt","4516.txt");
	//sys_fremove("fs0:/4516.txt");
	//int b = sys_fexist("fs0:/abc");
	//mylog("xxxxxxxxxxxx!!!!!!!!!!!!!");
	//sys_fseek(FileTest, SYS_FST_START, 2);
//	mylog("xxxxxxxxxxxx!!!!!!!!!!!!!");
//	int a = 1;
//	sys_dbgprintf("%s-%s-%s","9","8","7");
//	sys_assert(1);
//	mylog("1");
//	sys_assert(0);
//	mylog("0");
//
//	char * test1 = "1234577";
//
//	char * test2 = "12345678";

//			time_t t;
//
//			struct tm * p;
//
//			t = time(NULL);
//			p = gmtime(&t);
//
//xtapi_getdeviceinfo
//	int a = p->tm_year;
//
//	double aa = clock();
	//mylog("start drawtext");

	//xfont_t * p = (xfont_t *)sys_xftcreate();

	//int test = xtime_mkTime(0);

//	unsigned short * jstringTowchar(JNIEnv *, jstring jstr);
//	void sys_xftdrawtext(xfont_t * pft, short int x, short int y, const unsigned short int * pwszText, unsigned char r, unsigned char g, unsigned char b){
	//gettimeofday

	//mylog("start drawtext create ok");

	///mylog("1111111");





//	   xint16_t year;   ///< 年
//	    xint8_t month;   ///< 月
//	    xint8_t day;     ///< 日
//	    xint8_t hour;    ///< 时
//	    xint8_t minute;  ///< 分
//	    xint8_t second;  ///< 秒
	//sys_srand(sys_xclock());
	//int sys_rand();
//mylog("xxxxxxxxx",1);
//SYS_Http *test = sys_httpcreate();
//mylog("xxxxxxxxx",2);
//
//int a = sys_httpisRunning(test);
//
//mylog("running1",a);
//
//sys_httpcancel(test);
//
//a = sys_httpisRunning(test);

mylog("running2",0);


//xtapi_t *test =  xtapi_create();
//
//
//
//	mylog("bbbbbbbbbbbb");
//
//    const xwifi_info_t * wifi = xtapi_getConnWifiInfo(test);
//
//    mylog("ccccccccccccccc");
//    mylog(wifi->name);
//    mylog("dddddddddddddddddddd");


	return 0;//sys_xmemcmp(test1,test2,strlen(test1));

}



