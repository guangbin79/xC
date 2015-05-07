/**
 * xC
 * @file xgles.h
 * @brief opengles2.0 API
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par android/ios pixel format different.
 * @par 修改记录
 *
 */

#ifndef _XGLES_H_
#define _XGLES_H_

/*-------------------------------------------------------------------------
 * Data type definitions
 *-----------------------------------------------------------------------*/

typedef void            XGLvoid;
typedef char            XGLchar;
typedef unsigned int    XGLenum;
typedef unsigned char   XGLboolean;
typedef unsigned int    XGLbitfield;
typedef signed char     XGLbyte;
typedef short           XGLshort;
typedef int             XGLint;
typedef int             XGLsizei;
typedef unsigned char   XGLubyte;
typedef unsigned short  XGLushort;
typedef unsigned int    XGLuint;
typedef float           XGLfloat;
typedef float           XGLclampf;
typedef int             XGLfixed;
typedef int             XGLclampx;
typedef long            XGLintptr;
typedef long            XGLsizeiptr;

/*-------------------------------------------------------------------------
 * Token definitions
 *-----------------------------------------------------------------------*/

/* OpenGL ES core versions */
#define XGL_ES_VERSION_2_0                                1

/* ClearBufferMask */
#define XGL_DEPTH_BUFFER_BIT                              0x00000100
#define XGL_STENCIL_BUFFER_BIT                            0x00000400
#define XGL_COLOR_BUFFER_BIT                              0x00004000

/* Boolean */
#define XGL_FALSE                                         0
#define XGL_TRUE                                          1

/* BeginMode */
#define XGL_POINTS                                        0x0000
#define XGL_LINES                                         0x0001
#define XGL_LINE_LOOP                                     0x0002
#define XGL_LINE_STRIP                                    0x0003
#define XGL_TRIANGLES                                     0x0004
#define XGL_TRIANGLE_STRIP                                0x0005
#define XGL_TRIANGLE_FAN                                  0x0006

/* BlendingFactorDest */
#define XGL_ZERO                                          0
#define XGL_ONE                                           1
#define XGL_SRC_COLOR                                     0x0300
#define XGL_ONE_MINUS_SRC_COLOR                           0x0301
#define XGL_SRC_ALPHA                                     0x0302
#define XGL_ONE_MINUS_SRC_ALPHA                           0x0303
#define XGL_DST_ALPHA                                     0x0304
#define XGL_ONE_MINUS_DST_ALPHA                           0x0305

/* BlendingFactorSrc */
/*      XGL_ZERO */
/*      XGL_ONE */
#define XGL_DST_COLOR                                     0x0306
#define XGL_ONE_MINUS_DST_COLOR                           0x0307
#define XGL_SRC_ALPHA_SATURATE                            0x0308

/* Buffer Objects */
#define XGL_ARRAY_BUFFER                                  0x8892
#define XGL_ELEMENT_ARRAY_BUFFER                          0x8893
#define XGL_ARRAY_BUFFER_BINDING                          0x8894
#define XGL_ELEMENT_ARRAY_BUFFER_BINDING                  0x8895

#define XGL_STREAM_DRAW                                   0x88E0
#define XGL_STATIC_DRAW                                   0x88E4
#define XGL_DYNAMIC_DRAW                                  0x88E8

/* DepthFunction */
/*      XGL_NEVER */
/*      XGL_LESS */
/*      XGL_EQUAL */
/*      XGL_LEQUAL */
/*      XGL_GREATER */
/*      XGL_NOTEQUAL */
/*      XGL_GEQUAL */
/*      XGL_ALWAYS */

/* EnableCap */
#define XGL_TEXTURE_2D                                    0x0DE1
#define XGL_CULL_FACE                                     0x0B44
#define XGL_BLEND                                         0x0BE2
#define XGL_DITHER                                        0x0BD0
#define XGL_STENCIL_TEST                                  0x0B90
#define XGL_DEPTH_TEST                                    0x0B71

/* ErrorCode */
#define XGL_NO_ERROR                                      0
#define XGL_INVALID_ENUM                                  0x0500
#define XGL_INVALID_VALUE                                 0x0501
#define XGL_INVALID_OPERATION                             0x0502
#define XGL_OUT_OF_MEMORY                                 0x0505

/* FrontFaceDirection */
#define XGL_CW                                            0x0900
#define XGL_CCW                                           0x0901

