package xc.api;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;

import org.apache.http.Header;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpRequestBase;
import org.apache.http.conn.ConnectTimeoutException;
import android.os.AsyncTask;

public class HttpAsyncTask extends AsyncTask<Void, Integer, Boolean> {

	// typedef enum _SYS_HTTPErrCode
	// {
	// SYS_HTTPERR_DISCONNECT = 600, //网络未连接
	// SYS_HTTPERR_CLIENTERR = 601, //http客户端错误
	// SYS_HTTPERR_TIMEOUT_RESPONSE = 700, //HTTP应答超时错误
	// SYS_HTTPERR_TIMEOUT_DATA = 701 //HTTP接收数据超时
	// } SYS_HTTPErrCode;
	private static final int SYS_HTTPERR_DISCONNECT = 600;// 网络未连接
	private static final int SYS_HTTPERR_CLIENTERR = 601; // http客户端错误
	private static final int SYS_HTTPERR_SERVERERR = 602; //http服务器非正常应答
	private static final int SYS_HTTPERR_TIMEOUT_RESPONSE = 700; // HTTP应答超时错误
	private static final int SYS_HTTPERR_TIMEOUT_DATA = 701; // HTTP接收数据超时

	// typedef enum _SYS_HttpErrorType
	// {
	// SYS_HTTPERRTYPE_UNAVAILABLE = 0x01, //网络不可用（自定义错误码600系列）
	// SYS_HTTPERRTYPE_RESPONSE, //http应答错误（标准http应答错误码）
	// SYS_HTTPERRTYPE_TIMEOUT //超时（自定义错误码700系列）
	// }SYS_HttpErrorType;
	private static final int SYS_HTTPERRTYPE_UNAVAILABLE = 0x01; // 网络不可用（自定义错误码600系列）
	private static final int SYS_HTTPERRTYPE_RESPONSE = 0x02; // http应答错误（标准http应答错误码）
	private static final int SYS_HTTPERRTYPE_TIMEOUT = 0x03; // 超时（自定义错误码700系列）

	// typedef enum _SYS_HttpEvent
	// {
	// SYS_EVT_HTTP_REQUEST = 0x0001, /* 请求 */
	// SYS_EVT_HTTP_RESPONSE = 0X0002, /* 应答 | dwParam1:状态码
	// dwParam2:完整数据体长度，只有状态码为200系列，才有该事件*/
	// SYS_EVT_HTTP_BODY = 0x0003, /* 数据体 | dwParam1 : http body size (uint32)
	// dwParam2 : http body (void *) */
	// SYS_EVT_HTTP_COMPLETED = 0x0004, /* 完成 */
	// SYS_EVT_HTTP_ERROR = 0x0005, /* 错误 | dwParam1 : 错误类型 dwParam2: 错误码,
	// 600之后为自定义错误*/
	// SYS_EVT_HTTP_DATA_GZIP /* GZIP标识 */
	// } SYS_HttpEvent;
	private static final int SYS_EVT_HTTP_REQUEST = 0x0001;
	private static final int SYS_EVT_HTTP_RESPONSE = 0x0002;
	private static final int SYS_EVT_HTTP_BODY = 0x0003;
	private static final int SYS_EVT_HTTP_COMPLETED = 0x0004;
	private static final int SYS_EVT_HTTP_ERROR = 0x0005;
	private static final int SYS_EVT_HTTP_DATA_GZIP = 0x006;
	
	private static final int M_EVT_HTTP_REQUEST = 0x0001;
	private static final int M_EVT_HTTP_RESPONSE = 0x0002;
	private static final int M_EVT_HTTP_RESPONSE_STRING = 0x003;
	private static final int M_EVT_HTTP_BODY = 0x0004;
	private static final int M_EVT_HTTP_COMPLETED = 0x0005;
	private static final int M_EVT_HTTP_ERROR = 0x0006;
	private static final int M_EVT_HTTP_DATA_GZIP = 0x007;

