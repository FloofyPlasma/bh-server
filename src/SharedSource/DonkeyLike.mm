#import "DonkeyLike.h"

@implementation DonkeyLike

- (id)actsAsInteractionObject
{
  return nil;
}

- (void)addRider:(id)arg1
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
  return NO;
}

- (void)blockheadUnloaded:(id)arg1
{
}

- (Vector2)cameraPosForBlockhead:(id)arg1
{
  return Vector2();
}

- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2
{
  return NO;
}

- (BOOL)canJumpMultipleTilesWhileFlying
{
  return NO;
}

- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2
{
  return nil;
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
  [self->rider autorelease];

  [super dealloc];
}

- (void)die:(id)arg1
{
}

- (void)doDonkeyLikeRemoteUpdate:(DonkeyLikeUpdateNetData)updateNetData
{
}

- (DonkeyLikeCreationNetData)donkeyLikeCreationNetDataForClient:(NSString*)clientIDToSendTo
{
  return DonkeyLikeCreationNetData();
}

- (DonkeyLikeUpdateNetData)donkeyLikeUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return DonkeyLikeUpdateNetData();
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (void)drawSubClassStuff:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix
{
}

- (BOOL)flies
{
  return NO;
}

- (PlantType)foodPlantType
{
  return PLANT_KELP;
}

- (BOOL)galloping
{
  return NO;
}

- (int)generateBreedForChild
{
  return 0;
}

- (void)hitWithForce:(int)arg1 blockhead:(id)arg2
{
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)jumps
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

- (uint16_t)maxHealth
{
  return 0;
}

- (float)maxVelocity
{
  return 0;
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

- (void)removeRider:(id)arg1
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (BOOL)requiresFuel
{
  return NO;
}

- (int)rideDirection
{
  return 0;
}

- (float)riderBodyYRotationForBlockhead:(id)arg1
{
  return 0;
}

- (float)riderBodyZRotationForBlockhead:(id)arg1
{
  return 0;
}

- (Vector)riderPosForBlockhead:(id)arg1
{
  return Vector();
}

- (void)setTargetVelocity:(Vector2)arg1
{
}

- (void)setupMatrices:(Vector2)renderPos dt:(float)dt
{
}

- (void)swipeUpGesture
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1
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

- (void)worldChanged:(std::vector<intpair>*)arg1
{
}

@end