// welcome to 
// http://www.cnblogs.com/bbqzsl
// https://github.com/bbqz007/xw
//
//  ocni.c
//  xsdk
//
//  Created by dennis chow on 16/8/27.
//  Copyright © 2016年 dennis chow. All rights reserved.
//

#ifdef __APPLE__
#include "ocni.h"
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>

static id _NewStringUTF(const char*);
static id _NewStrongRef(id);
static void _DeleteStrongRef(id);
static BOOL _isSameObject(id, id);
static idweak _NewWeakGlobalRef(id);
static void _DeleteWeakGlobalRef(idweak);

Class   (*OCRT::FindClass)(const char*) = objc_getClass;
SEL     (*OCRT::FindSel)(const char*) = sel_getUid;
id      (*OCRT::NewStringUTF)(const char*) = _NewStringUTF;

id      (*OCRT::NewGlobalRef)(id) = _NewStrongRef;
void    (*OCRT::DeleteGlobalRef)(id) = _DeleteStrongRef;
void    (*OCRT::DeleteLocalRef)(id) = _DeleteStrongRef;
BOOL    (*OCRT::IsSameObject)(id, id) = _isSameObject;

id      (*OCRT::NewLocalRef)(id) = _NewStrongRef;

id      (*OCRT::OCSelAndRtnObject)(id, SEL, ...) = (id(*)(id, SEL, ...))objc_msgSend;
int     (*OCRT::OCSelAndRtnInt)(id, SEL, ...) = (int(*)(id, SEL, ...))objc_msgSend;
BOOL    (*OCRT::OCSelAndRtnBool)(id, SEL, ...) = (BOOL(*)(id, SEL, ...))objc_msgSend;
void    (*OCRT::OCSelAndNoRtn)(id, SEL, ...) = (void(*)(id, SEL, ...))objc_msgSend;

id      (*OCRT::OCClsSelAndRtnObject)(Class, SEL, ...) = (id(*)(Class, SEL, ...))objc_msgSend;
int     (*OCRT::OCClsSelAndRtnInt)(Class, SEL, ...) = (int(*)(Class, SEL, ...))objc_msgSend;
BOOL    (*OCRT::OCClsSelAndRtnBool)(Class, SEL, ...) = (BOOL(*)(Class, SEL, ...))objc_msgSend;
void    (*OCRT::OCClsSelAndNoRtn)(Class, SEL, ...) = (void(*)(Class, SEL, ...))objc_msgSend;

idweak  (*OCRT::NewWeakGlobalRef)(id) = _NewWeakGlobalRef;
void    (*OCRT::DeleteWeakGlobalRef)(idweak) = _DeleteWeakGlobalRef;


static id _NewStringUTF(const char* cStr)
{
    return (id) CFStringCreateWithCString(NULL, cStr, kCFStringEncodingUTF8);
}

static id _NewStrongRef(id obj)
{
    Class clazz = OCRT::FindClass("OCWeakReference");
    if(OCRT::OCSelAndRtnBool(obj, OCRT::FindSel("isKindOfClass:"), clazz))
    {
        id ref = OCRT::OCSelAndRtnObject(obj, OCRT::FindSel("getRef"));
        return _NewStrongRef(ref);
    }
    return OCRT::OCSelAndRtnObject(obj, OCRT::FindSel("retain"));
}

static void _DeleteStrongRef(id obj)
{
    return OCRT::OCSelAndNoRtn(obj, OCRT::FindSel("release"));
}

static BOOL _isSameObject(id rhl, id rhr)
{
    return OCRT::OCSelAndRtnBool(rhl, OCRT::FindSel("isEqual:"), rhr);
}

static idweak _NewWeakGlobalRef(id ref)
{
    Class clazz = OCRT::FindClass("OCWeakReference");
    if(OCRT::OCSelAndRtnBool(ref, OCRT::FindSel("isKindOfClass:"), clazz))
    {
        return _NewStrongRef(ref);
    }
    idweak ocwref = OCRT::OCClsSelAndRtnObject(clazz, OCRT::FindSel("weakReferenceTo:"), ref);
    return (idweak) OCRT::OCSelAndRtnObject(ocwref, OCRT::FindSel("retain"));
}

static void _DeleteWeakGlobalRef(idweak ocwref)
{
    _DeleteStrongRef(ocwref);
}

#endif //__APPLE__