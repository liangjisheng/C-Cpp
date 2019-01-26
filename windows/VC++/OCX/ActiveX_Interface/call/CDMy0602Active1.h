// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "D:\\vs2010_projects\\0602Active1\\Debug\\0602Active1.ocx" no_namespace
// CDMy0602Active1 wrapper class

class CDMy0602Active1 : public COleDispatchDriver
{
public:
	CDMy0602Active1(){} // Calls COleDispatchDriver default constructor
	CDMy0602Active1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDMy0602Active1(const CDMy0602Active1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _DMy0602Active1 methods
public:
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	CString GetLiveHeadPath()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// _DMy0602Active1 properties
public:

};
