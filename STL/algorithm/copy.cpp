#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

// template<class InputIterator,class OutputIterator>
// OutputIterator copy(InputIterator first,InputIterator last,
//		OutputIterator result);

void print(int n) { cout<<n<<' '; }

int main()
{
	vector<int> vecScore1,vecScore2;
	vecScore1.push_back(23);
	vecScore1.push_back(33);
	vecScore1.push_back(43);
	vecScore1.push_back(53);
	vecScore2.push_back(23);
	vecScore2.push_back(56);
	vecScore2.push_back(67);
	vecScore2.push_back(78);
	vector<int> vecScore;
	vecScore.resize(vecScore1.size()+vecScore2.size());
	
	vector<int>::iterator lastit=copy(vecScore1.begin(),
		vecScore1.end(),vecScore.begin());
	copy(vecScore2.begin(),vecScore2.end(),lastit);
	for_each(vecScore.begin(),vecScore.end(),print);
	cout<<endl;

	system("pause");
	return 0;
}