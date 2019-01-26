#include"stdio.h"
#include"windows.h"

int main() 
{
	// 调节CPU忙闲比例，可以控制单核CUP使用比例
	const DWORD busyTime=10; // 10 毫秒，接近windows的调度时间片
	const DWORD idleTime=10; // 忙闲相同，使CPU使用率达到50%
	DWORD startTime=0;
	while(true) {
		startTime=GetTickCount(); // 获取系统启动到现在所经历的毫秒数
		// busy loop
		while( (GetTickCount()-startTime) <= busyTime);
		// idle loop
		Sleep(idleTime);
	}
	return 0;
}