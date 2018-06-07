// useDMA.cpp -- inheritance,friends and DMA
#include"iostream"
#include"dma.h"

int main() 
{
	using std::cout;
	using std::endl;

	base shirt("Portabelly",8);
	lackDMA balloon("red",4,"Blimpo");
	hasDMA mp("Mercator",5,"Buffalo Keys");
	cout<<shirt<<endl;
	cout<<balloon<<endl;
	cout<<mp<<endl;
	lackDMA balloon2(balloon);
	hasDMA mp2;
	mp2=mp;
	cout<<balloon2<<endl;
	cout<<mp2<<endl;
	return 0;
}