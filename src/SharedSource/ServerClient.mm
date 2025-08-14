#import "ServerClient.h"

#import "BHServer.h"
#import "Database.h"

@implementation ServerClient

@synthesize allLightBlockIndices;
@synthesize foundItemsList;
@synthesize worldIndicesContainingTamedAnimals;
@synthesize lightBlockIndex;
@synthesize timeSinceLastHeartbeatRequest;
@synthesize hasEverRequestedHeartbeat;
@synthesize requestsHeartBeat;
@synthesize wiredDynamicObjects;
@synthesize isAdmin;
@synthesize clientID;
@synthesize paused;
@synthesize requestedBlockIndices;
@synthesize connected;

- (void)addCreationDataUpdateObjectDataToSend:(NSData*)netData ofType:(uint8_t)dynamicObjectType
{
}

- (void)addCreationObjectDataToSend:(NSData*)netData ofType:(uint8_t)dynamicObjectType objectID:(uint64_t)objectID
{
}

- (void)addFillRequest:(uint32_t)fillIndex
{
}

- (void)addRemovalObjectDataToSend:(NSData*)netData ofType:(uint8_t)dynamicObjectType objectID:(uint64_t)objectID
{
}

- (void)addUpdateObjectDataToSend:(NSData*)netData ofType:(uint8_t)dynamicObjectType reliable:(BOOL)reliable
{
}

- (BOOL)blockIsRequested:(int)macroIndex
{
  return NO;
}

- (BOOL)blockIsWired:(int)macroIndex
{
  return NO;
}

- (void)blockRemoved:(int)macroIndex
{
}

- (void)clientReconnected
{
}

- (BOOL)createIfNotCreatedForBlockRequest:(int)macroIndex
{
  return NO;
}

- (void)dealloc
{
  // TODO: dealloc worldIndicesContainingTamedAnimals

  [self->clientID release];
  [self->wiredBlocks release];
  [self->requestedBlockIndices release];
  [self->wiredDynamicObjects release];
  [self->creationArraysToSend release];
  [self->updateArraysToSend release];
  [self->creationDataUpdateArraysToSend release];
  [self->updateUnreliableArraysToSend release];
  [self->removalArraysToSend release];
  [self->fillIndices release];
  [self->allLightBlockIndices release];

  [super dealloc];
}

- (BOOL)dynamicObjectIsWired:(uint64_t)uniqueID
{
  return NO;
}

- (NSArray*)getAndRemoveAllRecieptDataForMacroPos:(intpair)macroPos world:(World*)world
{
  return nil;
}

- (ServerClient*)initWithClientID:(NSString*)clientID_ server:(BHServer*)server_ lightBlockIndex:(int)lightBlockIndex_ lightBlockDatabase:(Database*)lightBlockDatabase_
{
  return nil;
}

- (void)removeBlockRequest:(int)macroIndex
{
}

- (void)requestForBlock:(ClientMacroBlockRequest)request
{
}

- (void)saveLightBlockIndices
{
}

- (void)sendAllObjectData
{
}

- (void)unwireDynamicObject:(uint64_t)uniqueID
{
}

- (void)wireDynamicObject:(uint64_t)uniqueID
{
}

@end