	private int httpErrorType = 0; // 错误码类型
	private int httpErrorCode = 0;// 错误码
	private int httpContentLength = 0;// 数据总长度
	private int mResponseCode;
	private int mContentLength;
	private String mHeaderLocation = null;//头信息的Location
	private byte[] mData;

	private HttpClient mHttpClient;
	private HttpResponse mResponse;
	private HttpRequestBase mRequest;

	private Xhttp mHttp;
	private int mHttpHandler;
	private boolean mIsCheckHeader = false; //是否校验头信息

	public volatile boolean mIsCancel = false;

	public HttpAsyncTask(Xhttp http, int handle, HttpClient client, HttpRequestBase request, boolean bcheck) {
		mHttp = http;
		mHttpHandler = handle;
		mRequest = request;
		mHttpClient = client;
		mIsCheckHeader = bcheck;
	}

	@Override
	protected Boolean doInBackground(Void... voids) {
		if (mIsCancel) {
			return true;
		}
		try {
			sendProgress(M_EVT_HTTP_REQUEST);
	    	if(!mIsCancel){
	    		mHttp.netstate = Xhttp.NETSTATE_RUNNING;
				mResponse = mHttpClient.execute(mRequest);
	    	}else{
	    		return true;
	    	}
		} catch (ConnectTimeoutException e1) { // 链接超时
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_TIMEOUT;
			httpErrorCode = SYS_HTTPERR_TIMEOUT_RESPONSE;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		} catch (SocketTimeoutException e1) {
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_TIMEOUT;
			httpErrorCode = SYS_HTTPERR_TIMEOUT_RESPONSE;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		} catch (ClientProtocolException e1) {
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_UNAVAILABLE;
			httpErrorCode = SYS_HTTPERR_CLIENTERR;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		} catch (UnknownHostException e1) { // 无法链接网络
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_UNAVAILABLE;
			httpErrorCode = SYS_HTTPERR_DISCONNECT;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		} catch (IOException e1) {
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_UNAVAILABLE;
			httpErrorCode = SYS_HTTPERR_DISCONNECT;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		}catch(Exception e){
			return false;
		}

		if (mIsCancel) {
			return true;
		}

		mResponseCode = mResponse.getStatusLine().getStatusCode();
		Header[] header = mResponse.getAllHeaders();
		
		if(header == null || header.length == 0) {
			httpErrorType = SYS_HTTPERRTYPE_UNAVAILABLE;
			httpErrorCode = SYS_HTTPERR_SERVERERR;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		}
		
		if (mIsCancel) {
			return true;
		}
		
		String sField = null;
		String sValue = null;
		boolean bGzip = false;
		boolean bPrivate = false;//判断是否包含我们自己的私有头信息
		String strLocation = null;
		for (int i = 0; i < header.length; i++) {
			Header mheader = header[i];
			sField = mheader.getName();
			sValue = mheader.getValue();
			
			sField = sField.toLowerCase(); //将名称转换为小写
			
//			Log.e("HttpAsyncTask", "sField == " + sField);
//			Log.e("HttpAsyncTask", "sValue == " + sValue);
									
			if(sField.equals("service-provider")){
				if(sValue.equals("tiros.com.cn")){
					bPrivate = true;
				}
			}
			if (sField.equals("content-length")) {
				httpContentLength = Integer.valueOf(sValue);
			}
			if (sField.equals("content-encoding")) {
				if (sValue.equals("gzip")) {
					bGzip = true;
				}
			}			
			if(sField.equals("location")){
				strLocation = sValue;
			}
		}
		
		if(mIsCheckHeader){
			if(!bPrivate){
				httpErrorType = SYS_HTTPERRTYPE_UNAVAILABLE;
				httpErrorCode = SYS_HTTPERR_SERVERERR;
				sendProgress(M_EVT_HTTP_ERROR);
				return false;
			}
		}
		
		if (mIsCancel) {
			return true;
		}
		
		if(mResponseCode == 302){
			if(strLocation != null){
				mHeaderLocation =  strLocation;
			}
			sendProgress(M_EVT_HTTP_RESPONSE_STRING);
		}else{
			sendProgress(M_EVT_HTTP_RESPONSE);
		}

		if (mIsCancel) {
			return true;
		}

		if (bGzip) {
			sendProgress(M_EVT_HTTP_DATA_GZIP);
		}

		if (mIsCancel) {
			return true;
		}

		InputStream is = null;
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		try {
			is = mResponse.getEntity().getContent();
		} catch (SocketTimeoutException e1) {
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_RESPONSE;
			httpErrorCode = SYS_HTTPERR_TIMEOUT_DATA;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		} catch (IOException e) {
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_RESPONSE;
			httpErrorCode = SYS_HTTPERR_TIMEOUT_DATA;
			sendProgress(M_EVT_HTTP_ERROR);
			return false;
		}
		
		if (mIsCancel) {
			return true;
		}

		int len = 0;
		mContentLength = 0;
		byte[] buff = new byte[1024 * 10];

		try {
			while (len != -1) {
				boolean breadtimeout = false;
				try {
					len = is.read(buff);
				} catch (Exception e1) {
					breadtimeout = true;
				}
				if (breadtimeout) {
					mHttp.netstate = Xhttp.NETSTATE_WAIT;
					httpErrorType = SYS_HTTPERRTYPE_TIMEOUT;
					httpErrorCode = SYS_HTTPERR_TIMEOUT_DATA;
					sendProgress(M_EVT_HTTP_ERROR);
					try {
						is.close();
						is = null;
					} catch (IOException e) {}
					
				}

				mContentLength = len;
				mData = buff;

				if (len != -1) {
					sendProgress(M_EVT_HTTP_BODY);
					if (mIsCancel) {
						try {
							is.close();
							is = null;
						} catch (IOException e) {}
					}
				}
			}
		} catch (Exception e) {
			// shizy 20120411 修改错误类型
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			httpErrorType = SYS_HTTPERRTYPE_TIMEOUT;
			httpErrorCode = SYS_HTTPERR_TIMEOUT_DATA;
			sendProgress(M_EVT_HTTP_ERROR);
		} finally {
			try {
				if (is != null) {
					is.close();
					is = null;
				}
				if (baos != null) {
					baos.close();
					baos = null;
				}
			} catch (IOException e) {}
		}
		sendProgress(M_EVT_HTTP_COMPLETED);
		return true;
	}

