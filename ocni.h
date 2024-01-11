// welcome to 
// http://www.cnblogs.com/bbqzsl
// https://github.com/bbqz007/xw
//
//  ocni.h
//  xsdk
//
//  Created by dennis chow on 16/8/27.
//  Copyright © 2016年 dennis chow. All rights reserved.
//

#ifndef ocni_h
#define ocni_h
#ifdef __APPLE__
#include <objc/objc.h>

typedef id idweak;
/*
 * Table of interface function pointers.
 */
struct OCRT {
    static Class    (*FindClass)(const char*);
    static SEL      (*FindSel)(const char*);
    static id       (*NewStringUTF)(const char*);
    
    static id       (*NewGlobalRef)(id);
    static void     (*DeleteGlobalRef)(id);
    static void     (*DeleteLocalRef)(id);
    static BOOL     (*IsSameObject)(id, id);
    
    static id       (*NewLocalRef)(id);
    
    static id       (*OCSelAndRtnObject)(id, SEL, ...);
    static int      (*OCSelAndRtnInt)(id, SEL, ...);
    static BOOL     (*OCSelAndRtnBool)(id, SEL, ...);
    static void     (*OCSelAndNoRtn)(id, SEL, ...);
    
    static id       (*OCClsSelAndRtnObject)(Class, SEL, ...);
    static int      (*OCClsSelAndRtnInt)(Class, SEL, ...);
    static BOOL     (*OCClsSelAndRtnBool)(Class, SEL, ...);
    static void     (*OCClsSelAndNoRtn)(Class, SEL, ...);
    
    static idweak   (*NewWeakGlobalRef)(id);
    static void     (*DeleteWeakGlobalRef)(idweak);
};
#endif //__APPLE__
#endif /* ocni_h */
