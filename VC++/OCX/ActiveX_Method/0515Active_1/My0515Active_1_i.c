

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri May 19 19:23:24 2017
 */
/* Compiler settings for My0515Active_1.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_My0515Active_1Lib,0xEC724B27,0x9859,0x4CDB,0xBF,0xB3,0x50,0x8E,0x00,0xD7,0x30,0x66);


MIDL_DEFINE_GUID(IID, DIID__DMy0515Active_1,0xC4892E4A,0x59BA,0x48E1,0xBF,0x43,0x8E,0xBA,0xA4,0x35,0xA0,0x69);


MIDL_DEFINE_GUID(IID, DIID__DMy0515Active_1Events,0x0558ABAD,0xEC6B,0x42D0,0xBD,0xF2,0x0D,0xA8,0xFA,0x03,0xF5,0xD0);


MIDL_DEFINE_GUID(CLSID, CLSID_My0515Active_1,0x4E29832B,0x7197,0x4B2D,0x91,0xF5,0x1D,0xC4,0x49,0xED,0x1E,0x85);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



