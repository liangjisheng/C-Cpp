// Calculating primes 前100个素数
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main()
{
	const int MAX(100);				// Number of primes required
	long primes[MAX] = { 2,3,5 };	// First three primes defined
	long trial(5);					// Candidate primes
	int count(3);					// Count of primes found
	bool found(false);				// Indicates when a prime is found

	do {
		trial += 2;
		found = false;
		for (int i = 0; i < count; i++)
		{
			found = (trial % *(primes + i)) == 0;
			if (found) break;
		}
		if (!found) *(primes + count++) = trial;
	} while (count<MAX);

	// Output primes 5 to a line
	for (int i = 0; i < MAX; i++)
	{
		cout << setw(10) << *(primes + i);
		if ((i + 1) % 5 == 0) cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}