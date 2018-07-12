

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef ___0602Active1idl_h__
#define ___0602Active1idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DMy0602Active1_FWD_DEFINED__
#define ___DMy0602Active1_FWD_DEFINED__
typedef interface _DMy0602Active1 _DMy0602Active1;
#endif 	/* ___DMy0602Active1_FWD_DEFINED__ */


#ifndef ___DMy0602Active1Events_FWD_DEFINED__
#define ___DMy0602Active1Events_FWD_DEFINED__
typedef interface _DMy0602Active1Events _DMy0602Active1Events;
#endif 	/* ___DMy0602Active1Events_FWD_DEFINED__ */


#ifndef __My0602Active1_FWD_DEFINED__
#define __My0602Active1_FWD_DEFINED__

#ifdef __cplusplus
typedef class My0602Active1 My0602Active1;
#else
typedef struct My0602Active1 My0602Active1;
#endif /* __cplusplus */

#endif 	/* __My0602Active1_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __My0602Active1Lib_LIBRARY_DEFINED__
#define __My0602Active1Lib_LIBRARY_DEFINED__

/* library My0602Active1Lib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_My0602Active1Lib;

#ifndef ___DMy0602Active1_DISPINTERFACE_DEFINED__
#define ___DMy0602Active1_DISPINTERFACE_DEFINED__

/* dispinterface _DMy0602Active1 */
/* [uuid] */ 


EXTERN_C const IID DIID__DMy0602Active1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("09569208-5136-4866-97DE-4DE989FE1517")
    _DMy0602Active1 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMy0602Active1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMy0602Active1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMy0602Active1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMy0602Active1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMy0602Active1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMy0602Active1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMy0602Active1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMy0602Active1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DMy0602Active1Vtbl;

    interface _DMy0602Active1
    {
        CONST_VTBL struct _DMy0602Active1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMy0602Active1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMy0602Active1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMy0602Active1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMy0602Active1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMy0602Active1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMy0602Active1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMy0602Active1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMy0602Active1_DISPINTERFACE_DEFINED__ */


#ifndef ___DMy0602Active1Events_DISPINTERFACE_DEFINED__
#define ___DMy0602Active1Events_DISPINTERFACE_DEFINED__

/* dispinterface _DMy0602Active1Events */
/* [uuid] */ 


EXTERN_C const IID DIID__DMy0602Active1Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CAB606D9-CE9E-49CD-B4A5-67B7B7D909B0")
    _DMy0602Active1Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMy0602Active1EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMy0602Active1Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMy0602Active1Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMy0602Active1Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMy0602Active1Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMy0602Active1Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMy0602Active1Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMy0602Active1Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DMy0602Active1EventsVtbl;

    interface _DMy0602Active1Events
    {
        CONST_VTBL struct _DMy0602Active1EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMy0602Active1Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DMy0602Active1Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DMy0602Active1Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DMy0602Active1Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DMy0602Active1Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DMy0602Active1Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DMy0602Active1Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMy0602Active1Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_My0602Active1;

#ifdef __cplusplus

class DECLSPEC_UUID("8AE0ABE5-47AF-401F-A841-F2716A65DBC2")
My0602Active1;
#endif
#endif /* __My0602Active1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


