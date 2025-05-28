#import "NPC.h"

@implementation NPC

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

- (Vector2)center
{
}

- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead
{
}

- (BOOL)isDoubleHeight
{
}

- (BOOL)isVisible
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

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
}

- (BOOL)willDieIfHitByForce:(int)force
{
}

- (NSData*)appendNPCCreationDataToData:(NSData*)subclassData
{
}

- (void)beginBlockheadInspection:(Blockhead*)blockhead
{
}

- (BOOL)belongsToLocalPlayer
{
}

- (BOOL)belongsToPlayerWithBlockhead:(Blockhead*)blockhead
{
}

- (void)blockheadIsComingToInspect:(Blockhead*)blockhead
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (void)blockheadsLoaded
{
}

- (NSString*)breedString
{
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (BOOL)canBeFedByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canMate
{
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (NSString*)cantBeFedTipStringForBlockhead:(Blockhead*)blockhead
{
}

- (NSString*)cantBeMilkedTipStringForBlockhead:(Blockhead*)blockhead
{
}

- (NSString*)cantBeShavedTipStringForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)captureByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
}

- (int)captureRequiredItemType
{
}

- (int)capturedItemType
{
}

- (void)changeName:(NSString*)newName
{
}

- (void)checkCurrentPositionForFood
{
}

- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline
{
}

- (void)createItemDropsForDeath
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

- (BOOL)diesOfLowFullness
{
}

- (BOOL)diesOfOldAge
{
}

- (void)drawName:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (BOOL)feedByBlockhead:(Blockhead*)blockhead
{
}

- (int)foodItemType
{
}

- (float)fullnessFraction
{
}

- (void)generateNewName
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

- (float)healthFraction
{
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (void)inspectionStopped
{
}
- (void)loadValuesFromSaveDict:(NSDictionary*)saveDict
{
}

- (BOOL)mateWithNPC:(NPC*)otherNPC
{
}

- (float)maxAge
{
}

- (uint16_t)maxHealth
{
}

- (BOOL)milkByBlockhead:(Blockhead*)blockhead
{
}

- (float)minFullness
{
}

- (float)minRidableAge
{
}

- (NSString*)name
{
}

- (Vector2)namePos
{
}

- (NPCCreationNetData)npcCreationNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (NPCType)npcType
{
}

- (NPCUpdateNetData)npcUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
}

- (DynamicObjectType)objectType
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

- (BOOL)removeIsRed
{
}

- (NSString*)removeTitle
{
}

- (Vector2)renderPos
{
}

- (BOOL)requiresPhysicalBlock
{
}

- (BOOL)ridableWhenTamed
{
}

- (float)riderBodyZRotationForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)secondChoiceIsBlue
{
}

- (NSString*)secondOptionTitle
{
}

- (void)setAdultCreationStartValues
{
}

- (void)setBabyCreationStartValues
{
}

- (void)setFreeByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)shaveByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)shouldSaveEveryChangeInPosition
{
}

- (NSString*)speciesName
{
}

- (void)successfulTame
{
}

- (BOOL)suffersDamageAtHighTemperatures
{
}

- (BOOL)tamed
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

@end