package xc.api;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.Context;
import android.content.res.AssetManager.AssetInputStream;

public class Const {
	
	private static Context mContext = null;

	public static void setAppContext(Context context) {
		mContext = context;
	}

	public static Context getAppContext() {
	return mContext;
	}

	public static void copyAssetDir(String srcDir, String dstDir) {
		try {
			String[] files = mContext.getResources().getAssets().list(srcDir);
			for (int i = 0; i < files.length; i++) {
				try {
					InputStream is = mContext.getResources().getAssets().open(srcDir + "/" + files[i]);
					createFile(dstDir + "/" + files[i]);
					FileOutputStream fos = new FileOutputStream(dstDir + "/" + files[i]);

					byte[] buff = new byte[1024];
					int len;
					while ((len = is.read(buff)) != -1) {
						fos.write(buff, 0, len);
					}
					fos.flush();
					fos.close();
					fos = null;
					is.close();
					is = null;
				} catch (IOException e) {
					// shizy 20111109
					copyAssetDir(srcDir + "/" + files[i], dstDir + "/" + files[i]);
				}
			}
		} catch (IOException e) {
		}
	}

	private static void createFile(String fileName) {
		try {
			File file = new File(fileName);

			String fileDir = null;
			for (int i = fileName.length() - 1; i >= 0; i--) {
				if (fileName.charAt(i) == '/') {
					fileDir = fileName.substring(0, i);
					break;
				}
			}

			File dir = new File(fileDir);
			if (!dir.exists()) {
				dir.mkdirs();
			}

			if (file.exists()) {
				file.delete();
			}
			file.createNewFile();

			dir = null;
			file = null;
			fileDir = null;
		} catch (IOException e) {
		}
	}
	
	public static void deleteFile(String filePath){
		File file = new File(filePath);
		if (file.exists()){
			if(!file.isDirectory()) {
				file.delete();
			}
		}
	}
	public static void copyFile(String srcFilePath, String dstFilePath){
		InputStream input = null;
		if (srcFilePath.lastIndexOf("/") > 0) {
			File dstDir = new File(srcFilePath.substring(0, srcFilePath.lastIndexOf("/")));
			if (!dstDir.exists()) {
				dstDir.mkdirs();
			}
			dstDir = null;
		}
		if (dstFilePath.lastIndexOf("/") > 0) {
			File dstDir = new File(dstFilePath.substring(0, dstFilePath.lastIndexOf("/")));
			if (!dstDir.exists()) {
				dstDir.mkdirs();
			}
			dstDir = null;
		}
		File srcfile = new File(srcFilePath);
		File dstfile = new File(dstFilePath);
		try {
			dstfile.createNewFile();
		} catch (IOException e1) {
		}
		try {
			input = new FileInputStream(srcfile);
		} catch (FileNotFoundException e1) {
		}
		
		FileOutputStream fos = null;
		try {
			fos = new FileOutputStream(dstfile);
		} catch (FileNotFoundException e) {
		}
		byte[] buff = new byte[1024];
		int len;
		try {
			while ((len = input.read(buff)) != -1) {
				fos.write(buff, 0, len);
			}
		} catch (IOException e) {
		}
		try {
			input.close();
		    fos.close();
		
		} catch (IOException e) {
		}
	}
	
	
	public static void copyAssetFile(String srcFileName, String dstFileName) {
		InputStream is = null;
		try {
			is = mContext.getResources().getAssets().open(srcFileName);
		} catch (IOException e1) {
			return;
		}
		File dstFile = new File(dstFileName);
		try{
			if (dstFile.exists()){
			   if(!dstFile.isDirectory()) {
				   dstFile.delete();
			   }
			}			
		}catch(Exception e){}

		if (dstFileName.lastIndexOf("/") > 0) {
			File dstDir = new File(dstFileName.substring(0, dstFileName.lastIndexOf("/")));
			if (!dstDir.exists()) {
				dstDir.mkdirs();
			}
			dstDir = null;
		}

		try {
			dstFile.createNewFile();
		} catch (IOException e) {
			return;
		}

		FileOutputStream fos = null;
		try {
			fos = new FileOutputStream(dstFile);
		} catch (FileNotFoundException e) {
			return;
		}

		byte[] buff = new byte[1024];
		int len;
		try {
			while ((len = is.read(buff)) != -1) {
				fos.write(buff, 0, len);
			}
		} catch (IOException e) {}
		try {
			fos.flush();
		} catch (IOException e) {
		}
		try {
			is.close();
			fos.close();
		} catch (IOException e) {}
		is = null;
		fos = null;
		dstFile = null;
	}


	public static byte[] readAssertsFile(String filename) {
		AssetInputStream in = null;
		try {
			in = (AssetInputStream) mContext.getAssets().open(filename);
		} catch (IOException e) {}
		int length = 0;
		try {
			length = in.available();
		} catch (IOException e) {}
		byte[] b = new byte[length];
		try {
			in.read(b);
		} catch (IOException e) {}
		finally{
			try {
				in.close();
			} catch (IOException e) {}
		}
		return b;
	}

}
