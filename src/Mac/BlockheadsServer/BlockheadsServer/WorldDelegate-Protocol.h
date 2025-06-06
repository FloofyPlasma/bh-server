#import <Foundation/Foundation.h>

@class Blockhead, Database, DatabaseEnvironment, NSDictionary, NSString;

@protocol WorldDelegate
- (void)viewServerWelcomeMessage:(NSString*)message
                     customRules:(NSDictionary*)customRulesToUse
                       allowEdit:(BOOL)allowEdit;
- (void)showDieConfirmationForBlockhead:(Blockhead*)dieBlockhead;
- (void)pinchZoomToScale:(float)scale;
- (void)hideChatView;
- (void)showChatUI;
- (void)fileWriteFailed:(NSString*)savePath;
- (void)showBlockheadAvailablePrompt:(int)nextBlockheadIndex;
- (BOOL)showDoubleTimePromptIfGoodTime:(NSString*)priceString;
- (void)instructionsButtonTapped;
- (void)achievementsButtonTapped;
- (NSString*)messageForAchivementWithIdentifier:(NSString*)identifier;
- (NSDictionary*)getDefaultGameSaveForWorldWithID:(NSString*)saveID;
- (void)updateiCloudRecentConnectionList;
- (BOOL)secondaryTouchCancelled;
- (void)presentSavedToCameraRollAlert;
- (void)render:(float)dt;
- (void)startIncentivizedVideo;
- (BOOL)hasRewardedVideoAvailable;
- (DatabaseEnvironment*)appDatabaseEnvironment;
- (Database*)appDatabase;
- (void)iapStarted;
- (void)exitWorld;
- (void)startCameraZoomForTeaserRecord;
- (void)setPaused:(BOOL)paused;
- (void)connectionToServerOK;
- (void)connectionToServerLostShouldRetry:(BOOL)shouldRetry;
- (void)showWelcomeBackPopupWithMessage:(NSString*)simulationEventsMessage;
@end
