// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RESORCEDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RESORCEDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RESORCEDLL_EXPORTS
#define RESORCEDLL_API __declspec(dllexport)
#else
#define RESORCEDLL_API __declspec(dllimport)
#endif

// This class is exported from the ResorceDLL.dll
class RESORCEDLL_API CResorceDLL {
public:
	CResorceDLL(void);
	// TODO: add your methods here.
};

extern RESORCEDLL_API int nResorceDLL;

RESORCEDLL_API int fnResorceDLL(void);
