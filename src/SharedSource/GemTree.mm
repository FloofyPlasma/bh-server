#import "GemTree.h"

@implementation GemTree

- (int)bushContentsType
{
  return 0;
}

- (ItemType)fruitItemType
{
  return ITEM_FLAX_MAT;
}

- (BOOL)fruitShouldFallInSeason:(int)season
{
  return NO;
}

- (ItemType)gemItemType
{
  return ITEM_FLAX_MAT;
}

- (id)getSaveDict
{
  return nil;
}

- (GemTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ gemTreeType:(TreeType)gemTreeType_
{
  return nil;
}

- (GemTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)isStaticTree
{
  return NO;
}

- (void)loadSaveDictValues:(NSDictionary*)saveDict
{
}

- (void)makeTileDead:(Tile*)tile
{
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)recursivelyAddOwnedTile:(intpair)tilePos toPositions:(std::unordered_set<int>*)ownedTilePositions
{
}

- (BOOL)shouldAddFallenFruits
{
  return NO;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  return NO;
}

- (TreeType)treeType
{
  return TREE_CACTUS;
}

- (int)trunkBushContentsType
{
  return 0;
}

- (int)trunkContentsType
{
  return 0;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end