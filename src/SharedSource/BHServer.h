#import <Foundation/Foundation.h>

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
- (void)doRepairForTileAtPos:(intpair)arg1;
- (BOOL)finishBulkTransaction;
- (void)startBulkTransaction;
- (void)sendPortalChestAcknowledgementIfNeededForClient:(id)arg1;
- (id)getRecentPlayerNamesForOwnershipSign;
- (void)sendPlayerChangedNotifcationToDelegate;
- (BOOL)isWaitingForMultiPartCommandResponse;
- (id)privacyString;
- (id)serverPlayerID;
- (id)playerNameForPlayerWithIDIncludingOldPlayers:(id)arg1;
- (void)updateCredit:(float)arg1;
- (float)credit;
- (BOOL)isCloudMatch;
- (id)getDebugLog;
- (void)handleCommand:(id)arg1 issueClient:(id)arg2;
- (id)removeCurseWordsFromBlockheadName:(id)arg1;
- (id)replaceCurseWordsForMessage:(id)arg1 client:(id)arg2;
- (id)modifyListForPlayerOrIP:(id)arg1
                      isAdded:(BOOL)arg2
                     listType:(int)arg3
                      banUDID:(BOOL)arg4;
- (id)modifyListForPlayerOrIP:(id)arg1 isAdded:(BOOL)arg2 listType:(int)arg3;
- (void)clearList:(int)arg1;
- (void)reloadLists;
- (void)delayedSendUpdatedPlayerListToClients;
- (void)sendUpdatedPlayerListToClients;
- (void)sendInitialPlayerListToClient:(id)arg1;
- (id)playerListToSendIncludingPhotosForClients:(id)arg1 sendClient:(id)arg2;
- (void)clientFinishedAwaySimulation:(id)arg1;
- (void)sendChatMessage:(id)arg1
    displayNotification:(BOOL)arg2
          sendToClients:(id)arg3;
- (BOOL)match:(id)arg1 shouldReinvitePlayer:(id)arg2;
- (void)sendNetworkData:(id)arg1 toPeers:(id)arg2 reliable:(BOOL)arg3;
- (void)match:(id)arg1 didReceiveData:(id)arg2 fromPlayer:(id)arg3;
- (BOOL)playerIsConnectedWithInfo:(id)arg1;
- (void)updatePlayers;
- (void)updatePlayer:(id)arg1;
- (BOOL)playerIsModWithAlias:(id)arg1;
- (BOOL)playerIsAdminWithAlias:(id)arg1;
- (BOOL)playerIsAdminWithID:(id)arg1;
- (BOOL)playerIsCloudWideInvisibleAdminWithAlias:(id)arg1;
- (BOOL)playerIsCloudWideAdminWithAlias:(id)arg1;
- (BOOL)playerIsOwnerWithAlias:(id)arg1;
- (BOOL)playerIsWhiteListedWithInfo:(id)arg1;
- (BOOL)playerIsBannedWithID:(id)arg1;
- (id)savedPlayerInfoDataForPlayer:(id)arg1;
- (BOOL)playerIsBlackListedWithInfo:(id)arg1;
- (void)infoArrived:(id)arg1 forPlayer:(id)arg2;
- (void)fullPlayerInformationNowAvailableForPlayer:(id)arg1;
- (BOOL)full;
- (void)match:(id)arg1 player:(id)arg2 didChangeState:(long long)arg3;
- (void)addPlayerDictToAllPlayersEver:(id)arg1;
- (void)match:(id)arg1 connectionWithPlayerFailed:(id)arg2 withError:(id)arg3;
- (void)cleanup;
- (void)match:(id)arg1 didFailWithError:(id)arg2;
- (void)setWorld:(id)arg1;
- (void)dealloc;
- (void)saveResetList;
- (void)saveAllPlayersArray;
- (void)bootPlayerNamed:(id)arg1 wasBan:(BOOL)arg2;
- (void)bootAllClientsDueToNoCredit;
- (void)delayedDisconnectPlayerDueToNoCreditWithID:(id)arg1;
- (void)bootPlayer:(id)arg1 wasBan:(BOOL)arg2;
- (void)delayedDisconnectPlayerDueToKickWithID:(id)arg1;
- (void)clientDisconnected:(id)arg1 wasKick:(BOOL)arg2;
- (id)initWithDelegate:(id)arg1
                 match:(id)arg2
           netNodeType:(long long)arg3
                saveID:(id)arg4
            maxPlayers:(int)arg5;

@end
