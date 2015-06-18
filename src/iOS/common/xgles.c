//
//  xgles.c
//  xC
//
//  Created by map on 15/6/18.
//  Copyright (c) 2015年 map. All rights reserved.
//

#include "../../../xgles.h"
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>


void xgles_genBuffers(XGLsizei n, XGLuint * buffers)
{
    glGenBuffers (n, buffers);
}

void xgles_deleteBuffers(XGLsizei n, const XGLuint * buffers)
{
    glDeleteBuffers(n, buffers);
}

void xgles_bindBuffer(XGLenum target, XGLuint buffer)
{
    glBindBuffer(target, buffer);
}

void xgles_bufferData(XGLenum target, XGLsizeiptr size, const XGLvoid * data, XGLenum usage)
{
    glBufferData(target, size, data, usage);
}

void xgles_bufferSubData(XGLenum target, XGLintptr offset, XGLsizeiptr size, const XGLvoid * data)
{
    glBufferSubData(target, offset, size, data);
}

XGLuint xgles_createShader(XGLenum type)
{
    return glCreateShader(type);
}

void xgles_getShaderSource(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * source)
{
    glGetShaderSource(shader, bufsize, length, source);
}

void xgles_compileShader(XGLuint shader)
{
    glCompileShader(shader);
}

void xgles_getShaderiv(XGLuint shader, XGLenum pname, XGLint * params)
{
    glGetShaderiv(shader, pname, params);
}

void xgles_getShaderInfoLog(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
    glGetShaderInfoLog(shader, bufsize, length, infolog);
}

void xgles_deleteShader(XGLuint shader)
{
    glDeleteShader(shader);
}

XGLuint xgles_createProgram(void)
{
    return glCreateProgram();
}

void xgles_attachShader(XGLuint program, XGLuint shader)
{
    glAttachShader(program, shader);
}

void xgles_deleteProgram(XGLuint program)
{
    glDeleteProgram(program);
}

void xgles_linkProgram(XGLuint program)
{
    glLinkProgram(program);
}

void xgles_useProgram(XGLuint program)
{
    glUseProgram(program);
}

void xgles_getProgramiv(XGLuint program, XGLenum pname, XGLint * params)
{
    glGetProgramiv(program, pname, params);
}

void xgles_getProgramInfoLog(XGLuint program, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
    glGetProgramInfoLog(program, bufsize, length, infolog);
}

XGLint xgles_getUniformLocation(XGLuint program, const XGLchar* name)
{
    return glGetUniformLocation(program, name);
}

void xgles_uniform1f(XGLint location, XGLfloat x)
{
    glUniform1f(location, x);
}

void xgles_uniform2f(XGLint location, XGLfloat x, XGLfloat y)
{
    glUniform2f(location, x, y);
}

void xgles_uniform3f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z)
{
    glUniform3f(location, x, y, z);
}

void xgles_uniform4f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z, XGLfloat w)
{
    glUniform4f(location, x, y, z, w);
}

void xgles_uniformMatrix3fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
    glUniformMatrix3fv(location, count, transpose, value);
}

void xgles_uniformMatrix4fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
    glUniformMatrix4fv(location, count, transpose, value);
}

void xgles_uniform1i(XGLint location, XGLint x)
{
    glUniform1i(location, x);
}

void xgles_getVertexAttribPointerv(XGLuint index, XGLenum pname, XGLvoid ** pointer)
{
    glGetVertexAttribPointerv(index, pname, pointer);
}

void xgles_enableVertexAttribArray(XGLuint index)
{
    glEnable(index);
}

void xgles_disableVertexAttribArray(XGLuint index)
{
    glDisableVertexAttribArray(index);
}

XGLint  xgles_getAttribLocation(XGLuint program, const XGLchar * name)
{
    return glGetAttribLocation(program, name);
}

void xgles_genFramebuffers(XGLsizei n, XGLuint * framebuffers)
{
    glGenFramebuffers(n, framebuffers);
}

