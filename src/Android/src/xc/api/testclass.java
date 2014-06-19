package xc.api;

public class testclass {

	public static native void printnativelog();
	
	public static native int filetest();
	
	public static  void printlnLog(String str, int code){
//		String x = "xxxxlog=";
//		System.out.println(x+str);
		System.out.printf("xxxxlog = %s----%d\n", str, code);
	}
	
}
