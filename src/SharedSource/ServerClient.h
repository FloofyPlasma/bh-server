#import <Foundation/Foundation.h>

#import <set>

#import "MJMath.h"
#import "World.h"

@class BHServer, Database;

/**
 * @class ServerClient
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @property allLightBlockIndices
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSMutableIndexSet* allLightBlockIndices; // @synthesize allLightBlockIndices;
@property (readonly)
    NSMutableIndexSet* foundItemsList; // @synthesize foundItemsList;
@property std::map<uint32_t, std::set<uint32_t>*>* worldIndicesContainingTamedAnimals; // @synthesize
                                                                                       // worldIndicesContainingTamedAnimals;
/**
 * @property lightBlockIndex
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int lightBlockIndex; // @synthesize lightBlockIndex;
@property float
    timeSinceLastHeartbeatRequest; // @synthesize timeSinceLastHeartbeatRequest;
@property BOOL
    hasEverRequestedHeartbeat; // @synthesize hasEverRequestedHeartbeat;
@property BOOL requestsHeartBeat; // @synthesize requestsHeartBeat;
@property (readonly)
    NSMutableIndexSet* wiredDynamicObjects; // @synthesize wiredDynamicObjects;
@property BOOL isAdmin; // @synthesize isAdmin;
/**
 * @property clientID
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* clientID; // @synthesize clientID;
@property BOOL paused; // @synthesize paused;
/**
 * @property requestedBlockIndices
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSMutableIndexSet* requestedBlockIndices; // @synthesize requestedBlockIndices;

@property BOOL connected;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveLightBlockIndices;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)getAndRemoveAllRecieptDataForMacroPos:(intpair)macroPos world:(World*)world;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addFillRequest:(uint32_t)fillIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendAllObjectData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRemovalObjectDataToSend:(NSData*)netData
                            ofType:(uint8_t)dynamicObjectType
                          objectID:(uint64_t)objectID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addUpdateObjectDataToSend:(NSData*)netData
                           ofType:(uint8_t)dynamicObjectType
                         reliable:(BOOL)reliable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addCreationDataUpdateObjectDataToSend:(NSData*)netData
                                       ofType:(uint8_t)dynamicObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addCreationObjectDataToSend:(NSData*)netData
                             ofType:(uint8_t)dynamicObjectType
                           objectID:(uint64_t)objectID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)unwireDynamicObject:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)wireDynamicObject:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)dynamicObjectIsWired:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockRemoved:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)createIfNotCreatedForBlockRequest:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeBlockRequest:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockIsRequested:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockIsWired:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)requestForBlock:(ClientMacroBlockRequest)request;
/**
 * @brief Deallocates this ServerClient, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientReconnected;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ServerClient*)initWithClientID:(NSString*)clientID_
                           server:(BHServer*)server_
                  lightBlockIndex:(int)lightBlockIndex_
               lightBlockDatabase:(Database*)lightBlockDatabase_;

@end
