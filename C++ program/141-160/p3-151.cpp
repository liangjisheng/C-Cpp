#include<iostream.h>
#include <time.h>

//main()�����Ķ���
void main(void)
{
    //����time_t���͵ı�����������Ϊ��λ���ϵͳʱ��
    time_t current_time;

    //�õ���ǰ��ϵͳʱ�䣨�룩
    time(&current_time); 

    //ת��ϵͳʱ��Ϊtm�ṹ��ʱ����Ϣ
    tm  *ptime=gmtime(&current_time);

    //��ʾtime_t�ṹ��ʱ��
    cout<<"current_time:"<<current_time<<endl;

    //��ʾtm�ṹ��ʱ����Ϣ
    cout<<"seconds after the minute:"<<(ptime->tm_sec)<<endl;
    cout<<"minutes after the hour:"<<(ptime->tm_min)<<endl; 
    cout<<"hours since midnight:"<<(ptime->tm_hour)<<endl;  
    cout<<"day of the month:"<<(ptime->tm_mday)<<endl;  
    cout<<"months since January:"<<(ptime->tm_mon)<<endl; 
    cout<<"years since 1900:"<<(ptime->tm_year)<<endl; 
    cout<<"days since Sunday:"<<(ptime->tm_wday)<<endl; 
    cout<<"days since January 1:"<<(ptime->tm_yday)<<endl; 
    cout<<"daylight savings time flag:"<<(ptime->tm_isdst)<<endl;
}
