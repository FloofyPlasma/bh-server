#import "Donkey.h"

@implementation Donkey

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
  return NO;
}

- (NSString*)breedString
{
  return nil;
}

- (BOOL)canJumpMultipleTilesWhileFlying
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

- (void)dealloc
{
}

- (void)drawSubClassStuff:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix
{
}

- (BOOL)flies
{
  return NO;
}

- (ItemType)foodItemType
{
  return ITEM_FLAX_MAT;
}

- (PlantType)foodPlantType
{
  return PLANT_KELP;
}

- (BOOL)galloping
{
  return NO;
}

- (int)generateBreedForChild
{
  return 0;
}

- (NSString**)getNamesArray
{
  return nullptr;
}

- (int)getNamesArrayCount
{
  return 0;
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

- (float)maxVelocity
{
  return 0;
}

- (float)minFullness
{
  return 0;
}

- (NPCType)npcType
{
  return NPC_SHARK;
}

- (void)setupMatrices:(Vector2)renderPos dt:(float)dt
{
}

- (NSString*)speciesName
{
  return nil;
}

@end