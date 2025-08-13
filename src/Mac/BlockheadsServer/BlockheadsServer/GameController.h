#import <Foundation/Foundation.h>

#import "BHNetNodeDelegate-Protocol.h"
#import "GameConstants.h"
#import "WorldDelegate-Protocol.h"

@class BHServer, CPCache, Database, DatabaseEnvironment, NSMutableArray, NSString, NSTimer, World;
@protocol GameControllerDelegate
, NSObject;

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
- (id)appDatabaseEnvironment;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)appDatabase;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)secondaryTouchCancelled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsConnectedWithInfo:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsModWithInfo:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsAdminWithInfo:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsWhiteListedWithInfo:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsBlackListedWithInfo:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)modList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)adminList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)blackList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)whiteList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isWaitingForMultiPartCommandResponse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)handleCommand:(id)arg1 issueClient:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isControllingBlockheadsForClientPlayer:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)full;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)presentMessageUIForMessageToPlayer:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fileWriteFailed:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)viewServerWelcomeMessage:(id)arg1 customRules:(id)arg2 allowEdit:(BOOL)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showBlockheadAvailablePrompt:(int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)showDoubleTimePromptIfGoodTime:(id)arg1;
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
- (id)messageForAchivementWithIdentifier:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)presentSavedToCameraRollAlert;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showDieConfirmationForBlockhead:(id)arg1;
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
- (void)pinchZoomToScale:(float)arg1;
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
- (void)render:(float)arg1;
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
- (void)showWelcomeBackPopupWithMessage:(id)arg1;
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
- (void)sendChatMessage:(id)arg1 sendToClients:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)chatMessages;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatMessageRecieved:(id)arg1 displayNotification:(BOOL)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)worldName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)port;
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
- (id)connectedClientIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)recentPlayers;
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
- (void)update:(float)arg1 accurateDT:(float)arg2;
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
- (id)getDefaultGameSaveForWorldWithID:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithWorldNamed:(id)arg1 saveID:(id)arg2 appDelegate:(id)arg3 port:(id)arg4 maxPlayers:(int)arg5 saveDelay:(int)arg6 worldWidthMacro:(int)arg7 credit:(int)arg8 cloudSalt:(id)arg9 ownerName:(id)arg10 privacy:(id)arg11 convertToCustomRules:(BOOL)arg12 expertMode:(BOOL)arg13 appDatabase:(id)arg14 appDatabaseEnvironment:(id)arg15 noExit:(BOOL)arg16;

@end
