
// �������(IO)��ָ�����ͬ�κ��ⲿ�豸֮������ݴ��ݡ����ݿ��԰�"��¼"��"���ݿ�"
// �ķ�ʽ���ݣ��ɿ��԰�"��"�ķ�ʽ����
// ��¼ֻ�����ڲ��ṹ�����ݿ飬��¼�ڲ���������Ҫ�����ʵ������֮�⣬�����ܰ���
// ������Ϣ����Щ������Ϣͨ���ǶԱ���¼���ݵ�����
// ����һ�ֳ����������������ݵ��޽ṹ������
// ���ݵı�ʾ��Ϊ���֣��ڲ���ʾ���ⲿ��ʾ����׼IO����Ҫ�����ַ����е��ⲿ����
// ���ڲ����ݱ�ʾ֮���ת�����Լ��ڳ������ⲿ�豸֮�������ķ�ʽ�����ַ�����
// IO���У������������4������ʽ��/���������壬����ת��������

// C++������ģ����ƣ�����IO���඼��ͨ��ģ�����ʵ�ֵ�ģ����
// typedef basic_ios<char, char_traits<char> > ios;
// typedef basic_istream<char, char_traits<char> > istream;
// typedef basic_ostream<char, char_traits<char> > ostream;
// typedef basic_iostream<char, char_traits<char> > iostream;
// typedef basic_ifstream<char, char_traits<char> > ifstream
// typedef basic_ofstream<char, char_traits<char> > ofstream
// typedef basic_fstream<char, char_traits<char> > fstream

// ��ν���Ͱ�ȫ����ָ����������������ʵ��(�������ָ����ָ�������)������
// ������ʵ���ʵ�����ͻ�Ը����ݽ��еĲ���֮�䱣��һ����

// endl����ΪI/O������,Ҳ�з����I/O����.I/O�������ı��������ɺ���,���ǲ���
// ��װ��ĳ������ڲ�,ʹ��ʱҲ��������ʾ�ĺ������õ���ʽ
// endl		���ʱ���뻻�в�ˢ����
// ends		���ʱ���ַ��������NULL��Ϊβ��
// flush	ˢ��,�����ӻ����������Ŀ���豸
// ws		����ʱ��ȥ�հ��ַ�

// �û����Ա�д�Լ��ĸ�ʽ������,ֻҪ������������������ض���ԭ�ͼ���

#include <iostream>
#include <iomanip>

using namespace std;

// ����cout�ĳ�Ա����operator<<()������һ��������ʽ
// ostream& ostream::operator<<(ostream& (*_Pfn)(ostream&));
// ֻҪ��������ĺ���ԭ��,�Ϳ�����Ϊһ��������
ostream& Tab(ostream &outs)
{
	for(int i = 0; i < 4; i++)
		outs << '-';
	return outs;
}

ostream& Money(ostream &outs)
{
	outs.setf(ios::left, ios::adjustfield);
	outs << '$' << setw(12) << setfill('#');
	return outs;
}

int main()
{
	double amount = 4532.64;
	cout << "The amount is " << Tab << Money << amount << endl;

	system("pause");
	return 0;
}