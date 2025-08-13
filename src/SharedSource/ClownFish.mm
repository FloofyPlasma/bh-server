#import "ClownFish.h"

#import "FishingRod.h"

@implementation ClownFish

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
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

- (ClownFishUpdateNetData)clownFishUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return ClownFishUpdateNetData();
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
  [self->tailCube release];
  [self->sideFinCube release];
  [self->hookedFishingRod setHookedFish:nil];
  [self->hookedFishingRod autorelease];

  [super dealloc];
}

- (void)die:(Blockhead*)killBlockhead_
{
}

- (void)doRemoteUpdate:(ClownFishUpdateNetData)updateNetData
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

- (ClownFish*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (ClownFish*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (ClownFish*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
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

- (void)remoteBlockheadHookedYou:(Blockhead*)blockhead
{
}

- (void)remoteCreationDataUpdate:(NSData*)netData
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (BOOL)ridableWhenTamed
{
  return NO;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (NSString*)speciesName
{
  return nil;
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