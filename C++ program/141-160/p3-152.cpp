#include<iostream.h>
#include <time.h>

//main()�����Ķ���
void main(void)
{
    //��������
    time_t current_time;

    //�õ���ǰϵͳʱ��
    time(&current_time);
	
    //ת��ϵͳʱ��Ϊtm�ṹ
    tm  *ptime=gmtime(&current_time);

    //ת��time_t���͵�ʱ���ַ�������ʾ
    char *timep=ctime(&current_time);
    cout<<"ctime(&current_time):"<<endl;
    cout<<timep;

    //ת��tm���͵�����ת��Ϊʱ���ַ�������ʾ
    char *tmp=asctime(ptime);
    cout<<"asctime(ptime):"<<endl;
    cout<<timep;
}
