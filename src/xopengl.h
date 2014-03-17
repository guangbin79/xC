/**
 * xC
 * @file xopengl.h
 * @brief opengles2.0 API
 * @author tangbo <tangbo@tiros.com.cn>
 * @date 2014/03/17
 * @par android/ios pixel format different.
 * 
 */

#ifndef _XOPENGL2_H_
#define _XOPENGL2_H_

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
/*      XGL_SRC_ALPHA */
/*      XGL_ONE_MINUS_SRC_ALPHA */
/*      XGL_DST_ALPHA */
/*      XGL_ONE_MINUS_DST_ALPHA */

///* BlendEquationSeparate */
//#define XGL_FUNC_ADD                                      0x8006
//#define XGL_BLEND_EQUATION                                0x8009
//#define XGL_BLEND_EQUATION_RGB                            0x8009    /* same as BLEND_EQUATION */
//#define XGL_BLEND_EQUATION_ALPHA                          0x883D

///* BlendSubtract */
//#define XGL_FUNC_SUBTRACT                                 0x800A
//#define XGL_FUNC_REVERSE_SUBTRACT                         0x800B
//
///* Separate Blend Functions */
//#define XGL_BLEND_DST_RGB                                 0x80C8
//#define XGL_BLEND_SRC_RGB                                 0x80C9
//#define XGL_BLEND_DST_ALPHA                               0x80CA
//#define XGL_BLEND_SRC_ALPHA                               0x80CB
//#define XGL_CONSTANT_COLOR                                0x8001
//#define XGL_ONE_MINUS_CONSTANT_COLOR                      0x8002
//#define XGL_CONSTANT_ALPHA                                0x8003
//#define XGL_ONE_MINUS_CONSTANT_ALPHA                      0x8004
//#define XGL_BLEND_COLOR                                   0x8005
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
//#define XGL_BUFFER_SIZE                                   0x8764
//#define XGL_BUFFER_USAGE                                  0x8765
//
//#define XGL_CURRENT_VERTEX_ATTRIB                         0x8626
//
///* CullFaceMode */
//#define XGL_FRONT                                         0x0404
//#define XGL_BACK                                          0x0405
//#define XGL_FRONT_AND_BACK                                0x0408

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
//#define XGL_SCISSOR_TEST                                  0x0C11
//#define XGL_POLYGON_OFFSET_FILL                           0x8037
//#define XGL_SAMPLE_ALPHA_TO_COVERAGE                      0x809E
//#define XGL_SAMPLE_COVERAGE                               0x80A0

/* ErrorCode */
#define XGL_NO_ERROR                                      0
#define XGL_INVALID_ENUM                                  0x0500
#define XGL_INVALID_VALUE                                 0x0501
#define XGL_INVALID_OPERATION                             0x0502
#define XGL_OUT_OF_MEMORY                                 0x0505

/* FrontFaceDirection */
#define XGL_CW                                            0x0900
#define XGL_CCW                                           0x0901

