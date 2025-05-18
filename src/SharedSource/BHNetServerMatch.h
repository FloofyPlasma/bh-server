#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <enet/enet.h>

#import "BHMatch.h"
#import "BHNetConstants.h"

@interface BHNetServerMatch : BHMatch <NSNetServiceDelegate> {
  unsigned short serverPort;
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
  unsigned short portToUse;
  BOOL hasLocalPLayer;
  NSTimer* pollTimer;
  float noCreditBootTimer;
  double credit;
  double pollTimerLastTime;
  BHNetPrivacy privacy;
}

@property BHNetPrivacy privacy; // @synthesize privacy;
- (BOOL)requiresPlayerAuthentication;
- (id)persistentIDForNetID:(id)arg1;
- (void)netServiceDidResolveAddress:(id)arg1;
- (void)netService:(id)arg1 didNotResolve:(id)arg2;
- (void)netService:(id)arg1 didNotPublish:(id)arg2;
- (BOOL)startServer;
- (void)removeClient:(id)arg1;
- (void)pollNetEvents;
- (void)clientApprovedWithInfo:(id)arg1;
- (id)clientPlayerInformationRecieved:(id)arg1 fromPeer:(id)arg2;
- (id)loadInfoForPlayer:(id)arg1;
- (BOOL)sendData:(id)arg1
       toPlayers:(id)arg2
    withDataMode:(long long)arg3
           error:(id*)arg4;
- (BOOL)isCloudMatch;
- (id)cloudSalt;
- (id)ownerName;
- (id)playerIDs;
- (id)localPlayerName;
- (id)localPlayerID;
- (void)dealloc;
- (void)disconnect;
- (void)disconnectPlayer:(id)arg1;
- (void)setCloudSalt:(id)arg1;
- (BOOL)owned;
- (void)setOwner:(id)arg1;
- (float)credit;
- (void)setCredit:(float)arg1;
- (id)initWithPort:(id)arg1
          userName:(id)arg2
             photo:(id)arg3
    hasLocalPLayer:(BOOL)arg4
         worldName:(id)arg5
            credit:(float)arg6
         cloudSalt:(id)arg7
         ownerName:(id)arg8
           privacy:(id)arg9;
- (void)setPrivacyByString:(id)arg1;

@end
