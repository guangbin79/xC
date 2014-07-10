package xc.api;

import android.os.Handler;
import android.os.Message;

public class MThread{

	private static final String TAG = MThread.class.getSimpleName();


	private static int EThreadPriority_low = -1;
	private static int EThreadPriority_default = 0;
	private static int EThreadPriority_high = 1;


	private int mThreadHandler;


	private boolean mNotify = false;


	
	private MyThread mThread = null;

	public MThread() {
	}


	public void sys_ThreadCreate(int handler, int bnotify) {
		mThreadHandler = handler;

		if (bnotify == 0) {
			mNotify = false;
		} else {
			mNotify = true;
		}

	}


	public int sys_ThreadStart() {


		
		if(mThread != null){
			mThread.interrupt();
			mThread = null;
		}
		mThread = new MyThread();
		mThread.start();
		return 1;
	}

	public int sys_ThreadIsExecuting() {

		if (mThread != null) {
			return 1;
		} else {
			return 0;
		}
	}

	public void sys_ThreadDestory() {

		try {
			mThread.interrupt();
			mThread = null;
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	Handler handler = new Handler() {
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case 1:
				mThread.interrupt();
				mThread = null;
				SYS_ThreadNotifyFunc(mThreadHandler);
				synchronized (MThread.this) {
					MThread.this.notify();
				}
				break;
			case 2:
				mThread.interrupt();
				mThread = null;
				synchronized (MThread.this) {
					MThread.this.notify();
				}
				break;
			}
			super.handleMessage(msg);
		}
	};

	class MyThread extends Thread {


		public void run() {
			SYS_ThreadProcFunc(mThreadHandler);
			if (mNotify) {
				synchronized (MThread.this) {
					handler.sendEmptyMessage(1);
					try {
						MThread.this.wait();
					} catch (InterruptedException e) {
					}
				}
			} else {
				synchronized (MThread.this) {
					handler.sendEmptyMessage(2);
					try {
						MThread.this.wait();
					} catch (InterruptedException e) {
					}
				}
			}
		}

	}

	public static native void SYS_ThreadProcFunc(int handler);

	public static native void SYS_ThreadNotifyFunc(int handler);


}