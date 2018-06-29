#include"iostream"
#include"deque"
using namespace std;
int main()
{
	deque<int> d;
	cout<<d.size()<<endl;
	int i;
	for(i=0;i<6;i+=2)
		d.push_front(i),d.push_back(i+1);
	for(i=0;i<d.size();i++)
		cout<<d[i]<<" ";
	cout<<endl;
	d.back()=999;
	d.pop_front();
	deque<int>::iterator It;
	for(It=d.begin();It!=d.end();It++)
		cout<<*It<<" ";
	cout<<endl;
	while(!d.empty())
		cout<<d.back()<<" ",d.pop_back();
	cout<<endl;
	return 0;
}