#include<iostream.h>
#include<math.h>   //��Ԥ����ָ�����
const double HD=3.1415926/180;
main() {
    cout<<"x\tsin(x)"<<endl;
    for (int i=0;i<=180;i=i+30) 
        cout<<i<<"\t"<<sin(i*HD)<<endl;
}
