#import "BHNetServerMatch.h"

@implementation BHNetServerMatch

- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary
{
}

- (BOOL)isCloudMatch
{
  return NO;
}

- (BOOL)owned
{
  return NO;
}

- (BOOL)requiresPlayerAuthentication
{
  return NO;
}

- (BOOL)sendData:(NSData*)data toPlayers:(NSArray*)playerIDs withDataMode:(BHMatchSendDataMode)mode error:(NSError**)error
{
  return NO;
}

- (BOOL)startServer
{
  return NO;
}

- (NSArray*)playerIDs
{
  return nil;
}

- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID
{
  return nil;
}

- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID
{
  return nil;
}

- (NSString*)cloudSalt
{
  return nil;
}

- (NSString*)localPlayerID
{
  return nil;
}

- (NSString*)localPlayerName
{
  return nil;
}

- (NSString*)ownerName
{
  return nil;
}

- (NSString*)persistentIDForNetID:(NSString*)netID
{
  return nil;
}

- (float)credit
{
  return 0;
}

- (id)initWithPort:(NSString*)port_ userName:(NSString*)userName_ photo:(id)photo hasLocalPLayer:(BOOL)hasLocalPlayer worldName:(NSString*)worldName_ credit:(float)credit_ cloudSalt:(NSString*)cloudSalt_ ownerName:(NSString*)ownerName_ privacy:(NSString*)privacy
{
  return nil;
}

- (void)dealloc
{
}

- (void)disconnect
{
}

- (void)disconnectPlayer:(NSString*)playerID
{
}

- (void)netService:(NSNetService*)sender didNotPublish:(NSDictionary*)errorDict
{
}

- (void)netService:(NSNetService*)sender didNotResolve:(NSDictionary*)errorDict
{
}

- (void)netServiceDidResolveAddress:(NSNetService*)sender
{
}

- (void)pollNetEvents
{
}

- (void)removeClient:(NSString*)clientID
{
}

- (void)setCloudSalt:(NSString*)newSalt
{
}

- (void)setCredit:(float)newCredit
{
}

- (void)setOwner:(NSString*)newOwnerName
{
}

- (void)setPrivacyByString:(NSString*)privacyString
{
}

@end