package xc.api;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		Const.setAppContext(this);
		
		assert(false);
		System.out.printf("xxxxxxfilexxx%dxxx\n", 0);
		int m = testclass.filetest();
		System.out.printf("xxxxxxrand=%dxxx\n",m);
		//System.out.println("java timexxxxx= :" + SystemClock.uptimeMillis()); 
		//SystemClock.uptimeMillis();
	
	
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	static {
        System.loadLibrary("xC");
    }


}
