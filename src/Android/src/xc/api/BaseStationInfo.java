package xc.api;

public class BaseStationInfo {
	public int mLac; 				//lac
	public int mCellId;				//cellid
	public int mMcc; 				//mobile_country_code
	public int mMnc; 				//mobile_network_code
	public short mSignalstrength;	//实际基站信号强度dbm
	public int mType;               //基站信息类别： 0:普通基站信息， 1:C网基站信息...
	public double mLat; 			//当前基站可获取的经度，若获取不到则为0
	public double mLon; 			//当前基站可获取的纬度，若获取不到则为0
}
