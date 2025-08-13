#import "AppleTree.h"

@implementation AppleTree

- (AppleTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge
{
  return nil;
}

- (AppleTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)fruitShouldFallInSeason:(int)arg1
{
  return NO;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  switch (tile->contents) {
  case CONTENTS_APPLE_TREE_BUSH_DEAD:
  case CONTENTS_APPLE_TREE_BUSH:
  case CONTENTS_APPLE_TREE_TRUNK:
  case CONTENTS_APPLE_TREE_TRUNK_BUSH:
  case CONTENTS_APPLE_TREE_TRUNK_DEAD:
    return YES;
  default:
    return NO;
  }
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (ItemType)fruitItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (TreeType)treeType
{
  return TREE_APPLE;
}

- (float)availableFood
{
  return 0;
}

- (void)makeTileDead:
    (Tile*)tile
{
}

- (void)setAvailableFood:(float)food
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks
{
}

@end
