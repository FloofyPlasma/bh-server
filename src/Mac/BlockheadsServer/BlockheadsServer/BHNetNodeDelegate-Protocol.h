

#import <Foundation/Foundation.h>

@class NSArray, NSData, NSDictionary, NSMutableDictionary;

@protocol BHNetNodeDelegate <NSObject>
- (void)stop;
- (void)clearChat;
- (void)chatMessageRecieved:(NSMutableDictionary*)arg1
        displayNotification:(BOOL)arg2;

@optional
- (void)connectionSucceededToMultiplayerServerWithWorldInfo:(NSData*)arg1;
- (void)cancelSelectedWhileAttemptingToConnect;
- (void)postGCMatchInvitePlayers:(NSArray*)arg1;
- (void)connectionToServerRejectedForReason:(unsigned short)arg1
                              extraDataDict:(NSDictionary*)arg2;
- (void)playersChanged;
- (void)connectionToServerLostShouldRetry:(BOOL)arg1;
@end
