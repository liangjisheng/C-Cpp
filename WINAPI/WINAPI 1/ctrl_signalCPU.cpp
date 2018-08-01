// C++ code to make manager sine graph
#include"stdio.h"
#include"stdlib.h"
#include"windows.h"
#include"math.h"

// 把一条正弦曲线0~2*PI之间的弧度等分成200份进行抽样，计算每个抽样点的振幅
// 然后每隔300ms的时间取下一个抽样点，并让CPU工作对应振幅的时间

const int SAMPLING_COUNT=200; // 抽样点的数量
const double PI=3.1415926;
const int TOTAL_AMPLITUDE=50;// 每隔抽样点对应的时间片

int main() {
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude=TOTAL_AMPLITUDE/2;
	double radian=0.0;
	double radianIncrement=2.0/(double)SAMPLING_COUNT;// 抽样点弧度的增量
	for(int i=0;i<SAMPLING_COUNT;i++) {
		busySpan[i]=(DWORD)(amplitude+(sin(PI*radian)*amplitude));
		radian+=radianIncrement;
	}
	DWORD startTime=0;
	for(int j=0;;j=(j+1)%SAMPLING_COUNT) {
		startTime=GetTickCount();
		while((GetTickCount()-startTime)<=busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE-busySpan[j]);
	}

	return 0;
}