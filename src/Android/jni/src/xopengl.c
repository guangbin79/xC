/*
 * @file xopengl.c
 * @Author: wangxt<wangxt@tiros.com.cn>
 * @Created on: 2014-6-19
 */
#include "../../../xopengl.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

void xopengl_genBuffers(XGLsizei n, XGLuint * buffers)
{
	glGenBuffers(n, buffers);
}

void xopengl_deleteBuffers(XGLsizei n, const XGLuint * buffers)
{
	glDeleteBuffers (n, buffers);
}

void xopengl_bindBuffer(XGLenum target, XGLuint buffer)
{
	glBindBuffer(target, buffer);
}

void xopengl_bufferData(XGLenum target, XGLsizeiptr size, const XGLvoid * data, XGLenum usage)
{
	glBufferData(target, size, data, usage);
}

void xopengl_bufferSubData(XGLenum target, XGLintptr offset, XGLsizeiptr size, const XGLvoid * data)
{
	glBufferSubData(target, offset, size, data);
}

XGLuint xopengl_createShader(XGLenum type)
{
	return glCreateShader(type);
}

void xopengl_getShaderiv(XGLuint shader, XGLenum pname, XGLint * params)
{
	glGetShaderiv(shader, pname, params);
}
void xopengl_getShaderInfoLog(XGLuint shader, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
	glGetShaderInfoLog(shader, bufsize, length, infolog);
}

void xopengl_deleteShader(XGLuint shader)
{
	glDeleteShader(shader);
}

XGLuint xopengl_createProgram(void)
{
	return (XGLuint)glCreateProgram();
}

void xopengl_attachShader(XGLuint program, XGLuint shader)
{
	glAttachShader(program, shader);
}

void xopengl_deleteProgram(XGLuint program)
{
	glDeleteProgram(program);
}

void xopengl_linkProgram(XGLuint program)
{
	glLinkProgram(program);
}

void xopengl_useProgram(XGLuint program)
{
	glUseProgram(program);
}

void xopengl_getProgramiv(XGLuint program, XGLenum pname, XGLint * params)
{
	glGetProgramiv(program, pname, params);
}

void xopengl_getProgramInfoLog(XGLuint program, XGLsizei bufsize, XGLsizei * length, XGLchar * infolog)
{
	glGetProgramInfoLog(program, bufsize, length, infolog);
}

XGLint xopengl_getUniformLocation(XGLuint program, const XGLchar* name)
{
 	return glGetUniformLocation(program, name);
}

void xopengl_uniform1f(XGLint location, XGLfloat x)
{
	glUniform1f(location, x);
}

void xopengl_uniform2f(XGLint location, XGLfloat x, XGLfloat y)
{
	glUniform2f(location, x, y);
}

void xopengl_uniform3f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z)
{
	glUniform3f(location, x, y, z);
}

void xopengl_uniform4f(XGLint location, XGLfloat x, XGLfloat y, XGLfloat z, XGLfloat w)
{
	glUniform4f(location, x, y, z, w);
}

void xopengl_uniformMatrix3fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
	glUniformMatrix3fv(location, count, transpose, value);
}

void xopengl_uniformMatrix4fv(XGLint location, XGLsizei count, XGLboolean transpose, const XGLfloat * value)
{
	glUniformMatrix4fv(location, count, transpose, value);
}

void xopengl_uniform1i(XGLint location, XGLint x)
{
	glUniform1i(location, x);
}

void xopengl_getVertexAttribPointerv(XGLuint index, XGLenum pname, XGLvoid ** pointer)
{
	glGetVertexAttribPointerv(index, pname, pointer);
}

void xopengl_enableVertexAttribArray(XGLuint index)
{
	glEnableVertexAttribArray(index);
}

void xopengl_disableVertexAttribArray(XGLuint index)
{
	glDisableVertexAttribArray(index);
}

XGLint  xopengl_getAttribLocation(XGLuint program, const XGLchar * name)
{
	return glGetAttribLocation(program, name);
}

void xopengl_genFramebuffers(XGLsizei n, XGLuint * framebuffers)
{
	glGenFramebuffers(n, framebuffers);
}

void xopengl_bindFramebuffer(XGLenum target, XGLuint framebuffer)
{
	glBindFramebuffer(target, framebuffer);
}

void xopengl_framebufferTexture2D(XGLenum target, XGLenum attachment, XGLenum textarget,
								  XGLuint texture, XGLint level)
{
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

XGLenum xopengl_checkFramebufferStatus(XGLenum target)
{
	return glCheckFramebufferStatus(target);
}

void xopengl_deleteFramebuffers(XGLsizei n, const XGLuint * framebuffers)
{
	glDeleteFramebuffers(n, framebuffers);
}

void xopengl_genRenderbuffers(XGLsizei n, XGLuint * renderbuffers)
{
	glGenRenderbuffers(n, renderbuffers);
}

void xopengl_bindRenderbuffer(XGLenum target, XGLuint renderbuffer)
{
	glBindRenderbuffer(target, renderbuffer);
}

void xopengl_renderbufferStorage(XGLenum target, XGLenum internalformat, XGLsizei width, XGLsizei height)
{
	glRenderbufferStorage(target, internalformat, width, height);
}

void xopengl_framebufferRenderbuffer(XGLenum target, XGLenum attachment, XGLenum renderbuffertarget, XGLuint renderbuffer)
{
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void xopengl_deleteRenderbuffers(XGLsizei n, const XGLuint * renderbuffers)
{
	glDeleteRenderbuffers(n, renderbuffers);
}

void xopengl_texParameterf(XGLenum target, XGLenum pname, XGLfloat param)
{
	glTexParameterf(target, pname, param);
}

void xopengl_texImage2D(XGLenum target, XGLint level, XGLint internalformat, XGLsizei width,
						XGLsizei height, XGLint border, XGLenum format, XGLenum type, const XGLvoid* pixels)
{
	glTexImage2D(target,level, internalformat, width, height, border, format, type, pixels);
}

void xopengl_genTextures(XGLsizei n, XGLuint * textures)
{
	glGenTextures(n, textures);
}

void xopengl_activeTexture(XGLenum texture)
{
	glActiveTexture(texture);
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

void xopengl_texSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset, XGLsizei width,
						   XGLsizei height, XGLenum format, XGLenum type, const XGLvoid* pixels)
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

void xopengl_copyTexSubImage2D(XGLenum target, XGLint level, XGLint xoffset, XGLint yoffset,
							   XGLint x, XGLint y, XGLsizei width, XGLsizei height)
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

