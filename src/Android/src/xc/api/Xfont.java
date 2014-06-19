package xc.api;

import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Align;
import android.graphics.Typeface;

public class Xfont {
	
	public static final int SYS_FS_MAP_1 = 100;
	public static final int SYS_FS_MAP_2 = 101;
	public static final int SYS_FS_MAP_3 = 102;
	public static final int SYS_FS_MAP_4 = 103;
	public static final int SYS_FS_MAP_5 = 104;
	public static final int SYS_FS_MAP_6 = 105;
	public static final int SYS_FS_MAP_7 = 106;
	public static final int SYS_FS_MAP_8 = 107;
	public static final int SYS_FS_MAP_9 = 108;
	public static final int SYS_FS_MAP_10 = 109;
	
	/** 获取屏幕密度 */
	public static float DISPLAY_HEIGHT = 1.5f;
	
	private Paint mPaint = null;
	private int mPnFits;
	private Ximage mImg = null;
	
	public void sys_ftcreate() {
		mPaint = new Paint();
		mPaint.setAntiAlias(true);
		mPaint.setTextAlign(Align.LEFT);	
		sys_ftsetstyle(SYS_FS_MAP_6);
	}
	
	public void sys_ftdestroy() {
		mPaint = null;
	}
	
	/**
	 * 绘制POI点图标及字体
	 * 共绘制五次
	 * @author 钱伟
	 * @date 2012/09/19 
	 */
	public void sys_ftdrawtext(Ximage img, int x, int y, String pwszText, int r, int g, int b) {	
	    
//		long starttime = System.currentTimeMillis();
		System.out.println("xxxxxxxxxtext1 start");
		int color = Color.rgb(r, g, b);
		System.out.println("xxxxxxxxxtext1 1");
		img.mCanvas.setBitmap(img.mBitmap);
		System.out.println("xxxxxxxxxtext1 2");
		if (color != Color.WHITE) {
			mPaint.setColor(Color.WHITE);
			img.mCanvas.drawText(pwszText, x+1, y - mPaint.getFontMetrics().ascent + 1, mPaint);
			img.mCanvas.drawText(pwszText, x-1, y - mPaint.getFontMetrics().ascent - 1, mPaint);
			img.mCanvas.drawText(pwszText, x+1, y - mPaint.getFontMetrics().ascent - 1, mPaint);
			img.mCanvas.drawText(pwszText, x-1, y - mPaint.getFontMetrics().ascent + 1, mPaint);
		}
		mPaint.setColor(color);
		img.mCanvas.drawText(pwszText, x, y - mPaint.getFontMetrics().ascent, mPaint);
		
//		Log.e("Font", "LLLL sys_ftdrawtext time = " + (System.currentTimeMillis() - starttime));
	}
	
	public int sys_ftmeasuretext(String pwszText, int nChars, int nMaxWidth) {
		if (pwszText == null){
			return 0;
		}
		float textWidth = mPaint.measureText(pwszText, 0, nChars);
		if(nMaxWidth != 0 && textWidth > nMaxWidth){
			textWidth = nMaxWidth;
			float len = 0;
			for(int i = 1; i <= pwszText.length(); i++){
				len = mPaint.measureText(pwszText, 0, i);
				if(len > nMaxWidth){
					mPnFits = i - 1;
					break;
				}
			}
		}
		else{
			mPnFits = pwszText.length();
		}
		return (int)textWidth;
	}
	
	public int sys_ftgetPnFits(){
		return mPnFits;
	}
	
	/**
	 * 为描边扩展位置
	 * @author 钱伟
	 * @date 2012/09/19 
	 */
	public int sys_ftgetfontsize(){
		return (int)mPaint.getTextSize() + 2; 
	}
	
	/**
	 * 有屏幕密度控制
	 * 设置字体高度 
	 * @author 钱伟
	 * @date 2012/09/19
	 */
	public int sys_ftgetheight() {
		int textSize = 0;
		if (DISPLAY_HEIGHT == 2.0) {
			textSize = (int)mPaint.getTextSize() + 4;
		} else {
			textSize = (int)mPaint.getTextSize() + 3;
		}
		return textSize; 
	}
	
	/**
	 * 根据手机屏幕密度
	 * 设置字体风格及字体大小
	 * @author 钱伟
	 * @date 2012/09/19
	 */
	public void sys_ftsetstyle(int style) {	
		mPaint.setTypeface(Typeface.defaultFromStyle(Typeface.NORMAL));
		if(style == SYS_FS_MAP_1){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(34f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(30f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(26f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(44f);
			}
		}else if(style == SYS_FS_MAP_2){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(32f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(28f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(20f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(42f);
			}
		}else if(style == SYS_FS_MAP_3){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(30f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(26f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(18f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(40f);
			}
		}else if(style == SYS_FS_MAP_4){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(28f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(22f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(16f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(40f);
			}
		}else if(style == SYS_FS_MAP_5){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(26f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(22f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(16f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(38f);
			}
		}else if(style == SYS_FS_MAP_6){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(26f);
			}else if(DISPLAY_HEIGHT == 1.5){
				mPaint.setTextSize(20f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(16f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(38f);
			}
		}else if(style == SYS_FS_MAP_7){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(24f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(18f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(14f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(36f);
			}
		}else if(style == SYS_FS_MAP_8){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(24f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(18f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(14f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(36f);
			}
		}else if(style == SYS_FS_MAP_9){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(20f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(16f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(12f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(34f);
			}
		}else if(style == SYS_FS_MAP_10){
			if (DISPLAY_HEIGHT == 2.0) {
				mPaint.setTextSize(18f);
			}else if(DISPLAY_HEIGHT == 1.5){		
				mPaint.setTextSize(14f);
			}else if(DISPLAY_HEIGHT == 1.0){
				mPaint.setTextSize(10f);
			}else if (DISPLAY_HEIGHT == 3.0) {
				mPaint.setTextSize(32f);
			}
		}
	}
	
	//////////////////////////////// 2012-07-04 caoyp ///////////////////////////////////////
	
	public void sys_ftdrawbegin(Ximage pimg){
		mImg = pimg;
	}
	
	public void sys_ftdrawtext2(int x, int y, String pwszText, int r, int g, int b){	
		
		System.out.println("xxxxxxxxxxxxxtext2 start");
		sys_ftdrawtext(mImg, x, y, pwszText, r, g, b);
		System.out.println("xxxxxxxxxxxxxxxxxxxtext2 end");
		
    }
	
	public void sys_ftdrawend(){} 
		
}
