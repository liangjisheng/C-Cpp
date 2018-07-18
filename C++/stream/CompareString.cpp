
#include <Windows.h>
#include <tchar.h>
#include <iostream>

using std::cout;
using std::endl;

// 此函数用来比较两字符串
//int CompareString(  
	//LCID Locale,       // locale identifier  
	//DWORD dwCmpFlags,  // comparison-style options  
	//LPCTSTR lpString1, // first string  
	//int cchCount1,     // size of first string  
	//LPCTSTR lpString2, // second string  
	//int cchCount2      // size of second string  
	//);  

// 函数CompareString的返回值，不像C运行期库的*cmp字符串比较
// 函数所返回的值。CompareString返回0指示失败，CSTR_LESS_THAN
// (定义为1)指示pString1小于pString2，CSTR_EQUAL（定义为2）
// 指示pString1与pString2相等，CSTR_GREATER_THAN（定义为3）
// 指示pString1大于pString2。为了稍微方便些，如果函数成功，
// 可以用返回值减去2，来使结果与C运行期库函数的返回值一致（-1，0和+1）。


void Compare()
{
	TCHAR szBuffer[10] = { 
		TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'),
		TEXT('A'), TEXT('A'), TEXT('A'), TEXT('A'), '\0' 
	};

	// 得到调用线程的id,就是调用这个线程的地方id，//$0804是中文，$0409是英语 - 美国，
	// $042A是越南，
	// SetThreadLocale修改的是control panel 中的区域设置既第一项选项卡中的设置，
	// 而非第三项选项卡的设置(第一项选项卡的设置影响的是日期格式，而第三项选项卡
	// 的设置影响的才是中英文环境)，SetThreadLocale并不能更改系统的语言环境，
	// 设置第三选项中语言应用SetLocaleInfo 函数。
	// LCID属性的作用是设置或者返回一个用来指定本地或者某个区域性质的整数
	// 比如某个地区的相关日期、时间以及货币
	LCID local = GetThreadLocale();
	int result = CompareString(local, NORM_IGNORECASE, 
		szBuffer, _countof(szBuffer), 
		TEXT("AAAAAAAAA"), 10);

	switch(result)
	{
	case 0:
		cout << "error" << endl;
		break;
	case CSTR_LESS_THAN:
		cout << "str1 > str2" << endl;
		break;
	case CSTR_GREATER_THAN:
		cout <<  "str1 < str2" << endl;
		break;
	case CSTR_EQUAL:
		cout << "str1 == str2" << endl;
		break;
	default:
		cout << "Don't goto there" << endl;
		break;
	}

	cout << result << endl;
}


int main()
{
	Compare();

	system("pause");
	return 0;
}