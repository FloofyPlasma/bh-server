#import <Foundation/Foundation.h>

@protocol BHNetNodeDelegate <NSObject>
- (void)stop;
- (void)clearChat;
- (void)chatMessageRecieved:(NSDictionary*)messageDict displayNotification:(BOOL)displayNotification;

@optional

- (void)connectionSucceededToMultiplayerServerWithWorldInfo:(NSData*)arg1;
- (void)cancelSelectedWhileAttemptingToConnect;
- (void)postGCMatchInvitePlayers:(NSArray*)arg1;
- (void)connectionToServerRejectedForReason:(unsigned short)arg1 extraDataDict:(NSDictionary*)arg2;
- (void)playersChanged;
- (void)connectionToServerLostShouldRetry:(BOOL)shouldRetry;
@end
