
// ʹ��new[]����n�����������ʱ��ʵ���Ϸ�����n���������ڴ�飬
// ÿ��������޲ι��캯�����Զ�����

// ��C++11֮ǰ���ϵı�׼�������һ������ָ��ļ�ʵ�֣���Ϊauto_ptr.
// �ź�����auto_ptr����ȱ�㣬ȱ��֮һ����STL������(����vector)ʹ��ʱ,
// auto_ptr��������������C++�Ѿ���ʽ������auto_ptr,��֮��shared_ptr
// ��unique_ptr,
// shared_ptr��unique_ptr֮�����������shared_ptr�����ü���������ָ�룬
// ��unique_ptr���ǣ�����ζ�ţ������ж��shared_ptrʵ��ָ��ͬһ�鶯̬����
// ���ڴ棬�����һ��shared_ptr�뿪������ʱ�����ͷ�����ڴ档shared_ptr
// Ҳ���̰߳�ȫ�ġ�
// ��һ����unique_ptr��ζ������Ȩ������unique_ptr�뿪������ʱ�����ͷŵײ�
// ���ڴ档Ĭ�ϵ�����ָ����unique_ptr,ֻ����Ҫ������Դʱ����ʹ��shared_ptr
// #include <memory>

#include <iostream>
#include <memory>
#include <stdio.h>

using std::cout;
using std::cerr;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;

class Simple
{
public:
	Simple() { cout << "Simple constructor called." << endl; }
	virtual ~Simple() { cout << "Simple destructor called." << endl; }
};


// unique_ptrĬ��ʹ�ñ��׼��new��delete�������������ͷ�
// �ڴ棬�����޸������Ϊ��
int* malloc_int(int value)
{
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}


// shared_ptrĬ��ʹ�ñ��׼��new��delete�������������ͷ�
// �ڴ棬�����޸������Ϊ��
void CloseFile(FILE* filePtr)
{
	if (nullptr == filePtr)
		return;
	fclose(filePtr);
	cout << "File closed." << endl;
}


int main()
{
	/*Simple* pSimple = new Simple[4];

	cout << endl;
	delete[] pSimple;
	pSimple = nullptr;*/

	unique_ptr<Simple> mySimpleSmartPtr(new Simple);

	// unique_ptr���涯̬���䣬����10��������C�������
	auto myVariableSizedArray = make_unique<int[]>(10);

	
	// �޸�unique_ptr���ͷ���
	auto deleter = [](int* p) { free(p); };
	unique_ptr<int, decltype(deleter)> myIntSmartPtr(malloc_int(42), deleter);


	// ����ʹ��make_shared����shared_ptr
	auto mySimpleSmartPtr_1 = make_shared<Simple>();


	// �޸�shared_ptr���ͷ���
	FILE* f = nullptr;
	fopen_s(&f, "data.txt", "w");
	shared_ptr<FILE> filePtr(f, CloseFile);
	if (nullptr == filePtr)
		cerr << "Error opening file." << endl;
	else
	{
		cout << "File opened." << endl;
		// Use filePtr
	}

	system("pause");
	return 0;
}