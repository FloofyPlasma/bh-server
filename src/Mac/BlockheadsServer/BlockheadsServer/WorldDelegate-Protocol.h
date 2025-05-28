#import <Foundation/Foundation.h>

@class Blockhead, Database, DatabaseEnvironment, NSDictionary, NSString;

@protocol WorldDelegate
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)viewServerWelcomeMessage:(NSString*)message
                     customRules:(NSDictionary*)customRulesToUse
                       allowEdit:(BOOL)allowEdit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showDieConfirmationForBlockhead:(Blockhead*)dieBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pinchZoomToScale:(float)scale;
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
- (void)fileWriteFailed:(NSString*)savePath;
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
- (void)instructionsButtonTapped;
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
- (NSDictionary*)getDefaultGameSaveForWorldWithID:(NSString*)saveID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateiCloudRecentConnectionList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)secondaryTouchCancelled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)presentSavedToCameraRollAlert;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)render:(float)dt;
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
- (DatabaseEnvironment*)appDatabaseEnvironment;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Database*)appDatabase;
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
- (void)startCameraZoomForTeaserRecord;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerOK;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerLostShouldRetry:(BOOL)shouldRetry;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showWelcomeBackPopupWithMessage:(NSString*)simulationEventsMessage;
@end
