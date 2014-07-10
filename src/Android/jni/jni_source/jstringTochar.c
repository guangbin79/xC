#include "./jni_include/jni_system.h"
#include <string.h>

char * jstringTochar(JNIEnv* env, jstring jstr) {
	if (jstr != NULL) {

		jint lenth = (*env)->GetStringUTFLength(env, jstr);

		const char * jwstr = (*env)-> GetStringUTFChars(env, jstr, 0);

		char * cstr = (char *) malloc(sizeof(char) * lenth + 1);

		strncpy(cstr, jwstr, lenth);

		cstr[lenth] = '\0';

		(*env)->ReleaseStringUTFChars(env, jstr, jwstr);

		return cstr;

	} else {
		return NULL;
	}

}

