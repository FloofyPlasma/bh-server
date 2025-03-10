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

@class NSString;
@protocol BHMatchDelegate;

@interface BHMatch //! : NSObject
{
  id<BHMatchDelegate> delegate;
  NSString* host;
  NSString* port;
}

@property (readonly) NSString* port; // @synthesize port;
@property (readonly) NSString* host; // @synthesize host;
- (id)cloudSalt;
- (id)ownerName;
- (BOOL)owned;
- (BOOL)isCloudMatch;
- (void)disconnectPlayer:(id)arg1;
- (void)removeClient:(id)arg1;
- (id)connectedPlayerIDs;
- (BOOL)usesGameCenterPlayerInformation;
- (BOOL)requiresPlayerAuthentication;
- (BOOL)audioChatSupported;
- (id)persistentIDForNetID:(id)arg1;
- (void)updatedPlayerListRecievedFromServer:(id)arg1;
- (void)sendPlayerInformationToServer:(id)arg1 password:(id)arg2;
- (void)clientApprovedWithInfo:(id)arg1;
- (id)clientPlayerInformationRecieved:(id)arg1 fromPeer:(id)arg2;
- (id)loadInfoForPlayer:(id)arg1;
- (BOOL)sendData:(id)arg1
       toPlayers:(id)arg2
    withDataMode:(long long)arg3
           error:(id*)arg4;
- (unsigned long long)expectedPlayerCount;
- (id)voiceChatWithName:(id)arg1;
- (void)disconnect;
- (void)setDelegate:(id)arg1;
- (id)playerIDs;
- (id)localPlayerName;
- (id)localPlayerID;

@end
