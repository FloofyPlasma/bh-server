#import <Foundation/Foundation.h>

@class GameController;

@protocol GameControllerDelegate <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearChat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatMessageRecievedFromGameController:(GameController*)gameController
                                  messageDict:(NSDictionary*)messageDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadCompleteForGameController:(GameController*)gameController_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeGameController:(GameController*)gameController_;
@end
