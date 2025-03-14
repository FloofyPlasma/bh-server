

#import <Foundation/Foundation.h>

#import "BHMatchDelegate-Protocol.h"
#import "BHNetConstants.h"

@interface BHMatch : NSObject {
  id<BHMatchDelegate> delegate;
  NSString* host;
  NSString* port;
}

@property (readonly) NSString* port; // @synthesize port;
@property (readonly) NSString* host; // @synthesize host;

- (NSString*)cloudSalt;
- (NSString*)ownerName;
- (BOOL)owned;
- (BOOL)isCloudMatch;
- (void)disconnectPlayer:(NSString*)playerID;
- (void)removeClient:(NSString*)clientID;
- (NSArray*)connectedPlayerIDs;
- (BOOL)usesGameCenterPlayerInformation;
- (BOOL)requiresPlayerAuthentication;
- (BOOL)audioChatSupported;
- (NSString*)persistentIDForNetID:(NSString*)netID;
- (void)updatedPlayerListRecievedFromServer:(NSData*)data;
- (void)sendPlayerInformationToServer:(NSString*)serverID password:(NSString*)password;
- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary;
- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID;
- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID;
- (BOOL)sendData:(NSData*)data
       toPlayers:(NSArray*)playerIDs
    withDataMode:(BHMatchSendDataMode)mode
           error:(NSError**)error;
- (NSUInteger)expectedPlayerCount;
- (id)voiceChatWithName:(NSString*)name;
- (void)disconnect;
- (void)setDelegate:(id<BHMatchDelegate>)delegate_;
- (NSArray*)playerIDs;
- (NSString*)localPlayerName;
- (NSString*)localPlayerID;

@end
