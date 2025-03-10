//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//! FIXME: Bad macro hack
#ifndef BOOL
#define BOOL bool
#endif

//! #import <objc/NSObject.h>

#import "BHMatchDelegate-Protocol.h"

@class BHMatch, GKVoiceChat, NSArray, NSMutableArray, NSMutableDictionary;
@protocol BHNetNodeDelegate;

@interface BHNetNode //! : NSObject <BHMatchDelegate>
{
  NSObject<BHNetNodeDelegate>* delegate;
  BHMatch* match;
  GKVoiceChat* voiceChat;
  NSMutableArray* livePlayerInfos;
  NSMutableDictionary* playerInfosForAllPlayersByID;
  long long netNodeType;
}

@property (readonly) long long netNodeType; // @synthesize netNodeType;
@property (readonly) BHMatch* match; // @synthesize match;
@property (readonly) NSArray* livePlayerInfos; // @synthesize livePlayerInfos;
- (void)notifyPlayersChanged;
- (BOOL)audioChatSupported;
- (id)localPlayerName;
- (id)localPlayerID;
- (void)sendChatMessage:(id)arg1
    displayNotification:(BOOL)arg2
          sendToClients:(id)arg3;
- (void)sendChatMessage:(id)arg1 sendToClients:(id)arg2;
- (BOOL)voiceChatActive;
- (void)match:(id)arg1 didFailWithError:(id)arg2;
- (void)endVoiceChat;
- (void)toggleAudioSessionActive;
- (void)startVoiceChat;
- (void)match:(id)arg1 didReceiveData:(id)arg2 fromPlayer:(id)arg3;
- (void)match:(id)arg1 connectionWithPlayerFailed:(id)arg2 withError:(id)arg3;
- (void)match:(id)arg1 player:(id)arg2 didChangeState:(long long)arg3;
- (id)serverPlayerID;
- (id)playerInfoForPeerID:(id)arg1;
- (void)cleanup;
- (void)purgeChatPicCache;
- (void)updatePlayerList:(id)arg1;
- (void)infoArrived:(id)arg1 forPlayer:(id)arg2;
- (BOOL)loadInfoForPlayer:(id)arg1;
- (void)updateMatch:(id)arg1;
- (id)initWithDelegate:(id)arg1 match:(id)arg2 netNodeType:(long long)arg3;

@end
