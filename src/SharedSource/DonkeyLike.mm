#import "DonkeyLike.h"

@implementation DonkeyLike

- (id)actsAsInteractionObject
{
}

- (void)addRider:(id)arg1
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
}

- (void)blockheadUnloaded:(id)arg1
{
}

- (Vector2)cameraPosForBlockhead:(id)arg1
{
}

- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2
{
}

- (BOOL)canJumpMultipleTilesWhileFlying
{
}

- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2
{
}

- (uint64_t)creationDataStructSize
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (void)die:(id)arg1
{
}

- (void)doDonkeyLikeRemoteUpdate:(DonkeyLikeUpdateNetData)updateNetData
{
}

- (DonkeyLikeCreationNetData)donkeyLikeCreationNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (DonkeyLikeUpdateNetData)donkeyLikeUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (void)drawSubClassStuff:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix
{
}

- (BOOL)flies
{
}

- (PlantType)foodPlantType
{
}

- (BOOL)galloping
{
}

- (int)generateBreedForChild
{
}

- (void)hitWithForce:(int)arg1 blockhead:(id)arg2
{
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (DonkeyLike*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)jumps
{
}

- (BOOL)jumpsOnSwipe
{
}

- (void)loadDerivedStuff
{
}

- (uint16_t)maxHealth
{
}

- (float)maxVelocity
{
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
}

- (BOOL)requiresFuel
{
}

- (int)rideDirection
{
}

- (float)riderBodyYRotationForBlockhead:(id)arg1
{
}

- (float)riderBodyZRotationForBlockhead:(id)arg1
{
}

- (Vector)riderPosForBlockhead:(id)arg1
{
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
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)worldChanged:(std::vector<intpair>*)arg1
{
}

@end