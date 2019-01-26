
#include <iostream>
#include <bitset>
#include <string>
#include <limits>

using namespace std;

int main()
{
	// print some numbers in binary representation
	cout << "267 as binary short: "
		<< bitset<numeric_limits<unsigned short>::digits>(267) << endl;

	cout << "267 as binary long: "
		<< bitset<numeric_limits<unsigned long>::digits>(267) << endl;

	cout << "10000000 with 24 bits: "
		<< bitset<64>((unsigned long long)1e7) << endl;

	// transform binary representation into integral number
	cout << "\"1000101011\" as number: "
		<< bitset<100>(string("1000101011")).to_ulong() << endl;
	
	system("pause");
	return 0;
}