	private void sendProgress(int progress) {
		synchronized (this) {
			publishProgress(progress);
			try {
				wait();
			} catch (InterruptedException e) {}
		}
	}

	protected void onProgressUpdate(Integer... progress) {
		if (mIsCancel) {
			synchronized (this) {
				notify();
			}
			return;
		}
		switch (progress[0]) {
		case M_EVT_HTTP_REQUEST:
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_REQUEST, 0, 0);
			break;
		case M_EVT_HTTP_RESPONSE:
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_RESPONSE, mResponseCode, httpContentLength);
			break;
		case M_EVT_HTTP_RESPONSE_STRING:
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_RESPONSE, mResponseCode, mHeaderLocation);
			break;
		case M_EVT_HTTP_BODY:
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_BODY, mContentLength, mData);
			break;
		case M_EVT_HTTP_COMPLETED:
			mHttp.netstate = Xhttp.NETSTATE_WAIT;
			mIsCancel = false;	
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_COMPLETED, 0, 0);
			break;
		case M_EVT_HTTP_ERROR:
			mHttp.sys_httpcancel();
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_ERROR, httpErrorType, httpErrorCode);
			break;
		case M_EVT_HTTP_DATA_GZIP:
			Xhttp.sys_httpEvent(mHttpHandler, SYS_EVT_HTTP_DATA_GZIP, 0, 0);
			break;
		default:
			break;
		}
		synchronized (this) {
			notify();
		}
	}

}