#include "Foundation/NSDictionary.h"
#import <Foundation/Foundation.h>

#import "BHNetNodeDelegate-Protocol.h"
#import "GameConstants.h"
#import "WorldDelegate-Protocol.h"

@class BHServer, CPCache, Database, DatabaseEnvironment, World;
@protocol GameControllerDelegate;

/**
 * @class GameController
 * @brief Placeholder! Please remember to fill this in.
 */
@interface GameController : NSObject <BHNetNodeDelegate, WorldDelegate> {
  World* world;
  BHServer* bhServer;
  NSString* worldName;
  CPCache* cache;
  NSTimer* updateTimer;
  double lastTime;
  float accumulator;
  BOOL needsToExitWorld;
  WindowInfo windowInfo;
  id<GameControllerDelegate> appDelegate;
  NSString* port;
  NSString* saveID;
  NSMutableArray* chatMessages;
  id<NSObject> appNapPreventionActivity;
  BOOL hasHadConnectedClients;
  Database* appDatabase;
  DatabaseEnvironment* appDatabaseEnvironment;
  BOOL noExit;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DatabaseEnvironment*)appDatabaseEnvironment;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Database*)appDatabase;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)secondaryTouchCancelled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsConnectedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsModWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsAdminWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsWhiteListedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsBlackListedWithInfo:(NSDictionary*)playerInfo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)modList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)adminList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)blackList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)whiteList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isWaitingForMultiPartCommandResponse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)handleCommand:(NSString*)command issueClient:(NSString*)issueClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)full;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)presentMessageUIForMessageToPlayer:(NSString*)playerId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fileWriteFailed:(NSString*)savePath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)viewServerWelcomeMessage:(NSString*)message customRules:(NSDictionary*)customRulesToUse allowEdit:(BOOL)allowEdit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showBlockheadAvailablePrompt:(int)nextBlockheadIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)showDoubleTimePromptIfGoodTime:(NSString*)priceString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startIncentivizedVideo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasRewardedVideoAvailable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)instructionsButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)displayShareUIIfAble;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)achievementsButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)messageForAchivementWithIdentifier:(NSString*)identifier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)presentSavedToCameraRollAlert;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showDieConfirmationForBlockhead:(Blockhead*)dieBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dismissIAPUIDueToError;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hdTexturesUnlocked;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pinchZoomToScale:(float)scale;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)showFreeOfferPromptIfGoodTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateiCloudRecentConnectionList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startVungleVideo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)render:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startIncentivizedShare;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)iapStarted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)exitWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doExitWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startCameraZoomForTeaserRecord;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerOK;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerLostShouldRetry:(BOOL)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showWelcomeBackPopupWithMessage:(NSString*)simulationEventsMessage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hideChatView;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showChatUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChatMessage:(NSString*)messageText sendToClients:(NSArray*)clientsToSend;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)chatMessages;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatMessageRecieved:(NSDictionary*)messageDict displayNotification:(BOOL)displayNotification;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)worldName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)port;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isRunning;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)loading;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)connectedClientIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)recentPlayers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stop;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cleanupWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dtf accurateDT:(float)accurateDT;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)idle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doIdleSafe;
/**
 * @brief Deallocates this GameController, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)getDefaultGameSaveForWorldWithID:(NSString*)saveID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GameController*)initWithWorldNamed:(NSString*)name
                               saveID:(NSString*)saveID_
                          appDelegate:(id)appDelegate_ // TODO: Find correct type
                                 port:(NSString*)port_
                           maxPlayers:(int)maxPlayers
                            saveDelay:(int)saveDelay
                      worldWidthMacro:(int)worldWidthMacro
                               credit:(int)credit
                            cloudSalt:(NSString*)cloudSalt
                            ownerName:(NSString*)ownerName
                              privacy:(NSString*)privacy
                 convertToCustomRules:(BOOL)convertToCustomRules
                           expertMode:(BOOL)expertMode
                          appDatabase:(Database*)appDatabase_
               appDatabaseEnvironment:(DatabaseEnvironment*)appDatabaseEnvironment_
                               noExit:(BOOL)noExit_;

@end
