package xc.api;

import java.util.Random;

public class Xrand {

	private static Random mRand = new Random();
	
	public static void sys_srand(int seed){
		mRand.setSeed(seed);
	}
	
	public static int sys_rand(){
		return mRand.nextInt();
	}
	
}
