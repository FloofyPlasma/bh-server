#import "TrainCar.h"

@implementation TrainCar

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

- (void)cleanup
{
}

- (BOOL)connectsToOtherCars
{
  return NO;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (TrainCar*)engineCar
{
  return nil;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isEngine
{
  return NO;
}

- (ItemType)itemType
{
  return ITEM_FLAX_MAT;
}

- (TrainCar*)leftCar
{
  return nil;
}

- (Vector2)leftWheelPos
{
  return Vector2();
}

- (void)loadDerivedStuff
{
}

- (uint16_t)maxHealth
{
  return 0;
}

- (int)maxNumberOfRiders
{
  return 0;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)railOrStationNameChanged
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (float)riderAnimationTimer
{
  return 0;
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (float)riderBodyZRotation
{
  return 0;
}

- (TrainCar*)rightCar
{
  return nil;
}

- (Vector2)rightWheelPos
{
  return Vector2();
}

- (void)setEngineCar:(TrainCar*)engineCar_
{
}

- (void)setLeftCar:(TrainCar*)leftCar_
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setRightCar:(TrainCar*)rightCar_
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (TrainCarCreationNetData)trainCarCreationNetData
{
  return TrainCarCreationNetData();
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
