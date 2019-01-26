// 获取当前进程句柄
HANDLE WINAPI GetCurrentProcess(void);
Remarks: Retrieves a pseudo handle for the current process.A pseudo handle is a special constant,   
         currently (HANDLE)-1, that is interpreted as the current process handle.

// 将伪进程句柄转换为实际句柄值

// 获取当前线程句柄
HANDLE WINAPI GetCurrentThread(void);
Remarks: Retrieves a pseudo handle for the calling thread.A pseudo handle is a special constant.
         经本人实践,该值为-2.

// 获取进程的退出代码
BOOL WINAPI GetExitCodeProcess(
  __in          HANDLE hProcess,
  __out         LPDWORD lpExitCode
);

// 获取线程的退出代码
BOOL WINAPI GetExitCodeThread(
  __in          HANDLE hThread,
  __out         LPDWORD lpExitCode
);

// 结束本进程
VOID WINAPI ExitProcess(
  __in          UINT uExitCode
);

// 结束其他进程
BOOL WINAPI TerminateProcess(
  __in          HANDLE hProcess,
  __in          UINT uExitCode
);
Note:The handle:hProcess must have the PROCESS_TERMINATE access right.

// 结束本线程
VOID WINAPI ExitThread(
  __in          DWORD dwExitCode
);

// 结束其他线程
BOOL WINAPI TerminateThread(
  __in_out      HANDLE hThread,
  __in          DWORD dwExitCode
);
Note:The handle:hThread must have the THREAD_TERMINATE access right.

// 由Process Handle获取Process Id
DWORD WINAPI GetProcessId(
  __in          HANDLE Process
);
Note:The handle:Process must have the PROCESS_QUERY_INFORMATION access right.

// 获取当前Process Id
DWORD WINAPI GetCurrentProcessId(void);

// 由Thread Handle获取Thread Id
DWORD WINAPI GetThreadId(
  __in          HANDLE Thread
);
Note:This handle:Thread must have the THREAD_QUERY_INFORMATION access right. 

//获取当前Thread Id
DWORD WINAPI GetCurrentThreadId(void);