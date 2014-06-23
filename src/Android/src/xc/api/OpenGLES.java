package xc.api;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;
import javax.microedition.khronos.opengles.GL11;
import android.view.SurfaceHolder;

/**
 * EGL环境创建类 2012-07-12
 * 
 * @author 曹颖鹏
 * 
 */
public class OpenGLES {

	/** 版本号变量 */
	public static final int OPENGL_ES_VERSION_1x = 1;
	public static final int OPENGL_ES_VERSION_2 = 2;

	private static final int EGL_CONTEXT_CLIENT_VERSION = 0x3098; // 版本号

	private static int EGL_OPENGL_ES2_BIT = 4; //配置字节数

	public static EGL10 EGL; //环境
	public static EGLDisplay Gl_Display = null; // 画布
	public static EGLContext Gl_Window_Context = null; //上下文
	public static EGLSurface Gl_Window_Surface = null;// Surface
	public static EGLConfig Gl_Config = null; //配置

	private static GL11 gl; //画笔

	/**
	 * 初始化函数
	 */
	public OpenGLES() {
	}

	/**
	 * 版本检测
	 * @param glesversion
	 */
	private static void DetectionVersion(int glesversion) {
		if (OPENGL_ES_VERSION_1x != glesversion && OPENGL_ES_VERSION_2 != glesversion) {
			throw new IllegalArgumentException("GL ES version has to be one of " + OPENGL_ES_VERSION_1x + " and "
					+ OPENGL_ES_VERSION_2);
		}
	}

	/**
	 * 环境创建
	 * @param glesVersion  版本号
	 */
	public static void EGLCreate(int glesVersion) {
		if (EGL == null) { //保证只创建一次
			//检测版本
			DetectionVersion(glesVersion);
			// Create EGL ,Display
			EGL = (EGL10) EGLContext.getEGL();
			//获取当前画布
			Gl_Display = EGL.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);
//			Log.e("EGLCreate ", "EGL.eglGetError()  0000000000 " + EGL.eglGetError());

			//初始化
			EGL.eglInitialize(Gl_Display, null);

			// Choose an EGLConfig
			int[] attrList;
			if (OPENGL_ES_VERSION_1x == glesVersion) {
				attrList = new int[] { EGL10.EGL_SURFACE_TYPE, EGL10.EGL_WINDOW_BIT, EGL10.EGL_NONE };
			} else {
				attrList = new int[] { EGL10.EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT, EGL10.EGL_SURFACE_TYPE,
						EGL10.EGL_WINDOW_BIT, EGL10.EGL_NONE };
			}
			EGLConfig[] configOut = new EGLConfig[1];
			int[] configNumOut = new int[1];
			//选择配置
			if (EGL.eglChooseConfig(Gl_Display, attrList, configOut, 1, configNumOut) && 1 == configNumOut[0]) {
				Gl_Config = configOut[0];
			}
//			Log.e("EGLCreate ", "EGL.eglGetError()  111111111111 " + EGL.eglGetError());

			// Create rendering context
			int[] contextAttrs = null;
			if (OPENGL_ES_VERSION_2 == glesVersion) {
				contextAttrs = new int[] { EGL_CONTEXT_CLIENT_VERSION, OPENGL_ES_VERSION_2, EGL10.EGL_NONE };
			}
			//获取上下文
			Gl_Window_Context = EGL.eglCreateContext(Gl_Display, Gl_Config, EGL10.EGL_NO_CONTEXT, contextAttrs);

//			Log.e("EGLCreate ", "EGL.eglGetError()  222222222 " + EGL.eglGetError());
		}
	}

	/**
	 * 创建WindowSurface
	 * 
	 * @param holder
	 */
	public static void EGLCreateWindowSurface(SurfaceHolder holder) {
		if(EGL != null){
			Gl_Window_Surface = EGL.eglCreateWindowSurface(Gl_Display, Gl_Config, holder, null);
//			Log.e("EGLCreateWindowSurface ", "EGL.eglGetError()  00000000000 " + EGL.eglGetError());
		}
	}

	/**
	 * 设置当前上下文为windowsurface,直接绘制屏幕
	 */
	public static void EGLWindowSurfaceMakeCurrent() {
		if(EGL != null){
			EGL.eglMakeCurrent(Gl_Display, Gl_Window_Surface, Gl_Window_Surface, Gl_Window_Context);
//			Log.e("surfacecreate ", "EGL.eglGetError()  000000000000 " + EGL.eglGetError());
		}
	}

	/**
	 * 销毁EGL环境上下文
	 */
	public static void EGLDestory() {
		if(EGL != null){
			EGL.eglDestroyContext(Gl_Display, Gl_Window_Context);
			EGL = null;
		}
	}

	/**
	 * 销毁EGLSurface
	 */
	public static void EGLSurfaceDestory() {
        if (Gl_Window_Surface != null && Gl_Window_Surface != EGL10.EGL_NO_SURFACE) {
    		EGL.eglMakeCurrent(Gl_Display, EGL10.EGL_NO_SURFACE, EGL10.EGL_NO_SURFACE, EGL10.EGL_NO_CONTEXT);
//    		Log.e("EGLSurfaceDestory ", "EGL.eglGetError()  00000000000 " + EGL.eglGetError());
    		EGL.eglDestroySurface(Gl_Display, Gl_Window_Surface);
//    		Log.e("EGLSurfaceDestory ", "EGL.eglGetError()  00000000000 " + EGL.eglGetError());
        }
	}

	public static void EGLSwapBuffers() {
		EGL.eglSwapBuffers(Gl_Display, Gl_Window_Surface);// 刷新屏幕
	}

	/**
	 * 填充颜色
	 */
	public void clearcolor() {
		gl = (GL11) Gl_Window_Context.getGL();
		gl.glClearColor(1, 0, 0, 1);
		gl.glClear(GL11.GL_COLOR_BUFFER_BIT);
		EGL.eglSwapBuffers(Gl_Display, Gl_Window_Surface);
	}

	/**
	 * 刷新
	 */
//	private static void glflush() {
//		gl = (GL11) Gl_Window_Context.getGL();
//		gl.glFlush();
//	}
}
