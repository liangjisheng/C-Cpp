#include"stdio.h"
#include"stdlib.h"
#include"windows.h"

int main() {
	_PROCESSOR_POWER_INFORMATION info;
	CallNTPowerInformation(11,		// query porcessor power information
		NULL,	// no input buffer
		0,		// input buffer size is 0
		&info,	// output buffer
		sizeof(info));// output buffer size
	DWORD t_begin=GetCPUTickCount();
	int *a=new int[10000000];
	for(int i=0;i<10000000;i++)
		a[i]=i;
	DWORD t_end=GetCPUTickCount();
	double millisec=(double)(t_end-t_begin)/(double)info.CurrentMhz;
	printf("used time:%lf\n",millisec);

	return 0;
}
