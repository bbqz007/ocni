# ocni
jni ==> oc (ni)

* port jni to oc.
* simply translate jni coding to oc.

### overview
* written in 2016 in a cross-platfrom sdk project.
* assume
  * a cpp implement sdk for android java and ios oc interface (api).
  * cpp code interact with the android java and ios oc layer.
  * there are adapter layer codes interacting with the android java layer, using jni apis.
  * now also a copy of similar codes interacting with ios oc layer is needed.
  * how can simply port the **jni** version codes to **oc** version.

### mapping jni api calls to oc calls
```
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
```

### home
* [home](http://www.cnblogs.com/bbqzsl)
* [github](https://github.com/bbqz007)

