#import "CaveTroll.h"

@implementation CaveTroll

- (BOOL)canCrawl
{
}

- (BOOL)canFly
{
}

- (int)currentTraverseToKeyFrame
{
}

- (NSDictionary*)infoForPathRecalculation
{
}

- (void)setNoLongerWaitingForPath
{
}

- (void)setPath:(NSArray*)path_ type:(PathType)pathType goalInteraction:(InteractionType)goalInteraction extraData:(NSDictionary*)pathExtraData_
{
}

- (void)setWaitingForPathToPos:(intpair)goalPos
{
}

- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos
{
}

- (BOOL)waitingForPath
{
}

- (void)addRider:(Blockhead*)rider_
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

- (BOOL)canCrawl
{
}

- (BOOL)canFly
{
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (ItemType)captureRequiredItemType
{
}

- (CaveTrollUpdateData)caveTrollUpdateDataForClient:(NSString*)clientIDToSendTo
{
}

- (BOOL)controlIsLocal
{
}

- (unsigned long long)creationDataStructSize
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (BOOL)crouching
{
}

- (CaveTrollAnimationType)currentAnimationType
{
}

- (InteractionType)currentInteractionType
{
}

- (TileTraverseKeyFrameType)currentTraverseToKeyFrame
{
}

- (void)dealloc
{
}

- (void)die:(Blockhead*)killBlockhead_
{
}

- (BOOL)diesOfLowFullness
{
}

- (BOOL)diesOfOldAge
{
}

- (void)doRemoteUpdate:(CaveTrollUpdateData)remoteUpdateData
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (BOOL)falling
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

- (id)infoForPathRecalculation
{
}

- (void)initSubDerivedStuffStuff
{
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)isHeadingForSquare:(intpair)squarePos
{
}

- (BOOL)jumpsOnSwipe
{
}

- (float)maxAge
{
}

- (uint16_t)maxHealth
{
}

- (Vector2)namePos
{
}

- (NPCType)npcType
{
}

- (void)preDrawUpdate:(float)dt cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
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

- (void)removeRider:(Blockhead*)rider_
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

- (BOOL)riderRidesWithArmsDown
{
}

- (void)setNoLongerWaitingForPath
{
}

- (void)setPath:(NSArray*)path_ type:(PathType)pathType goalInteraction:(InteractionType)goalInteraction extraData:(NSDictionary*)goalInteraction
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)setWaitingForPathToPos:(intpair)goalPos
{
}

- (NSString*)speciesName
{
}

- (void)startInteractingWithTileAtIndex:(int)tileIndex tile:(Tile*)tile interactionType:(InteractionType)interactionType_
{
}

- (void)stopInteracting
{
}

- (BOOL)suffersDamageAtHighTemperatures
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
}

- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (BOOL)waitingForPath
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end