///* GetPName */
//#define XGL_LINE_WIDTH                                    0x0B21
//#define XGL_ALIASED_POINT_SIZE_RANGE                      0x846D
//#define XGL_ALIASED_LINE_WIDTH_RANGE                      0x846E
//#define XGL_CULL_FACE_MODE                                0x0B45
//#define XGL_FRONT_FACE                                    0x0B46
//#define XGL_DEPTH_RANGE                                   0x0B70
//#define XGL_DEPTH_WRITEMASK                               0x0B72
//#define XGL_DEPTH_CLEAR_VALUE                             0x0B73
//#define XGL_DEPTH_FUNC                                    0x0B74
//#define XGL_STENCIL_CLEAR_VALUE                           0x0B91
//#define XGL_STENCIL_FUNC                                  0x0B92
//#define XGL_STENCIL_FAIL                                  0x0B94
//#define XGL_STENCIL_PASS_DEPTH_FAIL                       0x0B95
//#define XGL_STENCIL_PASS_DEPTH_PASS                       0x0B96
//#define XGL_STENCIL_REF                                   0x0B97
//#define XGL_STENCIL_VALUE_MASK                            0x0B93
//#define XGL_STENCIL_WRITEMASK                             0x0B98
//#define XGL_STENCIL_BACK_FUNC                             0x8800
//#define XGL_STENCIL_BACK_FAIL                             0x8801
//#define XGL_STENCIL_BACK_PASS_DEPTH_FAIL                  0x8802
//#define XGL_STENCIL_BACK_PASS_DEPTH_PASS                  0x8803
//#define XGL_STENCIL_BACK_REF                              0x8CA3
//#define XGL_STENCIL_BACK_VALUE_MASK                       0x8CA4
//#define XGL_STENCIL_BACK_WRITEMASK                        0x8CA5
//#define XGL_VIEWPORT                                      0x0BA2
//#define XGL_SCISSOR_BOX                                   0x0C10
///*      XGL_SCISSOR_TEST */
//#define XGL_COLOR_CLEAR_VALUE                             0x0C22
//#define XGL_COLOR_WRITEMASK                               0x0C23
//#define XGL_UNPACK_ALIGNMENT                              0x0CF5
//#define XGL_PACK_ALIGNMENT                                0x0D05
//#define XGL_MAX_TEXTURE_SIZE                              0x0D33
//#define XGL_MAX_VIEWPORT_DIMS                             0x0D3A
//#define XGL_SUBPIXEL_BITS                                 0x0D50
//#define XGL_RED_BITS                                      0x0D52
//#define XGL_GREEN_BITS                                    0x0D53
//#define XGL_BLUE_BITS                                     0x0D54
//#define XGL_ALPHA_BITS                                    0x0D55
//#define XGL_DEPTH_BITS                                    0x0D56
//#define XGL_STENCIL_BITS                                  0x0D57
//#define XGL_POLYGON_OFFSET_UNITS                          0x2A00
///*      XGL_POLYGON_OFFSET_FILL */
//#define XGL_POLYGON_OFFSET_FACTOR                         0x8038
//#define XGL_TEXTURE_BINDING_2D                            0x8069
//#define XGL_SAMPLE_BUFFERS                                0x80A8
//#define XGL_SAMPLES                                       0x80A9
//#define XGL_SAMPLE_COVERAGE_VALUE                         0x80AA
//#define XGL_SAMPLE_COVERAGE_INVERT                        0x80AB
//
///* GetTextureParameter */
///*      XGL_TEXTURE_MAG_FILTER */
///*      XGL_TEXTURE_MIN_FILTER */
///*      XGL_TEXTURE_WRAP_S */
///*      XGL_TEXTURE_WRAP_T */
//
//#define XGL_NUM_COMPRESSED_TEXTURE_FORMATS                0x86A2
//#define XGL_COMPRESSED_TEXTURE_FORMATS                    0x86A3
//
///* HintMode */
//#define XGL_DONT_CARE                                     0x1100
//#define XGL_FASTEST                                       0x1101
//#define XGL_NICEST                                        0x1102
//
///* HintTarget */
//#define XGL_GENERATE_MIPMAP_HINT                          0x8192

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

/* PixelType */
/*      XGL_UNSIGNED_BYTE */
#define XGL_UNSIGNED_SHORT_4_4_4_4                        0x8033
#define XGL_UNSIGNED_SHORT_5_5_5_1                        0x8034
#define XGL_UNSIGNED_SHORT_5_6_5                          0x8363

/* Shaders */
#define XGL_FRAGMENT_SHADER                               0x8B30
#define XGL_VERTEX_SHADER                                 0x8B31
//#define XGL_MAX_VERTEX_ATTRIBS                            0x8869
//#define XGL_MAX_VERTEX_UNIFORM_VECTORS                    0x8DFB
//#define XGL_MAX_VARYING_VECTORS                           0x8DFC
//#define XGL_MAX_COMBINED_TEXTURE_IMAGE_UNITS              0x8B4D
//#define XGL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                0x8B4C
//#define XGL_MAX_TEXTURE_IMAGE_UNITS                       0x8872
//#define XGL_MAX_FRAGMENT_UNIFORM_VECTORS                  0x8DFD
//#define XGL_SHADER_TYPE                                   0x8B4F
//#define XGL_DELETE_STATUS                                 0x8B80
//#define XGL_LINK_STATUS                                   0x8B82
//#define XGL_VALIDATE_STATUS                               0x8B83
//#define XGL_ATTACHED_SHADERS                              0x8B85
//#define XGL_ACTIVE_UNIFORMS                               0x8B86
//#define XGL_ACTIVE_UNIFORM_MAX_LENGTH                     0x8B87
//#define XGL_ACTIVE_ATTRIBUTES                             0x8B89
//#define XGL_ACTIVE_ATTRIBUTE_MAX_LENGTH                   0x8B8A
//#define XGL_SHADING_LANGUAGE_VERSION                      0x8B8C
#define XGL_CURRENT_PROGRAM                               0x8B8D

