#include<iostream.h>
#include<string.h>

//��ʾ����ĺ���ģ��
template <class T> void arr_put(T arr[],int size) {
    for (int i=0 ;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//ѡ�񷨶���������ĺ���ģ��
template <class T> void sort(T arr[],int size) {
    T temp;
    int i,j;
    for (i=0;i<size-1;i++)
        for (j=i+1;j<size;j++)
            if (arr[i]>arr[j])
            {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            }
}

//���ֲ��ҷ��ĺ���ģ��
template <class T> int binary_search(T array[], T value, int size)
{
    int found = 0;
    int high = size, low = 0, mid;

    mid = (high + low) / 2;

    cout<<"Looking for "<<value<<endl;
    while ((! found) && (high >= low))
    {
      if (value == array[mid])
        found = 1;
      else if (value < array[mid])
        high = mid - 1;
      else
        low = mid + 1;
        mid = (high + low) / 2;
    }
    return((found) ? mid: -1);
}

//main()������ʹ�ô�������ĺ���ģ��
void main(void)
{
    //����int������
    int array[10]={1,3,5,7,9,2,4,6,8,10};
    
    //��ʾ�����ֵ
    arr_put(array,10);
	
    //������������ʾ
    sort(array,10);
    arr_put(array,10);

    //��������
    cout<<"Result of search: "<<binary_search(array, 3, 10)<<endl;
    cout<<"Result of search: "<<binary_search(array, 2, 10)<<endl;
    cout<<"Result of search: "<<binary_search(array, 9, 10)<<endl;
    cout<<"Result of search: "<<binary_search(array, 5, 10)<<endl;
    cout<<"------------------------------"<<endl;

    //�����ַ���������
    char ch1,str[]="happy";
    int size=strlen(str);
    
    //��ʾ�����ֵ
    arr_put(str,size);
	
    //������������ʾ
    sort(str,size);
    arr_put(str,size);

    //��������
    cout<<"Input a char:";
    cin>>ch1;
    cout<<"Result of search: "<<binary_search(str, ch1, size)<<endl;
}
