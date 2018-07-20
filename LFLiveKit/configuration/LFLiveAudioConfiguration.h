//
//  LFLiveAudioConfiguration.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>

/// Audio bit rate (默认96Kbps)
typedef NS_ENUM (NSUInteger, LFLiveAudioBitRate) {
    /// 32Kbps Audio bit rate
    LFLiveAudioBitRate_32Kbps = 32000,
    /// 64Kbps Audio bit rate
    LFLiveAudioBitRate_64Kbps = 64000,
    /// 96Kbps Audio bit rate
    LFLiveAudioBitRate_96Kbps = 96000,
    /// 128Kbps Audio bit rate
    LFLiveAudioBitRate_128Kbps = 128000,
    /// Default Audio bit rate，The default is 96Kbps
    LFLiveAudioBitRate_Default = LFLiveAudioBitRate_96Kbps
};

/// Audio sample rate (default 44.1KHz)
typedef NS_ENUM (NSUInteger, LFLiveAudioSampleRate){
    /// 16KHz Sampling rate
    LFLiveAudioSampleRate_16000Hz = 16000,
    /// 44.1KHz Sampling rate
    LFLiveAudioSampleRate_44100Hz = 44100,
    /// 48KHz Sampling rate
    LFLiveAudioSampleRate_48000Hz = 48000,
    /// Default audio Sampling rate，The default is 44.1KHz
    LFLiveAudioSampleRate_Default = LFLiveAudioSampleRate_44100Hz
};

///  Audio Live quality（Audio quality）
typedef NS_ENUM (NSUInteger, LFLiveAudioQuality){
    /// Low Audio quality audio sample rate: 16KHz audio bitrate: numberOfChannels 1 : 32Kbps  2 : 64Kbps
    LFLiveAudioQuality_Low = 0,
    /// Medium Audio quality audio sample rate: 44.1KHz audio bitrate: 96Kbps
    LFLiveAudioQuality_Medium = 1,
    /// High Audio quality audio sample rate: 44.1MHz audio bitrate: 128Kbps
    LFLiveAudioQuality_High = 2,
    /// Very High Audio quality audio sample rate: 48KHz, audio bitrate: 128Kbps
    LFLiveAudioQuality_VeryHigh = 3,
    /// Default Audio quality audio sample rate: 44.1KHz, audio bitrate: 96Kbps
    LFLiveAudioQuality_Default = LFLiveAudioQuality_High
};

@interface LFLiveAudioConfiguration : NSObject<NSCoding, NSCopying>

/// Default audio configuration
+ (instancetype)defaultConfiguration;
/// Audio configuration
+ (instancetype)defaultConfigurationForQuality:(LFLiveAudioQuality)audioQuality;

#pragma mark - Attribute
///=============================================================================
/// @name Attribute
///=============================================================================
/// Number of channels(default 2)
@property (nonatomic, assign) NSUInteger numberOfChannels;
/// Sampling rate
@property (nonatomic, assign) LFLiveAudioSampleRate audioSampleRate;
/// Code rate
@property (nonatomic, assign) LFLiveAudioBitRate audioBitrate;
/// flv coded audio head 44100 为0x12 0x10
@property (nonatomic, assign, readonly) char *asc;
/// Cache length
@property (nonatomic, assign,readonly) NSUInteger bufferLength;

@end
