
// ��throw�׳�һ���쳣��catch�Ӿ�����ͨ���������ô���һ����������������
// һЩ��ͬ�㣬��������Ҳ������޴�Ĳ���
// ��������ͬ�㣬���ݺ����������쳣��;�������Ǵ�ֵ�������û�ָ�룬��
// ����ͬ�ģ������ڴ��ݲ������쳣�Ĺ����У�ϵͳ��Ҫ��ɵĲ���������ȫ
// ��ͬ�ġ�������������ԭ���ǣ����ú���ʱ������Ŀ���Ȩ���ջ��᷵�ص�
// �����ĵ��ô������ǵ��׳�һ���쳣ʱ������Ȩ��Զ����ص��׳��쳣�ĵط�

// ���������
#include <iostream>

using namespace std;

class stuff
{
	int n;
	char c;
public:
	void Addr() { cout << this << endl; }
	friend istream& operator>>(istream&, stuff&);
};

istream& operator>>(istream& in, stuff& w)
{
	w.Addr();
	cout << "input a integer and char:";
	cin >> w.n;
	cin >> w.c;
	cin.get();
	return in;
}

void passAndThrow()
{
	stuff localStuff;
	localStuff.Addr();
	cin >> localStuff;
	throw localStuff;
}

void passAndThrow_static()
{
	static stuff localStuff;
	localStuff.Addr();
	cin >> localStuff;
	throw localStuff;
}

int main()
{
	// ���쳣�������ǿ�Ƹ��ƿ������������������������׳��쳣�Ĳ���
	// �׳��쳣�����ٶȱȲ�������Ҫ��
	
	try{
		// passAndThrow();

		// ��ʹ�׳��Ķ��󲻻ᱻ�ͷţ�Ҳ����п�����������ʱlocalStuff��
		// �ֲ���̬�����׳��쳣ʱlocalStuff�����ᱻ��������ʱ�Խ�����
		// ��localStuff��һ������
		passAndThrow_static();
	}
	// ����catch�Ӿ䲶׽�����쳣��������ã����ǲ�׽�����쳣�����Ѿ�����
	// localStuff����������һ��������ԭ����throw���һ��ִ�У�����
	// passAndThrow()��ִ��Ҳ������localStuff���������Ӷ���������������
	// �����localStuff����(���������Ŀ���)���ݸ�catch�Ӿ䣬����Ӿ���ܵ�
	// ��ֻ��һ���������˵Ķ���һ��localStuff��ʬ�壬�����޷�ʹ�õ�
	// ���C++�淶Ҫ����Ϊ�쳣�׳��Ķ�����뱻����
	catch(stuff &w){
		w.Addr();
	}

	system("pause");
	return 0;
}