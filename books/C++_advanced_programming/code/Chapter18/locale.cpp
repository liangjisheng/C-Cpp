#include <iostream>
// #include <wchar.h>
// #include <tchar.h>
// #include <ctype.h>
// #include <stdint.h>
#include <locale>

using namespace std;

int main()
{
    //const char* s1 = u8R"(Raw UTF-8 encoded string literal)";
    //const wchar_t* s2 = LR"(Raw wide string literal)";
    //const char16_t* s3 = uR"(Raw char16_t string literal)";
    //const char32_t* s4 = UR"(Raw char32_t string literal)";

    //const char* formula = u8"\03C0 r\u00B2";
    //cout << formula << endl;

    locale loc("");
    if(loc.name().find("en_US") == string::npos &&
       loc.name().find("United States") == string::npos)
    {
        wcout << L"Welcome non-U.S. English speaker!" << endl;
    }
    else
        wcout << L"Welcome U.S. English speaker!" << endl;


    //locale locUSEng("en_US");            // For Linux
    //locale locUSEng("English_United States");       // For windows

    // locale locBritEng("en_GB");          // For Linux
    //locale locBritEng("English_Great Britain");     // For windows
    //wstring dollars = use_facet<moneypunct<wchar_t> >(locUSEng).curr_symbol();
    //wstring pounds = use_facet<moneypunct<wchar_t> >(locBritEng).curr_symbol();
    //wcout << L"In the US, the currency symbol is " << dollars << endl;
    //wcout << L"In Great Britain, the currency symbol is " << pounds << endl;

    return 0;
}
