#import "Dodo.h"

@implementation Dodo

- (void)addRider:(Blockhead*)blockhead
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
  return NO;
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (NSString*)breedString
{
  return nil;
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
  return Vector2();
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return NO;
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return nil;
}

- (ItemType)captureRequiredItemType
{
  return ITEM_FLAX_MAT;
}

- (ItemType)capturedItemType
{
  return ITEM_FLAX_MAT;
}

- (void)createItemDropsForDeath
{
}

- (uint64_t)creationDataStructSize
{
  return 0;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->bodyCube release];
  [self->neckCube release];
  [self->headCube release];
  [self->legCube release];
  [self->footCube release];

  [super dealloc];
}

- (void)die:(Blockhead*)killBlockhead_
{
}

- (void)doRemoteUpdate:(DodoUpdateNetData)updateNetData
{
}

- (DodoUpdateNetData)dodoUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return DodoUpdateNetData();
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (ItemType)foodItemType
{
  return ITEM_FLAX_MAT;
}

- (NSString**)getNamesArray
{
  return nullptr;
}

- (int)getNamesArrayCount
{
  return 0;
}

- (int)getRandomDirection
{
  return 0;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead
{
}

- (Dodo*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (Dodo*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Dodo*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (void)jumpAndCluck
{
}

- (BOOL)jumpsOnSwipe
{
  return NO;
}

- (void)loadDerivedStuff
{
}

- (float)maxAge
{
  return 0;
}

- (uint16_t)maxHealth
{
  return 0;
}

- (NPCType)npcType
{
  return NPC_SHARK;
}

- (void)reactToBeingFed
{
}

- (void)reactToBeingHit
{
}

- (void)remoteCreationDataUpdate:(NSData*)netData
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeRider:(Blockhead*)blockhead
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (int)rideDirection
{
  return 0;
}

- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead
{
  return 0;
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
  return Vector();
}

- (BOOL)riderRidesWithArmsDown
{
  return NO;
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (NSString*)speciesName
{
  return nil;
}

- (void)successfulTame
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

@end