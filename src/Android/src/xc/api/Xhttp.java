package xc.api;

import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Vector;
import org.apache.http.Header;
import org.apache.http.HttpHost;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.params.AllClientPNames;
import org.apache.http.client.params.HttpClientParams;
import org.apache.http.client.utils.URIUtils;
import org.apache.http.entity.ByteArrayEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Proxy;
import android.provider.Settings;

public class Xhttp {
    

	public static final int NSEERR_DICONNECT = 600;

	public static final int NSEERR_CLIENTERR = 601;

	public static final int NSEERR_TIMEOUT_RESPONSE = 700;

	public static final int NSEERR_TIMEOUT_DATA = 701;

	public static final int NSEERR_TOTALLENERR = 702;
	
	public static final int NETSTATE_RUNNING = 0;
	
	public static final int NETSTATE_WAIT = 1;
	
	public int netstate = 1;
	private int mHttpHandler;
	private HttpGet mHttpGet;
	private HttpPost mHttpPost;
	public HttpClient mHttpClient;
	public HttpAsyncTask httpasync;
	private HttpParams mParams;
	private Map<String, String> mHeaders;
	private int  httpConnectTimeOutTime = 30*1000;
	private int  httpSoTimeOutTime = 20*1000;
	
    public void sys_httpcreate(int http, int dwConnectTimeout, int dwResponseTimeout) {
    	mHttpHandler = http;
    	httpConnectTimeOutTime = dwConnectTimeout;
    	httpSoTimeOutTime = dwResponseTimeout;
		mHeaders = new HashMap<String, String>();
	    mParams = new BasicHttpParams();
		mHttpClient = new DefaultHttpClient(mParams);
		HttpClientParams.setRedirecting(mParams, false);
	}
    
    public void sys_httpdestroy() {
		sys_httpcancel();
		mHeaders.clear();
		mHeaders = null;
		if(mHttpClient != null)	
		{
			mHttpClient.getConnectionManager().shutdown();
			mHttpClient = null;
		}
		mHttpHandler = 0;
		mParams = null;
		httpasync = null;
		mHttpPost = null;
		mHttpGet = null;
	}


	public void sys_httpsettimeout(int dwMSecs1, int dwMSecs2) {
		httpConnectTimeOutTime = dwMSecs1;
		httpSoTimeOutTime = dwMSecs2;
	}

	public boolean sys_httpaddheader(String name, String value) {
		mHeaders.put(name, value);
		return true;
	}

	public void sys_httpremoveheader(String name) {
		mHeaders.remove(name);
	}

	public void clearHeaders(){
		if(mHeaders != null){
			mHeaders.clear();
		}
	}

