

//此为测试代码。不用审核

#include "xc_api_testclass.h"
#include <stdio.h> 


//#include "../../lib/api/system/debug.h"
JavaVM * jvm;
JNIEXPORT void JNICALL Java_xc_api_testclass_printnativelog
  (JNIEnv * jniEnv1, jclass cls)
 {
	JNIEnv * jniEnv;

	(*jvm)->AttachCurrentThread(jvm, &jniEnv, 0);
	jclass TestCls = (*jniEnv)->FindClass(jniEnv,"xc/api/Xfile");
	if(TestCls!=NULL)
	{
	jmethodID TestID = (*jniEnv)->GetStaticMethodID(jniEnv, TestCls, "printjavalog","()V");


	if(TestID != NULL)
	{
	(*jniEnv)->CallStaticVoidMethod(jniEnv, TestCls, TestID);
	}
	}
 }




