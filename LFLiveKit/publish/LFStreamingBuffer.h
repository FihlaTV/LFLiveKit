//
//  LFStreamingBuffer.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFAudioFrame.h"
#import "LFVideoFrame.h"


/** current buffer status */
typedef NS_ENUM (NSUInteger, LFLiveBuffferState) {
    LFLiveBuffferUnknown = 0,      //< Unknown
    LFLiveBuffferIncrease = 1,    //< Buffer state difference should lower the code rate
    LFLiveBuffferDecline = 2      //< Buffer status should improve the bit rate
};

@class LFStreamingBuffer;
/** this two method will control videoBitRate */
@protocol LFStreamingBufferDelegate <NSObject>
@optional
/** Current buffer change (increase or decrease) according to the updateInterval time callback in the buffer */
- (void)streamingBuffer:(nullable LFStreamingBuffer *)buffer bufferState:(LFLiveBuffferState)state;
@end

@interface LFStreamingBuffer : NSObject


/** The delegate of the buffer. buffer callback */
@property (nullable, nonatomic, weak) id <LFStreamingBufferDelegate> delegate;

/** current frame buffer */
@property (nonatomic, strong, readonly) NSMutableArray <LFFrame *> *_Nonnull list;

/** buffer count max size default 1000 */
@property (nonatomic, assign) NSUInteger maxCount;

/** count of drop frames in last time */
@property (nonatomic, assign) NSInteger lastDropFrames;

/** add frame to buffer */
- (void)appendObject:(nullable LFFrame *)frame;

/** pop the first frome buffer */
- (nullable LFFrame *)popFirstObject;

/** remove all objects from Buffer */
- (void)removeAllObject;

@end
