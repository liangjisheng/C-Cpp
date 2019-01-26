#pragma once
#include "HttpClientSyn.h"
#include <string>
#include <map>

class CHttpUploadFiles:public CHttpClientSyn
{
public:
    CHttpUploadFiles(void);
    ~CHttpUploadFiles(void);
public:
    BOOL TransDataToServer(const std::wstring wstrUrl, VecStParam& VecExtInfo, 
        const std::wstring& wstrFilePath,  const std::wstring& wstrFileKey );
private:
    DWORD GetDataSize();
    BOOL GetData(LPVOID lpBuffer, DWORD dwBufferSize, DWORD& dwWrite);
    BOOL ModifyRequestHeader(HINTERNET hRequest);
    std::wstring GenerateExtInfo(const VecStParam& VecExtInfo);
    VOID AddExtInfo(VecStParam& VecExtInfo);

    
private:
    std::wstring m_wstrNewHeader;
    std::wstring m_wstrBlockStart;
    std::string m_strBlockStartUTF8;
    std::wstring m_wstrBlockEnd;
    std::string m_strUploadFileHeaderUTF8;
    std::wstring m_wstrFilePath;
    VecStParam m_VecExtInfo;

    enum EREADPART{
        EHeader,
        EFile,
    };
    struct StReadInfo{
        DWORD dwReadIndex;
        EREADPART eType;
    }m_ReadInfo;
private:
    BOOL ReadFromString( const std::string& strContent, LPVOID lpBuffer, DWORD dwBufferSize, DWORD dwIndex, DWORD& dwWrite);
};

