#include "./jni_include/jni_system.h"

unsigned short * jstringTowchar(JNIEnv *env, jstring jstr)
{ 
      if(jstr){

      	 jint lenth = (*env)->GetStringLength(env, jstr);

      	 unsigned short * wstr = (unsigned short *)malloc(sizeof(unsigned short) * lenth + 1);

         const jchar * jwstr = (*env)-> GetStringChars(env, jstr, 0);

         jni_wcsncpy(wstr, jwstr, lenth);

         wstr[lenth]=L'\0';

         (*env)->ReleaseStringChars(env, jstr, jwstr);

         return wstr;
      }else{
         return 0;
     }

} 

