// welcome to 
// http://www.cnblogs.com/bbqzsl
// https://github.com/bbqz007/xw
//
//  OCWeakReference.h
//  test
//
//  Created by dennis chow on 16/8/28.
//  Copyright © 2016年 dennis chow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCWeakReference : NSObject
@property(assign, nonatomic) id ref;
+ (__strong id)weakReferenceTo:(__strong id)other;
@end
