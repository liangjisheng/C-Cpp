#include<iostream.h>
#include<conio.h>
#include <time.h>

//����ʱ���ӳٺ���
void Dtime(double dt) {
    time_t current_time;
    time_t start_time;

    //�õ���ʼʱ��
    time(&start_time);
    //�ӳٴ���
    do 
    {
      time(&current_time);
    }
    while (difftime(current_time,start_time)<dt);
}

//main()�����Ķ���
void main(void)
{
    //��������
    int i;
    time_t current_time;
    char *timep;
    //ѭ��10�Σ�ÿ��2����ʾһ��ʱ��
    for(i=0;i<10;i++) {
        time(&current_time);
        timep=ctime(&current_time);
        cputs(timep);
        Dtime(2);
    }
}
