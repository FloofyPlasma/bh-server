#import "Yak.h"

@implementation Yak

- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (ItemType)captureRequiredItemType
{
  return ITEM_FLAX_MAT;
}

- (ItemType)capturedItemType
{
  return ITEM_FLAX_MAT;
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
  [self->bodyCubeHairy release];
  [self->bodyCubeShaved release];
  [self->neckCube release];
  [self->headCube release];
  [self->legCube release];
  [self->hornCubeA release];
  [self->hornCubeB release];

  [super dealloc];
}

- (void)doYakRemoteUpdate:(YakUpdateNetData)remoteData
{
}

- (void)drawSubClassStuff:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix
{
}

- (ItemType)foodItemType
{
  return ITEM_FLAX_MAT;
}

- (PlantType)foodPlantType
{
  return PLANT_KELP;
}

- (float)foodToRemoveWhenSpawningNPC
{
  return 0;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (Yak*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientId
{
  return nil;
}

- (Yak*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)jumps
{
  return NO;
}

- (BOOL)jumpsOnSwipe
{
  return NO;
}

- (void)loadDerivedStuff
{
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

- (NPCType)npcType
{
  return NPC_SHARK;
}

- (void)remoteCreationDataUpdate:(NSData*)netData
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)setAdultCreationStartValues
{
}

- (void)setupMatrices:(Vector2)renderPos dt:(float)dt
{
}

- (BOOL)shaveByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (NSString*)speciesName
{
  return nil;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updateTextures
{
}

- (YakUpdateNetData)yakUpdateNetDataForClient:(NSString*)clientIDToSendTo
{
  return YakUpdateNetData();
}

@end