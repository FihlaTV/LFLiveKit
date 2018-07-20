//
//  LFLiveDebug.h
//  LaiFeng
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LFLiveDebug : NSObject

@property (nonatomic, copy) NSString *streamId;                         ///< flow id
@property (nonatomic, copy) NSString *uploadUrl;                        ///< stream address
@property (nonatomic, assign) CGSize videoSize;                         ///< upload resolution
@property (nonatomic, assign) BOOL isRtmp;                              ///< upload method（TCP or RTMP）

@property (nonatomic, assign) CGFloat elapsedMilli;                     ///< time unit from the last count (ms)
@property (nonatomic, assign) CGFloat timeStamp;                        ///< current timestamp to calculate data within 1s
@property (nonatomic, assign) CGFloat dataFlow;                         ///< total flow 
@property (nonatomic, assign) CGFloat bandwidth;                        ///< 1s total internal bandwidth
@property (nonatomic, assign) CGFloat currentBandwidth;                 ///< last bandwidth

@property (nonatomic, assign) NSInteger dropFrame;                      ///< number of frames lost
@property (nonatomic, assign) NSInteger totalFrame;                     ///< total number of frames

@property (nonatomic, assign) NSInteger capturedAudioCount;             ///< number of internal audio captures
@property (nonatomic, assign) NSInteger capturedVideoCount;             ///< number of internal video captures
@property (nonatomic, assign) NSInteger currentCapturedAudioCount;      ///< last audio captures
@property (nonatomic, assign) NSInteger currentCapturedVideoCount;      ///< last video captures

@property (nonatomic, assign) NSInteger unSendCount;                    ///< number of unsent (represents the current buffer waiting to be sent)

@end
