// 0724-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "0724-1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


MACAddresses GetINETMacAddresses();
MACAddresses GetNetBiosMacAddresses();
DWORD GetPartitionVolumeSerialNumber();
void GetDiskPhysicalSerialNumber( char* pchDiskPhysicalSN );
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			DWORD VolumeSerialNumber = 0;
			if( ! GetPartitionVolumeSerialNumber() )
				TRACE( "(Get Disk Partition ID met error : %d)\n", GetLastError() );
			else
				printf( "Disk Partition ID = %0xd\n", VolumeSerialNumber );

			char pchSerialNumber[ 50 ];
			GetDiskPhysicalSerialNumber( pchSerialNumber );
			printf("PhysicalSerialNumber is %s\n", pchSerialNumber );
			printf("--------\n");

			MACAddresses& vAddresses = GetINETMacAddresses();
			for( vsIt it = vAddresses.begin(); it != vAddresses.end(); ++ it )
				printf( "INET MAC addresses = %s\n", it->c_str() );

			MACAddresses& vAddresses2 = GetNetBiosMacAddresses();
			for( vsIt it = vAddresses2.begin(); it != vAddresses2.end(); ++ it )
				printf( "NetBios MAC addresses = %s\n", it->c_str() );

			system("pause");
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
