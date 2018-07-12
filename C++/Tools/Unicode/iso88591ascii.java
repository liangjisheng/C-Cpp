import java.io.UnsupportedEncodingException;

public class iso88951ascii 
{
	public static void iso()
	{
		// String str = "&#$abc";
		String str = "úù§abc";
		try{
			byte[] ch = str.getBytes("ISO-8859-1");
			String ascii = new String(ch, "ASCII");
			String iso = new String(ch, "ISO-8859-1");
			System.out.println(str + " length:" + ch.length 
					+ "\nbytecode:" + byte2hex(ch) 
					+ "\nASCII:" + ascii
					+ "\nISO-8859-1:" + iso );
		}catch(UnsupportedEncodingException e){
			e.printStackTrace();
		}
	}
	
	private static String byte2hex(byte[] src) 
	{
		 StringBuilder stringBuilder = new StringBuilder("");   
		    if (src == null || src.length <= 0)   
		        return null;   
		    for (int i = 0; i < src.length; i++) {   
		        int v = src[i] & 0xFF;   
		        String hv = Integer.toHexString(v);   
		        if (hv.length() < 2) {   
		            stringBuilder.append(0);   
		        }   
		        stringBuilder.append(hv);
		        if(i != src.length - 1)
		        	stringBuilder.append(" ");
		    }   
		    return stringBuilder.toString();   
	}

	public static void gb()
	{
		String str = "啊aA";
		byte [] ch;
		try{
			// java中使用Unicode编码，所以两个字节相当于一个字符
			ch = str.getBytes("GB2312");
			System.out.println("ch length:" + ch.length + " bytecode:" + byte2hex(ch));
			ch = str.getBytes("GBK");	// 长度不是固定的
			System.out.println("ch length:" + ch.length + " bytecode:" + byte2hex(ch));
			// 由于表示汉字或者图形符号的高位字节的首个bit都为1，而ASCII的是个bit为0，从而
			// 实现了这两个字符对ASCII的兼容
		}catch(UnsupportedEncodingException e){
			e.printStackTrace();
		}
	}

	public static void unicode()
	{
		String str1 = "中文测试";
		byte [] ch;
		try{
			ch = str1.getBytes("unicode");
			System.out.println(str1.length());
			// 前面会有一个fe ff这个字节，该字节为BOM(Byte Order Mark)表示字节读取顺序
			System.out.println(str1 + " length:" + ch.length + " unicode " + byte2hex(ch));
			// utf-8使用3个字节表示汉字，1个字节表示英文字符
			ch = str1.getBytes("utf-8");
			System.out.println(str1 + " length:" + ch.length + " utf-8 " + byte2hex(ch));
			ch = str1.getBytes("utf-16");
			System.out.println(str1 + " length:" + ch.length + " utf-16 " + byte2hex(ch));
			ch = str1.getBytes("utf-32");
			System.out.println(str1 + " length:" + ch.length + " utf-32 " + byte2hex(ch));
			
			str1 = "test";
			System.out.println();
			System.out.println(str1.length());
			ch = str1.getBytes("unicode");
			System.out.println(str1 + " length:" + ch.length + " unicode " + byte2hex(ch));
			ch = str1.getBytes("utf-8");
			System.out.println(str1 + " length:" + ch.length + " utf-8 " + byte2hex(ch));
			ch = str1.getBytes("utf-16");
			System.out.println(str1 + " length:" + ch.length + " utf-16 " + byte2hex(ch));
			ch = str1.getBytes("utf-32");
			System.out.println(str1 + " length:" + ch.length + " utf-32 " + byte2hex(ch));
		}catch(UnsupportedEncodingException e){
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) 
	{
		// ISO-8859-1(Latin1)编码是单字节编码，向下兼容ASCII，编码
		// 范围是0x00-0xFF,0x00-0x7F之间完全和ASCII一致，0x80-0x9F
		// 之间是控制字符，0xA0-0xFF之间是文字符号。因为ISO-8859-1
		// 编码范围使用了单字节内的所有空间，在支持ISO-8859-1的系统
		// 中传输和存储其它任何编码的字节流都不会被抛弃。换言之，把
		// 其它任何编码的字节流当做ISO-8859-1编码看待都没有问题
		// iso();
		// gb();
		
		// UTF(Unicode transfromation format)是Unicode的不同实现，这里的
		// 实现是指字符在计算机中的表示方式
		// UTF-8是一种针对Unicode的可变长度的字符编码，可以用来表示Unicode
		// 中的任何字元，且其编码的中的第一个字节仍与ASCII兼容
		// UTF-16使用两个字节表示常用的字符(码位从U+0000到U+FFFF)，对于超出
		// U+FFFF外的字符需要4字节表示
		// UTF-32是另一种将Unicode字符编码的协议，对每一个Unicode码位均使用
		// 4字节来表示
		// unicode();
		
		// Unicode和GBK之间的转换是可逆的,每个汉字转换为2个字节，通过字节可以转换回字符串
		// Unicode和utf-8之间的转换是可逆的，每个汉字转换为3个字节，通过字节可以转换回字符串
		// Unicode和ISO-8859-1转化非可逆，字符串可以转换为字节，但字符串中有汉字的话
		// 就不能通过字节在转换回字符串了
	}
}
