#import "NormalPlant.h"

@implementation NormalPlant

@synthesize availableFood;

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (BOOL)canDieSeason:(int)season
{
  return NO;
}

- (TileContents)contentsType
{
  return CONTENTS_CHERRY_TREE_PROMISE;
}

- (void)dealloc
{
  [self->light release];

  [super dealloc];
}

- (ItemType)droppedItemType
{
  return ITEM_FLAX_MAT;
}

- (BOOL)emitsLight
{
  return NO;
}

- (TileContents)flowerContentsType
{
  return CONTENTS_CHERRY_TREE_PROMISE;
}

- (BOOL)floweringSeason:(int)season
{
  return NO;
}

- (ItemType)folliageItemType
{
  return ITEM_FLAX_MAT;
}

- (float)foodToRemoveWhenSpawningNPC
{
  return 0;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeightGene:(int16_t)maxHeight_ growthRateGene:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
  return nil;
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (Vector)lightColor
{
  return Vector();
}

- (float)lightFactor
{
  return 0;
}

- (int)lightGlowQuadCount
{
  return 0;
}

- (float)maxAgeBase
{
  return 0;
}

- (int)minAllowedTemperature
{
  return 0;
}

- (NPCType)npcSpawnType
{
  return NPC_SHARK;
}

- (int)numberOfOccupiedTilesAbove
{
  return 0;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (ImageType)renderImageType
{
  return IMAGE_STEAM_LOCO_RIGHT;
}

- (ItemType)seedItemType
{
  return ITEM_FLAX_MAT;
}

- (void)setFlowering:(BOOL)newFlowering
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (int)tileHarvested:(intpair)tilePos removeBlockhead:(Blockhead*)removeBlockhead correctToolMultiplier:(int)correctToolMultiplier
{
  return 0;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end