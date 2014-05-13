#include "../../../xopengl.h"
#include <QtOpenGL>

static QGLFunctions qgl_fun;

void xopengl_genBuffers(XGLsizei n, XGLuint * buffers)
{
    qgl_fun.glGenBuffers(n, buffers);
}

void xopengl_deleteBuffers(XGLsizei n, const XGLuint * buffers)
{
    qgl_fun.glDeleteBuffers(n, buffers);
}

void xopengl_bindBuffer(XGLenum target, XGLuint buffer)
{
    qgl_fun.glBindBuffer(target, buffer);
}

void xopengl_bufferData(XGLenum target, XGLsizeiptr size, const XGLvoid * data, XGLenum usage)
{
    qgl_fun.glBufferData(target, size, data, usage);
}

void xopengl_bufferSubData(XGLenum target, XGLintptr offset, XGLsizeiptr size, const XGLvoid * data)
{
    qgl_fun.glBufferSubData(target, offset, size, data);
}

XGLuint xopengl_createShader(XGLenum type)
{
    return qgl_fun.glCreateShader(type);
}

void sys_xopengl_getShaderSource(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * source)
{
    qgl_fun.glGetShaderSource(shader, bufsize, length, source);
}

void xopengl_compileShader(XGLuint shader)
{
    qgl_fun.glCompileShader(shader);
}

void xopengl_getShaderiv(XGLuint shader, XGLenum pname, XGLint * params)
{
    qgl_fun.glGetShaderiv(shader, pname, params);
}

void xopengl_getShaderInfoLog(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
    qgl_fun.glGetShaderInfoLog(shader, bufsize, length, infolog);
}

void xopengl_deleteShader(XGLuint shader)
{
    qgl_fun.glDeleteShader(shader);
}

XGLuint xopengl_createProgram(void)
{
    return qgl_fun.glCreateProgram();
}

void xopengl_attachShader(XGLuint program, XGLuint shader)
{
    qgl_fun.glAttachShader(program, shader);
}

void xopengl_deleteProgram(XGLuint program)
{
    qgl_fun.glDeleteProgram(program);
}

void xopengl_linkProgram(XGLuint program)
{
    qgl_fun.glLinkProgram(program);
}

void xopengl_useProgram(XGLuint program)
{
    qgl_fun.glUseProgram(program);
}

void xopengl_getProgramiv(XGLuint program, XGLenum pname, XGLint * params)
{
    qgl_fun.glGetProgramiv(program, pname, params);
}

void xopengl_getProgramInfoLog(XGLuint program, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
    qgl_fun.glGetProgramInfoLog(program, bufsize, length, infolog);
}

XGLint xopengl_getUniformLocation(XGLuint program, const XGLchar* name)
{
    return qgl_fun.glGetUniformLocation(program, name);
}

void xopengl_uniform1f(XGLint location, XGLfloat x)
{
    qgl_fun.glUniform1f(location, x);
}

void xopengl_uniform2f(XGLint location, XGLfloat x, XGLfloat y)
{
    qgl_fun.glUniform2f(location, x, y);
}

void xopengl_uniform3f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z)
{
    qgl_fun.glUniform3f(location, x, y, z);
}

void xopengl_uniform4f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z, XGLfloat w)
{
    qgl_fun.glUniform4f(location, x, y, z, w);
}

void xopengl_uniformMatrix3fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
    qgl_fun.glUniformMatrix3fv(location, count, transpose, value);
}

void xopengl_uniformMatrix4fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
    qgl_fun.glUniformMatrix4fv(location, count, transpose, value);
}

void xopengl_uniform1i(XGLint location, XGLint x)
{
    qgl_fun.glUniform1i(location, x);
}

void xopengl_getVertexAttribPointerv(XGLuint index, XGLenum pname, XGLvoid ** pointer)
{
    qgl_fun.glGetVertexAttribPointerv(index, pname, pointer);
}

void xopengl_enableVertexAttribArray(XGLuint index)
{
    qgl_fun.glEnableVertexAttribArray(index);
}

void xopengl_disableVertexAttribArray(XGLuint index)
{
    qgl_fun.glDisableVertexAttribArray(index);
}

XGLint xopengl_getAttribLocation(XGLuint program, const XGLchar * name)
{
    return qgl_fun.glGetAttribLocation(program, name);
}

