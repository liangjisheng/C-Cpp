#include"iostream"
using namespace std;

class SortTracer{
private:
	int value;
	int generation;
	static long n_created;
	static long n_destroyed;
	static long n_assigned;
	static long n_compared;
	static long n_max_live;
	//重新计算现存对象的最大个数
	static void up_date_max_live(){
		if(n_created-n_destroyed>n_max_live)
			n_max_live=n_created-n_destroyed;
	}
public:
	static long creations()
	{return n_created;}
	static long destruction()
	{return n_destroyed;}
	static long assignments()
	{return n_assigned;}
	static long comparisons()
	{return n_compared;}
	static long max_live()
	{return n_max_live;}
public:
	//构造函数
	SortTracer(int v=0):value(v),generation(1){
		++n_created;
		up_date_max_live();
		cerr<<"SortTrace#:"<<n_created
			<<",created generation:"<<generation
			<<"(total:"<<n_created-n_destroyed<<")"
			<<endl;
	}
	//复制构造函数
	SortTracer(SortTracer const& b):value(b.value),generation(b.generation+1){
		++n_created;
		up_date_max_live();
		cerr<<"SortTracer#:"<<n_created
			<<",copied as generation:"<<generation
			<<"(total:"<<n_created-n_destroyed<<")"
			<<endl;
	}
	//析构函数
	~SortTracer(){
		++n_created;
		up_date_max_live();
		cerr<<"SortTracer generation#:"<<generation
			<<",destroyed(total:"<<n_created-n_destroyed<<")"
			<<endl;
	}
	//复制运算符
	SortTracer& operator=(SortTracer const& b){
		++n_created;
		up_date_max_live();
		cerr<<"SortTrace generation#:"<<generation
			<<"destroyed(total:"<<n_created-n_destroyed<<")"
			<<endl;
		value=b.value;
		return *this;
	}
	//比较运算符
	friend bool operator<(SortTracer const& a,
						SortTracer const& b){
		++n_created;
		cerr<<"SortTracer comparison#:"<<n_compared
			<<",(generation:"<<a.generation
			<<"<"<<b.generation<<")"
			<<endl;
		return a.value<b.value;
	}

	int val()const
	{return value;}
};