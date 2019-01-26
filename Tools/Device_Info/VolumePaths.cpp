
// http://myvs01.blog.163.com/blog/static/1853340902011612119124/
// 对于在linux下，我们可以读取/proc/partitions来获得系统中所有的硬盘和分区的各个设备名，
// 但对于windows下，我们又如何获得系统下的各个设备呢，这里用了windows下的API －－－ 
// FindFirstVolume、FindNextVolume和 FindVolumeClose。

// 用于显示系统中的所有设备和卷的路径名。对于每个卷，例子中的程序将会查找系统中的每个卷，
// 程序将获得卷的设备名和卷的路径名，并显示出了。

#include <windows.h>
#include <stdio.h>

void DisplayVolumePaths(__in PWCHAR VolumeName)
{
	DWORD CharCount = MAX_PATH + 1;
	PWCHAR Names = NULL;
	PWCHAR NameIdx = NULL;
	BOOL Success = FALSE;
	for (;;)
	{
		// Allocate a buffer to hold the paths.
		Names = (PWCHAR) new BYTE [CharCount * sizeof(WCHAR)];
		memset(Names, 0, CharCount * sizeof(WCHAR));
		if ( !Names )
		{
			// If memory can't be allocated, return.
			return;
		}

		// Obtain all of the paths
		// for this volume.
		Success = GetVolumePathNamesForVolumeNameW(VolumeName, Names, CharCount, &CharCount);
		if ( Success )
			break;
		if ( GetLastError() != ERROR_MORE_DATA )
			break;

		// Try again with the
		// new suggested size.
		delete [] Names;
		Names = NULL;
	}
	if ( Success )
	{
		// Display the various paths.
		for ( NameIdx = Names;NameIdx[0] != L'\0';NameIdx += wcslen(NameIdx) + 1 )
			wprintf(L" %s", NameIdx);
		wprintf(L"\n");
	}
	if ( Names != NULL )
	{
		delete [] Names;
		Names = NULL;
	}
	return;
}


void __cdecl wmain(void)
{
	DWORD CharCount = 0;
	WCHAR DeviceName[MAX_PATH] = L"";
	DWORD Error = ERROR_SUCCESS;
	HANDLE FindHandle = INVALID_HANDLE_VALUE;
	BOOL Found = FALSE;
	size_t Index = 0;
	BOOL Success = FALSE;
	WCHAR VolumeName[MAX_PATH] = L"";
	//
	// Enumerate all volumes in the system.
	FindHandle = FindFirstVolumeW(VolumeName, ARRAYSIZE(VolumeName));
	if (FindHandle == INVALID_HANDLE_VALUE)
	{
		Error = GetLastError();
		wprintf(L"FindFirstVolumeW failed with error code %d/n", Error);
		return;
	}
	for (;;)
	{
		// Skip the //?/ prefix and remove the trailing backslash.
		Index = wcslen(VolumeName) - 1;
		if (VolumeName[0] != L'\\' ||
			VolumeName[1] != L'\\' ||
			VolumeName[2] != L'?' ||
			VolumeName[3] != L'\\' ||
			VolumeName[Index] != L'\\')
		{
			Error = ERROR_BAD_PATHNAME;
			wprintf(L"FindFirstVolumeW/FindNextVolumeW returned a bad path: %s/n", VolumeName);
			break;
		}
		// QueryDosDeviceW doesn't allow a trailing backslash,
		// so temporarily remove it.
		VolumeName[Index] = L'\0';
		CharCount = QueryDosDeviceW(&VolumeName[4], DeviceName, ARRAYSIZE(DeviceName));
		VolumeName[Index] = L'\\';
		if ( CharCount == 0 )
		{
			Error = GetLastError();
			wprintf(L"QueryDosDeviceW failed with error code %d\n", Error);
			break;
		}
		wprintf(L"\nFound a device:\n %s", DeviceName);
		wprintf(L"\nVolume name: %s", VolumeName);
		wprintf(L"\nPaths:");
		DisplayVolumePaths(VolumeName);
		wprintf(L"\n");
	
		// Move on to the next volume.
		Success = FindNextVolumeW(FindHandle, VolumeName, ARRAYSIZE(VolumeName));
		if ( !Success )
		{
			Error = GetLastError();
			if (Error != ERROR_NO_MORE_FILES)
			{
				wprintf(L"FindNextVolumeW failed with error code %d\n", Error);
				break;
			}
			// Finished iterating
			// through all the volumes.
			Error = ERROR_SUCCESS;
			break;
		}
	}
	FindVolumeClose(FindHandle);
	FindHandle = INVALID_HANDLE_VALUE;

	getchar();
	return;
}

