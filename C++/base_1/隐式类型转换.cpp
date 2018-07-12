#include"iostream"
using namespace std;
class Data{
private:
	string s1;
public:
	Data(const string &str=""):s1(str){}//隐式类型转换string to Data
	void setstring(const Data &r){s1=r.s1;}
};
int main()
{
	Data one;
	string str="hello";
	one.setstring(str);
	return 0;
}