	public boolean sys_httppost(String contentType, String url, byte[] data) {
		isNeedWapConnect();
		HttpConnectionParams.setConnectionTimeout(mParams, httpConnectTimeOutTime);
		HttpConnectionParams.setSoTimeout(mParams, httpSoTimeOutTime);
						
		URI uri = URI.create(url);
		
		if(mHttpClient == null){
			mHttpClient = new DefaultHttpClient(mParams);
		}
		
		if(mHttpPost == null){
			mHttpPost = new HttpPost(uri);
		}
		else {
			mHttpPost.setURI(uri);
			Header[] headers = mHttpPost.getAllHeaders();
			if (headers != null) {
				for (int i = 0; i < headers.length; i++) {
					mHttpPost.removeHeader(headers[i]);
				}
			}
		}
		addPostData(mHttpPost, contentType, uri, data);
		
		boolean bContainsHead = false;
		String host = uri.getHost();
		if(host.contains("test8.lbs8.com") || host.contains("dev8.lbs8.com") || host.contains("nvd.lbs8.com") || host.contains("testx.lbs8.com")){
			bContainsHead = true;
		}
				
		try {
			httpasync = new HttpAsyncTask(this, mHttpHandler, mHttpClient,	mHttpPost, bContainsHead);
			httpasync.execute();
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	public boolean sys_httpget(String url) {
		isNeedWapConnect();
		HttpConnectionParams.setConnectionTimeout(mParams, httpConnectTimeOutTime);
		HttpConnectionParams.setSoTimeout(mParams, httpSoTimeOutTime);		
		URI uri = URI.create(url);

		if(mHttpClient == null){
			mHttpClient = new DefaultHttpClient(mParams);
		}
					
		if(mHttpGet == null){
			mHttpGet = new HttpGet(createGetUri(uri));
		}else {
			mHttpGet.setURI(createGetUri(uri));
		}
		
		if (mHeaders != null) {
			
			Set<Entry<String, String>> set = mHeaders.entrySet();
			
			Iterator<Entry<String, String>> iterator = set.iterator();
			
			while (iterator.hasNext()) {
				@SuppressWarnings("rawtypes")
				Map.Entry entry = (Map.Entry)iterator.next();
				String key = (String) entry.getKey();
				String value = (String) entry.getValue();
				mHttpGet.setHeader(key, value);
				entry = null;
			}
			set = null;
			iterator = null;
			clearHeaders();
		}
		
		boolean bContainsHead = false;
		String host = uri.getHost();
		if(host.contains("test8.lbs8.com") || host.contains("dev8.lbs8.com") || host.contains("nvd.lbs8.com") || host.contains("testx.lbs8.com")){
			bContainsHead = true;
		}
		
		try {
			httpasync = new HttpAsyncTask(this, mHttpHandler, mHttpClient,	mHttpGet, bContainsHead);
			httpasync.execute();
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	public void sys_httpcancel(){	
		httpConnectTimeOutTime = 30*1000;
		httpSoTimeOutTime = 20*1000;
		
		if (httpasync != null) {
			httpasync.cancel(true);
			httpasync.mIsCancel = true;
			httpasync = null;
		}
		
		if (mHttpPost != null) {
			if(!mHttpPost.isAborted()){
				mHttpPost.abort();
			}
			mHttpPost = null;
		}
		if (mHttpGet != null) {
			if(!mHttpGet.isAborted()){
				mHttpGet.abort();
			}
			mHttpGet = null;
		}
	    if(netstate == NETSTATE_RUNNING){
			if(mHttpClient != null)
			{
				mHttpClient.getConnectionManager().shutdown();
				mHttpClient = null;
			}
	    }
		clearHeaders();
		netstate = NETSTATE_WAIT;
	}
	
	public void sys_httpgetuserdata(){
		
	}

	public static String[][] formetString(String query) {
		Vector<String> name = new Vector<String>();
		Vector<String> value = new Vector<String>();
		Vector<String> pairs = new Vector<String>();
		query = "&" + query + "&";
		int size = 0;
		for (int i = 0; i < query.length(); i++) {
			if (query.charAt(i) == '&') {
				pairs.addElement(query.substring(size, i));
				size = i;
			}
		}
		for (int i = 1; i < pairs.size(); i++) {
			String str = (String) pairs.elementAt(i);
			int index = str.indexOf("=");
			name.addElement(str.substring(1, index));
			value.addElement(str.substring(index + 1, str.length()));
		}
		String[][] result = new String[pairs.size() - 1][2];
		for (int i = 0; i < result.length; i++) {
			result[i][0] = (String) name.elementAt(i);
			result[i][1] = (String) (value.elementAt(i)).toString();
		}
		name.clear();
		value.clear();
		pairs.clear();
		name = null;
		value = null;
		pairs = null;
		return result;
	}

	public List<NameValuePair> getPostParams(URI uri) {
		List<NameValuePair> params = null;
		String query = null;
		try {
			query = uri.getQuery();
			if (query != null) {
				String[][] changeparam = formetString(query);
				params = new ArrayList<NameValuePair>(changeparam.length);
				for (int i = 0; i < changeparam.length; i++) {
					params.add(new BasicNameValuePair(changeparam[i][0], changeparam[i][1]));
				}
			}
		} catch (Exception e) {}		
		return params;
	}

	public void addPostData(HttpPost post, String contentType, URI uri, byte[] data) {
		if (contentType != null) {
			post.setHeader("Content-Type", contentType);
		}
		if (mHeaders != null) {
			Set<Entry<String, String>> set = mHeaders.entrySet();
			Iterator<Entry<String, String>> iterator = set.iterator();
			while (iterator.hasNext()) {
				@SuppressWarnings("rawtypes")
				Map.Entry entry = (Map.Entry)iterator.next();
				String key = (String)entry.getKey();
				String value = (String)entry.getValue();							
				post.setHeader(key, value);
				entry = null;
			}
			set = null;
			iterator = null;
			clearHeaders();
		}
		
		if(getPostParams(uri) != null){
			try {
				post.setEntity(new UrlEncodedFormEntity(getPostParams(uri)));
			} catch (UnsupportedEncodingException e1) {}		
		}
		post.setEntity(new ByteArrayEntity(data));
	}
	
	public URI createGetUri(URI uri) {
		String scheme = null, host = null, path = null, query = null, fragment = null;
		int port = -1;
		scheme = uri.getScheme();
		host = uri.getHost();
		port = uri.getPort();
		path = uri.getPath();
		try {
			query = uri.getQuery();
		} catch (Exception e) {
			query = null;
		}
		try {
			fragment = uri.getFragment();
		} catch (Exception e) {
			fragment = null;
		}
		try {
			uri = URIUtils.createURI(scheme, host, port, path, query, fragment);
		} catch (URISyntaxException e1) {}
		return uri;
	}

	public void isNeedWapConnect() {
		String  defaultHost = Proxy.getDefaultHost();
		ConnectivityManager cm = (ConnectivityManager)Const.getAppContext().getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo netinfo = cm.getActiveNetworkInfo();		
		if(defaultHost != null && netinfo != null && netinfo.getType() != ConnectivityManager.TYPE_WIFI){	
			HttpHost proxy = new HttpHost(defaultHost, Proxy.getDefaultPort());
			mParams.setParameter(AllClientPNames.DEFAULT_PROXY, proxy);
		}else{
			mParams.removeParameter(AllClientPNames.DEFAULT_PROXY);			
		}
	}
	
	public boolean isNetWorkEnable(){
		ConnectivityManager cm = (ConnectivityManager)Const.getAppContext().getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo netinfo = cm.getActiveNetworkInfo();
        if(netinfo != null){
        	if(netinfo.isConnected()){
        		return true;
        	}
        	return false;
        }
		return false;
	}
	
	public boolean isAirPlaneMode() {
		return (Settings.System.getInt(Const.getAppContext().getContentResolver(), Settings.System.AIRPLANE_MODE_ON, 0) != 0) ? false : true;
	}

	public static native void sys_httpEvent(int http, int statecode, int param1, int param2);
	public static native void sys_httpEvent(int http, int statecode, int param1, byte[] param2);
	public static native void sys_httpEvent(int http, int statecode, int param1, String param2);
	
	public int sys_httpisRunning(){
		return netstate;
	}
}
