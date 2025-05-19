#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <enet/enet.h>

#import "BHMatch.h"
#import "BHNetConstants.h"

@interface BHNetServerMatch : BHMatch <NSNetServiceDelegate> {
  uint16_t serverPort;
  NSNetService* reliableServerService;
  __CFSocket* reliableServerListeningSocket;
  ENetHost* enetServer;
  NSMutableDictionary* connections;
  NSMutableDictionary* persistentIdsToEnetIds;
  NSMutableDictionary* enetIdsToPersistentIds;
  NSMutableArray* playerInfos;
  NSString* userName;
  NSString* worldName;
  NSString* ownerName;
  NSString* cloudSalt;
  uint16_t portToUse;
  BOOL hasLocalPLayer;
  NSTimer* pollTimer;
  float noCreditBootTimer;
  double credit;
  double pollTimerLastTime;
  BHNetPrivacy privacy;
}

@property BHNetPrivacy privacy; // @synthesize privacy;
- (BOOL)requiresPlayerAuthentication;
- (NSString*)persistentIDForNetID:(NSString*)netID;
- (void)netServiceDidResolveAddress:(NSNetService*)sender;
- (void)netService:(NSNetService*)sender didNotResolve:(NSDictionary*)errorDict;
- (void)netService:(NSNetService*)sender didNotPublish:(NSDictionary*)errorDict;
- (BOOL)startServer;
- (void)removeClient:(NSString*)clientID;
- (void)pollNetEvents;
- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary;
- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID;
- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID;
- (BOOL)sendData:(NSData*)data
       toPlayers:(NSArray*)playerIDs
    withDataMode:(BHMatchSendDataMode)mode
           error:(NSError**)error;
- (BOOL)isCloudMatch;
- (NSString*)cloudSalt;
- (NSString*)ownerName;
- (NSArray*)playerIDs;
- (NSString*)localPlayerName;
- (NSString*)localPlayerID;
- (void)dealloc;
- (void)disconnect;
- (void)disconnectPlayer:(NSString*)playerID;
- (void)setCloudSalt:(NSString*)newSalt;
- (BOOL)owned;
- (void)setOwner:(NSString*)newOwnerName;
- (float)credit;
- (void)setCredit:(float)newCredit;
- (id)initWithPort:(NSString*)port_
          userName:(NSString*)port_
             photo:(id)photo // TODO: This doesn't have a known type yet
    hasLocalPLayer:(BOOL)photo
         worldName:(NSString*)worldName_
            credit:(float)credit_
         cloudSalt:(NSString*)credit_
         ownerName:(NSString*)ownerName_
           privacy:(NSString*)ownerName_;
- (void)setPrivacyByString:(NSString*)privacyString;

@end
