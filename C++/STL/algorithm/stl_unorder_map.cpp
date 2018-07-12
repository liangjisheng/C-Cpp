
#include<iostream>
#include<string>
#include<unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

int main()
{
	unordered_map<string, string> mymap = 
	{
		{ "house", "maison" },
		{ "apple", "pomme" },
		{ "tree", "arbre" },
		{ "book", "livre" },
		{ "door", "porte" },
		{ "grapefruit", "pamplemousse" }
	};

	unsigned n = mymap.bucket_count();
	cout << "mymap has " << n << " buckets\n";
	for (unsigned i = 0; i < n; ++i)
	{
		cout << "bucket #" << i << " contains: ";
		for (auto it = mymap.begin(i); it != mymap.end(i); ++it)
			cout << "[" << it->first << ":" << it->second << "]";
		cout << endl;
	}

	system("pause");
	return 0;
}