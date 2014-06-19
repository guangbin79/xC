package xc.api;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;
import javax.microedition.khronos.opengles.GL11;
import android.view.SurfaceHolder;

/**
 * EGL���������� 2012-07-12
 * 
 * @author ��ӱ��
 * 
 */
public class OpenGLES {

	/** �汾�ű��� */
	public static final int OPENGL_ES_VERSION_1x = 1;
	public static final int OPENGL_ES_VERSION_2 = 2;

	private static final int EGL_CONTEXT_CLIENT_VERSION = 0x3098; // �汾��

	private static int EGL_OPENGL_ES2_BIT = 4; //�����ֽ���

	public static EGL10 EGL; //����
	public static EGLDisplay Gl_Display = null; // ����
	public static EGLContext Gl_Window_Context = null; //������
	public static EGLSurface Gl_Window_Surface = null;// Surface
	public static EGLConfig Gl_Config = null; //����

	private static GL11 gl; //����

	/**
	 * ��ʼ������
	 */
	public OpenGLES() {
	}

	/**
	 * �汾���
	 * @param glesversion
	 */
	private static void DetectionVersion(int glesversion) {
		if (OPENGL_ES_VERSION_1x != glesversion && OPENGL_ES_VERSION_2 != glesversion) {
			throw new IllegalArgumentException("GL ES version has to be one of " + OPENGL_ES_VERSION_1x + " and "
					+ OPENGL_ES_VERSION_2);
		}
	}

	/**
	 * ��������
	 * @param glesVersion  �汾��
	 */
	public static void EGLCreate(int glesVersion) {
		if (EGL == null) { //��ֻ֤����һ��
			//���汾
			DetectionVersion(glesVersion);
			// Create EGL ,Display
			EGL = (EGL10) EGLContext.getEGL();
			//��ȡ��ǰ����
			Gl_Display = EGL.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);
//			Log.e("EGLCreate ", "EGL.eglGetError()  0000000000 " + EGL.eglGetError());

			//��ʼ��
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
			//ѡ������
			if (EGL.eglChooseConfig(Gl_Display, attrList, configOut, 1, configNumOut) && 1 == configNumOut[0]) {
				Gl_Config = configOut[0];
			}
//			Log.e("EGLCreate ", "EGL.eglGetError()  111111111111 " + EGL.eglGetError());

			// Create rendering context
			int[] contextAttrs = null;
			if (OPENGL_ES_VERSION_2 == glesVersion) {
				contextAttrs = new int[] { EGL_CONTEXT_CLIENT_VERSION, OPENGL_ES_VERSION_2, EGL10.EGL_NONE };
			}
			//��ȡ������
			Gl_Window_Context = EGL.eglCreateContext(Gl_Display, Gl_Config, EGL10.EGL_NO_CONTEXT, contextAttrs);

//			Log.e("EGLCreate ", "EGL.eglGetError()  222222222 " + EGL.eglGetError());
		}
	}

	/**
	 * ����WindowSurface
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
	 * ���õ�ǰ������Ϊwindowsurface,ֱ�ӻ�����Ļ
	 */
	public static void EGLWindowSurfaceMakeCurrent() {
		if(EGL != null){
			EGL.eglMakeCurrent(Gl_Display, Gl_Window_Surface, Gl_Window_Surface, Gl_Window_Context);
		}
	}

	/**
	 * ���EGL����������
	 */
	public static void EGLDestory() {
		if(EGL != null){
			EGL.eglDestroyContext(Gl_Display, Gl_Window_Context);
			EGL = null;
		}
	}

	/**
	 * ���EGLSurface
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
		EGL.eglSwapBuffers(Gl_Display, Gl_Window_Surface);// ˢ����Ļ
	}
	
	
	public static boolean EGLmakeCurrentContext(){
		return EGL.eglMakeCurrent(Gl_Display, Gl_Window_Surface, Gl_Window_Surface, Gl_Window_Context);
	}

	/**
	 * �����ɫ
	 */
	public void clearcolor() {
		gl = (GL11) Gl_Window_Context.getGL();
		gl.glClearColor(1, 0, 0, 1);
		gl.glClear(GL11.GL_COLOR_BUFFER_BIT);
		EGL.eglSwapBuffers(Gl_Display, Gl_Window_Surface);
	}

	/**
	 * ˢ��
	 */
//	private static void glflush() {
//		gl = (GL11) Gl_Window_Context.getGL();
//		gl.glFlush();
//	}
}
