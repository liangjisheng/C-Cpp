
#include "stdafx.h"

// Get Disk partition volumn id, not hard disk id
DWORD GetPartitionVolumeSerialNumber() 
{
	TCHAR lpRootPathName[]= _T( "\\\\.\\PhysicalDrive0\\" ); // Use physical drive, not C:disk
	TCHAR lpVolumeNameBuffer[ 12 ]; //disk volumn
	DWORD nVolumeNameSize =12; 
	DWORD VolumeSerialNumber; // Serial number
	DWORD MaximumComponentLength; 
	TCHAR lpFileSystemNameBuffer[ 10 ]; 
	DWORD nFileSystemNameSize = 10; 
	DWORD FileSystemFlags; 
	BOOL ret = GetVolumeInformation( lpRootPathName, 
		lpVolumeNameBuffer,
		nVolumeNameSize, 
		&VolumeSerialNumber,
		&MaximumComponentLength, 
		&FileSystemFlags, 
		lpFileSystemNameBuffer,
		nFileSystemNameSize); 

	printf( "Partition serial number is %0xd\n", VolumeSerialNumber );
	if( ret )
		return VolumeSerialNumber;
	else
		return FALSE;
}