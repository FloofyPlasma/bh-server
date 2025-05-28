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

/**
 * @class BHServer
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @property connectedClientIDs
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* connectedClientIDs; // @synthesize connectedClientIDs=connectedClients;
/**
 * @property serverDatabase
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Database* serverDatabase; // @synthesize serverDatabase;
/**
 * @property playerUpdate
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* playerUpdate; // @synthesize playerUpdate;
/**
 * @property modList
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* modList; // @synthesize modList;
/**
 * @property adminList
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* adminList; // @synthesize adminList;
/**
 * @property whiteList
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* whiteList; // @synthesize whiteList;
/**
 * @property blackList
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* blackList; // @synthesize blackList;
/**
 * @property recentPlayers
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* recentPlayers; // @synthesize recentPlayers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doRepairForTileAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)finishBulkTransaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startBulkTransaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPortalChestAcknowledgementIfNeededForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)getRecentPlayerNamesForOwnershipSign;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPlayerChangedNotifcationToDelegate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isWaitingForMultiPartCommandResponse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)privacyString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)serverPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)playerNameForPlayerWithIDIncludingOldPlayers:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateCredit:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)credit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudMatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)getDebugLog;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)handleCommand:(NSString*)command issueClient:(NSString*)issueClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)removeCurseWordsFromBlockheadName:(NSString*)blockheadName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)replaceCurseWordsForMessage:(NSString*)message client:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP
                             isAdded:(BOOL)isAdded
                            listType:(ListType)listType
                             banUDID:(BOOL)banUDID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP isAdded:(BOOL)isAdded listType:(ListType)listType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearList:(ListType)listType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadLists;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)delayedSendUpdatedPlayerListToClients;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendUpdatedPlayerListToClients;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendInitialPlayerListToClient:(NSString*)sendClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)playerListToSendIncludingPhotosForClients:(NSArray*)includingClients sendClient:(NSString*)sendClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientFinishedAwaySimulation:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChatMessage:(NSString*)messageText
    displayNotification:(BOOL)displayNotification
          sendToClients:(NSArray*)clientsToSend;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)match:(BHMatch*)match shouldReinvitePlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNetworkData:(NSData*)netData toPeers:(NSArray*)peers reliable:(BOOL)reliable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match_ didReceiveData:(NSData*)data fromPlayer:(NSString*)peer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsConnectedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePlayers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePlayer:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsModWithAlias:(NSString*)alias;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsAdminWithAlias:(NSString*)alias;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsAdminWithID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsCloudWideInvisibleAdminWithAlias:(NSString*)alias;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsCloudWideAdminWithAlias:(NSString*)alias;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsOwnerWithAlias:(NSString*)alias;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsWhiteListedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsBannedWithID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)savedPlayerInfoDataForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsBlackListedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fullPlayerInformationNowAvailableForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)full;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match_ player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addPlayerDictToAllPlayersEver:(NSDictionary*)playerDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cleanup;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorld:(World*)world_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveResetList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveAllPlayersArray;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)bootPlayerNamed:(NSString*)playerName wasBan:(BOOL)wasBan;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)bootAllClientsDueToNoCredit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)delayedDisconnectPlayerDueToNoCreditWithID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)bootPlayer:(NSString*)playerID wasBan:(BOOL)wasBan;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)delayedDisconnectPlayerDueToKickWithID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientDisconnected:(NSString*)playerID wasKick:(BOOL)wasKick;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BHServer*)initWithDelegate:(id)delegate_ //* TODO: Figure out what this delegate is...
                        match:(BHMatch*)match_
                  netNodeType:(BHNetNodeType)netNodeType_
                       saveID:(NSString*)saveID_
                   maxPlayers:(int)maxPlayers_;

@end
