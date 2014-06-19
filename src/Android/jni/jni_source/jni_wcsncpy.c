/*
 * jni_wcsncpy.c
 *
 *  Created on: 2011-10-20
 *      Author: shizy
 */
#include "../jni_include/jni_system.h"

unsigned short * jni_wcsncpy(unsigned short * dst0, const unsigned short * src0, unsigned int count){

	unsigned short * dscan = dst0;

	const unsigned short * sscan = src0;

	while (count > 0)
	{
		--count;
		if ((*dscan++ = *sscan++) == '\0'){
			break;
		}
	}

	while (count-- > 0){
		*dscan++ = '\0';
	}
	return dst0;
}
