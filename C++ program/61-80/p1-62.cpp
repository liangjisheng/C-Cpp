#include<iostream.h>
main()  
{
    //����ṹ���ͣ���Ϊ�����Ľṹ��������ֵ
    struct s_tag {
           short    i;
           float x;
    } sx={100,3.1416};

    //�����������ͣ���Ϊ���������ϱ�������ֵ
    union   u_tag  {
            short    i;
            float x;
    } ux={1000};

    //����ṹ���ͺͽṹ�������й���Ϣ
    cout<<"sizeof(struct s_tag)="<<sizeof(struct s_tag)<<endl;
    cout<<"sx.i="<<sx.i<<endl;
    cout<<"sx.x="<<sx.x<<endl;
    cout<<"sizeof(sx)="<<sizeof(sx)<<endl;
    cout<<"------------------------------"<<endl;

    //����������ͺ����ϱ������й���Ϣ
    cout<<"sizeof(union u_tag)="<<sizeof(union u_tag)<<endl;
    ux.i=200;
    cout<<"ux.i="<<ux.i<<endl;  //������ϱ���ux ��i��Ա
    ux.x=123.456;
    cout<<"ux.x="<<ux.x<<endl;  //������ϱ���ux ��x��Ա
    cout<<"sizeof(ux)="<<sizeof(ux)<<endl;
}
