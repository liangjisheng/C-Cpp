#include<iostream.h>
#include<conio.h>
#include <time.h>

//����ʱ���ӳٺ���
void Dtime(double dt) {
    time_t current_time;
    time_t start_time;

    // �õ���ʼʱ��
    time(&start_time);
    //�ӳٴ���
    do 
    {
      time(&current_time);
    } 
    while (difftime(current_time,start_time)<dt);
}

//����̨������ʾ
void cputs_show(int n) {
    time_t current_time;
    char *timep;
    cputs("Show time with cputs\n");

    for(int i=0;i<5;i++) {
        time(&current_time);
        timep=ctime(&current_time);
        cputs(timep);
        Dtime(n);
    }
}

//cout������ʾ
void cout_show(int n) {
    time_t current_time;
    char *timep;
    cout<<"Show time with cout"<<endl;

    for(int i=0;i<5;i++) {
        time(&current_time);
        timep=ctime(&current_time);
        cout<<timep;
        Dtime(n);
    }
}

//main()�����Ķ���
void main(void)
{
    cputs_show(1);
    cout_show(1);
}
