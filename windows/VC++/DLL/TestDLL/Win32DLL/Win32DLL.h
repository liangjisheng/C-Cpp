// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WIN32DLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WIN32DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WIN32DLL_EXPORTS
#define WIN32DLL_API  __declspec(dllexport)
#else
#define WIN32DLL_API  __declspec(dllimport)
#endif

// This class is exported from the Win32DLL.dll
class WIN32DLL_API CWin32DLL {
public:
	CWin32DLL(void);
	// TODO: add your methods here.
    int Add(int x, int y);
};

extern WIN32DLL_API int nWin32DLL;

extern "C" WIN32DLL_API int GetValue(void);
