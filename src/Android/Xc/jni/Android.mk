
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
               
LOCAL_MODULE    := NDK

LOCAL_CFLAGS =-D__LITTLE_ENDIAN
#LOCAL_CFLAGS =-D__LITTLE_ENDIAN -fshort-wchar 

MY_SRC_ROOT := $(LOCAL_PATH)/./

MY_SRC_DIRS := $(MY_SRC_ROOT)



$(call __ndk_info, Start traversal source files!)
MY_SRC_C := $(foreach dir, $(MY_SRC_DIRS),\
  						$(shell find $(dir) -name *.cpp)\
						)
										
$(call __ndk_info, Traversal source files over!)

MY_SRCS := $(MY_SRC_C)

$(call __ndk_info, Start replace $(LOCAL_PATH)/!)
LOCAL_SRC_FILES := $(foreach src, $(MY_SRCS),\
  	$(subst $(LOCAL_PATH)/,,$(src)) \
)
$(call __ndk_info, Replace $(LOCAL_PATH)/ over!)

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog

include $(BUILD_STATIC_LIBRARY)
