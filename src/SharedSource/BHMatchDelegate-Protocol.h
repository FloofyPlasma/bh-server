#import <Foundation/Foundation.h>

#import "BHNetConstants.h"

@class BHMatch;

@protocol BHMatchDelegate

@optional
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)bootAllClientsDueToNoCredit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePlayerList:(NSArray*)playerListIncoming;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)match:(BHMatch*)match shouldReinvitePlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match didReceiveData:(NSData*)data fromPlayer:(NSString*)peerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
@end
