#import <Foundation/Foundation.h>

@protocol BHNetNodeDelegate <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stop;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatMessageRecieved:(NSDictionary*)messageDict displayNotification:(BOOL)displayNotification;

@optional

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionSucceededToMultiplayerServerWithWorldInfo:(NSData*)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cancelSelectedWhileAttemptingToConnect;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)postGCMatchInvitePlayers:(NSArray*)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerRejectedForReason:(unsigned short)arg1 extraDataDict:(NSDictionary*)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerLostShouldRetry:(BOOL)shouldRetry;
@end
