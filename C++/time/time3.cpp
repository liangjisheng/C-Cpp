//��õ�ǰ�ļ���Ƶ�ʣ���ÿ����ж��ٴμ���
// QueryPerformanceFrequency(&limtp);

//��õ�ǰ��������������cpu����
//QueryPreformanceCounter(&limtp);

#include"ctime"
#include"iostream"
using namespace std;

int main() {
	time_t s,e,time;
	s=clock();
	for(int i=0;i<50000;i++)
		cout<<i<<" ";
	cout<<endl;
	e=clock();
	time=e-s;
	cout<<endl<<"time:"<<time<<endl;
	system("pause");

	return 0;
}