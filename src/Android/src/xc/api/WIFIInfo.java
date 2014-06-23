package xc.api;

public class WIFIInfo {
	public String mName;         	//name
	public String mMac;           	//mac地址，12位+1位,mac地址格式没有连接字符,比如mac地址为12:34:56:78:9a:bc,对应为123456789abc
	public String mIp;       		//连接后实际分配的ip地址
	public short mSignalstrength;  	//wifi信号强度
}
