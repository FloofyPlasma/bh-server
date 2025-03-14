#import <Foundation/Foundation.h>

#import "BHMatchDelegate-Protocol.h"
#import "BHNetConstants.h"
#import "BHNetNodeDelegate-Protocol.h"

@class BHMatch, GKVoiceChat;

typedef NSInteger BHNetNodeType;

@interface BHNetNode : NSObject <BHMatchDelegate> {
  NSObject<BHNetNodeDelegate>* delegate;
  BHMatch* match;
  GKVoiceChat* voiceChat;
  NSMutableArray* livePlayerInfos;
  NSMutableDictionary* playerInfosForAllPlayersByID;
  BHNetNodeType netNodeType;
}

@property (readonly) BHNetNodeType netNodeType; // @synthesize netNodeType;
@property (readonly) BHMatch* match; // @synthesize match;
@property (readonly) NSArray* livePlayerInfos; // @synthesize livePlayerInfos;

- (void)notifyPlayersChanged;
- (BOOL)audioChatSupported;
- (NSString*)localPlayerName;
- (NSString*)localPlayerID;
- (void)sendChatMessage:(NSString*)messageText displayNotification:(BOOL)displayNotification sendToClients:(NSArray*)clientsToSend;
- (void)sendChatMessage:(NSString*)messageText sendToClients:(NSArray*)clientsToSend;
- (BOOL)voiceChatActive;
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
- (void)endVoiceChat;
- (void)toggleAudioSessionActive;
- (void)startVoiceChat;
- (void)match:(BHMatch*)match didReceiveData:(NSData*)data fromPlayer:(NSString*)peerID;
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
- (void)match:(BHMatch*)match player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
- (NSString*)serverPlayerID;
- (NSDictionary*)playerInfoForPeerID:(NSString*)peerID;
- (void)cleanup;
- (void)purgeChatPicCache;
- (void)updatePlayerList:(NSArray*)playerListIncoming;
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
- (BOOL)loadInfoForPlayer:(NSString*)playerID;
- (void)updateMatch:(BHMatch*)match_;
- (BHNetNode*)initWithDelegate:(NSObject<BHNetNodeDelegate>*)delegate_ match:(BHMatch*)match_ netNodeType:(BHNetNodeType)netNodeType_;

@end
