#import "Shark.h"

@implementation Shark

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

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
  return Vector2();
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return NO;
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)item
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

- (Vector2)center
{
  return Vector2();
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
}

- (void)die:(Blockhead*)killBlockhead_
{
}

- (void)doRemoteUpdate:(SharkUpdateNetData)remoteUpdateData
{
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

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead
{
}

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isUnderLocalControl
{
  return NO;
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

- (unsigned short)maxHealth
{
  return 0;
}

- (float)minFullness
{
  return 0;
}

- (float)minRidableAge
{
  return 0;
}

- (Vector2)namePos
{
  return Vector2();
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

- (BOOL)riderDPadShouldAllowUpDown
{
  return NO;
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

- (SharkUpdateNetData)sharkUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return SharkUpdateNetData();
}

- (NSString*)speciesName
{
  return nil;
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

@end