/* StencilFunction */
#define XGL_NEVER                                         0x0200
#define XGL_LESS                                          0x0201
#define XGL_EQUAL                                         0x0202
#define XGL_LEQUAL                                        0x0203
#define XGL_GREATER                                       0x0204
//#define XGL_NOTEQUAL                                      0x0205
//#define XGL_GEQUAL                                        0x0206
//#define XGL_ALWAYS                                        0x0207

///* StencilOp */
///*      XGL_ZERO */
//#define XGL_KEEP                                          0x1E00
//#define XGL_REPLACE                                       0x1E01
//#define XGL_INCR                                          0x1E02
//#define XGL_DECR                                          0x1E03
//#define XGL_INVERT                                        0x150A
//#define XGL_INCR_WRAP                                     0x8507
//#define XGL_DECR_WRAP                                     0x8508

/* StringName */
#define XGL_VENDOR                                        0x1F00
#define XGL_RENDERER                                      0x1F01
#define XGL_VERSION                                       0x1F02
#define XGL_EXTENSIONS                                    0x1F03

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

//#define XGL_TEXTURE_CUBE_MAP                              0x8513
//#define XGL_TEXTURE_BINDING_CUBE_MAP                      0x8514
//#define XGL_TEXTURE_CUBE_MAP_POSITIVE_X                   0x8515
//#define XGL_TEXTURE_CUBE_MAP_NEGATIVE_X                   0x8516
//#define XGL_TEXTURE_CUBE_MAP_POSITIVE_Y                   0x8517
//#define XGL_TEXTURE_CUBE_MAP_NEGATIVE_Y                   0x8518
//#define XGL_TEXTURE_CUBE_MAP_POSITIVE_Z                   0x8519
//#define XGL_TEXTURE_CUBE_MAP_NEGATIVE_Z                   0x851A
//#define XGL_MAX_CUBE_MAP_TEXTURE_SIZE                     0x851C

/* TextureUnit */
#define XGL_TEXTURE0                                      0x84C0
#define XGL_TEXTURE1                                      0x84C1
#define XGL_TEXTURE2                                      0x84C2
#define XGL_TEXTURE3                                      0x84C3
//#define XGL_TEXTURE4                                      0x84C4
//#define XGL_TEXTURE5                                      0x84C5
//#define XGL_TEXTURE6                                      0x84C6
//#define XGL_TEXTURE7                                      0x84C7
//#define XGL_TEXTURE8                                      0x84C8
//#define XGL_TEXTURE9                                      0x84C9
//#define XGL_TEXTURE10                                     0x84CA
//#define XGL_TEXTURE11                                     0x84CB
//#define XGL_TEXTURE12                                     0x84CC
//#define XGL_TEXTURE13                                     0x84CD
//#define XGL_TEXTURE14                                     0x84CE
//#define XGL_TEXTURE15                                     0x84CF
//#define XGL_TEXTURE16                                     0x84D0
//#define XGL_TEXTURE17                                     0x84D1
//#define XGL_TEXTURE18                                     0x84D2
//#define XGL_TEXTURE19                                     0x84D3
//#define XGL_TEXTURE20                                     0x84D4
//#define XGL_TEXTURE21                                     0x84D5
//#define XGL_TEXTURE22                                     0x84D6
//#define XGL_TEXTURE23                                     0x84D7
//#define XGL_TEXTURE24                                     0x84D8
//#define XGL_TEXTURE25                                     0x84D9
//#define XGL_TEXTURE26                                     0x84DA
//#define XGL_TEXTURE27                                     0x84DB
//#define XGL_TEXTURE28                                     0x84DC
//#define XGL_TEXTURE29                                     0x84DD
//#define XGL_TEXTURE30                                     0x84DE
//#define XGL_TEXTURE31                                     0x84DF
//#define XGL_ACTIVE_TEXTURE                                0x84E0

/* TextureWrapMode */
#define XGL_REPEAT                                        0x2901
#define XGL_CLAMP_TO_EDGE                                 0x812F
//#define XGL_MIRRORED_REPEAT                               0x8370

