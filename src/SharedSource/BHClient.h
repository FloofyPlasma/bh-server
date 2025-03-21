#import "BHNetNode.h"

@class ClientTileLoader, NSMutableDictionary, NSString, World;

@interface BHClient : BHNetNode {
  NSMutableDictionary* cachedPlayerImages;
  ClientTileLoader* clientTileLoader;
  World* world;
  NSString* gameServerID;
  NSString* joinPassword;
  NSString* serverOwnerName;
}

@property (readonly) NSString* serverOwnerName; // @synthesize serverOwnerName;
@property (readonly) NSString* joinPassword; // @synthesize joinPassword;
@property (readonly) NSString* gameServerID; // @synthesize gameServerID;
- (id)serverPlayerID;
- (id)port;
- (id)host;
- (void)sendNewWelcomeMessageToServer:(id)arg1;
- (BOOL)isGameCenterMatch;
- (BOOL)isCloudMatch;
- (void)purgeChatPicCache;
- (BOOL)waitingForBlocks;
- (void)chatMessageRecieved:(id)arg1 displayNotification:(BOOL)arg2;
- (void)sendData:(id)arg1 toPeer:(id)arg2 reliable:(BOOL)arg3;
- (void)sendDataToServer:(id)arg1 reliable:(BOOL)arg2;
- (void)sendChatMessage:(id)arg1 sendToClients:(id)arg2;
- (void)match:(id)arg1 didReceiveData:(id)arg2 fromPlayer:(id)arg3;
- (void)cleanup;
- (void)match:(id)arg1 didFailWithError:(id)arg2;
- (void)match:(id)arg1 connectionWithPlayerFailed:(id)arg2 withError:(id)arg3;
- (void)match:(id)arg1 player:(id)arg2 didChangeState:(long long)arg3;
- (void)setWorld:(id)arg1 clientTileLoader:(id)arg2;
- (void)dealloc;
- (id)initWithDelegate:(id)arg1 match:(id)arg2 netNodeType:(long long)arg3;

@end
