
// The following code shows a simple use of LocalAlloc and LocalFree

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>


// First parameter is memory allocation attributes. 
// The default is the LMEM_FIXED value

// LPTR Combines LMEM_FIXED and LMEM_ZEROINIT.
// LHND Combines LMEM_MOVEABLE and LMEM_ZEROINIT.
// LMEM_FIXED
// LMEM_MOVEABLE
// LMEM_ZEROINIT
// NONZEROLHND Same as LMEM_MOVEABLE.
// NONZEROLPTR Same as LMEM_FIXED.

void _cdecl _tmain()
{
	LPTSTR pszBuf = NULL;
	pszBuf = (LPTSTR)LocalAlloc(LPTR, MAX_PATH * sizeof(TCHAR));

	// Handle error condition
	if(NULL == pszBuf)
	{
		_tprintf(TEXT("LocalAlloc failed(%d)\n"), GetLastError());
		return ;
	}

	// see how much memory was allocated
	_tprintf(TEXT("LocalAlloc allocated %d bytes\n"), LocalSize(pszBuf));

	// Use the memory allocated

	// Free the memory when finished with it
	LocalFree(pszBuf);

	getchar();
}