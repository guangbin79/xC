package xc.api;

//import java.io.File;
//import java.io.FileOutputStream;
//import java.io.IOException;
//import java.io.RandomAccessFile;
import java.util.List;
//import java.util.UUID;
import java.util.Vector;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.telephony.NeighboringCellInfo;
import android.telephony.TelephonyManager;
import android.telephony.gsm.GsmCellLocation;

public class Xtapi {

	private int mType;
	private TelephonyManager mTelephonyManager;
	private WifiManager wifiManager;
	private Vector<BaseStationInfo> basestationinfo  = null;
	
	public void sys_tapicreate(){
		mTelephonyManager = (TelephonyManager)Const.getAppContext().getSystemService(Context.TELEPHONY_SERVICE);
		wifiManager = (WifiManager)Const.getAppContext().getSystemService(Context.WIFI_SERVICE);
		mType = mTelephonyManager.getPhoneType();
	}
	
	public void sys_tapidestroy(){
		mTelephonyManager = null;
		basestationinfo = null;
	}
	
	public int sys_tapigetbscount() {

		if (basestationinfo != null) {
			basestationinfo.clear();
			basestationinfo = null;
		}
		
		if (mTelephonyManager.getSimState() == TelephonyManager.SIM_STATE_ABSENT
				|| mTelephonyManager.getSimState() == TelephonyManager.SIM_STATE_UNKNOWN) {
			return 0;
		}
		
		basestationinfo = new Vector<BaseStationInfo>();

		if (mType == TelephonyManager.PHONE_TYPE_CDMA) { // C网定位
			android.telephony.cdma.CdmaCellLocation cdmacell = (android.telephony.cdma.CdmaCellLocation) mTelephonyManager.getCellLocation();
			if (cdmacell != null) {
				BaseStationInfo stationInfo = new BaseStationInfo();
				stationInfo.mLac = cdmacell.getSystemId();
				stationInfo.mCellId = cdmacell.getBaseStationId();
				int baselon = cdmacell.getBaseStationLongitude();
				int baselat = cdmacell.getBaseStationLatitude();
				if ( baselon == Integer.MAX_VALUE || baselat == Integer.MAX_VALUE) {
					return 0;
				}
				
				//单位：度 * 1000000 
				stationInfo.mLon = baselon / 14400D * 1000000;			
				stationInfo.mLat = baselat / 14400D * 1000000;
				
				//判断获取到的经纬度是否在国界内
				if(stationInfo.mLon < 71000000D || stationInfo.mLon > 136000000D
						|| stationInfo.mLat  < 16000000D || stationInfo.mLat > 57000000D ){
					return 0;
				}
				
				String MCC_MNC = mTelephonyManager.getSubscriberId();

				if (MCC_MNC != null && MCC_MNC.length() > 0) {
					stationInfo.mMcc = Integer.parseInt(MCC_MNC.substring(0, 3));
					stationInfo.mMnc = Integer.parseInt(MCC_MNC.substring(3, 5));
				}
				stationInfo.mSignalstrength = 30;
				basestationinfo.add(stationInfo);

				stationInfo = null;
			}
			return basestationinfo.size();

		} else { // G网定位
			// 主基站
			GsmCellLocation gsmcell = (GsmCellLocation) mTelephonyManager.getCellLocation();
			if (gsmcell != null) {
				BaseStationInfo stationInfo = new BaseStationInfo();
				stationInfo.mLac = gsmcell.getLac();
				stationInfo.mCellId = gsmcell.getCid();
				stationInfo.mSignalstrength = 33;
				String MCC_MNC = mTelephonyManager.getSubscriberId();
				if (MCC_MNC != null && MCC_MNC.length() > 0) {
					stationInfo.mMcc = Integer.parseInt(MCC_MNC.substring(0, 3));
					stationInfo.mMnc = Integer.parseInt(MCC_MNC.substring(3, 5));
				}
				basestationinfo.add(stationInfo);
			}
			// 相邻基站
			List<NeighboringCellInfo> cells = mTelephonyManager.getNeighboringCellInfo();
			if (cells != null && cells.size() != 0) {
				int size = cells.size();
				for (int i = 0; i < cells.size(); i++) {
					BaseStationInfo stationInfo = new BaseStationInfo();
					stationInfo.mLac = cells.get(i).getLac();
					stationInfo.mCellId = cells.get(i).getCid();
					stationInfo.mSignalstrength = (short) cells.get(i).getRssi();
					String MCC_MNC = mTelephonyManager.getSubscriberId();

					if (MCC_MNC != null && MCC_MNC.length() > 0) {
						stationInfo.mMcc = Integer.parseInt(MCC_MNC.substring(0, 3));
						stationInfo.mMnc = Integer.parseInt(MCC_MNC.substring(3, 5));
					}
					if (stationInfo.mCellId > 0) {
						basestationinfo.add(stationInfo);
					} else {
						size = size - 1;
					}

					stationInfo = null;
				}
			}
			return basestationinfo.size();
		}
	}
	
