//
//  LFLiveDebug.m
//  LaiFeng
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import "LFLiveDebug.h"

@implementation LFLiveDebug

- (NSString *)description {
    return [NSString stringWithFormat:@"Number of frames lost:%ld Total number of frames:%ld Last audio captures:%d Last video captures:%d Number of unsent:%ld Total flow:%0.f",_dropFrame,_totalFrame,_currentCapturedAudioCount,_currentCapturedVideoCount,_unSendCount,_dataFlow];
}


@end
