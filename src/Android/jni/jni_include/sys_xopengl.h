//
//#include "../../../xopengl.h"
//#include <GLES2/gl2.h>
//#include <GLES2/gl2ext.h>
//
//#ifndef _XOPENGL_H_
//#define _XOPENGL_H_
//
///*-------------------------------------------------------------------------
// * Data type definitions
// *-----------------------------------------------------------------------*/
//
//typedef void            XGLvoid;
//typedef char            XGLchar;
//typedef unsigned int    XGLenum;
//typedef unsigned char   XGLboolean;
//typedef unsigned int    XGLbitfield;
//typedef signed char     XGLbyte;
//typedef short           XGLshort;
//typedef int             XGLint;
//typedef int             XGLsizei;
//typedef unsigned char   XGLubyte;
//typedef unsigned short  XGLushort;
//typedef unsigned int    XGLuint;
//typedef float           XGLfloat;
//typedef float           XGLclampf;
//typedef int             XGLfixed;
//typedef int             XGLclampx;
//typedef long            XGLintptr;
//typedef long            XGLsizeiptr;
//
///*-------------------------------------------------------------------------
// * Token definitions
// *-----------------------------------------------------------------------*/
//
///* OpenGL ES core versions */
//#define XGL_ES_VERSION_2_0                                1
//
///* ClearBufferMask */
//#define XGL_DEPTH_BUFFER_BIT                              0x00000100
//#define XGL_STENCIL_BUFFER_BIT                            0x00000400
//#define XGL_COLOR_BUFFER_BIT                              0x00004000
//
///* Boolean */
//#define XGL_FALSE                                         0
//#define XGL_TRUE                                          1
//
///* BeginMode */
//#define XGL_POINTS                                        0x0000
//#define XGL_LINES                                         0x0001
//#define XGL_LINE_LOOP                                     0x0002
//#define XGL_LINE_STRIP                                    0x0003
//#define XGL_TRIANGLES                                     0x0004
//#define XGL_TRIANGLE_STRIP                                0x0005
//#define XGL_TRIANGLE_FAN                                  0x0006
//
///* BlendingFactorDest */
//#define XGL_ZERO                                          0
//#define XGL_ONE                                           1
//#define XGL_SRC_COLOR                                     0x0300
//#define XGL_ONE_MINUS_SRC_COLOR                           0x0301
//#define XGL_SRC_ALPHA                                     0x0302
//#define XGL_ONE_MINUS_SRC_ALPHA                           0x0303
//#define XGL_DST_ALPHA                                     0x0304
//#define XGL_ONE_MINUS_DST_ALPHA                           0x0305
//
///* BlendingFactorSrc */
///*      XGL_ZERO */
///*      XGL_ONE */
//#define XGL_DST_COLOR                                     0x0306
//#define XGL_ONE_MINUS_DST_COLOR                           0x0307
//#define XGL_SRC_ALPHA_SATURATE                            0x0308
//
///* Buffer Objects */
//#define XGL_ARRAY_BUFFER                                  0x8892
//#define XGL_ELEMENT_ARRAY_BUFFER                          0x8893
//#define XGL_ARRAY_BUFFER_BINDING                          0x8894
//#define XGL_ELEMENT_ARRAY_BUFFER_BINDING                  0x8895
//
//#define XGL_STREAM_DRAW                                   0x88E0
//#define XGL_STATIC_DRAW                                   0x88E4
//#define XGL_DYNAMIC_DRAW                                  0x88E8
//
///* DepthFunction */
///*      XGL_NEVER */
///*      XGL_LESS */
///*      XGL_EQUAL */
///*      XGL_LEQUAL */
///*      XGL_GREATER */
///*      XGL_NOTEQUAL */
///*      XGL_GEQUAL */
///*      XGL_ALWAYS */
//
///* EnableCap */
//#define XGL_TEXTURE_2D                                    0x0DE1
//#define XGL_CULL_FACE                                     0x0B44
//#define XGL_BLEND                                         0x0BE2
//#define XGL_DITHER                                        0x0BD0
//#define XGL_STENCIL_TEST                                  0x0B90
//#define XGL_DEPTH_TEST                                    0x0B71
//
///* ErrorCode */
//#define XGL_NO_ERROR                                      0
//#define XGL_INVALID_ENUM                                  0x0500
//#define XGL_INVALID_VALUE                                 0x0501
//#define XGL_INVALID_OPERATION                             0x0502
//#define XGL_OUT_OF_MEMORY                                 0x0505
//
///* FrontFaceDirection */
//#define XGL_CW                                            0x0900
//#define XGL_CCW                                           0x0901
//
///* DataType */
//#define XGL_BYTE                                          0x1400
//#define XGL_UNSIGNED_BYTE                                 0x1401
//#define XGL_SHORT                                         0x1402
//#define XGL_UNSIGNED_SHORT                                0x1403
//#define XGL_INT                                           0x1404
//#define XGL_UNSIGNED_INT                                  0x1405
//#define XGL_FLOAT                                         0x1406
//#define XGL_FIXED                                         0x140C
//
///* PixelFormat */
//#define XGL_DEPTH_COMPONENT                               0x1902
//#define XGL_ALPHA                                         0x1906
//#define XGL_RGB                                           0x1907
//#define XGL_RGBA                                          0x1908
//#define XGL_LUMINANCE                                     0x1909
//#define XGL_LUMINANCE_ALPHA                               0x190A
//
//#if GL_APPLE_texture_format_BGRA8888 || GL_IMG_read_format
//#define GL_BGRA                                                 0x80E1
//#endif
//
///* PixelType */
///*      XGL_UNSIGNED_BYTE */
//#define XGL_UNSIGNED_SHORT_4_4_4_4                        0x8033
//#define XGL_UNSIGNED_SHORT_5_5_5_1                        0x8034
//#define XGL_UNSIGNED_SHORT_5_6_5                          0x8363
//
///* Shaders */
//#define XGL_FRAGMENT_SHADER                               0x8B30
//#define XGL_VERTEX_SHADER                                 0x8B31
//
//#define XGL_CURRENT_PROGRAM                               0x8B8D
//
///* StencilFunction */
//#define XGL_NEVER                                         0x0200
//#define XGL_LESS                                          0x0201
//#define XGL_EQUAL                                         0x0202
//#define XGL_LEQUAL                                        0x0203
//#define XGL_GREATER                                       0x0204
//
///* TextureMagFilter */
//#define XGL_NEAREST                                       0x2600
//#define XGL_LINEAR                                        0x2601
//
///* TextureMinFilter */
///*      XGL_NEAREST */
///*      XGL_LINEAR */
//#define XGL_NEAREST_MIPMAP_NEAREST                        0x2700
//#define XGL_LINEAR_MIPMAP_NEAREST                         0x2701
//#define XGL_NEAREST_MIPMAP_LINEAR                         0x2702
//#define XGL_LINEAR_MIPMAP_LINEAR                          0x2703
//
///* TextureParameterName */
//#define XGL_TEXTURE_MAG_FILTER                            0x2800
//#define XGL_TEXTURE_MIN_FILTER                            0x2801
//#define XGL_TEXTURE_WRAP_S                                0x2802
//#define XGL_TEXTURE_WRAP_T                                0x2803
//
///* TextureTarget */
///*      XGL_TEXTURE_2D */
//#define XGL_TEXTURE                                       0x1702
//
///* TextureUnit */
//#define XGL_TEXTURE0                                      0x84C0
//#define XGL_TEXTURE1                                      0x84C1
//#define XGL_TEXTURE2                                      0x84C2
//#define XGL_TEXTURE3                                      0x84C3
//
///* TextureWrapMode */
//#define XGL_REPEAT                                        0x2901
//#define XGL_CLAMP_TO_EDGE                                 0x812F
//
///* Framebuffer Object. */
//#define XGL_FRAMEBUFFER                                   0x8D40
//#define XGL_RENDERBUFFER                                  0x8D41
//
//#define XGL_RGBA4                                         0x8056
//#define XGL_RGB5_A1                                       0x8057
//#define XGL_RGB565                                        0x8D62
//#define XGL_DEPTH_COMPONENT16                             0x81A5
//
//#define XGL_COLOR_ATTACHMENT0                             0x8CE0
//#define XGL_DEPTH_ATTACHMENT                              0x8D00
//#define XGL_STENCIL_ATTACHMENT                            0x8D20
//
//#define XGL_INVALID_FRAMEBUFFER_OPERATION                 0x0506
//
//#define XGL_MAX_RENDERBUFFER_SIZE                         0x84E8
//#define XGL_MAX_TEXTURE_SIZE                              0x0D33
//#define XGL_MAX_VIEWPORT_DIMS                             0x0D3A
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//void sys_opengl_genBuffers(XGLsizei n, XGLuint * buffers);
//
//#ifdef __cplusplus
//}
//#endif
//
//#endif /* _XFONT_H_ */
//