	public BaseStationInfo sys_tapigetbsbyindex(int aIndex){
		if(basestationinfo == null || aIndex < 0 || aIndex >= basestationinfo.size()){
			return null;
		}	
		return basestationinfo.elementAt(aIndex);
	}
	
	public WIFIInfo sys_tapigetconnwifiinfo(){
		System.out.println("javawifi------11111");
		if(wifiManager == null){
			System.out.println("javawifi------22222");
			return null;
		}
		System.out.println("javawifixxxxx------33333");
		WifiInfo wifiInfo = wifiManager.getConnectionInfo();
		System.out.println("javawifixxxxxx------444444");
		if(wifiInfo == null){
			return null;
		}
		
		System.out.println("javawifi------555555");
		if(wifiInfo.getSSID() != null && wifiInfo.getBSSID() != null){
			WIFIInfo info = new WIFIInfo();
			info.mName = wifiInfo.getSSID();
			info.mMac = wifiInfo.getBSSID().replaceAll(":","");				
			info.mIp = "" + wifiInfo.getIpAddress();
			info.mSignalstrength = (short)wifiInfo.getRssi();
			return info;
		}
		return null;
	}
	
	public String sys_tapigetmobileid() {
		String imei = mTelephonyManager.getDeviceId();
		if (imei == null) {
			return "123456789123456";
		}
		return imei;
	}
	
	// 动态产生mobileid
//	private synchronized static String getDeviceid() {
//		String sID = null;
//		try {
//			File installation = new File(Const.getAppContext().getFilesDir(), "INSTALLATION");
//			if (!installation.exists()) {
//				writeInstallationFile(installation);
//			}
//			sID = readInstallationFile(installation);
//		} catch (Exception e) {
//			e.printStackTrace();
//			return sID;
//		}
//		return sID;
//	}
//	
//	
//	private static String readInstallationFile(File installation) throws IOException {
//		RandomAccessFile f = new RandomAccessFile(installation, "r");
//		byte[] bytes = new byte[(int) f.length()];
//		f.readFully(bytes);
//		f.close();
//		return new String(bytes);
//	}
//
//	private static void writeInstallationFile(File installation) throws IOException {
//		FileOutputStream out = new FileOutputStream(installation);
//		String id = UUID.randomUUID().toString();
//		out.write(id.getBytes());
//		out.close();
//	}
	
	/**
	 * @brief 获取设备卡的IMSI
	 * @return - 实际获取的IMSI
	 */
	public String sys_tapigetimsi(){
		return mTelephonyManager.getSubscriberId();
	}
	
	/**
	 * @brief 获取当前网络的联网类别
	 * @return - 实时获取当前网络的联网类别：0:普通网络(默认及获取不到具体类型) 1:wifi 2:gsm 3:cdma 4:tdcdma 5:cdma2000 6:wcdma。。。
	 */
	public int sys_tapigetnettype(){
		
		ConnectivityManager manager = (ConnectivityManager)Const.getAppContext().getSystemService(Context.CONNECTIVITY_SERVICE);  
	        
		if(manager == null) {
			return -1;  
		}  
	        
		NetworkInfo netWorkInfo = manager.getActiveNetworkInfo();  
	        
		if (netWorkInfo == null || !netWorkInfo.isConnected()) {
			return -1;
		}
		
		int type = netWorkInfo.getType();
		if(type == ConnectivityManager.TYPE_WIFI){
			return 1;
		}
		else if(type == ConnectivityManager.TYPE_MOBILE){
			int phoneType = mTelephonyManager.getNetworkType();
			if(phoneType == TelephonyManager.NETWORK_TYPE_CDMA){
				return 3;
			}
			else if(phoneType == TelephonyManager.NETWORK_TYPE_EDGE){
				return 2;
			}
		}
		return 0;
	}
	
	public String sys_tapigetosversion(){
		return android.os.Build.VERSION.RELEASE;
	}
	
	public String sys_tapigetdevicemodel(){
		return android.os.Build.MODEL;
	}
	
	public String sys_tapigetmanufacturername(){
		String manufacturer = android.os.Build.MANUFACTURER;
		String product = android.os.Build.PRODUCT;
//		String device = android.os.Build.DEVICE;
		if (null != manufacturer) {
			return manufacturer;
		}
		if (null != product) {
			return product;
		}
		return "";
	}
	
	public String tapigetlbskey(){
		return null;
//		LocationManagerProxy locationManager = LocationManagerProxy.getInstance(Const.context);
//		locationManager.startLbs();
//		String key = locationManager.requestLbsCipherTicket();
//		locationManager.destroy();		
//		return key;
	}
}
