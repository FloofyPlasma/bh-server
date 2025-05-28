#import "CaveTroll.h"

@implementation CaveTroll

- (BOOL)canCrawl
{
  return NO;
}

- (BOOL)canFly
{
  return NO;
}

- (TileTraverseKeyFrameType)currentTraverseToKeyFrame
{
  return TRAVERSE_KF_BOB;
}

- (NSDictionary*)infoForPathRecalculation
{
  return nil;
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
  return NO;
}

- (BOOL)waitingForPath
{
  return NO;
}

- (void)addRider:(Blockhead*)rider_
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

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return nil;
}

- (ItemType)captureRequiredItemType
{
  return ITEM_FLAX_MAT;
}

- (CaveTrollUpdateData)caveTrollUpdateDataForClient:(NSString*)clientIDToSendTo
{
  return CaveTrollUpdateData();
}

- (BOOL)controlIsLocal
{
  return NO;
}

- (unsigned long long)creationDataStructSize
{
  return 0;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (BOOL)crouching
{
  return NO;
}

- (CaveTrollAnimationType)currentAnimationType
{
  return CTA_LIE;
}

- (InteractionType)currentInteractionType
{
  return INTERACTION_DIG_BACK_WALL;
}

- (void)dealloc
{
}

- (void)die:(Blockhead*)killBlockhead_
{
}

- (BOOL)diesOfLowFullness
{
  return NO;
}

- (BOOL)diesOfOldAge
{
  return NO;
}

- (void)doRemoteUpdate:(CaveTrollUpdateData)remoteUpdateData
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (BOOL)falling
{
  return NO;
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

- (void)initSubDerivedStuffStuff
{
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (CaveTroll*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isHeadingForSquare:(intpair)squarePos
{
  return NO;
}

- (BOOL)jumpsOnSwipe
{
  return NO;
}

- (float)maxAge
{
  return 0;
}

- (uint16_t)maxHealth
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

- (BOOL)riderRidesWithArmsDown
{
  return NO;
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (NSString*)speciesName
{
  return nil;
}

- (void)startInteractingWithTileAtIndex:(int)tileIndex tile:(Tile*)tile interactionType:(InteractionType)interactionType_
{
}

- (void)stopInteracting
{
}

- (BOOL)suffersDamageAtHighTemperatures
{
  return NO;
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end