##include<iostream.h>
main()
{
    //��������ͱ���
    int a[5],i,sum;
    double avg;
	
    //�Ӽ�����ѭ��Ϊ���鸳ֵ
    for (i=0;i<5;i++) {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }

    //ֱ����ʾ����Ԫ��
    cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
    
    //����forѭ����ʾ�����Ԫ�ص�ֵ
    for (i=0;i<5;i++)
        cout<<a[i]<<"  ";
    cout<<endl;

    //��������Ԫ��֮��,����ʾ������
    sum=a[0]+a[1]+a[2]+a[3]+a[4];
    cout<<"sum="<<sum<<endl;

    //����ѭ������������ۼӺ�
    for (sum=0,i=0;i<5;i++)
        sum+=a[i];

    //��ʾ�ۼӺͼ�ƽ��ֵ
    cout<<"sum="<<sum<<endl;
    avg=sum/5.0;
    cout<<"avg="<<avg<<endl;
}
