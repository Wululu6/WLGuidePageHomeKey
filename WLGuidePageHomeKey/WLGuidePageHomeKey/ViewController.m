//
//  ViewController.m
//  WLGuidePageHomeKey
//
//  Created by apple on 2018/11/26.
//  Copyright © 2018年 apple. All rights reserved.
//

#import "ViewController.h"

#import "WLGuidePageManager.h"



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor whiteColor];
    
    // 创建控件
    [self creatControl];
    
    [[NSUserDefaults standardUserDefaults] setBool:NO forKey:WLGuidePageHomeKey];
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // 引导视图
    [self showGuidePage];
    
}

- (void)creatControl
{
    // 底图
    UIImageView *imgView = [[UIImageView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    imgView.image = [UIImage imageNamed:@"backImg"];
    imgView.contentMode = UIViewContentModeScaleAspectFill;
    [self.view addSubview:imgView];
}

- (void)showGuidePage {
    
    // 判断是否已显示过
    if (![[NSUserDefaults standardUserDefaults] boolForKey:WLGuidePageHomeKey]) {
        // 显示
        [[WLGuidePageManager shareManager] showGuidePageWithType:WLGuidePageTypeHome completion:^{
            [[WLGuidePageManager shareManager] showGuidePageWithType:WLGuidePageTypeMajor];
        }];
    }
}


@end
