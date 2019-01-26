
// ��ʾ��ֵ
#include<iostream>
#include<limits>
#include<string>

// numeric_limits��һ��ͨ�õ�ģ�壬Ϊ���е������ṩĬ�ϼ�ֵ
// ���ڸ��������͵ļ�ֵ�����ػ��汾(specialization)�ṩ,
// ͨ�õ�numeric_limits template�����ػ��汾��������<limits>
// ͷ�ļ���

using std::cout;
using std::endl;
using std::boolalpha;
using std::numeric_limits;
using std::string;

int main()
{
	// use textual representation for bool
	cout << boolalpha;

	cout << "max(short): " << numeric_limits<short>::max() << endl;
	cout << "max(int): " << numeric_limits<int>::max() << endl;
	cout << "max(long): " << numeric_limits<long>::max() << endl;
	cout << endl;

	cout << "max(float): " << numeric_limits<float>::max() << endl;
	cout << "max(double): " << numeric_limits<double>::max() << endl;
	cout << "max(long double): " << numeric_limits<long double>::max() << endl;
	cout << endl;

	cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
	// �ж�string�Ƿ�������ֵ���ޣ����Զ��κ����ͽ��в�ѯ���������ͣ�
	// �������Ƿ����˼�ֵ
	cout << "is_specialized(string): " 
		<< numeric_limits<string>::is_specialized << endl;

	system("pause");
	return 0;
}