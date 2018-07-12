int UniToUTF8(CString strUnicode,char *szUtf8)  
{  
    //MessageBox(strUnicode);  
    int ilen = WideCharToMultiByte(CP_UTF8, 0, (LPCTSTR)strUnicode, -1, NULL, 0, NULL, NULL);   
    char *szUtf8Temp=new char[ilen + 1];  
    memset(szUtf8Temp, 0, ilen +1);   
    WideCharToMultiByte (CP_UTF8, 0, (LPCTSTR)strUnicode, -1, szUtf8Temp, ilen, NULL,NULL);   
    //size_t a = strlen(szUtf8Temp);  
    sprintf(szUtf8, "%s", szUtf8Temp);//   
    delete[] szUtf8Temp;   
    return ilen;  
} 

CString UTF8_to_UNICODE(const char *utf8_string, int length)
{
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, utf8_string, length, NULL, 0);   
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    ::MultiByteToWideChar(CP_UTF8, NULL, utf8_string, length, wszString, wcsLen);
    wszString[wcsLen] = '\0';
    CString unicodeText(wszString); 
    delete[] wszString;
    return unicodeText;
}