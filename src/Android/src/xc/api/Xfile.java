package xc.api;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
//import android.content.Context;
import android.os.Environment;
import android.os.StatFs;
//import cn.com.tiros.api.Const;

public class Xfile {

	public static final int SYS_OFM_READ = 0;
	public static final int SYS_OFM_READWRITE = 1;
	public static final int SYS_OFM_APPEND = 2;
	public static final int SYS_OFM_CREATE = 3;

	public static final int SYS_FST_START = 0;
	public static final int SYS_FST_END = 1;
	public static final int SYS_FST_CURRENT_DOWN = 2;
	public static final int SYS_FST_CURRENT_UP = 3;

	//public static final String PATH_FS1 = "/tiros-com-cn-ext";
	public static final String PATH_FS1 = "/wwxxtt";

	public static final String PATH_FS4 = "/Cloud";

	private static final double SYS_MEMORY_UNIT = 1048576.0;

	private RandomAccessFile mRandomFile = null;

	public int sys_fopen(String fileName, int mode) {
		
		
		
		String filePath = libToJavaPath(fileName);
		File file = new File(filePath);
		switch (mode) {
		case SYS_OFM_READ:// 只读
			if (file.exists()) {
				try {
					mRandomFile = new RandomAccessFile(file, "r");
				} catch (FileNotFoundException e) {
					return 0;
				}
			} else {
				return 0;
			}
			break;
		case SYS_OFM_READWRITE:// 读写
			if (file.exists()) {
				try {
					mRandomFile = new RandomAccessFile(file, "rw");
				} catch (Exception e) {
					return 0;
				}
			} else {
				return 0;
			}
			break;
		case SYS_OFM_APPEND:// 追加
			if (file.exists()) {
				try {
					mRandomFile = new RandomAccessFile(file, "rw");
					mRandomFile.seek(file.length());
				} catch (Exception e) {
					return 0;
				}
			} else {
				return 0;
			}
			break;
		case SYS_OFM_CREATE:// 创建
			if (file.exists()) {
			System.out.println("xxxxxxxxxxxxxxxx-SYS_OFM_CREATE-1");
				return 0;
			}

			String fileDir = null;

			for (int i = filePath.length() - 1; i >= 0; i--) {
				if (filePath.charAt(i) == '/') {
					fileDir = filePath.substring(0, i);
					break;
				}
			}

			File f = new File(fileDir);
			System.out.println("xxxxxxxxxxxxxxxx-SYS_OFM_CREATE-2");
			if (!f.exists()) {
				System.out.println("xxxxxxxxxxxxxxxx-SYS_OFM_CREATE-3");
				f.mkdirs();
			}
			fileDir = null;
			f = null;
			try {
				mRandomFile = new RandomAccessFile(file, "rw");
			} catch (FileNotFoundException e) {
				return 0;
			}
			break;
		}
		file = null;
		filePath = null;
		return 1;
	}

	public void sys_fclose() {
		System.out.println("xxxxxxxxxxxxxxxx-sys_fclose-1");
		try {
			if (mRandomFile != null) {
				mRandomFile.close();
				System.out.println("xxxxxxxxxxxxxxxx-sys_fclose-2");
			}
		} catch (IOException e) {
		}
		System.out.println("xxxxxxxxxxxxxxxx-sys_fclose-3");
		mRandomFile = null;
	}

	public int sys_fchsize(int size) {
		if (mRandomFile == null) {
			return 0;
		}
		try {
			mRandomFile.setLength(size);
		} catch (IOException e) {
		}
		return size;
	}

	/**
	 * 文件是否存在
	 * 
	 * @param fileName
	 * @return
	 */
	public static int sys_fexist(String fileName) {
		System.out.println("xxxxxxxxxxxxxxxx-java-sys_fexist-start");
		System.out.printf("xxxxxxxxxxxxxxxx-java-sys_fexist-%sxx\n", fileName);
		String filePath = libToJavaPath(fileName);
		File file = new File(filePath);
		if (file.exists()) {
			return 1;
		}
		filePath = null;
		file = null;
		return 0;
	}

