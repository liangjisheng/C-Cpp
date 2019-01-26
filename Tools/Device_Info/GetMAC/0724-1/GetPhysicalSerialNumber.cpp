
#include "stdafx.h"
#include <Iphlpapi.h>
#pragma comment(lib,"Iphlpapi")
//#pragma warning( disable : 4996 )
// IOCTL command constants
#define DFP_GET_VERSION 0x00074080
#define DFP_RECEIVE_DRIVE_DATA 0x0007c088
// values for IDEREGS.bCommandReg
#define IDE_ATAPI_IDENTIFY 0xA1
#define IDE_ATA_IDENTIFY 0xEC
#define IDENTIFY_BUFFER_SIZE 512

//save disk information
typedef struct _GETVERSIONOUTPARAMS
{
	BYTE bVersion;
	BYTE bRevision;
	BYTE bReserved;
	BYTE bIDEDeviceMap;
	DWORD fCapabilities;
	DWORD dwReserved[4];
} GETVERSIONOUTPARAMS, *PGETVERSIONOUTPARAMS, *LPGETVERSIONOUTPARAMS;

// IDE register information
typedef struct _IDEREGS
{
	BYTE bFeaturesReg;
	BYTE bSectorCountReg;
	BYTE bSectorNumberReg;
	BYTE bCylLowReg;
	BYTE bCylHighReg;
	BYTE bDriveHeadReg;
	BYTE bCommandReg;
	BYTE bReserved;
} IDEREGS, *PIDEREGS, *LPIDEREGS;

// disk command input parameter
typedef struct _SENDCMDINPARAMS
{
	DWORD cBufferSize;
	IDEREGS irDriveRegs;
	BYTE bDriveNumber;
	BYTE bReserved[3];
	DWORD dwReserved[4];
	BYTE bBuffer[1];
} SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;

// disk status
typedef struct _DRIVERSTATUS
{
	BYTE bDriverError;
	BYTE bIDEStatus;
	BYTE bReserved[2];
	DWORD dwReserved[2];
} DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;

// sent param for disk commands
typedef struct _SENDCMDOUTPARAMS
{
	DWORD cBufferSize;
	DRIVERSTATUS DriverStatus;
	BYTE bBuffer[1];
} SENDCMDOUTPARAMS, *PSENDCMDOUTPARAMS, *LPSENDCMDOUTPARAMS;

void GetDiskPhysicalSN(char pchDiskPhysicalSN[14])
{
	BYTE IdOutCmd[530];
	HANDLE drive=CreateFile(L"\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL );
	if ( drive == INVALID_HANDLE_VALUE )
	{
		pchDiskPhysicalSN[ 0 ] = 0;
		return ;
	}
	GETVERSIONOUTPARAMS VersionParams;
	DWORD cbBytesReturned = 0;
	memset( ( void* ) &VersionParams, 0, sizeof( VersionParams ) );
	if ( ! DeviceIoControl( drive, DFP_GET_VERSION, NULL, 0, &VersionParams, sizeof( VersionParams ), &cbBytesReturned, NULL ) )
	{
		pchDiskPhysicalSN[ 0 ] = 0;
		return ;
	}
	if (VersionParams.bIDEDeviceMap<=0)
	{
		pchDiskPhysicalSN[ 0 ] = 0;
		return ;
	}
	BYTE bIDCmd = 0;
	SENDCMDINPARAMS scip;
	bIDCmd = ( VersionParams.bIDEDeviceMap >> 0 & 0x10 ) ? IDE_ATAPI_IDENTIFY : IDE_ATA_IDENTIFY;
	memset( &scip, 0, sizeof( scip) );
	memset( IdOutCmd, 0, sizeof( IdOutCmd ) );
	scip.cBufferSize = IDENTIFY_BUFFER_SIZE;
	scip.irDriveRegs.bFeaturesReg = 0;
	scip.irDriveRegs.bSectorCountReg = 1;
	scip.irDriveRegs.bSectorNumberReg = 1;
	scip.irDriveRegs.bCylLowReg = 0;
	scip.irDriveRegs.bCylHighReg = 0;
	scip.irDriveRegs.bDriveHeadReg= 0xA0 | ( ( ( BYTE ) drive & 1 ) << 4 );
	scip.irDriveRegs.bCommandReg = bIDCmd;
	scip.bDriveNumber = ( BYTE ) drive;
	scip.cBufferSize = IDENTIFY_BUFFER_SIZE;
	if ( ! DeviceIoControl( drive, DFP_RECEIVE_DRIVE_DATA, &scip, sizeof( SENDCMDINPARAMS)- 1, ( LPVOID )&IdOutCmd, sizeof( SENDCMDOUTPARAMS ) + IDENTIFY_BUFFER_SIZE - 1, &cbBytesReturned, NULL ) )
	{
		pchDiskPhysicalSN[ 0 ] = 0;
		return ;
	}
	USHORT *pIdSector = ( USHORT * )( ( PSENDCMDOUTPARAMS )IdOutCmd )->bBuffer;
	int nPosition = 0;
	for( int nIndex = 13; nIndex < 20; nIndex++ )
	{
		pchDiskPhysicalSN[ nPosition++ ]=( unsigned char )( pIdSector[ nIndex ] / 256 );
		pchDiskPhysicalSN[ nPosition++ ]=( unsigned char )( pIdSector[ nIndex ] % 256 );
	}
}

void GetDiskPhysicalSerialNumber( char* pchSerialNumber )
{
	char pchDiskPhysicalSN[ 14 ];
	GetDiskPhysicalSN( pchDiskPhysicalSN );
	int nSerial[ 14 ];
	for( int i = 0 ; i < 14; ++ i )
	{
		nSerial[ i ] = pchDiskPhysicalSN[ i ];
		nSerial[ i ] &= 0x000000ff;
	}
	sprintf( pchSerialNumber, "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
		nSerial[ 0 ],
		nSerial[ 1 ],
		nSerial[ 2 ],
		nSerial[ 3 ],
		nSerial[ 4 ],
		nSerial[ 5 ],
		nSerial[ 6 ],
		nSerial[ 7 ],
		nSerial[ 8 ],
		nSerial[ 9 ],
		nSerial[ 10 ],
		nSerial[ 11 ],
		nSerial[ 12 ],
		nSerial[ 13 ]); // Should use scl::FormatString inside 
}
