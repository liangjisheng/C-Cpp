
#include <Windows.h>
#include <stdio.h>
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
#include <cfgmgr32.h>

typedef struct _SSDevHandles
{
	DWORD dwDevsCount;
	HDEVINFO hDevInfoSet;
	SP_DEVINFO_DATA *pDevDatas;
} SSDevHandles;


HANDLE STDCALL SSDevGetDevices(LPCTSTR lpVid, LPCTSTR lpPID, const GUID* pSetupClassGuid,
	const GUID* pInterfaceClassGuid)
{
	SSDevHandles *phDevs = NULL;
	HDEVINFO hDevInfoSet = INVALID_HANDLE_VALUE;
	check_int_begin
	{
		if(lpVid != NULL && _tcslen(lpVid) == 0)
			lpVid = NULL;
		if(lpPID != NULL && _tcslen(lpPID) == 0)
			lpPID = NULL;
		hDevInfoSet = SetupDiCreateDeviceInfoList(pSetupClassGuid, NULL);
		check_int_bool(hDevInfoSet != INVALID_HANDLE_VALUE, SS_RC_NOT_FOUND);
		if(pInterfaceClassGuid == NULL)
			hDevInfoSet = SetupDiGetClassDevsEx(NULL, NULL, NULL,
			DIGCF_ALLCLASSES|DIGCF_DEVICEINTERFACE|DIGCF_PRESENT,
			hDevInfoSet, NULL, NULL);
		else
			hDevInfoSet = SetupDiGetClassDevsEx(pInterfaceClassGuid, NULL, NULL,
			DIGCF_DEVICEINTERFACE|DIGCF_PRESENT,
			hDevInfoSet, NULL, NULL);
		check_int_bool(hDevInfoSet != INVALID_HANDLE_VALUE, SS_RC_NOT_FOUND);
		SP_DEVINFO_DATA dtDevInfo = { sizeof(SP_DEVINFO_DATA) };
		for(DWORD dwMemIdx = 0; ;dwMemIdx++)
		{
			if(!SetupDiEnumDeviceInfo(hDevInfoSet, dwMemIdx, &dtDevInfo))
			{
				if(::GetLastError() == ERROR_NO_MORE_ITEMS)
				{
					break;
				}
				continue;;
			}
			if(lpVid != NULL || lpPID != NULL)
			{
				TCHAR szInstanceId[MAX_INSTANCE_ID] = {0};
				SetupDiGetDeviceInstanceId(hDevInfoSet, &dtDevInfo, szInstanceId, SS_DIMOF(szInstanceId), NULL);
				if(_tcslen(szInstanceId) <= 0)
					continue;
				TCHAR szVID[5] = {0}, szPID[5] = {0};
				if(!SSDevUtilGetVIDPID(szInstanceId, szVID, SS_DIMOF(szVID), szPID, SS_DIMOF(szPID)))
					continue;
				if(lpVid != NULL && _tcsicmp(lpVid, szVID) != 0)
					continue;
				if(lpPID != NULL && _tcsicmp(lpPID, szPID) != 0)
					continue;
			}
			DWORD dwCapbilities = 0;
			if(!SetupDiGetDeviceRegistryProperty(hDevInfoSet, &dtDevInfo, SPDRP_CAPABILITIES, NULL,\
				(BYTE*)&dwCapbilities, sizeof(DWORD), NULL))
				continue;
			if(!SS_FLAG_ISSET(dwCapbilities, CM_DEVCAP_REMOVABLE))
				continue;
			if(phDevs == NULL)
			{
				phDevs = (SSDevHandles *)SS_MALLOC(sizeof(SSDevHandles));
				memset(phDevs, 0, sizeof(SSDevHandles));
				phDevs->hDevInfoSet = INVALID_HANDLE_VALUE;
			}
			phDevs->pDevDatas = (SP_DEVINFO_DATA*)SS_REALLOC(phDevs->pDevDatas, (phDevs->dwDevsCount + 1) * sizeof(SP_DEVINFO_DATA));
			MP_ASSERT(phDevs->pDevDatas != NULL);
			phDevs->pDevDatas[phDevs->dwDevsCount] = dtDevInfo;
			phDevs->dwDevsCount++;
		}
	}
	check_int_finally
	{
		if(phDevs != NULL && phDevs->dwDevsCount > 0)
		{
			phDevs->hDevInfoSet = hDevInfoSet;
			hDevInfoSet = INVALID_HANDLE_VALUE;
		}
		if(hDevInfoSet != INVALID_HANDLE_VALUE)
		{
			SetupDiDestroyDeviceInfoList(hDevInfoSet);
			hDevInfoSet = INVALID_HANDLE_VALUE;
		}
	}
	return phDevs;
}