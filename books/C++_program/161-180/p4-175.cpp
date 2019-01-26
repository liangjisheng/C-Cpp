#include<iostream.h>
#include<string.h>

//��ʾ����ĺ���ģ��
template <class T> void arr_put(T arr[],int size) {
    for (int i=0 ;i<=size;i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}

//ѡ����������ĺ���ģ��
template <class T> void sort(T arr[],int size) {
    T temp;
    int i,j;
    for (i=0;i<size;i++)
        for (j=i+1;j<=size;j++)
            if (arr[i]<=arr[j])
            {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            }
}

//��main()�����в�����������ĺ���ģ��
void main(void)
{
    //��������ģ�崦��int������
    cout<<"int:"<<endl;
    int a[]={1,5,2,7,9,0,10,-1};
    arr_put(a,7);
    sort(a,7);
    arr_put(a,7);

    //��������ģ�崦��double������
    cout<<"double:"<<endl;
    double x[]={1.2,2.1,1.414,1.732};
    arr_put(x,3);
    sort(x,3);
    arr_put(x,3);

    //��������ģ�崦��char��������
    cout<<"char:"<<endl;
    char str[80];
    cout<<"str:";
    cin>>str;
    int size=strlen(str);
    arr_put(str,size);
    sort(str,size);
    arr_put(str,size);
}
