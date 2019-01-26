#include <stdio.h>
#include <climits>

using namespace std;

#define LOG(...) {\
    fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

int main()
{
    int x = 3;
    LOG("x = %d", x);

    long long ll_min = LLONG_MIN;
    long long ll_max = LLONG_MAX;
    unsigned long long ull_max = ULLONG_MAX;

    printf("min of long long: %lld\n", ll_min);
    printf("max of long long: %lld\n", ll_max);
    printf("max of unsigned long long: %llu\n", ull_max);

    return 0;
}