	/**
	 * 获取磁盘总空间
	 * 
	 * @param pszDisk
	 * @return MB
	 */
	public static double sys_fgetspace(String pszDisk) {
		System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-start");
		StatFs sf = null;
		if (pszDisk.startsWith("fs1")) {
			System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-1");
			if (sys_fexist("fs1:/") == 0) {
				System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-2");
				String filePath = libToJavaPath(pszDisk);
				System.out.printf("xxxxxxxxxxxxxxxx-java-filePath111=%sxxx\n",filePath);
				File f = new File(filePath);
				f.mkdirs();
				filePath = null;
				f = null;
			}
			try {
				System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-3");
				sf = new StatFs(Environment.getExternalStorageDirectory().getPath());
				System.out.printf("xxxxxxxxxxxxxxxx-java-filePathFs=%sxxx\n",Environment.getExternalStorageDirectory().getPath());
			} catch (Exception e) {
			}
		} else {
			System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-4");
			String filePath = libToJavaPath(pszDisk);
			System.out.printf("xxxxxxxxxxxxxxxx-java-filePath=%sxxx\n",filePath);
			try {
				System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-5");
				sf = new StatFs(filePath);
			} catch (Exception e) {
			}
		}
		System.out.println("xxxxxxxxxxxxxxxx-java-fgetspace-6");
		return ((long) sf.getBlockCount() * (long) sf.getBlockSize()) / SYS_MEMORY_UNIT;
	}

	/**
	 * 获取磁盘剩余空间
	 * 
	 * @param pszDisk
	 * @return MB
	 */
	public static double sys_fgetfreespace(String pszDisk) {
		StatFs sf = null;
		if (pszDisk.startsWith("fs1")) {
			if (sys_fexist("fs1:/") == 0) {
				String filePath = libToJavaPath(pszDisk);
				File f = new File(filePath);
				f.mkdirs();
				filePath = null;
				f = null;
			}
			try {
				sf = new StatFs(Environment.getExternalStorageDirectory().getPath());
			} catch (Exception e) {
			}
		} else {
			String filePath = libToJavaPath(pszDisk);
			try {
				sf = new StatFs(filePath);
			} catch (Exception e) {
			}
		}
		return ((long) sf.getAvailableBlocks() * (long) sf.getBlockSize()) / SYS_MEMORY_UNIT;
	}

	/**
	 * 获取文件大小
	 * 
	 * @param fileName
	 * @return
	 */
	public static int sys_fgetsize(String fileName) {
		String filePath = libToJavaPath(fileName);
		File file = new File(filePath);
		filePath = null;
		if (file.exists()) {
			int length = (int) file.length();
			file = null;
			return length;
		}
		file = null;
		return 0;
	}

	/**
	 * 建立目录 Create all the directories needed for this File
	 * 
	 * @return
	 */
	public static int sys_fmkdir(String dirName) {
		System.out.println("xxxxxxxxxxxxxxxx-java-mkdir-start");
		String filePath = libToJavaPath(dirName);
		System.out.println("xxxxxxxxxxxxxxxx-java-mkdir-1");
		File file = new File(filePath);
		
		System.out.printf("xxxxxxfilePath=%s\n", filePath);
		
		
		
		System.out.println("xxxxxxxxxxxxxxxx-java-mkdir-2");
		if (!file.exists()) 
		{
			if (file.mkdirs()) 
			{
				file = null;
				System.out.println("xxxxxxxxxxxxxxxx-1");
				return 1;
			} 
			else
			{
				file = null;
				System.out.println("xxxxxxxxxxxxxxxx-2");
				return 0;
			}
		} 
		else 
		{
			file = null;
			System.out.println("xxxxxxxxxxxxxxxx-3");
			return 1;
		}
	}

	public int sys_fread(byte[] b, int bufSize) {
		System.out.printf("xxxxxxxxx--sys_fread--start bufsize=%d\n", bufSize);
		if (mRandomFile == null) {
			System.out.println("xxxxxxxxx--sys_fread--1");
			return 0;
		}
		int size = 0;
		try {
			System.out.println("xxxxxxxxx--sys_fread--2");
			size = mRandomFile.read(b, 0, bufSize);
			System.out.printf("xxxxxxxxx--sys_fread--%d--size\n", size);
		} catch (IndexOutOfBoundsException e) {
		} catch (IOException e) {
		}
		if (size < 0) {
			System.out.println("xxxxxxxxx--sys_fread--3");
			size = 0;
		}
		return size;
	}

	/**
	 * 删除文件
	 * 
	 * @param file
	 * @return
	 */
	public static int sys_fremove(String fileName) {
		String filePath = libToJavaPath(fileName);
		File file = new File(filePath);
		if (file.exists()) {
			if (!file.isDirectory()) {
				if (file.delete()) {
					file = null;
					return 1;
				}
			}
		} else {
			return 1;
		}
		file = null;
		return 0;
	}

	/**
	 * 改名
	 * 
	 * @param oldName
	 * @param newName
	 * @return
	 */
	public static int sys_frename(String oldName, String newName) {
		String oldPath = libToJavaPath(oldName);
		String newPath = libToJavaPath(newName);
		File oldFile = new File(oldPath);
		File newFile = new File(newPath);
		if (oldFile.renameTo(newFile)) {
			oldFile = null;
			newFile = null;
			return 1;
		} else {
			oldFile = null;
			newFile = null;
			return 0;
		}
	}

