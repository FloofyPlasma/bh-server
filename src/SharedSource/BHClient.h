#import "BHNetNode.h"

@class ClientTileLoader, NSMutableDictionary, NSString, World;

/**
 * @class BHClient
 * @brief Placeholder! Please remember to fill this in.
 */
@interface BHClient : BHNetNode {
  NSMutableDictionary* cachedPlayerImages;
  ClientTileLoader* clientTileLoader;
  World* world;
  NSString* gameServerID;
  NSString* joinPassword;
  NSString* serverOwnerName;
}

/**
 * @property serverOwnerName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* serverOwnerName; // @synthesize serverOwnerName;
/**
 * @property joinPassword
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* joinPassword; // @synthesize joinPassword;
/**
 * @property gameServerID
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* gameServerID; // @synthesize gameServerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)serverPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)port;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)host;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNewWelcomeMessageToServer:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isGameCenterMatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudMatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)purgeChatPicCache;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatMessageRecieved:(id)arg1 displayNotification:(BOOL)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendData:(id)arg1 toPeer:(id)arg2 reliable:(BOOL)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendDataToServer:(id)arg1 reliable:(BOOL)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChatMessage:(id)arg1 sendToClients:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(id)arg1 didReceiveData:(id)arg2 fromPlayer:(id)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cleanup;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(id)arg1 didFailWithError:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(id)arg1 connectionWithPlayerFailed:(id)arg2 withError:(id)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(id)arg1 player:(id)arg2 didChangeState:(long long)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorld:(id)arg1 clientTileLoader:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithDelegate:(id)arg1 match:(id)arg2 netNodeType:(long long)arg3;

@end
