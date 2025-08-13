#import "NPC.h"

@implementation NPC

@synthesize age;
@synthesize breed;

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

- (Vector2)center
{
  return Vector2();
}

- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead
{
}

- (BOOL)isDoubleHeight
{
  return NO;
}

- (BOOL)isVisible
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

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (BOOL)willDieIfHitByForce:(int)force
{
  return NO;
}

- (NSData*)appendNPCCreationDataToData:(NSData*)subclassData
{
  return nil;
}

- (void)beginBlockheadInspection:(Blockhead*)blockhead
{
}

- (BOOL)belongsToLocalPlayer
{
  return NO;
}

- (BOOL)belongsToPlayerWithBlockhead:(Blockhead*)blockhead
{
  return NO;
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
  return nil;
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return NO;
}

- (BOOL)canBeFedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)canMate
{
  return NO;
}

- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return nil;
}

- (NSString*)cantBeFedTipStringForBlockhead:(Blockhead*)blockhead
{
  return nil;
}

- (NSString*)cantBeMilkedTipStringForBlockhead:(Blockhead*)blockhead
{
  return nil;
}

- (NSString*)cantBeShavedTipStringForBlockhead:(Blockhead*)blockhead
{
  return nil;
}

- (BOOL)captureByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType
{
  return NO;
}

- (int)captureRequiredItemType
{
  return 0;
}

- (int)capturedItemType
{
  return 0;
}

- (void)changeName:(NSString*)newName
{
}

- (void)checkCurrentPositionForFood
{
}

- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline
{
  return nil;
}

- (void)createItemDropsForDeath
{
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
  [self->name autorelease];
  [self->tameCountsByClientID release];
  [self->tamedClientID release];
  [self->killBlockhead release];

  [super dealloc];
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

- (void)drawName:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (BOOL)feedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (int)foodItemType
{
  return 0;
}

- (float)fullnessFraction
{
  return 0;
}

- (void)generateNewName
{
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

- (float)healthFraction
{
  return 0;
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (NPC*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (void)inspectionStopped
{
}
- (void)loadValuesFromSaveDict:(NSDictionary*)saveDict
{
}

- (BOOL)mateWithNPC:(NPC*)otherNPC
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

- (BOOL)milkByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (float)minFullness
{
  return 0;
}

- (float)minRidableAge
{
  return 0;
}

- (NSString*)name
{
  return nil;
}

- (Vector2)namePos
{
  return Vector2();
}

- (NPCCreationNetData)npcCreationNetDataForClient:(NSString*)clientIDToSendTo
{
  return NPCCreationNetData();
}

- (NPCType)npcType
{
  return NPC_SHARK;
}

- (NPCUpdateNetData)npcUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return NPCUpdateNetData();
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
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
  return NO;
}

- (NSString*)removeTitle
{
  return nil;
}

- (Vector2)renderPos
{
  return Vector2();
}

- (BOOL)requiresPhysicalBlock
{
  return NO;
}

- (BOOL)ridableWhenTamed
{
  return NO;
}

- (float)riderBodyZRotationForBlockhead:(Blockhead*)blockhead
{
  return 0;
}

- (BOOL)secondChoiceIsBlue
{
  return NO;
}

- (NSString*)secondOptionTitle
{
  return nil;
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
  return NO;
}

- (BOOL)shouldSaveEveryChangeInPosition
{
  return NO;
}

- (NSString*)speciesName
{
  return nil;
}

- (void)successfulTame
{
}

- (BOOL)suffersDamageAtHighTemperatures
{
  return NO;
}

- (BOOL)tamed
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

@end