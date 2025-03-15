#import "BHMatch.h"

@class NSDictionary, NSMutableArray, NSMutableDictionary, NSNetServiceBrowser,
    NSString, NSTimer;
@protocol BHNetClientSearchDelegate;

@interface BHNetClientMatch
    : BHMatch <NSNetServiceBrowserDelegate, NSNetServiceDelegate> {
  NSNetServiceBrowser* browser;
  NSMutableDictionary* domainBrowsers;
  NSMutableArray* domains;
  NSMutableArray* clientServicesWaiting;
  struct _ENetHost* enetClient;
  struct _ENetPeer* enetPeer;
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

@property (readonly) NSString* cloudKey; // @synthesize cloudKey;
@property (readonly) BOOL isLocal; // @synthesize isLocal;
@property (readonly) id photo; // @synthesize photo;
@property (readonly) NSString* userName; // @synthesize userName;
@property BOOL searching; // @synthesize searching;
- (BOOL)isCloudMatch;
- (void)netService:(id)arg1 didNotResolve:(id)arg2;
- (void)sendPlayerInformationToServer:(id)arg1 password:(id)arg2;
- (void)worldSelectedAtIndex:(int)arg1;
- (void)netServiceDidResolveAddress:(id)arg1;
- (void)netServiceBrowser:(id)arg1
           didFindService:(id)arg2
               moreComing:(BOOL)arg3;
- (void)netServiceBrowser:(id)arg1 didFindDomain:(id)arg2 moreComing:(BOOL)arg3;
- (id)loadInfoForPlayer:(id)arg1;
- (BOOL)sendData:(id)arg1
       toPlayers:(id)arg2
    withDataMode:(long long)arg3
           error:(id*)arg4;
- (id)localPlayerName;
- (id)localPlayerID;
- (id)playerIDs;
- (void)startSearchForServers;
- (void)dealloc;
- (void)disconnect;
- (void)setSearchDelegate:(id)arg1;
- (void)connectToSpecificHostAndPort;
- (void)pollNetEvents;
- (id)initWithSearchDelegate:(id)arg1
                        host:(id)arg2
                        port:(id)arg3
                    userName:(id)arg4
                   userPhoto:(id)arg5
                    cloudKey:(id)arg6;


@end
