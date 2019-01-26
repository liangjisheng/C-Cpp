
// GetACP() 这个 API 用于判断目前正在生效的ANSI代码页，
// 返回值为目前活动ANSI代码页的标识符，可能的代码页包括下面这些：
//874	泰语
//932	日语
//936	中文（简体）
//949	朝鲜语
//950	中文（台湾和香港繁体）	
//1200	Unicode
//1250	东欧语言	
//1251	西里尔语
//1252	美国和西欧语言	
//1253	希腊语
//1254	土耳其语	
//1255	希伯来语
//1256	阿拉伯语	
//1257	波罗的语

// 代码页是字符集编码的别名，也称“内码表”，是特定语言的字符集的一张表。
// 代码页分为两种：一种是ANSI代码页；另一种是OEM代码页。

// ⑴OEM代码页主要是用于Windows系统中的命令行界面（Console）程序，虚拟Dos。

// ⑵ANSI代码页主要是用于Windows系统中本地编码不是Unicode的图形用户界面（Gui）程序。

#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	UINT nCodePage = GetACP();
	cout << "Current CodePage:" << nCodePage << '\t';
	if(874 == nCodePage)
		cout << "泰语" << endl;
	else if(932 == nCodePage)
		cout << "日语" << endl;
	else if(936 == nCodePage)
		cout << "中文（简体）" << endl;
	else if(949 == nCodePage)
		cout << "朝鲜语" << endl;
	else if(950 == nCodePage)
		cout << "中文（台湾和香港繁体）" << endl;
	else if(1200 == nCodePage)
		cout << "Unicode" << endl;
	else if(1250 == nCodePage)
		cout << "东欧语言" << endl;
	else if(1251 == nCodePage)
		cout << "西里尔语" << endl;
	else if(1252 == nCodePage)
		cout << "美国和西欧语言" << endl;
	else if(1253 == nCodePage)
		cout << "希腊语" << endl;
	else if(1254 == nCodePage)
		cout << "土耳其语" << endl;
	else if(1255 == nCodePage)
		cout << "希伯来语" << endl;
	else if(1256 == nCodePage)
		cout << "阿拉伯语" << endl;
	else if(1257 == nCodePage)
		cout << "波罗的语" << endl;

	cout << endl;
	LCID lcid = GetSystemDefaultLCID();
	cout << "lcid: " << lcid << '\t';
	if(lcid == 0x409)
		cout << "美国英语" << endl;
	else if(lcid == 0x404)
		cout << "中国繁体" << endl;
	else if(lcid == 0x804)
		cout << "中国简体" << endl;

	system("pause");
	return 0;
}