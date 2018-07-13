
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MY1095_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MY1095_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef MY1095_EXPORTS
#define MY1095_API __declspec(dllexport)
#else
#define MY1095_API __declspec(dllimport)
#endif

// This class is exported from the 1095.dll
class MY1095_API CMy1095 {
public:
	CMy1095();
	void print()
	{ printf("lishuyu\n"); }
	// TODO: add your methods here.
};

extern MY1095_API int nMy1095;

MY1095_API int fnMy1095(void);