/* DataType */
#define XGL_BYTE                                          0x1400
#define XGL_UNSIGNED_BYTE                                 0x1401
#define XGL_SHORT                                         0x1402
#define XGL_UNSIGNED_SHORT                                0x1403
#define XGL_INT                                           0x1404
#define XGL_UNSIGNED_INT                                  0x1405
#define XGL_FLOAT                                         0x1406
#define XGL_FIXED                                         0x140C

/* PixelFormat */
#define XGL_DEPTH_COMPONENT                               0x1902
#define XGL_ALPHA                                         0x1906
#define XGL_RGB                                           0x1907
#define XGL_RGBA                                          0x1908
#define XGL_LUMINANCE                                     0x1909
#define XGL_LUMINANCE_ALPHA                               0x190A
#define XGL_BGRA                                          0x80E1

/* PixelType */
/*      XGL_UNSIGNED_BYTE */
#define XGL_UNSIGNED_SHORT_4_4_4_4                        0x8033
#define XGL_UNSIGNED_SHORT_5_5_5_1                        0x8034
#define XGL_UNSIGNED_SHORT_5_6_5                          0x8363

/* Shaders */
#define XGL_FRAGMENT_SHADER                               0x8B30
#define XGL_VERTEX_SHADER                                 0x8B31

#define XGL_CURRENT_PROGRAM                               0x8B8D

/* StencilFunction */
#define XGL_NEVER                                         0x0200
#define XGL_LESS                                          0x0201
#define XGL_EQUAL                                         0x0202
#define XGL_LEQUAL                                        0x0203
#define XGL_GREATER                                       0x0204

/* TextureMagFilter */
#define XGL_NEAREST                                       0x2600
#define XGL_LINEAR                                        0x2601

/* TextureMinFilter */
/*      XGL_NEAREST */
/*      XGL_LINEAR */
#define XGL_NEAREST_MIPMAP_NEAREST                        0x2700
#define XGL_LINEAR_MIPMAP_NEAREST                         0x2701
#define XGL_NEAREST_MIPMAP_LINEAR                         0x2702
#define XGL_LINEAR_MIPMAP_LINEAR                          0x2703

/* TextureParameterName */
#define XGL_TEXTURE_MAG_FILTER                            0x2800
#define XGL_TEXTURE_MIN_FILTER                            0x2801
#define XGL_TEXTURE_WRAP_S                                0x2802
#define XGL_TEXTURE_WRAP_T                                0x2803

/* TextureTarget */
/*      XGL_TEXTURE_2D */
#define XGL_TEXTURE                                       0x1702

/* TextureUnit */
#define XGL_TEXTURE0                                      0x84C0
#define XGL_TEXTURE1                                      0x84C1
#define XGL_TEXTURE2                                      0x84C2
#define XGL_TEXTURE3                                      0x84C3

/* TextureWrapMode */
#define XGL_REPEAT                                        0x2901
#define XGL_CLAMP_TO_EDGE                                 0x812F

/* Framebuffer Object. */
#define XGL_FRAMEBUFFER                                   0x8D40
#define XGL_RENDERBUFFER                                  0x8D41

#define XGL_RGBA4                                         0x8056
#define XGL_RGB5_A1                                       0x8057
#define XGL_RGB565                                        0x8D62
#define XGL_DEPTH_COMPONENT16                             0x81A5

#define XGL_COLOR_ATTACHMENT0                             0x8CE0
#define XGL_DEPTH_ATTACHMENT                              0x8D00
#define XGL_STENCIL_ATTACHMENT                            0x8D20

#define XGL_INVALID_FRAMEBUFFER_OPERATION                 0x0506

#define XGL_MAX_RENDERBUFFER_SIZE                         0x84E8
#define XGL_MAX_TEXTURE_SIZE                              0x0D33
#define XGL_MAX_VIEWPORT_DIMS                             0x0D3A

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------------------------------------------------
 * Entrypoint definitions
 *-----------------------------------------------------------------------*/

