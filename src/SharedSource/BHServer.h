#import <Foundation/Foundation.h>

#import "BHNetConstants.h"
#import "BHNetNode.h"
#import "MJMath.h"

enum ListType {
  LIST_TYPE_BLACKLIST = 0x0,
  LIST_TYPE_WHITELIST = 0x1,
  LIST_TYPE_ADMIN = 0x2,
  LIST_TYPE_MOD = 0x3,
};

@class Database, DatabaseEnvironment, World;

@interface BHServer : BHNetNode {
  World* world;
  NSString* saveID;
  NSMutableArray* unapprovedClients;
  NSMutableArray* connectedClients;
  NSMutableArray* chatHistory;
  NSMutableArray* recentPlayers;
  NSArray* blackList;
  NSArray* curseList;
  NSArray* whiteList;
  NSArray* adminList;
  NSArray* cloudWideAdminList;
  NSArray* cloudWideInvisibleAdminList;
  NSArray* modList;
  NSMutableArray* resetList;
  NSMutableSet* repairSet;
  int maxPlayers;
  NSMutableDictionary* cachedPlayerImages;
  NSMutableDictionary* cachedPlayerBanned;
  BOOL needsToSendUpdatedListToClients;
  NSMutableArray* clientsWaitingForInitialData;
  NSMutableArray* clientsConnectedWithPhotosUnsent;
  NSMutableDictionary* tradePortalTransactions;
  NSString* playerUpdate;
  float playerUpdateTimer;
  double lastPlayerUpdate;
  double rulesChangedTime;
  DatabaseEnvironment* serverDatabaseEnvironment;
  Database* serverDatabase;
}

@property (readonly) NSArray* connectedClientIDs; // @synthesize connectedClientIDs=connectedClients;
@property (readonly) Database* serverDatabase; // @synthesize serverDatabase;
@property (readonly) NSString* playerUpdate; // @synthesize playerUpdate;
@property (readonly) NSArray* modList; // @synthesize modList;
@property (readonly) NSArray* adminList; // @synthesize adminList;
@property (readonly) NSArray* whiteList; // @synthesize whiteList;
@property (readonly) NSArray* blackList; // @synthesize blackList;
@property (readonly) NSArray* recentPlayers; // @synthesize recentPlayers;
- (void)doRepairForTileAtPos:(intpair)pos;
- (BOOL)finishBulkTransaction;
- (void)startBulkTransaction;
- (void)sendPortalChestAcknowledgementIfNeededForClient:(NSString*)clientID;
- (NSArray*)getRecentPlayerNamesForOwnershipSign;
- (void)sendPlayerChangedNotifcationToDelegate;
- (BOOL)isWaitingForMultiPartCommandResponse;
- (NSString*)privacyString;
- (NSString*)serverPlayerID;
- (NSString*)playerNameForPlayerWithIDIncludingOldPlayers:(NSString*)playerID;
- (void)updateCredit:(float)dt;
- (float)credit;
- (BOOL)isCloudMatch;
- (NSString*)getDebugLog;
- (void)handleCommand:(NSString*)command issueClient:(NSString*)issueClient;
- (NSString*)removeCurseWordsFromBlockheadName:(NSString*)blockheadName;
- (NSString*)replaceCurseWordsForMessage:(NSString*)message client:(NSString*)playerID;
- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP
                             isAdded:(BOOL)isAdded
                            listType:(ListType)listType
                             banUDID:(BOOL)banUDID;
- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP isAdded:(BOOL)isAdded listType:(ListType)listType;
- (void)clearList:(ListType)listType;
- (void)reloadLists;
- (void)delayedSendUpdatedPlayerListToClients;
- (void)sendUpdatedPlayerListToClients;
- (void)sendInitialPlayerListToClient:(NSString*)sendClient;
- (NSArray*)playerListToSendIncludingPhotosForClients:(NSArray*)includingClients sendClient:(NSString*)sendClient;
- (void)clientFinishedAwaySimulation:(NSString*)clientID;
- (void)sendChatMessage:(NSString*)messageText
    displayNotification:(BOOL)displayNotification
          sendToClients:(NSArray*)clientsToSend;
- (BOOL)match:(BHMatch*)match shouldReinvitePlayer:(NSString*)playerID;
- (void)sendNetworkData:(NSData*)netData toPeers:(NSArray*)peers reliable:(BOOL)reliable;
- (void)match:(BHMatch*)match_ didReceiveData:(NSData*)data fromPlayer:(NSString*)peer;
- (BOOL)playerIsConnectedWithInfo:(NSDictionary*)playerInfo;
- (void)updatePlayers;
- (void)updatePlayer:(NSString*)clientID;
- (BOOL)playerIsModWithAlias:(NSString*)alias;
- (BOOL)playerIsAdminWithAlias:(NSString*)alias;
- (BOOL)playerIsAdminWithID:(NSString*)playerID;
- (BOOL)playerIsCloudWideInvisibleAdminWithAlias:(NSString*)alias;
- (BOOL)playerIsCloudWideAdminWithAlias:(NSString*)alias;
- (BOOL)playerIsOwnerWithAlias:(NSString*)alias;
- (BOOL)playerIsWhiteListedWithInfo:(NSDictionary*)playerInfo;
- (BOOL)playerIsBannedWithID:(NSString*)playerID;
- (NSData*)savedPlayerInfoDataForPlayer:(NSString*)playerID;
- (BOOL)playerIsBlackListedWithInfo:(NSDictionary*)playerInfo;
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
- (void)fullPlayerInformationNowAvailableForPlayer:(NSString*)playerID;
- (BOOL)full;
- (void)match:(BHMatch*)match_ player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
- (void)addPlayerDictToAllPlayersEver:(NSDictionary*)playerDict;
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
- (void)cleanup;
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
- (void)setWorld:(World*)world_;
- (void)saveResetList;
- (void)saveAllPlayersArray;
- (void)bootPlayerNamed:(NSString*)playerName wasBan:(BOOL)wasBan;
- (void)bootAllClientsDueToNoCredit;
- (void)delayedDisconnectPlayerDueToNoCreditWithID:(NSString*)playerID;
- (void)bootPlayer:(NSString*)playerID wasBan:(BOOL)wasBan;
- (void)delayedDisconnectPlayerDueToKickWithID:(NSString*)playerID;
- (void)clientDisconnected:(NSString*)playerID wasKick:(BOOL)wasKick;
- (BHServer*)initWithDelegate:(id)delegate_ //* TODO: Figure out what this delegate is...
                 match:(BHMatch*)match_
           netNodeType:(BHNetNodeType)netNodeType_
                saveID:(NSString*)saveID_
            maxPlayers:(int)maxPlayers_;

@end