void xopengl_genFramebuffers(XGLsizei n, XGLuint * framebuffers)
{
    qgl_fun.glGenFramebuffers(n, framebuffers);
}

void xopengl_bindFramebuffer(XGLenum target, XGLuint framebuffer)
{
    qgl_fun.glBindFramebuffer(target, framebuffer);
}

void xopengl_framebufferTexture2D(XGLenum target, XGLenum attachment, XGLenum textarget, XGLuint texture, XGLint level)
{
    qgl_fun.glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

XGLenum xopengl_checkFramebufferStatus(XGLenum target)
{
    return qgl_fun.glCheckFramebufferStatus(target);
}

void xopengl_deleteFramebuffers(XGLsizei n, const XGLuint * framebuffers)
{
    qgl_fun.glDeleteFramebuffers(n, framebuffers);
}

void xopengl_genRenderbuffers(XGLsizei n, XGLuint * renderbuffers)
{
    qgl_fun.glGenRenderbuffers(n, renderbuffers);
}

void xopengl_bindRenderbuffer(XGLenum target, XGLuint renderbuffer)
{
    qgl_fun.glBindRenderbuffer(target, renderbuffer);
}

void xopengl_renderbufferStorage(XGLenum target, XGLenum internalformat, XGLsizei width, XGLsizei height)
{
    qgl_fun.glRenderbufferStorage(target, internalformat, width, height);
}

void xopengl_framebufferRenderbuffer(XGLenum target, XGLenum attachment, XGLenum renderbuffertarget, XGLuint renderbuffer)
{
    qgl_fun.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void xopengl_deleteRenderbuffers(XGLsizei n, const XGLuint * renderbuffers)
{
    qgl_fun.glDeleteRenderbuffers(n, renderbuffers);
}

void xopengl_texParameterf(XGLenum target, XGLenum pname, XGLfloat param)
{
    glTexParameterf(target, pname, param);
}

void xopengl_texImage2D(XGLenum target, XGLint level, XGLint internalformat, XGLsizei width, XGLsizei height, XGLint border, XGLenum format, XGLenum type, const XGLvoid* pixels)
{
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void xopengl_genTextures(XGLsizei n, XGLuint * textures)
{
    glGenTextures(n, textures);
}

void xopengl_activeTexture(XGLenum texture)
{
    qgl_fun.glActiveTexture(texture);
}

void xopengl_bindTexture(XGLenum target, XGLuint texture)
{
    glBindTexture(target, texture);
}

void xopengl_deleteTextures(XGLsizei n, const XGLuint * textures)
{
    glDeleteTextures(n, textures);
}

XGLenum xopengl_getError(void)
{
    return glGetError();
}

void xopengl_texSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLsizei width, XGLsizei height, XGLenum format, XGLenum type, const XGLvoid* pixels)
{
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void xopengl_getIntegerv(XGLenum pname, XGLint* params)
{
    glGetIntegerv(pname, params);
}

void xopengl_drawArrays(XGLenum mode, XGLint first, XGLsizei count)
{
    glDrawArrays(mode, first, count);
}

void xopengl_drawElements(XGLenum mode, XGLsizei count, XGLenum type, const XGLvoid * indices)
{
    glDrawElements(mode, count, type, indices);
}

void xopengl_enable(XGLenum cap)
{
    glEnable(cap);
}

void xopengl_disable(XGLenum cap)
{
    glDisable(cap);
}

void xopengl_finish(void)
{
    glFinish();
}

void xopengl_flush(void)
{
    glFlush();
}

void xopengl_blendFunc(XGLenum sfactor, XGLenum dfactor)
{
    glBlendFunc(sfactor, dfactor);
}

void xopengl_depthFunc(XGLenum func)
{
    glDepthFunc(func);
}

void xopengl_depthMask(XGLboolean flag)
{
    glDepthMask(flag);
}

void xopengl_copyTexSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLint x, XGLint y, XGLsizei width, XGLsizei height)
{
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void xopengl_clear(XGLbitfield mask)
{
    glClear(mask);
}

void xopengl_clearColor(XGLfloat red, XGLfloat green, XGLfloat blue, XGLfloat alpha)
{
    glClearColor(red, green, blue, alpha);
}

void xopengl_viewport(XGLint x, XGLint y, XGLsizei width, XGLsizei height)
{
    glViewport(x, y, width, height);
}