void xgles_genBuffers(XGLsizei n, XGLuint * buffers);
void xgles_deleteBuffers(XGLsizei n, const XGLuint * buffers);
void xgles_bindBuffer(XGLenum target, XGLuint buffer);
void xgles_bufferData(XGLenum target, XGLsizeiptr size, const XGLvoid * data, XGLenum usage);
void xgles_bufferSubData(XGLenum target, XGLintptr offset, XGLsizeiptr size, const XGLvoid * data);
XGLuint xgles_createShader(XGLenum type);
void xgles_getShaderSource(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * source);
void xgles_compileShader(XGLuint shader);
void xgles_getShaderiv(XGLuint shader, XGLenum pname, XGLint * params);
void xgles_getShaderInfoLog(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog);
void xgles_deleteShader(XGLuint shader);
XGLuint xgles_createProgram(void);
void xgles_attachShader(XGLuint program, XGLuint shader);
void xgles_deleteProgram(XGLuint program);
void xgles_linkProgram(XGLuint program);
void xgles_useProgram(XGLuint program);
void xgles_getProgramiv(XGLuint program, XGLenum pname, XGLint * params);
void xgles_getProgramInfoLog(XGLuint program, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog);
XGLint xgles_getUniformLocation(XGLuint program, const XGLchar* name);
void xgles_uniform1f(XGLint location, XGLfloat x);
void xgles_uniform2f(XGLint location, XGLfloat x, XGLfloat y);
void xgles_uniform3f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z);
void xgles_uniform4f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z, XGLfloat w);
void xgles_uniformMatrix3fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value);
void xgles_uniformMatrix4fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value);
void xgles_uniform1i(XGLint location, XGLint x);
void xgles_attachShader(XGLuint program, XGLuint shader);
void xgles_getVertexAttribPointerv(XGLuint index, XGLenum pname, XGLvoid ** pointer);
void xgles_enableVertexAttribArray(XGLuint index);
void xgles_disableVertexAttribArray(XGLuint index);
XGLint  xgles_getAttribLocation(XGLuint program, const XGLchar * name);
void xgles_genFramebuffers(XGLsizei n, XGLuint * framebuffers);
void xgles_bindFramebuffer(XGLenum target, XGLuint framebuffer);
void xgles_framebufferTexture2D(XGLenum target, XGLenum attachment, XGLenum textarget, XGLuint texture, XGLint level);
XGLenum xgles_checkFramebufferStatus(XGLenum target);
void xgles_deleteFramebuffers(XGLsizei n, const XGLuint * framebuffers);
void xgles_genRenderbuffers(XGLsizei n, XGLuint * renderbuffers);
void xgles_bindRenderbuffer(XGLenum target, XGLuint renderbuffer);
void xgles_renderbufferStorage(XGLenum target, XGLenum internalformat, XGLsizei width, XGLsizei height);
void xgles_framebufferRenderbuffer(XGLenum target, XGLenum attachment, XGLenum renderbuffertarget, XGLuint renderbuffer);
void xgles_deleteRenderbuffers(XGLsizei n, const XGLuint * renderbuffers);
void xgles_texParameterf(XGLenum target, XGLenum pname, XGLfloat param);
void xgles_texImage2D(XGLenum target, XGLint level, XGLint internalformat, XGLsizei width, XGLsizei height, XGLint border, XGLenum format, XGLenum type, const XGLvoid* pixels);
void xgles_genTextures(XGLsizei n, XGLuint * textures);
void xgles_activeTexture(XGLenum texture);
void xgles_bindTexture(XGLenum target, XGLuint texture);
void xgles_deleteTextures(XGLsizei n, const XGLuint * textures);
XGLenum xgles_getError(void);
void xgles_texSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLsizei width, XGLsizei height, XGLenum format, XGLenum type, const XGLvoid* pixels);
void xgles_getIntegerv(XGLenum pname, XGLint* params);
void xgles_drawArrays(XGLenum mode, XGLint first, XGLsizei count);
void xgles_drawElements(XGLenum mode, XGLsizei count, XGLenum type, const XGLvoid * indices);
void xgles_enable(XGLenum cap);
void xgles_disable(XGLenum cap);
void xgles_finish(void);
void xgles_flush(void);
void xgles_blendFunc(XGLenum sfactor, XGLenum dfactor);
void xgles_depthFunc(XGLenum func);
void xgles_depthMask(XGLboolean flag);
void xgles_copyTexSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLint x, XGLint y, XGLsizei width, XGLsizei height);
void xgles_clear(XGLbitfield mask);
void xgles_clearColor(XGLfloat red, XGLfloat green, XGLfloat blue, XGLfloat alpha);
void xgles_viewport(XGLint x, XGLint y, XGLsizei width, XGLsizei height);

#ifdef __cplusplus
}
#endif

#endif /* _XGLES_H_ */

