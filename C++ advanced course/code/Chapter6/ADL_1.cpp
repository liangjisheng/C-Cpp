
// ADL��Argument Dependent Lookup����д����������ز��ң�Ҳ��ΪKoenig���ң�
// (�����ּ����ķ�����Andrew Koenig���������������ADL��ʱҲ���ΪKL).
// ADL��ָ�����������޶���ĺ������ý������ֲ���ʱ��Ӧ�õ�һ�ֲ��ҹ���
// ADL�Ĺ�����ǵ������������޶���ĺ������ý������ֲ���ʱ������ǰ����
// �ռ������⣬Ҳ��Ѻ��������������������ֿռ������ҷ�Χ

#include <iostream>
using namespace std;

namespace Koenig
{
	class OneClass
	{
	public:
		ostream& print(ostream &out) const 
		{ out << member << endl; return out; }
		OneClass(int mem = 5) : member(mem) {}
	private:
		int member;
	};

	inline ostream& operator<<(ostream &out, const OneClass &one)
	{ return one.print(out); }
}


int main()
{
	Koenig::OneClass one(10);
	// �������ڽ���main����(ȫ����)�����operator<<����ʱ�����ܹ���ȷ��λ��
	// Koenig���ֿռ������operator<<,������Ϊ����Koenig���ҹ��򣬱�������Ҫ
	// �Ѳ�������OneClass���ڵ����ֿռ�KoenigҲ�����operator<<���õ����ֲ���
	// ��Χ��
	cout << one;

	system("pause");
	return 0;
}
