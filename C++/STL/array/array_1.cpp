#include"iostream"
#include"array"
using namespace std;

int main()
{
	// 定义一个只能保存12个string数据元素的array容器
	array<string,12> arrMonths;
	arrMonths[0]="Jan";
	arrMonths[1]="Feb";
	arrMonths[2]="Mar";
	arrMonths[3]="Apr";
	arrMonths[4]="May";
	arrMonths[5]="Jun";
	arrMonths[6]="Jul";
	arrMonths[7]="Aug";
	arrMonths[8]="Sep";
	arrMonths[9]="Oct";
	arrMonths[10]="Nov";
	arrMonths[11]="Dec";

	for(array<string,12>::iterator it=arrMonths.begin();
		it!=arrMonths.end();it++)
			cout<<*it<<' ';
	cout<<endl;

	system("pause");
	return 0;
}