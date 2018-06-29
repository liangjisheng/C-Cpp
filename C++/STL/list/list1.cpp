#include"iostream"
#include"list"
using namespace std;
int main()
{
	int i,a[]={15,36,7,17};
	list<int>::iterator It;
	list<int>L1,L2,L3(a,a+4);
	for(i=1;i<=6;i++)
		L1.push_back(i);
	for(i=1;i<=3;i++)
		L2.push_back(i);
	It=L1.begin();advance(It,2);//It指向第三个元素3
	L1.splice(It,L2);
	L2.splice(L2.begin(),L1,It);//It仍指向3，此时3为第6个元素
	L1.remove(20);
	L1.sort();
	L1.merge(L3);
	L1.push_front(L2.front());
	L1.reverse();
	cout<<"L1=";
	for(It=L1.begin();It!=L1.end();It++)
		cout<<*It<<" ";
	cout<<endl<<"L2=";
	for(It=L2.begin();It!=L2.end();It++)
		cout<<*It<<" ";
	cout<<endl;
	return 0;
}


//标准list类模板是双向循环链表
#include"iostream"
using namespace std;
#include"list"
#include"algorithm"//标准算法
template<typename T>
ostream & operator<<(ostream &out,list<T> l)//重载list<T>输出运算符，作为模板
{
	for(list<T>::iterator i=l.begin();i!=l.end();i++)
		out<<*i<<" ";
	out<<endl;
	return out;
}
int main()
{
	//构造函数
	//list<T> l; list<T> l(n); list<T> l(n,initval); list<T> l(fPtr,lPtr);
	list<int> l,l1(4,11),l2(6);
	cout<<"l:"<<l<<"size= "<<l.size()<<endl;//输出l以及获取l的大小
	cout<<"l1:"<<l1<<"size= "<<l1.size()<<endl;
	cout<<"l2:"<<l2<<"size= "<<l2.size()<<endl;
	int b[]={2,22,222,2222};
	list<int> l3(b,b+4);
	cout<<"l3:"<<l3<<endl;
    //赋值
	cout<<"Assignments l=l3 and l2=l3:"<<endl;
	l=l3;
	l2=l3;
	cout<<"l:"<<l<<"size= "<<l.size()<<endl;
	cout<<"l2:"<<l2<<"size= "<<l2.size()<<endl;
    //插入列表元素
	cout<<"Insert in l1:"<<endl;
	list<int>::iterator i;
	i=l1.begin();i++;i++;
	l1.insert(i,66666);//在l1中i位置插入66666
	cout<<l1<<endl;
	l1.insert(i,3,555);//在l1中i位置插入3个555
	cout<<l1<<endl;
	l1.push_back(888);//在l1最后插入888
	l1.push_front(111);//在l1开始插入111
	cout<<l1<<endl;
    //删除列表元素
	cout<<"Erases in l1:"<<endl;
	i=find(l1.begin(),l1.end(),66666);//在l1中查找66666所在的位置
	if(i!=l1.end())
	{cout<<"66666 found --will erase it"<<endl;l1.erase(i);}
	else 
		cout<<"66666 not found."<<endl;
	cout<<l1<<endl;
	i=l1.begin();i++;
	list<int>::iterator j=l1.end();
	--j;--j;i=--j;i--;i--;
	l1.erase(i,j);//删除l1中从位置i到位置j的所有元素
	cout<<l1<<endl;
	l1.pop_back();//删除最后一个元素
	l1.pop_front();//删除第一个元素
	cout<<l1<<endl;
    //反转链表
	cout<<"Reverse l3:"<<endl;
	l3.reverse();
	cout<<l3<<endl;
    //对列表排序
	cout<<"Sort l1"<<endl;
	l1.sort();
	cout<<l1<<endl;
    //合并两个列表
	cout<<"Sort l3,and then merge l1 and l3:"<<endl;
	l3.sort();l1.merge(l3);
	cout<<"l1: "<<l1<<endl;
	cout<<"l3: "<<l3<<endl;
    //粘贴一个列表到另一个列表中
	cout<<"Splice l2 into l at second position:"<<endl;
	i=l1.begin();i++;
	l.splice(i,l2);
	cout<<"l: "<<l<<endl;
	cout<<"l2: "<<l2<<endl;
    //在l1列表全部范围中删除22元素
	cout<<"Remove 22s form l:"<<endl;
	l.remove(22);
	cout<<l<<endl;
    //删除列表中重复的元素
	cout<<"Unique applied to l1:"<<endl;
	l1.unique();
	cout<<l1<<endl;
    
	//析构函数~list();
	return 0;
}