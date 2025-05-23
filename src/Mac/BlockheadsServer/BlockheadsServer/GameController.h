#import <Foundation/Foundation.h>

#import "BHNetNodeDelegate-Protocol.h"
#import "GameConstants.h"
#import "WorldDelegate-Protocol.h"

@class BHServer, CPCache, Database, DatabaseEnvironment, NSMutableArray, NSString, NSTimer, World;
@protocol GameControllerDelegate
, NSObject;

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

- (id)appDatabaseEnvironment;
- (id)appDatabase;
- (BOOL)secondaryTouchCancelled;
- (BOOL)playerIsConnectedWithInfo:(id)arg1;
- (BOOL)playerIsModWithInfo:(id)arg1;
- (BOOL)playerIsAdminWithInfo:(id)arg1;
- (BOOL)playerIsWhiteListedWithInfo:(id)arg1;
- (BOOL)playerIsBlackListedWithInfo:(id)arg1;
- (id)modList;
- (id)adminList;
- (id)blackList;
- (id)whiteList;
- (BOOL)isWaitingForMultiPartCommandResponse;
- (void)handleCommand:(id)arg1 issueClient:(id)arg2;
- (BOOL)isControllingBlockheadsForClientPlayer:(id)arg1;
- (BOOL)full;
- (void)presentMessageUIForMessageToPlayer:(id)arg1;
- (void)fileWriteFailed:(id)arg1;
- (void)viewServerWelcomeMessage:(id)arg1 customRules:(id)arg2 allowEdit:(BOOL)arg3;
- (void)showBlockheadAvailablePrompt:(int)arg1;
- (BOOL)showDoubleTimePromptIfGoodTime:(id)arg1;
- (void)startIncentivizedVideo;
- (BOOL)hasRewardedVideoAvailable;
- (void)instructionsButtonTapped;
- (void)displayShareUIIfAble;
- (void)achievementsButtonTapped;
- (id)messageForAchivementWithIdentifier:(id)arg1;
- (void)presentSavedToCameraRollAlert;
- (void)showDieConfirmationForBlockhead:(id)arg1;
- (void)dismissIAPUIDueToError;
- (BOOL)hdTexturesUnlocked;
- (void)pinchZoomToScale:(float)arg1;
- (BOOL)showFreeOfferPromptIfGoodTime;
- (void)updateiCloudRecentConnectionList;
- (void)startVungleVideo;
- (void)render:(float)arg1;
- (void)startIncentivizedShare;
- (void)iapStarted;
- (void)exitWorld;
- (void)doExitWorld;
- (void)startCameraZoomForTeaserRecord;
- (void)setPaused:(BOOL)arg1;
- (void)connectionToServerOK;
- (void)connectionToServerLostShouldRetry:(BOOL)arg1;
- (void)showWelcomeBackPopupWithMessage:(id)arg1;
- (void)hideChatView;
- (void)showChatUI;
- (void)sendChatMessage:(id)arg1 sendToClients:(id)arg2;
- (id)chatMessages;
- (void)clearChat;
- (void)chatMessageRecieved:(id)arg1 displayNotification:(BOOL)arg2;
- (void)playersChanged;
- (id)worldName;
- (id)port;
- (BOOL)isRunning;
- (BOOL)loading;
- (id)connectedClientIDs;
- (id)recentPlayers;
- (void)stop;
- (void)cleanupWorld;
- (void)update:(float)arg1 accurateDT:(float)arg2;
- (void)idle;
- (void)doIdleSafe;
- (void)dealloc;
- (id)getDefaultGameSaveForWorldWithID:(id)arg1;
- (id)initWithWorldNamed:(id)arg1 saveID:(id)arg2 appDelegate:(id)arg3 port:(id)arg4 maxPlayers:(int)arg5 saveDelay:(int)arg6 worldWidthMacro:(int)arg7 credit:(int)arg8 cloudSalt:(id)arg9 ownerName:(id)arg10 privacy:(id)arg11 convertToCustomRules:(BOOL)arg12 expertMode:(BOOL)arg13 appDatabase:(id)arg14 appDatabaseEnvironment:(id)arg15 noExit:(BOOL)arg16;

@end