///* Uniform Types */
//#define XGL_FLOAT_VEC2                                    0x8B50
//#define XGL_FLOAT_VEC3                                    0x8B51
//#define XGL_FLOAT_VEC4                                    0x8B52
//#define XGL_INT_VEC2                                      0x8B53
//#define XGL_INT_VEC3                                      0x8B54
//#define XGL_INT_VEC4                                      0x8B55
//#define XGL_BOOL                                          0x8B56
//#define XGL_BOOL_VEC2                                     0x8B57
//#define XGL_BOOL_VEC3                                     0x8B58
//#define XGL_BOOL_VEC4                                     0x8B59
//#define XGL_FLOAT_MAT2                                    0x8B5A
//#define XGL_FLOAT_MAT3                                    0x8B5B
//#define XGL_FLOAT_MAT4                                    0x8B5C
//#define XGL_SAMPLER_2D                                    0x8B5E
//#define XGL_SAMPLER_CUBE                                  0x8B60
//
///* Vertex Arrays */
//#define XGL_VERTEX_ATTRIB_ARRAY_ENABLED                   0x8622
//#define XGL_VERTEX_ATTRIB_ARRAY_SIZE                      0x8623
//#define XGL_VERTEX_ATTRIB_ARRAY_STRIDE                    0x8624
//#define XGL_VERTEX_ATTRIB_ARRAY_TYPE                      0x8625
//#define XGL_VERTEX_ATTRIB_ARRAY_NORMALIZED                0x886A
//#define XGL_VERTEX_ATTRIB_ARRAY_POINTER                   0x8645
//#define XGL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING            0x889F
//
///* Read Format */
//#define XGL_IMPLEMENTATION_COLOR_READ_TYPE                0x8B9A
//#define XGL_IMPLEMENTATION_COLOR_READ_FORMAT              0x8B9B
//
///* Shader Source */
//#define XGL_COMPILE_STATUS                                0x8B81
//#define XGL_INFO_LOG_LENGTH                               0x8B84
//#define XGL_SHADER_SOURCE_LENGTH                          0x8B88
//#define XGL_SHADER_COMPILER                               0x8DFA
//
///* Shader Binary */
//#define XGL_SHADER_BINARY_FORMATS                         0x8DF8
//#define XGL_NUM_SHADER_BINARY_FORMATS                     0x8DF9
//
///* Shader Precision-Specified Types */
//#define XGL_LOW_FLOAT                                     0x8DF0
//#define XGL_MEDIUM_FLOAT                                  0x8DF1
//#define XGL_HIGH_FLOAT                                    0x8DF2
//#define XGL_LOW_INT                                       0x8DF3
//#define XGL_MEDIUM_INT                                    0x8DF4
//#define XGL_HIGH_INT                                      0x8DF5

/* Framebuffer Object. */
#define XGL_FRAMEBUFFER                                   0x8D40
#define XGL_RENDERBUFFER                                  0x8D41

#define XGL_RGBA4                                         0x8056
#define XGL_RGB5_A1                                       0x8057
#define XGL_RGB565                                        0x8D62
#define XGL_DEPTH_COMPONENT16                             0x81A5
//#define XGL_STENCIL_INDEX8                                0x8D48

//#define XGL_RENDERBUFFER_WIDTH                            0x8D42
//#define XGL_RENDERBUFFER_HEIGHT                           0x8D43
//#define XGL_RENDERBUFFER_INTERNAL_FORMAT                  0x8D44
//#define XGL_RENDERBUFFER_RED_SIZE                         0x8D50
//#define XGL_RENDERBUFFER_GREEN_SIZE                       0x8D51
//#define XGL_RENDERBUFFER_BLUE_SIZE                        0x8D52
//#define XGL_RENDERBUFFER_ALPHA_SIZE                       0x8D53
//#define XGL_RENDERBUFFER_DEPTH_SIZE                       0x8D54
//#define XGL_RENDERBUFFER_STENCIL_SIZE                     0x8D55

//#define XGL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE            0x8CD0
//#define XGL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME            0x8CD1
//#define XGL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL          0x8CD2
//#define XGL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE  0x8CD3

#define XGL_COLOR_ATTACHMENT0                             0x8CE0
#define XGL_DEPTH_ATTACHMENT                              0x8D00
#define XGL_STENCIL_ATTACHMENT                            0x8D20

//#define XGL_NONE                                          0

