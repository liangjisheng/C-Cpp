
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MY1074_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MY1074_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef MY1074_EXPORTS
#define MY1074_API __declspec(dllexport)
#else
#define MY1074_API __declspec(dllimport)
#endif

// This class is exported from the 1074.dll
class MY1074_API CMy1074 {
public:
	CMy1074(void);
	// TODO: add your methods here.
};

extern MY1074_API int n;

MY1074_API int fnMy1074(void);

