#import <Foundation/Foundation.h>

#import "BHNetConstants.h"

@class BHMatch;

@protocol BHMatchDelegate

@optional
- (void)bootAllClientsDueToNoCredit;
- (void)updatePlayerList:(NSArray*)playerListIncoming;
- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID;
- (BOOL)match:(BHMatch*)match shouldReinvitePlayer:(NSString*)playerID;
- (void)match:(BHMatch*)match player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state;
- (void)match:(BHMatch*)match didReceiveData:(NSData*)data fromPlayer:(NSString*)peerID;
- (void)match:(BHMatch*)match didFailWithError:(NSError*)error;
- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error;
@end
