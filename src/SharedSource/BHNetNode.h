#import <Foundation/Foundation.h>

#import "BHMatchDelegate-Protocol.h"
#import "BHNetConstants.h"
#import "BHNetNodeDelegate-Protocol.h"

@class BHMatch, GKVoiceChat;

typedef NSInteger BHNetNodeType;

/**
 * @class BHNetNode
 * @brief Placeholder! Please remember to fill this in.
 */
@interface BHNetNode : NSObject <BHMatchDelegate> {
  NSObject<BHNetNodeDelegate>* delegate;
  BHMatch* match;
  GKVoiceChat* voiceChat;
  NSMutableArray* livePlayerInfos;
  NSMutableDictionary* playerInfosForAllPlayersByID;
  BHNetNodeType netNodeType;
}

/**
 * @property netNodeType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BHNetNodeType netNodeType; // @synthesize netNodeType;
/**
 * @property match
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BHMatch* match; // @synthesize match;
/**
 * @property livePlayerInfos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* livePlayerInfos; // @synthesize livePlayerInfos;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)notifyPlayersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)audioChatSupported;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChatMessage:(NSString*)messageText displayNotification:(BOOL)displayNotification sendToClients:(NSArray*)clientsToSend;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChatMessage:(NSString*)messageText sendToClients:(NSArray*)clientsToSend;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)voiceChatActive;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)endVoiceChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)toggleAudioSessionActive;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startVoiceChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match didReceiveData:(NSData*)data fromPlayer:(NSString*)peerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)serverPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)playerInfoForPeerID:(NSString*)peerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cleanup;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)purgeChatPicCache;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePlayerList:(NSArray*)playerListIncoming;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)loadInfoForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateMatch:(BHMatch*)match_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BHNetNode*)initWithDelegate:(NSObject<BHNetNodeDelegate>*)delegate_ match:(BHMatch*)match_ netNodeType:(BHNetNodeType)netNodeType_;

@end
