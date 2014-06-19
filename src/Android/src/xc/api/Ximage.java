package xc.api;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Bitmap.Config;
import android.graphics.BitmapFactory;

public class Ximage {

	private  int imgwidth = 0;
	private  int imgheight = 0;
	public Bitmap mBitmap = null;
	public Canvas mCanvas;

	
	public void  sys_imgcreate(int width, int height){
		mBitmap = Bitmap.createBitmap(width, height, Config.ARGB_8888);
		mCanvas = new Canvas(mBitmap);
	}

	public void sys_imgload(byte[] imgdata, int datasize) {	
		mBitmap = BitmapFactory.decodeByteArray(imgdata, 0, datasize);
		mBitmap = mBitmap.copy(Config.ARGB_8888, true);					
		imgwidth = mBitmap.getWidth();
		imgheight = mBitmap.getHeight();
		mCanvas = new Canvas(mBitmap);
	}
	
	public Object getBitmapObj(){
		return mBitmap;
	}
	
	public void sys_imgdestroy(){
		if(mBitmap != null && !mBitmap.isRecycled()){
			mBitmap.recycle();
			mBitmap = null;
		}
		mCanvas = null;
	}

	public int imgload_getwidth() {		
		return imgwidth;
	}

	public int imgload_getheight() {
		return imgheight;
	}
	
	public void sys_imgclearcolor(int r, int g, int b, int a){
		mBitmap.eraseColor(0);
	}
	
}
