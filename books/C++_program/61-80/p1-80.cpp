#include<iostream.h>
//���庯����������ĺͺ�ƽ��ֵ
void calculate(int a[],int size,int& sum,float& average)
{
    sum=0;
    for (int i=0;i<size;i++) {
        sum+=a[i];
    }
    average=sum/size;
}
//������ʾ����ĺ���
void put_arr(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
main()
{
    //�������鲢��ʼ��
    int asize,bsize;
    int a[]={2,4,6,1,3,5};
    int b[]={1,3,5,7,9,11,13,15};
    
    //��ʾ�����ֵ
    asize=sizeof(a)/sizeof(int);
	cout<<"put_arr(a,asize):"<<endl;
    put_arr(a,asize);
    bsize=sizeof(b)/sizeof(int);
	cout<<"put_arr(b,bsize):"<<endl;
    put_arr(b,bsize);

    //��������ĺͺ�ƽ��ֵ
    float a_ave,b_ave;
    int a_sum,b_sum;
	cout<<"calculate(a,asize,a_sum,a_ave):"<<endl;
    calculate(a,asize,a_sum,a_ave);
    cout<<"a_sum="<<a_sum;
    cout<<" a_ave="<<a_ave<<endl;

	cout<<"calculate(b,bsize,b_sum,b_ave):"<<endl;
    calculate(b,bsize,b_sum,b_ave);
    cout<<"b_sum="<<b_sum;
    cout<<" b_ave="<<b_ave<<endl;
}
