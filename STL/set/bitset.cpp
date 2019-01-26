#include"iostream"
#include"bitset"
//set()       设置所有位为1
//reset()     设置所有位为0
//set(i,bv)   设置b[i]为bv，bv默认为1
//reset(i)    设置b[i]为0
//flip()      改变所有位，0变1，1变0
//flip(i)     改变第i位
//size()      总的位数
//count()     为1的位的个数
//any()       如果所有位为1，则返回真，否则返回假
//none()      如果没有位为1，则返回真，否则返回假
//test(i)     如果b[i]为1,返回真，否则返回假
//to_ulong()  将存储在b中的位串转换成所代表的unsigned long int
//to_string() 将存储在b中的位串转换成所代表的string
using namespace std;
int main()
{
	bitset<15> a;//创建5位二进制数
	cout<<"input a bitset:";
	cin>>a;
	cout<<a<<endl;
	bitset<10> a1(49);//创建10位二进制数，将49存储在其中
    cout<<a1<<endl;
	char bitstring[]="101100111000";
	bitset<16> a2(bitstring),a3(bitstring,3),a4(bitstring,0,4);
	cout<<a2<<endl<<a3<<endl<<a4<<endl;
	return 0;
}