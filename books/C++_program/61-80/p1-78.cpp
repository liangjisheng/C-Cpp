#include<iostream.h>
//�ú���ԭ������Ҫʹ�õĺ���
void show_array1(int*,int);
void show_array2(int a[],int);
void sort(int*,int);
main()
{
    //�������鲢��ʼ��
    int a[]={2,4,6,1,3,5};
    int b[3][3]={{2,4,6},{1,3,5},{0,1,2}};
    
    //��ʾ�����ֵ
    cout<<"show_array1(int*,int):"<<endl;
    show_array1(a,6);
    show_array1(&b[0][0],3*3);

    //��sort1������ʾ
    cout<<"sort(int*,int) and show_array1(int*,int): "<<endl;
    sort(a,6);
    show_array1(a,6);
    sort(&b[0][0],3*3);
    show_array1(&b[0][0],9);

    //��ʾ�����ֵ
    cout<<"show_array2(int a[],int):"<<endl;
    show_array2(a,6);
    show_array2(&b[0][0],3*3);
}

//��ʾ����,��ָ�뵱����
void show_array1(int *p,int size) {
    for(int i=0;i<size;i++)
        cout<<*(p+i)<<" ";
    cout<<endl;
}

//��ʾ����,�����鵱����
void show_array2(int a[],int size) {
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}   

//�����鰴�Ӵ�С˳������
void sort(int *p,int size) {
    int t;
    for (int i=0;i<size-1;i++)
        for (int j=i+1;j<size;j++)
            if (*(p+i)<=*(p+j))
            {
               t=*(p+i);
               *(p+i)=*(p+j);
               *(p+j)=t;
            }
}
