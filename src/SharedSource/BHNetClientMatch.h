#import "BHMatch.h"

#import <enet/enet.h>

@protocol BHNetClientSearchDelegate;

/**
 * @class BHNetClientMatch
 * @brief Placeholder! Please remember to fill this in.
 */
@interface BHNetClientMatch
    : BHMatch <NSNetServiceBrowserDelegate, NSNetServiceDelegate> {
  NSNetServiceBrowser* browser;
  NSMutableDictionary* domainBrowsers;
  NSMutableArray* domains;
  NSMutableArray* clientServicesWaiting;
  ENetHost* enetClient;
  ENetPeer* enetPeer;
  NSString* remotePeerID;
  NSString* userName;
  id photo;
  NSString* cloudKey;
  NSDictionary* myPlayerInfo;
  NSMutableDictionary* playerInfos;
  id<BHNetClientSearchDelegate> searchDelegate;
  NSTimer* pollTimer;
  NSMutableArray* foundHosts;
  BOOL searching;
  BOOL paused;
  BOOL isLocal;
}

/**
 * @property cloudKey
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* cloudKey; // @synthesize cloudKey;
/**
 * @property isLocal
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL isLocal; // @synthesize isLocal;
/**
 * @property photo
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) id photo; // @synthesize photo;
/**
 * @property userName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* userName; // @synthesize userName;
@property BOOL searching; // @synthesize searching;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudMatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netService:(id)arg1 didNotResolve:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPlayerInformationToServer:(id)arg1 password:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldSelectedAtIndex:(int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netServiceDidResolveAddress:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netServiceBrowser:(id)arg1
           didFindService:(id)arg2
               moreComing:(BOOL)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netServiceBrowser:(id)arg1 didFindDomain:(id)arg2 moreComing:(BOOL)arg3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)loadInfoForPlayer:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendData:(id)arg1
       toPlayers:(id)arg2
    withDataMode:(long long)arg3
           error:(id*)arg4;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)localPlayerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)localPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)playerIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startSearchForServers;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnect;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setSearchDelegate:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectToSpecificHostAndPort;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pollNetEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithSearchDelegate:(id)arg1
                        host:(id)arg2
                        port:(id)arg3
                    userName:(id)arg4
                   userPhoto:(id)arg5
                    cloudKey:(id)arg6;

@end
