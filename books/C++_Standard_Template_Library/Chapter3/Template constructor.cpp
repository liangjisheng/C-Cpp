
// Template constructor��member template��һ��������ʽ,ͨ������
// �ڸ��ƶ���ʱʵ����ʽ���ת����ע�⣬template constructor�����ڱ�(hide)
// implicit copy constructor.����ͱ���ȫ�Ǻϣ�implicit copy constructor
// �ͻᱻ����������������

#include"iostream"
using namespace std;

template<typename T>
class MyClass
{
	public:
		MyClass()
		{

		}
		template<typename U>
		MyClass(const MyClass<U>& x)
		{
			cout<<"template constructor"<<endl;
		}
		MyClass(const MyClass& x)
		{
			cout<<"built-in copy constructor"<<endl;
		}
};


int main()
{
	MyClass<double> xd;
	MyClass<double> xd2(xd);	// calls built-in copy
	MyClass<int> xi(xd);		// calls template constructor

	system("pause");
	return 0;
}