#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <enet/enet.h>

#import "BHMatch.h"
#import "BHNetConstants.h"

/**
 * @class BHNetServerMatch
 * @brief Placeholder! Please remember to fill this in.
 */
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
  BHNetPrivacy _privacy;
}

@property BHNetPrivacy privacy; // @synthesize privacy;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPlayerAuthentication;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)persistentIDForNetID:(NSString*)netID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netServiceDidResolveAddress:(NSNetService*)sender;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netService:(NSNetService*)sender didNotResolve:(NSDictionary*)errorDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netService:(NSNetService*)sender didNotPublish:(NSDictionary*)errorDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)startServer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pollNetEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendData:(NSData*)data
       toPlayers:(NSArray*)playerIDs
    withDataMode:(BHMatchSendDataMode)mode
           error:(NSError**)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudMatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cloudSalt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)ownerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)playerIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnect;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnectPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setCloudSalt:(NSString*)newSalt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)owned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setOwner:(NSString*)newOwnerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)credit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setCredit:(float)newCredit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithPort:(NSString*)port_
          userName:(NSString*)port_
             photo:(id)photo // TODO: This doesn't have a known type yet
    hasLocalPLayer:(BOOL)photo
         worldName:(NSString*)worldName_
            credit:(float)credit_
         cloudSalt:(NSString*)credit_
         ownerName:(NSString*)ownerName_
           privacy:(NSString*)ownerName_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPrivacyByString:(NSString*)privacyString;

@end
