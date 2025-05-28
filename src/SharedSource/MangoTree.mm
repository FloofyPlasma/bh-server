#import "MangoTree.h"

@implementation MangoTree

- (ItemType)fruitItemType
{
  return ITEM_FLAX_MAT;
}

- (BOOL)fruitShouldFallInSeason:(int)season
{
  return NO;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (MangoTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge
{
  return nil;
}

- (MangoTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSMutableDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (void)makeTileDead:(Tile*)tile
{
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  return NO;
}

- (TreeType)treeType
{
  return TREE_CACTUS;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks
{
}

@end