	/**
	 * 删除目录
	 * 
	 * @param dirName
	 * @return
	 */
	public static int sys_frmdir(String dirName) {
		System.out.println("xxxxxxxxxxxxxxxx-frmdir--start");
		String filePath = libToJavaPath(dirName);
		System.out.printf("xxxxxxxxxxxxxxxx-filePath =%sxx\n",filePath);
		
		File file = new File(filePath);
		if (file.exists() && file.isDirectory()) {
			deleteFile(file);
			System.out.println("xxxxxxxxxxxxxxxx-frmdir--ok");
		}
		file = null;
		return 1;
	}
	
	/**
	 * @brief 定位文件读写位置
	 * @param[in] seekType - 文件定位类型
	 * @param[in] moveDistance - 从定位类型约定位置的位移
	 * @return - 当前文件读写位置,FST_START的偏移量
	 */
	public synchronized int sys_fseek(int type, int moveDis) {
		if (mRandomFile == null) {
			return 0;
		}
		int oldIndex = 0;
		int seekIndex = 0;
		try {
			oldIndex = (int) mRandomFile.getFilePointer();
		} catch (IOException e) {
		}
		seekIndex = oldIndex;
		if (type == SYS_FST_CURRENT_DOWN) {
			try {
				seekIndex += moveDis;
				if (seekIndex > (int) mRandomFile.length()) {
					seekIndex = (int) mRandomFile.length();
				}
			} catch (IOException e) {
			}
		} else if (type == SYS_FST_CURRENT_UP) {
			seekIndex -= moveDis;
			if (seekIndex < 0) {
				seekIndex = 0;
			}
		} else if (type == SYS_FST_START) {
			seekIndex = moveDis;
		} else if (type == SYS_FST_END) {
			try {
				seekIndex = (int) mRandomFile.length();
	
			} catch (IOException e) {
			}
		}
		try {
			mRandomFile.seek(seekIndex);
		} catch (IOException e) {
		}
		return seekIndex;
	}

	/**
	 * 写文件
	 **/
	public int sys_fwrite(byte[] pvBuf, int bufSize) {
		if (mRandomFile == null) {
			return 0;
		}
		try {
			mRandomFile.write(pvBuf, 0, bufSize);
		} catch (Exception e) {
			return 0;
		}
		pvBuf = null;
		return bufSize;
	}

