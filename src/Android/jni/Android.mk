#ubuntu系统下tiros-module库makefile文件

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := xC

LOCAL_CFLAGS =-D__LITTLE_ENDIAN -D_UNSUPPORT_STDARG -DTIROS_ANDROID_PLATFORM

MY_SRC_DIRS := $(LOCAL_PATH)

$(call __ndk_info, Start traversal source files!)
MY_SRC_C := $(foreach dir, $(MY_SRC_DIRS),\
  						$(shell find $(dir) -name *.c)\
						)
						
MY_SRC_CPP := $(foreach dir, $(MY_SRC_DIRS),\
  						$(shell find $(dir) -name *.cpp)\
						)
						
$(call __ndk_info, Traversal source files over!)

MY_SRCS := $(MY_SRC_C) $(MY_SRC_CPP)

$(call __ndk_info, Start replace $(LOCAL_PATH)/!)
LOCAL_SRC_FILES := $(foreach src, $(MY_SRCS),\
  	$(subst $(LOCAL_PATH)/,,$(src)) \
)
$(call __ndk_info, Replace $(LOCAL_PATH)/ over!)

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog -lz -lGLESv2 -ljnigraphics

#include $(BUILD_SHARED_LIBRARY)
include $(BUILD_STATIC_LIBRARY)
