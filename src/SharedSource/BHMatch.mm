#import "BHMatch.h"

@implementation BHMatch

@synthesize port;
@synthesize host;

- (NSString*)cloudSalt
{
  return NULL;
}

- (NSString*)ownerName
{
  return NULL;
}

- (BOOL)owned
{
  return NO;
}

- (BOOL)isCloudMatch
{
  return NO;
}

- (void)disconnectPlayer:(NSString*)playerID
{
  return;
}

- (void)removeClient:(NSString*)clientID
{
  return;
}

- (NSArray*)connectedPlayerIDs
{
  return NULL;
}

- (BOOL)usesGameCenterPlayerInformation
{
  return NO;
}

- (BOOL)requiresPlayerAuthentication
{
  return NO;
}

- (BOOL)audioChatSupported
{
  return NO;
}

- (NSString*)persistentIDForNetID:(NSString*)netID
{
  return netID;
}

- (void)updatedPlayerListRecievedFromServer:(NSData*)data
{
  if (data) {
    [self->delegate updatePlayerList:[NSPropertyListSerialization propertyListWithData:data options:2 format:0 error:NULL]];
  } else {
    [self->delegate updatePlayerList:NULL];
  }
}

- (void)sendPlayerInformationToServer:(NSString*)serverID password:(NSString*)password
{
  return;
}

- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary
{
  return;
}

- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID
{
  return NULL;
}

- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID
{
  return [NSMutableDictionary dictionaryWithObject:playerID forKey:@"playerID"];
}

- (BOOL)sendData:(NSData*)data toPlayers:(NSArray*)playerIDs withDataMode:(BHMatchSendDataMode)mode error:(NSError* __autoreleasing*)error
{
  return NO;
}

- (NSUInteger)expectedPlayerCount
{
  return NO;
}

- (id)voiceChatWithName:(NSString*)name
{
  return NULL;
}

- (void)disconnect
{
  return;
}

- (void)setDelegate:(__autoreleasing id<BHMatchDelegate>)delegate_
{
  self->delegate = delegate_;
}

- (NSArray*)playerIDs
{
  return NULL;
}

- (NSString*)localPlayerName
{
  return @"local_player";
}

- (NSString*)localPlayerID
{
  return @"local_player";
}

@end
