// welcome to 
// http://www.cnblogs.com/bbqzsl
// https://github.com/bbqz007/xw
//
//  OCWeakReference.m
//  test
//
//  Created by dennis chow on 16/8/28.
//  Copyright © 2016年 dennis chow. All rights reserved.
//

#import "OCWeakReference.h"

#if !__has_feature(objc_arc)
#error "__weak only be supported in case of ARC on iOS platform"
#error "but xsdk needs MRC case."
#endif

@interface OCWeakReference ()
{
    
}
@property(weak, nonatomic) id wref;
@end

@implementation OCWeakReference
+ (__strong id)weakReferenceTo:(__strong id)other
{
    OCWeakReference* ocwref = [[OCWeakReference alloc] init];
    ocwref.ref = other;
    return ocwref;
}

- (id)getRef
{
    if (!_wref)
    {
        return nil;
    }
    __strong id sref = _wref;
    return sref;
}

- (void)setRef:(id)ref
{
    if (!ref)
    return;
    self.wref = ref;
}
@end