void xgles_bindFramebuffer(XGLenum target, XGLuint framebuffer)
{
    glBindFramebuffer(target, framebuffer);
}

void xgles_framebufferTexture2D(XGLenum target, XGLenum attachment, XGLenum textarget, XGLuint texture, XGLint level)
{
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

XGLenum xgles_checkFramebufferStatus(XGLenum target)
{
    return glCheckFramebufferStatus(target);
}

void xgles_deleteFramebuffers(XGLsizei n, const XGLuint * framebuffers)
{
    glDeleteFramebuffers(n, framebuffers);
}

void xgles_genRenderbuffers(XGLsizei n, XGLuint * renderbuffers)
{
    glGenRenderbuffers(n, renderbuffers);
}

void xgles_bindRenderbuffer(XGLenum target, XGLuint renderbuffer)
{
    glBindRenderbuffer(target, renderbuffer);
}

void xgles_renderbufferStorage(XGLenum target, XGLenum internalformat, XGLsizei width, XGLsizei height)
{
    glRenderbufferStorage(target, internalformat, width, height);
}

void xgles_framebufferRenderbuffer(XGLenum target, XGLenum attachment, XGLenum renderbuffertarget, XGLuint renderbuffer)
{
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void xgles_deleteRenderbuffers(XGLsizei n, const XGLuint * renderbuffers)
{
    glDeleteRenderbuffers(n, renderbuffers);
}

void xgles_texParameterf(XGLenum target, XGLenum pname, XGLfloat param)
{
    glTexParameterf(target, pname, param);
}

void xgles_texImage2D(XGLenum target, XGLint level, XGLint internalformat, XGLsizei width, XGLsizei height, XGLint border, XGLenum format, XGLenum type, const XGLvoid* pixels)
{
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void xgles_genTextures(XGLsizei n, XGLuint * textures)
{
    glGenTextures(n, textures);
}

void xgles_activeTexture(XGLenum texture)
{
    glActiveTexture(texture);
}

void xgles_bindTexture(XGLenum target, XGLuint texture)
{
    glBindTexture(target, texture);
}

void xgles_deleteTextures(XGLsizei n, const XGLuint * textures)
{
    glDeleteTextures(n, textures);
}

XGLenum xgles_getError(void)
{
    return glGetError();
}

void xgles_texSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLsizei width, XGLsizei height, XGLenum format, XGLenum type, const XGLvoid* pixels)
{
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void xgles_getIntegerv(XGLenum pname, XGLint* params)
{
    glGetIntegerv(pname, params);
}

void xgles_drawArrays(XGLenum mode, XGLint first, XGLsizei count)
{
    glDrawArrays(mode, first, count);
}

void xgles_drawElements(XGLenum mode, XGLsizei count, XGLenum type, const XGLvoid * indices)
{
    glDrawElements(mode, count, type, indices);
}

void xgles_enable(XGLenum cap)
{
    glEnable(cap);
}

void xgles_disable(XGLenum cap)
{
    glDisable(cap);
}

void xgles_finish(void)
{
    glFinish();
}

void xgles_flush(void)
{
    glFlush();
}

void xgles_blendFunc(XGLenum sfactor, XGLenum dfactor)
{
    glBlendFunc(sfactor, dfactor);
}

void xgles_depthFunc(XGLenum func)
{
    glDepthFunc(func);
}

void xgles_depthMask(XGLboolean flag)
{
    glDepthMask(flag);
}

void xgles_copyTexSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLint x, XGLint y, XGLsizei width, XGLsizei height)
{
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void xgles_clear(XGLbitfield mask)
{
    glClear(mask);
}

void xgles_clearColor(XGLfloat red, XGLfloat green, XGLfloat blue, XGLfloat alpha)
{
    glClearColor(red, green, blue, alpha);
}

void xgles_viewport(XGLint x, XGLint y, XGLsizei width, XGLsizei height)
{
    glViewport(x, y, width, height);
}
