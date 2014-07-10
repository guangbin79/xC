package xc.api;

import android.os.SystemClock;

public class Xtime {
	public static double sys_clock(){
		return SystemClock.uptimeMillis();
	}
}
