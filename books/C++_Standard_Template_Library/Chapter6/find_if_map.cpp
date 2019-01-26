
// 使用全局的find_if()算法来查找具有特定value的元素
#include <iostream>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::find_if;
using std::pair;

// function object to check the value of a map element
template<class K, class V>
class value_equals
{
private:
	V Value;
public:
	// constructor (initialize value to compare with)
	value_equals(const V& v) : Value(v) {}

	// comparison
	bool operator() (pair<const K, V> elem)
	{
		return elem.second == Value;
	}
};

int main()
{
	typedef map<float, float> FloatFloatMap;
	FloatFloatMap coll;
	FloatFloatMap::iterator pos;

	// fill container
	coll[1] = 7;
	coll[2] = 4;
	coll[3] = 2;
	coll[4] = 3;
	coll[5] = 6;
	coll[6] = 1;
	coll[7] = 3;

	// search an element with key 3.0
	pos = coll.find(3.0);
	if (pos != coll.end())
		cout << pos->first << ": " << pos->second << endl;

	// search an element with value 3.0
	pos = find_if(coll.begin(), coll.end(),
			value_equals<float, float>(3.0));
	if (pos != coll.end())
		cout << pos->first << ": " << pos->second << endl;

	system("pause");
	return 0;
}