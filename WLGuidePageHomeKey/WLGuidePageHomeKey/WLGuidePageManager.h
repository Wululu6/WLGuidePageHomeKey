//
//  WLGuidePageManager.h
//  WLGuidePageHomeKey
//
//  Created by apple on 2018/11/26.
//  Copyright © 2018年 apple. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#define WLGuidePageHomeKey @"WLGuidePageHomeKey"
#define WLGuidePageMajorKey @"WLGuidePageMajorKey"

NS_ASSUME_NONNULL_BEGIN

#define KMainW [UIScreen mainScreen].bounds.size.width
#define KMainH [UIScreen mainScreen].bounds.size.height

#define KScreenRate (375 / KMainW)
#define KSuitFloat(float) (float / KScreenRate)
#define KSuitSize(width, height) CGSizeMake(width / KScreenRate, height / KScreenRate)
#define KSuitPoint(x, y) CGPointMake(x / KScreenRate, y / KScreenRate)
#define KSuitRect(x, y, width, heigth) CGRectMake(x / KScreenRate, y / KScreenRate, width / KScreenRate, heigth / KScreenRate)


typedef void(^FinishBlock)(void);


typedef NS_ENUM(NSInteger, WLGuidePageType) {
    WLGuidePageTypeHome = 0,
    WLGuidePageTypeMajor,
};

@interface WLGuidePageManager : NSObject

// 获取单例
+ (instancetype)shareManager;

/**
 显示方法
 
 @param type 指引页类型
 */
- (void)showGuidePageWithType:(WLGuidePageType)type;

/**
 显示方法
 
 @param type 指引页类型
 @param completion 完成时回调
 */
- (void)showGuidePageWithType:(WLGuidePageType)type completion:(FinishBlock)completion;

@end

NS_ASSUME_NONNULL_END
