#import "Boat.h"

@implementation Boat

- (NSString*)actionTitle
{
  return nil;
}

- (InteractionObject*)actsAsInteractionObject
{
  return nil;
}

- (void)addRider:(Blockhead*)blockhead
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
  return NO;
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
  return Vector2();
}

- (BOOL)isDoubleHeight
{
  return NO;
}

- (BOOL)jumpsOnSwipe
{
  return NO;
}

- (void)removeRider:(Blockhead*)blockhead
{
}

- (BOOL)requiresFuel
{
  return NO;
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

- (BOOL)riderDPadShouldGiveDiscreteValues
{
  return NO;
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
  return Vector();
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)swipeUpGesture
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (void)blockheadsLoaded
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->frontBackCube release];
  [self->sideCube release];
  [self->bottomCube release];
  [self->ownerID release];
  [self->rider autorelease];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (Boat*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (Boat*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Boat*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (void)loadDerivedStuff
{
}

- (uint16_t)maxHealth
{
  return 0;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (float)riderBodyZRotation
{
  return 0;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved_
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

- (void)updatePosition:(intpair)newPosition
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end