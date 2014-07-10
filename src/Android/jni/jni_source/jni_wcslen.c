/*
 * jni_wcslen.c
 *
 *  Created on: 2011-10-20
 *      Author: shizy
 */
#include "./jni_include/jni_system.h"

unsigned int jni_wcslen(const unsigned short * str){

	const unsigned short * start = str;

	while(*str){
		str++;
	}

	return str - start;
}
