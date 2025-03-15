#import <Foundation/Foundation.h>

@class GameController;

@protocol GameControllerDelegate <NSObject>
- (void)clearChat;
- (void)chatMessageRecievedFromGameController:(GameController*)arg1
                                  messageDict:(NSDictionary*)arg2;
- (void)playersChanged;
- (void)loadCompleteForGameController:(GameController*)arg1;
- (void)removeGameController:(GameController*)arg1;
@end
