#include<iostream.h>
#include <time.h>

//ʱ���ӳٺ���
void Dtime(int dt) {
    time_t current_time;
    time_t start_time;
    // �õ���ʼʱ��
    time(&start_time); 
    do 
    {
      time(&current_time);
    } 
    while ((current_time - start_time) < dt);
}

//main()�����Ķ���
void main(void)
{
    cout<<"The First information!"<<endl;
    cout<<"About to delay 5 seconds"<<endl;
    Dtime(5);
    cout<<"The Second information!"<<endl;
}
