#import "Shark.h"

@implementation Shark

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

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)item
{
}

- (ItemType)captureRequiredItemType
{
}

- (ItemType)capturedItemType
{
}

- (Vector2)center
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

- (void)doRemoteUpdate:(SharkUpdateNetData)remoteUpdateData
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

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
}

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Shark*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
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

- (unsigned short)maxHealth
{
}

- (float)minFullness
{
}

- (float)minRidableAge
{
}

- (Vector2)namePos
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

- (BOOL)riderDPadShouldAllowUpDown
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)riderRidesWithArmsDown
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (SharkUpdateNetData)sharkUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (NSString*)speciesName
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
}

- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

@end