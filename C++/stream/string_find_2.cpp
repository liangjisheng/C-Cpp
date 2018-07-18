#include"iostream"
#include"string"
#include"cstring"
using namespace std;
int main(int argc,char *argv[])
{
	string s="abcdeabcdeabcdeABCDE";
	cout<<"s:"<<s<<endl;
	cout<<"s.find(cde): "
		<<s.find("cde")<<endl;
	cout<<"s.find(cde): "
		<<s.rfind("cde")<<endl;
	cout<<"s.find_first_of(udu): "//返回s中第一个和udu任意字符相匹配的位置
		<<s.find_first_of("ude")
		<<"\ns.find_first_of(udu,5): "//返回s中从第5个位置开始第一个和udu任意字符相匹配的位置
		<<s.find_first_of("udu",5)<<endl;
	cout<<"s.find_first_of(usurp): "
		<<s.find_first_of("usurp")
		<<"\n***NOTE: string::nops= "
		<<string::npos<<endl;
	cout<<"s.find_first_not_of(udead): "
		<<s.find_first_not_of("udead")<<endl;//返回s中第一个和udu任意字符不相匹配的位置
	cout<<"s.find_last_not_of(udead): "
		<<s.find_last_not_of("udead",s.size())<<endl;//返回s中小于等于pos的最大的一个和udead中任意字符不相匹配的位置
	return 0;
}