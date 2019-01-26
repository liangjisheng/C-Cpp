#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>      // for put_time()

using namespace std;
using namespace std::chrono;


int main()
{
	// Get current time as a time_point
	system_clock::time_point tpoint = system_clock::now();
	// Convert to a time_t
	time_t tt = system_clock::to_time_t(tpoint);
	// Convert to local time
	tm t;
	localtime_s(&t, &tt);
	// Write the time to the console
	cout << put_time(&t, "%H:%M:%S") << endl;

	return 0;
}
