#import "Scorpion.h"

@implementation Scorpion

- (void)addRider:(Blockhead*)blockhead
{
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (ItemType)captureRequiredItemType
{
}

- (ItemType)capturedItemType
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

- (void)die:(Blockhead*)killBlockhead_
{
}

- (void)doRemoteUpdate:(ScorpionUpdateNetData)updateNetData
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (ItemType)foodItemType
{
}

- (NSString**)getNamesArray
{
}

- (int)getNamesArrayCount
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead
{
}

- (Scorpion*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
}

- (Scorpion*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Scorpion*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)isUnderLocalControl
{
}

- (BOOL)jumpsOnSwipe
{
}

- (void)loadDerivedStuff
{
}

- (float)maxAge
{
}

- (uint16_t)maxHealth
{
}

- (NPCType)npcType
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

- (void)removeRider:(Blockhead*)blockhead
{
}

- (Vector2)renderPos
{
}

- (int)rideDirection
{
}

- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)riderRidesWithArmsDown
{
}

- (ScorpionUpdateNetData)scorpionUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (NSString*)speciesName
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

@end