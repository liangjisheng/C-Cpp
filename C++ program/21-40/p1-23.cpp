#include <iostream.h>
main()
{
    float a,b,s;

    cout<<"a b"<<endl;
    cin>>a>>b;	   //����cin�Ӽ�����Ϊ���� a,b ��ֵ
    s=a;
    if (a<b) {
       s=b;         //if�����ֻ����һ����䣬��ʡ�Ի�����
    }
    s=s*s;          //����s�б���a,b�нϴ��һ������ƽ��
    cout<<"s="<<s;
}