//#define XGL_FRAMEBUFFER_COMPLETE                          0x8CD5
//#define XGL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT             0x8CD6
//#define XGL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT     0x8CD7
//#define XGL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS             0x8CD9
//#define XGL_FRAMEBUFFER_UNSUPPORTED                       0x8CDD
//
//#define XGL_FRAMEBUFFER_BINDING                           0x8CA6
//#define XGL_RENDERBUFFER_BINDING                          0x8CA7
#define XGL_MAX_RENDERBUFFER_SIZE                         0x84E8

#define XGL_INVALID_FRAMEBUFFER_OPERATION                 0x0506

#ifdef __cplusplus
extern "C" {
#endif
    
/*-------------------------------------------------------------------------
 * Entrypoint definitions
 *-----------------------------------------------------------------------*/

void xopengl_genBuffers (XGLsizei n, XGLuint* buffers);
void xopengl_deleteBuffers (XGLsizei n, const XGLuint* buffers);
void xopengl_bindBuffer (XGLenum target, XGLuint buffer);
void xopengl_bufferData (XGLenum target, XGLsizeiptr size, const XGLvoid* data, XGLenum usage);
void xopengl_bufferSubData (XGLenum target, XGLintptr offset, XGLsizeiptr size, const XGLvoid* data);
XGLuint xopengl_createShader (XGLenum type);
void xopengl_getShaderSource (XGLuint shader, XGLsizei bufsize, XGLsizei* length, XGLchar* source);
void xopengl_compileShader (XGLuint shader);
void xopengl_getShaderiv (XGLuint shader, XGLenum pname, XGLint* params);
void xopengl_getShaderInfoLog (XGLuint shader, XGLsizei bufsize, XGLsizei* length, XGLchar* infolog);
void xopengl_deleteShader (XGLuint shader);
XGLuint xopengl_createProgram (void);
void xopengl_attachShader (XGLuint program, XGLuint shader);
void xopengl_deleteProgram (XGLuint program);
void xopengl_linkProgram (XGLuint program);
void xopengl_useProgram (XGLuint program);
void xopengl_getProgramiv (XGLuint program, XGLenum pname, XGLint* params);
void xopengl_getProgramInfoLog (XGLuint program, XGLsizei bufsize, XGLsizei* length, XGLchar* infolog)
int xopengl_getUniformLocation (XGLuint program, const XGLchar* name);
void xopengl_uniform1f (XGLint location, XGLfloat x);
void xopengl_uniform2f (XGLint location, XGLfloat x, XGLfloat y);
void xopengl_uniform3f (XGLint location, XGLfloat x, XGLfloat y, XGLfloat z);
void xopengl_uniform4f (XGLint location, XGLfloat x, XGLfloat y, XGLfloat z, XGLfloat w);
void xopengl_uniformMatrix3fv (XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat* value);
void xopengl_uniformMatrix4fv (XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat* value);
void xopengl_uniform1i (XGLint location, XGLint x);
void xopengl_attachShader (XGLuint program, XGLuint shader);
void xopengl_getVertexAttribPointerv (XGLuint index, XGLenum pname, XGLvoid** pointer);
void xopengl_enableVertexAttribArray (XGLuint index);
void xopengl_disableVertexAttribArray (XGLuint index);
int  xopengl_getAttribLocation (XGLuint program, const XGLchar* name);
void xopengl_genFramebuffers (XGLsizei n, XGLuint* framebuffers);
void xopengl_bindFramebuffer (XGLenum target, XGLuint framebuffer);
void xopengl_framebufferTexture2D (XGLenum target, XGLenum attachment, XGLenum textarget, XGLuint texture, XGLint level);
XGLenum xopengl_checkFramebufferStatus (XGLenum target);
void xopengl_deleteFramebuffers (XGLsizei n, const XGLuint* framebuffers);
void xopengl_genRenderbuffers (XGLsizei n, XGLuint* renderbuffers);
void xopengl_bindRenderbuffer (XGLenum target, XGLuint renderbuffer);
void xopengl_renderbufferStorage (XGLenum target, XGLenum internalformat, XGLsizei width, XGLsizei height);
void xopengl_framebufferRenderbuffer (XGLenum target, XGLenum attachment, XGLenum renderbuffertarget, XGLuint renderbuffer);
void xopengl_deleteRenderbuffers (XGLsizei n, const XGLuint* renderbuffers);

#ifdef __cplusplus
}
#endif

#endif /* _XOPENGL2_H_ */

