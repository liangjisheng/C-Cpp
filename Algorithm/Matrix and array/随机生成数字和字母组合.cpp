// 求一种快速生成随机数的算法，问题如下:
// 从0~9、a-z中随机抽取18个字符组成一个18位随机数，
// 一共需要生成10亿个这样的随机数，然后把这些随机数写入文件，
// 算法需要尽量快速，本算法需解决的两个最大的问题就是：
// 1、10亿数据量的规模对算法速度和文件存储方式的要求。
// 2、生成不重复数据的算法。

// 知道这个随机的要求是什么,是要完全的随机,还是可以是一个建立在某种算法上的随机序列? 
// 如果是后者的话,需要找一个大于10亿的与10^18互质的一个数M(可以随机产生一个这样的数),
// 然后再随机一个起始项S, 

// S % 10^18为第一个数,S+M % 10^18为第二个数......S + (10^9 - 1) * M % 10^18 
// 为第10亿个数

// 还是用1~8和b~y比较快一些,毕竟是32个字符,用二进制比较好表示,速度也更有保证. 
// 可以利用本原多项式来生成. 
// 考虑模2的89阶本原多项式即可. p(x)=x^89+x^6+x^5+x^3+1.

#include"cstdlib"
#include"iostream"
#include"windows.h"
using namespace std;

char map2char[]={'1','2','3','4','5','6','7','8','9','b','c',
				'd','e','f','g','h','i','j','k','l','m','n',
				'o','p','q','r','s','t','u','v','w','x','y'};
void getbit(unsigned e,char *s,int offset) {
	int i=17;
	while(i>=0) {
		s[18*offset+i]=((e>>i)&1);
		--i;
	}
}

int main(int argc,char *argv[]) {
	srand(GetTickCount());
	char bit[90],S[90];
	for(int i=0;i<sizeof(bit);i++) 
		bit[i]=0,S[i]=0;
	unsigned x,T;
	for(int k=0;k<5;k++) {
		do { x=rand(); }while(x==0);
		getbit(x,S,k);
		getbit(x,bit,k);
	}
	unsigned head=89;
	unsigned j=0,time=GetTickCount(),Max=10000;
	do {
		++j;
		T=(bit[head]&1)^(bit[(head-83)%90]&1)^(bit[(head-84)%90]&1)
			^(bit[(head-86)%90]&1)^(bit[(head-89)%90]&1);
		bit[head]=T;
		head=(head+1)%90;
		for(int index=0;index<18;index++) {
			int num=0;
			for(int j=0;j<5;j++)
				num+=(bit[(head+5*index+j)%90]==0) ? 0 : (1<<j);
			cout<<map2char[num];
		}
		cout<<endl;
	}while(j<Max);
	cout<<"time: "<<GetTickCount()-time<<" ms!"<<endl;

	system("PAUSE");
	return 0;
}