	/**
	 * @brief 获取存储器是否存在
	 * @param[in] pszDisk - 准备判断是否存在的存储器
	 * @return - true：该存储器存在 false:该存储器不存在
	 * @par 接口使用约定: 1.参数pszDisk可以为 “fs0:/”、“fs1:/”或“fs2:/”<br>
	 */
	public static int sys_fdiskexist(String pszDisk) {
		if (pszDisk != null) {
			if (pszDisk.startsWith("fs4:/")) {
				sys_fmkdir("fs4:/");
				return 1;
			} else if (pszDisk.startsWith("fs0:/")) {
				return 1;
			} else if (pszDisk.startsWith("fs1:/")) {
				if (Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED)) {
					return 1;
				}
			} else if (pszDisk.startsWith("fs2:/")) {
				return 1;
			}
		}
		return 0;
	}

	/**
	 * @par ******** 注意 ******** <br>
	 *      文件系统目前共有四种类型: <br>
	 *      fs0:/代表应用程序内部存储器 <br>
	 *      fs1:/代表扩展存储器,建议在操作系统扩展存储器(T卡)里建立tiros-com-cn-ext目录作为腾瑞万里扩展存储器 <br>
	 *      fs2:/应用程序缓存存储目录，主要用于存储缓存数据，此目录内文件有可能被系统清除（如ios5系统）
	 *      fs3:/系统媒体文件存储目录，其下又分为： fs3:/picture/ 映射到系统图片存储目录 fs3:/audio/
	 *      映射到系统的音频文件存储目录 fs3:/video/ 映射到系统的视频文件存储目录
	 *      备注：系统媒体文件存储目录暂时固定只支持为以上3种媒体目录
	 *      如果路径没有fs0:/、fs1:/、fs2:/、fs3:\的前缀,则默认为fs0:/ <br>
	 * 
	 * @par 代码示例 fs0:/first/test1.dat-->应用程序内部存储根目录下first目录中的test1.dat文件 <br>
	 *      fs1:/second/test2.dat-->扩展存储器根目录下second目录中的test2.dat文件 <br>
	 *      fs2:/img/navidog.png-->应用程序缓存存储目录根目录下img目录中的navidog.png文件 <br>
	 *      fs3:/picture/p1.png-->系统媒体目录的图片存储目录下p1.png文件
	 *      fs3:/audio/a1.mp3-->系统媒体目录的音频存储目录下a1.mp3文件
	 *      fs3:/video/v1.avi-->系统媒体目录的视频存储目录下v1.avi文件
	 *      fourth/test4.dat-->没有固定前缀，则默认指向应用程序内部存储根目录下fourth目录中的test4.dat文件 <br>
	 */
	public static String libToJavaPath(String filename) {
		
		System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-start");
		filename = winToLinuxPath(filename);
		System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-1");
		String filepath = null;

		boolean is = filename.contains(":");
		System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-2");
		if (is) {
			System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-3");
			String substr = filename.substring(0, 3);
			String newfilename = filename.substring(4, filename.length());
			System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-4");
			if (substr.equals("fs0")) {
				filepath = Const.getAppContext().getFilesDir().getPath() + newfilename;
			} else if (substr.equals("fs1")) {
				System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-5");
				filepath = Environment.getExternalStorageDirectory().getPath() + PATH_FS1 + newfilename;
			} else if (substr.equals("fs2")) {
				filepath = Const.getAppContext().getCacheDir().getPath() + newfilename;
			} else if (substr.equals("fs3")) {

			} else if (substr.equals("fs4")) {
				filepath = Const.getAppContext().getFilesDir().getPath() + PATH_FS4 + newfilename;
			} else if (substr.equals("fs5")) {
				filepath = "/data/data/" + Const.getAppContext().getPackageName() + newfilename;
			}
			substr = null;
			newfilename = null;
		} else {
			System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-8.");
			if (filename.startsWith("./")) {
				System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-9");
				filename = filename.substring(1);
				System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-10 ");
			}
			System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-11");
			filepath = Const.getAppContext().getFilesDir().getPath() +(filename.startsWith("/") ? "" : "/") + filename;
			//Const.getAppContext().getFilesDir().getPath();
			System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-12");
		}
		filename = null;

		// shizy 20120424 处理路径中包含../的情况
		while (filepath.contains("../")) {
			int start = filepath.indexOf("../");
			if (start <= 0) {
				break;
			}
			String str1 = filepath.substring(0, start - 1);
			String str2 = filepath.substring(start + 3);
			filepath = str1.substring(0, str1.lastIndexOf("/") + 1) + str2;
		}
		System.out.printf("xxxxxxfilePath=%s\n", filepath);
		System.out.println("xxxxxxxxxxxxxxxx-java-libToJavaPath-13");
		return filepath;
	}

	/**
	 * @param javaFilePath
	 * @return /data/data/..... /sdcard/.... /data/data/tiroscomcn/.... ....
	 */
	public static String javaToLibPath(String javaFilePath) {

//		String fs0Path = Const.getAppContext().getFilesDir().getPath();
//		String fs1Path = Environment.getExternalStorageDirectory().getPath() + PATH_FS1;
//		String fs2Path = Const.getAppContext().getCacheDir().getPath();
//		String fs3Path = "fs3:/";
//		String fs4Path = Const.getAppContext().getFilesDir().getPath() + PATH_FS4;
//
		String filePath = null;
//
//		if (javaFilePath.startsWith(fs4Path)) {
//			filePath = "fs4:" + javaFilePath.substring(fs4Path.length(), javaFilePath.length());
//		} else if (javaFilePath.startsWith(fs1Path)) {
//			filePath = "fs1:" + javaFilePath.substring(fs1Path.length(), javaFilePath.length());
//		} else if (javaFilePath.startsWith(fs2Path)) {
//			filePath = "fs2:" + javaFilePath.substring(fs2Path.length(), javaFilePath.length());
//		} else if (javaFilePath.startsWith(fs3Path)) {
//			filePath = "fs3:" + javaFilePath.substring(fs3Path.length(), javaFilePath.length());
//		} else if (javaFilePath.startsWith(fs0Path)) {
//			filePath = "fs0:" + javaFilePath.substring(fs0Path.length(), javaFilePath.length());
//		}
	
		return filePath;
	}

	/**
	 * 将window系统的路径转换为linux系统的路径
	 * 
	 * @param file
	 * @return
	 */
	public static String winToLinuxPath(String file) {
		return file.replace('\\', '/');
	}

	/**
	 * 将Linux路径转换为windows路径
	 * 
	 * @param file
	 * @return
	 */
	public static String linuxToWinPath(String file) {
		return file.replace('/', '\\');
	}

	public static void deleteFile(File file) {
		if (file.isDirectory()) {
			File[] flist = file.listFiles();
			if(flist == null){
				file.delete();
				return;
			}
			for (int i = 0; i < flist.length; i++) {
				if (flist[i].isDirectory()) {
					deleteFile(flist[i]);
				} else {
					flist[i].delete();
				}
			}
			file.delete();
		}
	}
	//测试用的
	public static void printjavalog(){
		
		System.out.println("xxxxxxxxxxxxxx---android--log!");
	}
}
