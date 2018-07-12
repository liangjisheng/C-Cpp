效用算子就是带参数的操纵算子，一个效用算子就是一个简单的类，

这个类的构造函数与工作在这个类里的一个重载操作符"<<"一起执行

想要的操作。下面是一个有两个效用算子的例子。第一输出的是

被截断的字符串，第二个打印的是一个二进制数。如下：

#include"effector.h"

int main(int argc,char* argv[])
{
	char* string="Things that make us happy,make us wise";
	for(int i=1;i<=strlen(string);i++)
		cout<<fixw(string,i)<<endl;
	ulong x=0xFEDCBA98UL;
	ulong y=0x76543210UL;
	cout<<"x in binary: "<<bin(x)<<endl;
	cout<<"y in binary: "<<bin(y)<<endl;
	return 0;
}



//效用算子头文件
//: EFFECTOR.CPP--Jerry Schwarz's "effectors" 效用算子

#include"iostream.h"
#include"stdlib.h"
#include"string.h"
#include"assert.h"
#include"limits.h"	//ULONG_MAX

//Put out a portion of a string:
class fixw{
	char* s;
public:
	fixw(const char*,int);
	~fixw();
	friend ostream& operator<<(ostream&,fixw&);
};

fixw::fixw(const char* S,int width){
	s=(char*)malloc(width+1);
	assert(s);
	strncpy(s,S,width);
	s[width]=0;	//Null-terminate
}

fixw::~fixw(){free(s);}

ostream& operator<<(ostream& os,fixw& fw){
	return os<<fw.s;
}

//Print a number in binary
typedef unsigned long ulong;

class bin{
	ulong n;
public:
	bin(ulong N);
	friend ostream& operator<<(ostream&,bin&);
};

bin::bin(ulong N){n=N;}

ostream& operator<<(ostream& os,bin& b){
	ulong bit=-(ULONG_MAX>>1);	//Top bit set
	while(bit){
		os<<(b.n & bit?'1':'0');
		bit>>=1;
	}
	return os;
}