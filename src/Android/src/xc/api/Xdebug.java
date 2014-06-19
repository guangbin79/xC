package xc.api;

import android.util.Log;

public class Xdebug {
	
	public static void sys_assert(boolean exp){
		assert(exp);
	}
	
	public static void sys_dbgprintf(String msg){
		if(msg != null){
			Log.d("xdebug_printf", msg);
		}
	}
	
}
