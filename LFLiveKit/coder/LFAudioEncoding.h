//
//  LFAudioEncoding.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "LFAudioFrame.h"
#import "LFLiveAudioConfiguration.h"



@protocol LFAudioEncoding;
/// Encoder coded callback
@protocol LFAudioEncodingDelegate <NSObject>
@required
- (void)audioEncoder:(nullable id<LFAudioEncoding>)encoder audioFrame:(nullable LFAudioFrame *)frame;
@end

/// Encoder abstract interface
@protocol LFAudioEncoding <NSObject>
@required
- (void)encodeAudioData:(nullable NSData*)audioData timeStamp:(uint64_t)timeStamp;
- (void)stopEncoder;
@optional
- (nullable instancetype)initWithAudioStreamConfiguration:(nullable LFLiveAudioConfiguration *)configuration;
- (void)setDelegate:(nullable id<LFAudioEncodingDelegate>)delegate;
- (nullable NSData *)adtsData:(NSInteger)channel rawDataLength:(NSInteger)rawDataLength;
@end

