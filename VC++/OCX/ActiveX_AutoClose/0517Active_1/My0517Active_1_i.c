

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat May 20 08:16:21 2017
 */
/* Compiler settings for My0517Active_1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_My0517Active_1Lib,0x02380D1B,0x2096,0x4206,0x86,0x27,0xF2,0xE6,0xAB,0xF0,0x2A,0x2A);


MIDL_DEFINE_GUID(IID, DIID__DMy0517Active_1,0xC1138B13,0xA897,0x4C80,0x9A,0xBF,0xCF,0x8C,0xC9,0x3A,0x84,0xEC);


MIDL_DEFINE_GUID(IID, DIID__DMy0517Active_1Events,0xAD4B7141,0xA2DF,0x4018,0x8A,0xCB,0x1C,0xBA,0x56,0x5B,0xCD,0xA7);


MIDL_DEFINE_GUID(CLSID, CLSID_My0517Active_1,0xA945DF92,0xB075,0x4B25,0xB9,0x36,0xAD,0x37,0xC2,0x36,0x33,0x20);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



