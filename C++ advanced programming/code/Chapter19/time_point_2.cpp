#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	using namespace std::chrono;

	system_clock::time_point now = system_clock::now();
	time_t last = system_clock::to_time_t(now - hours(24));
	time_t next = system_clock::to_time_t(now + hours(24));

	tm lastTm, nextTm;
	localtime_s(&lastTm, &last);
	localtime_s(&nextTm, &next);

	cout << "One day ago, the time was "
		<< put_time(&lastTm, "%F %T") << endl;
	cout << "Next day, the time was "
		<< put_time(&nextTm, "%F %T") << endl;

	return 0;
}
