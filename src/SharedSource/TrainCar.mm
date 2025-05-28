#import "TrainCar.h"

@implementation TrainCar

- (NSString*)actionTitle
{
}

- (InteractionObject*)actsAsInteractionObject
{
}

- (void)addRider:(Blockhead*)blockhead
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)isDoubleHeight
{
}

- (BOOL)jumpsOnSwipe
{
}

- (void)removeRider:(Blockhead*)blockhead
{
}

- (BOOL)requiresFuel
{
}

- (int)rideDirection
{
}

- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)riderDPadShouldAllowUpDown
{
}

- (BOOL)riderDPadShouldGiveDiscreteValues
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
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
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (TrainCar*)engineCar
{
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
}

- (ItemType)freeblockCreationItemType
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (TrainCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)isEngine
{
}

- (ItemType)itemType
{
}

- (TrainCar*)leftCar
{
}

- (Vector2)leftWheelPos
{
}

- (void)loadDerivedStuff
{
}

- (uint16_t)maxHealth
{
}

- (int)maxNumberOfRiders
{
}

- (DynamicObjectType)objectType
{
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
}

- (float)riderAnimationTimer
{
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (float)riderBodyZRotation
{
}

- (TrainCar*)rightCar
{
}

- (Vector2)rightWheelPos
{
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
}

- (TrainCarCreationNetData)trainCarCreationNetData
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)updatePosition:(intpair)newPosition
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end