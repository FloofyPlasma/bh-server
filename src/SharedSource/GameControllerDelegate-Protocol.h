

#import "NSObject-Protocol.h"

@class GameController, NSDictionary;

@protocol GameControllerDelegate <NSObject>
- (void)clearChat;
- (void)chatMessageRecievedFromGameController:(GameController*)arg1
                                  messageDict:(NSDictionary*)arg2;
- (void)playersChanged;
- (void)loadCompleteForGameController:(GameController*)arg1;
- (void)removeGameController:(GameController*)arg1;
@end
