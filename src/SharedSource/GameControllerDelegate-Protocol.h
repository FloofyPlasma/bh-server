#import <Foundation/Foundation.h>

@class GameController;

@protocol GameControllerDelegate <NSObject>
- (void)clearChat;
- (void)chatMessageRecievedFromGameController:(GameController*)gameController
                                  messageDict:(NSDictionary*)messageDict;
- (void)playersChanged;
- (void)loadCompleteForGameController:(GameController*)gameController_;
- (void)removeGameController:(GameController*)gameController_;
@end
