#import "Tree.h"

@implementation Tree

- (void)addFallenFruits
{
}

- (void)checkIfDeadTilesNeedRemoved
{
}

- (void)dealloc
{
}

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

- (void)growInTimeSinceSaved:(NSTimeInterval)saveTime
{
}

- (uint16_t)growthRateGeneVariation
{
  return 0;
}

- (int)height
{
  return 0;
}

- (void)incrementHeight
{
}

- (Tree*)initStaticTreeWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (Tree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge
{
  return nil;
}

- (Tree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)isGrowingInCompost
{
  return NO;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (BOOL)isStaticTree
{
  return NO;
}

- (void)killAllOwnedTiles
{
}

- (void)killAllOwnedTilesAboveY:(int)yMin
{
}

- (void)loadSaveDictValues:(NSDictionary*)saveDict
{
}

- (void)makeTileDead:(Tile*)tile
{
}

- (uint16_t)maxHeightGeneVariation
{
  return 0;
}

- (BOOL)occupiesNormalContents
{
  return NO;
}

- (void)removeAllOwnedTiles:(BOOL)createFreeBlocks
{
}

- (void)removeFromMacroBlock
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

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateAllOwnedTilesToNewIDSize
{
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end