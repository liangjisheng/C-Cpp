

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jun 02 11:03:28 2017
 */
/* Compiler settings for My0602Active1.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_My0602Active1Lib,0x77B660CE,0xF293,0x4325,0xB0,0xBE,0xC8,0x82,0xB4,0xA0,0x7C,0xED);


MIDL_DEFINE_GUID(IID, DIID__DMy0602Active1,0x09569208,0x5136,0x4866,0x97,0xDE,0x4D,0xE9,0x89,0xFE,0x15,0x17);


MIDL_DEFINE_GUID(IID, DIID__DMy0602Active1Events,0xCAB606D9,0xCE9E,0x49CD,0xB4,0xA5,0x67,0xB7,0xB7,0xD9,0x09,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_My0602Active1,0x8AE0ABE5,0x47AF,0x401F,0xA8,0x41,0xF2,0x71,0x6A,0x65,0xDB,0xC2);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



