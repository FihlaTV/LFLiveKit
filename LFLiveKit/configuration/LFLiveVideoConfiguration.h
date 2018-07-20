//
//  LFLiveVideoConfiguration.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Video resolution(All 16:9. When this device does not support the current resolution, it automatically reduces one level.)
typedef NS_ENUM (NSUInteger, LFLiveVideoSessionPreset){
    /// Low resolution
    LFCaptureSessionPreset360x640 = 0,
    /// Medium resolution
    LFCaptureSessionPreset540x960 = 1,
    /// High resolution
    LFCaptureSessionPreset720x1280 = 2
};

/// Video quality
typedef NS_ENUM (NSUInteger, LFLiveVideoQuality){
    /// Resolution： 360 *640 number of frames：15 code rate：500Kps
    LFLiveVideoQuality_Low1 = 0,
    /// Resolution： 360 *640 number of frames：24 code rate：800Kps
    LFLiveVideoQuality_Low2 = 1,
    /// Resolution： 360 *640 number of frames：30 code rate：800Kps
    LFLiveVideoQuality_Low3 = 2,
    /// Resolution： 540 *960 number of frames：15 code rate：800Kps
    LFLiveVideoQuality_Medium1 = 3,
    /// Resolution： 540 *960 number of frames：24 code rate：800Kps
    LFLiveVideoQuality_Medium2 = 4,
    /// Resolution： 540 *960 number of frames：30 code rate：800Kps
    LFLiveVideoQuality_Medium3 = 5,
    /// Resolution： 720 *1280 number of frames：15 code rate：1000Kps
    LFLiveVideoQuality_High1 = 6,
    /// Resolution： 720 *1280 number of frames：24 code rate：1200Kps
    LFLiveVideoQuality_High2 = 7,
    /// Resolution： 720 *1280 number of frames：30 code rate：1200Kps
    LFLiveVideoQuality_High3 = 8,
    /// Default allocation
    LFLiveVideoQuality_Default = LFLiveVideoQuality_Low2
};

@interface LFLiveVideoConfiguration : NSObject<NSCoding, NSCopying>

/// Default video configuration
+ (instancetype)defaultConfiguration;
/// Video configuration (quality)
+ (instancetype)defaultConfigurationForQuality:(LFLiveVideoQuality)videoQuality;

/// Video configuration (quality & landscape is horizontal)
+ (instancetype)defaultConfigurationForQuality:(LFLiveVideoQuality)videoQuality outputImageOrientation:(UIInterfaceOrientation)outputImageOrientation;

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/// Video Resolution，
// Be sure to set the width and height to a multiple of 2, otherwise green edges may appear during decoding playback.
// (This one videoSizeRespectingAspectRatio Set to YES may change)
@property (nonatomic, assign) CGSize videoSize;

/// Whether the output image is proportional, the default is NO
@property (nonatomic, assign) BOOL videoSizeRespectingAspectRatio;

/// Video output direction
@property (nonatomic, assign) UIInterfaceOrientation outputImageOrientation;

/// Auto rotate (Only supported here left change right / portrait cahange portraitUpsideDown)
@property (nonatomic, assign) BOOL autorotate;

/// Video frame rate, ie fps
@property (nonatomic, assign) NSUInteger videoFrameRate;

/// Video maximum frame rate, ie fps
@property (nonatomic, assign) NSUInteger videoMaxFrameRate;

/// Video minimym frame rate, ie fps
@property (nonatomic, assign) NSUInteger videoMinFrameRate;

/// Maximum keyframe interval, which can be set to 2 times fps, affecting the size of a gop
@property (nonatomic, assign) NSUInteger videoMaxKeyframeInterval;

/// Videocode rate, the unit is bps
@property (nonatomic, assign) NSUInteger videoBitRate;

/// Video maximum code rate，the unit is bps
@property (nonatomic, assign) NSUInteger videoMaxBitRate;

/// Video最小code rate，the unit is bps
@property (nonatomic, assign) NSUInteger videoMinBitRate;

///< Resolution
@property (nonatomic, assign) LFLiveVideoSessionPreset sessionPreset;

///< ≈sde3Resolution
@property (nonatomic, assign, readonly) NSString *avSessionPreset;

///< Is it a landscape
@property (nonatomic, assign, readonly) BOOL landscape;

@end
