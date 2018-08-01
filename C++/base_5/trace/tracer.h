#include"iostream"
using namespace std;

class SortTracer{
	int value;		// 要被排序的整数值
	int generation;	// 产生拷贝的份数
	static long n_created;	//调用构造函数的次数
	static long n_destroyed;	// 调用析构函数的次数
	static long n_assigned;	//赋值的次数
	static long n_compared;	// 比较的次数
	static long n_max_live;	// 现存对象的最大个数
	// 重新计算现存对象的最大个数
	static void update_max_live() {
		if(n_created-n_destroyed > n_max_live)
			n_max_live=n_created-n_destroyed;
	}
public:
	static long creations()
	{ return n_created; }
	static long destructions()
	{ return n_destroyed; }
	static long assignments()
	{ return n_assigned; }
	static long comparisions()
	{ return n_compared; }
	static long max_live()
	{ return n_max_live; }

public:
	SortTracer(int v=0) : value(v),generation(1) {
		++n_created;
		update_max_live();
		cerr<<"SortTracer # "<<n_created
			<<", created generation "<<generation
			<<" (total: "<<n_created-n_destroyed<<")\n";
	}
	SortTracer(SortTracer const& b) 
		: value(b.value),generation(b.generation+1) {
		++n_created;
		update_max_live();
		cerr<<"SortTracer # "<<n_created
			<<", copied as generation "<<generation
			<<" (total: "<<n_created-n_destroyed<<")\n";
	}

	~SortTracer() {
		++n_destroyed;
		update_max_live();
		cerr<<"SortTracer generation "<<generation
			<<" destroyed (total: "
			<<n_created-n_destroyed<<")\n";
	}

	SortTracer& operator=(SortTracer const& b) {
		++n_assigned;
		cerr<<"SortTracer assignments # "<<n_assigned
			<<" (generation "<<generation
			<<" = "<<b.generation<<")\n";
		value=b.value;
		return *this;
	}

	friend bool operator< (SortTracer const& a,
		SortTracer const& b) {
		++n_compared;
		cerr<<"SortTracer comparison # "<<n_compared
			<<" (generation "<<a.generation
			<<" < "<<b.generation<<")\n";
		return a.value<b.value;
	}

	int val() const
	{ return value; }
};
