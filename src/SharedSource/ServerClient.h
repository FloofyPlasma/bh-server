#import <Foundation/Foundation.h>

#import <set>

#import "MJMath.h"
#import "World.h"

@class BHServer, Database;

@interface ServerClient : NSObject {
  NSString* clientID;
  BHServer* server;
  NSMutableIndexSet* requestedBlockIndices;
  std::map<uint32_t, uint8_t> requestedBlockRequestTypes;
  NSMutableIndexSet* wiredBlocks;
  NSMutableIndexSet* wiredDynamicObjects;
  NSMutableDictionary* creationArraysToSend;
  NSMutableDictionary* updateArraysToSend;
  NSMutableDictionary* creationDataUpdateArraysToSend;
  NSMutableDictionary* updateUnreliableArraysToSend;
  NSMutableDictionary* removalArraysToSend;
  BOOL requestsHeartBeat;
  BOOL hasEverRequestedHeartbeat;
  float timeSinceLastHeartbeatRequest;
  int lightBlockIndex;
  NSMutableArray* fillIndices;
  std::map<uint32_t, std::set<uint32_t>*>* worldIndicesContainingTamedAnimals;
  BOOL paused;
  BOOL connected;
  BOOL isAdmin;
  NSMutableIndexSet* foundItemsList;
  NSMutableIndexSet* allLightBlockIndices;
  Database* lightBlockDatabase;
}

@property (readonly) NSMutableIndexSet* allLightBlockIndices; // @synthesize allLightBlockIndices;
@property (readonly)
    NSMutableIndexSet* foundItemsList; // @synthesize foundItemsList;
@property std::map<uint32_t, std::set<uint32_t>*>* worldIndicesContainingTamedAnimals; // @synthesize
                                                                                       // worldIndicesContainingTamedAnimals;
@property (readonly) int lightBlockIndex; // @synthesize lightBlockIndex;
@property float
    timeSinceLastHeartbeatRequest; // @synthesize timeSinceLastHeartbeatRequest;
@property BOOL
    hasEverRequestedHeartbeat; // @synthesize hasEverRequestedHeartbeat;
@property BOOL requestsHeartBeat; // @synthesize requestsHeartBeat;
@property (readonly)
    NSMutableIndexSet* wiredDynamicObjects; // @synthesize wiredDynamicObjects;
@property BOOL isAdmin; // @synthesize isAdmin;
@property (readonly) NSString* clientID; // @synthesize clientID;
@property BOOL paused; // @synthesize paused;
@property (readonly) NSMutableIndexSet* requestedBlockIndices; // @synthesize requestedBlockIndices;

@property BOOL connected;
- (void)saveLightBlockIndices;
- (NSArray*)getAndRemoveAllRecieptDataForMacroPos:(intpair)macroPos world:(World*)world;
- (void)addFillRequest:(uint32_t)fillIndex;
- (void)sendAllObjectData;
- (void)addRemovalObjectDataToSend:(NSData*)netData
                            ofType:(uint8_t)dynamicObjectType
                          objectID:(uint64_t)objectID;
- (void)addUpdateObjectDataToSend:(NSData*)netData
                           ofType:(uint8_t)dynamicObjectType
                         reliable:(BOOL)reliable;
- (void)addCreationDataUpdateObjectDataToSend:(NSData*)netData
                                       ofType:(uint8_t)dynamicObjectType;
- (void)addCreationObjectDataToSend:(NSData*)netData
                             ofType:(uint8_t)dynamicObjectType
                           objectID:(uint64_t)objectID;
- (void)unwireDynamicObject:(uint64_t)uniqueID;
- (void)wireDynamicObject:(uint64_t)uniqueID;
- (BOOL)dynamicObjectIsWired:(uint64_t)uniqueID;
- (void)blockRemoved:(int)macroIndex;
- (BOOL)createIfNotCreatedForBlockRequest:(int)macroIndex;
- (void)removeBlockRequest:(int)macroIndex;
- (BOOL)blockIsRequested:(int)macroIndex;
- (BOOL)blockIsWired:(int)macroIndex;
- (void)requestForBlock:(ClientMacroBlockRequest)request;
- (void)dealloc;
- (void)clientReconnected;
- (ServerClient*)initWithClientID:(NSString*)clientID_
                           server:(BHServer*)server_
                  lightBlockIndex:(int)lightBlockIndex_
               lightBlockDatabase:(Database*)lightBlockDatabase_;

@end
