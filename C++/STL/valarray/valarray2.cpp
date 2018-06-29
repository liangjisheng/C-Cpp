// valarray2.cpp -- slice 获取valarray的子数组
#include"iostream"
#include"valarray"

int main() {
	using namespace std;
	int i;
	valarray<int> va(20),vaResult;
	for(i=0;i<20;i++)
		va[i]=2*(i+1);
	cout<<"The operand valarray va is:\n";
	for(i=0;i<20;i++) {
		cout<<va[i]<<' ';
		if(i==9) cout<<endl;
	}
	cout<<endl;

	slice vaSlice(1,7,3);	// 从索引为1开始获取，间隔为3，总共获取7个
	vaResult=va[vaSlice];
	cout<<"\nThe slice of valarray va is va[slice(1,7,3)]:\n";
	for(i=0;i<7;i++)
		cout<<vaResult[i]<<' ';
	cout<<endl;

	// Gslice类的用法和slice基本相同，只是它截取的是循环子串，
	// 当母串进行一次提取后的字串元素数目达不到要求时，
	// gslice会将提取后的母串继续组合进行提取直到满足要求或者母串被提取完了
	return 0;
}