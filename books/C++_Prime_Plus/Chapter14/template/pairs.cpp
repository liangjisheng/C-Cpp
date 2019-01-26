// implement of pairs template
#include"iostream"
#include"string"
#include"pairs.h"

int main() 
{
	using std::cout;
	using std::endl;
	using std::string;

	Pairs<string,int> ratings[4]={
		Pairs<string,int>("The Purple Duke",5),
		Pairs<string,int>("Jake's Frisco Al Fresco",4),
		Pairs<string,int>("Mont Souffle",5),
		Pairs<string,int>("Gertie's Eats",3)
	};
	int joints=sizeof(ratings) / sizeof(Pairs<string,int>);
	cout<<"Rating:\tEatery\n";
	for(int i=0;i<joints;i++)
		cout<<ratings[i].second()<<":\t"
		<<ratings[i].first()<<endl;
	ratings[3].first()="lishuyu";
	ratings[3].second()=6;
	cout<<ratings[3].second()<<":\t"
		<<ratings[3].first()<<endl;
	return 0;
}