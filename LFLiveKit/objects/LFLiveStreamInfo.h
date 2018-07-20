//
//  LFLiveStreamInfo.h
//  LFLiveKit
//
//  Created by LaiFeng on 16/5/20.
//  Copyright © 2016年 LaiFeng All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFLiveAudioConfiguration.h"
#import "LFLiveVideoConfiguration.h"



/// 流状态
typedef NS_ENUM (NSUInteger, LFLiveState){
    /// ready
    LFLiveReady = 0,
    /// pending
    LFLivePending = 1,
    /// start
    LFLiveStart = 2,
    /// stop
    LFLiveStop = 3,
    /// error
    LFLiveError = 4,
    /// refreshing
    LFLiveRefresh = 5
};

typedef NS_ENUM (NSUInteger, LFLiveSocketErrorCode) {
    LFLiveSocketError_PreView = 201,              ///< Preview failed
    LFLiveSocketError_GetStreamInfo = 202,        ///< Failed to get streaming information
    LFLiveSocketError_ConnectSocket = 203,        ///< Failed to connect to the socket
    LFLiveSocketError_Verification = 204,         ///< Verify server failed
    LFLiveSocketError_ReConnectTimeOut = 205      ///< Reconnect server timeout
};

@interface LFLiveStreamInfo : NSObject

@property (nonatomic, copy) NSString *streamId;

#pragma mark -- FLV
@property (nonatomic, copy) NSString *host;
@property (nonatomic, assign) NSInteger port;
#pragma mark -- RTMP
@property (nonatomic, copy) NSString *url;          ///< Upload address (it is good for RTMP)
///Audio configuration
@property (nonatomic, strong) LFLiveAudioConfiguration *audioConfiguration;
///Video configuration
@property (nonatomic, strong) LFLiveVideoConfiguration *videoConfiguration;

@end
