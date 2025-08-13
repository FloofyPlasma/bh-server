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
  if (self->treeFruits) {
    free(self->treeFruits);
  }

  [super dealloc];
}

- (ItemType)fruitItemType
{
  return ITEM_NONE;
}

- (BOOL)fruitShouldFallInSeason:(int)season
{
  return NO;
}

- (NSMutableDictionary*)getSaveDict
{
  NSMutableDictionary* dict = [[super getSaveDict] mutableCopy];

  dict[@"height"] = @(self->height);
  dict[@"saveTime"] = @([self->world worldTime]);
  dict[@"treeSeasonOffset"] = @(self->treeSeasonOffset);
  dict[@"age"] = @(self->age);
  dict[@"dead"] = @(self->dead);
  dict[@"timeDied"] = @(self->timeDied);
  dict[@"removeCheckCount"] = @(self->removeCheckCount);

  NSMutableArray* fruitArray = [NSMutableArray array];
  if (self->fruitCount > 0) {
    for (int i = 0; i < self->fruitCount; i++) {
      NSMutableDictionary* fruitDict = [NSMutableDictionary dictionary];

      TreeFruit* fruit = &self->treeFruits[i];
      fruitDict[@"pos.x"] = @(fruit->pos.x);
      fruitDict[@"pos.y"] = @(fruit->pos.y);
      fruitDict[@"hasCreatedFreeBlockThisSeason"] = @(fruit->hasCreatedFreeBlockThisSeason);

      [fruitArray addObject:fruitDict];
    }
  }
  dict[@"treeFruit"] = fruitArray;

  if (![self isStaticTree]) {
    dict[@"maxHeightGene"] = @(self->maxHeightGene);
    dict[@"growthRateGene"] = @(self->growthRateGene);
    dict[@"maxHeightReached"] = @(self->maxHeightReached);
    dict[@"growthCounter"] = @(self->growthCounter);
    dict[@"growthRate"] = @(self->growthRate);
    dict[@"maxHeight"] = @(self->maxHeight);
    dict[@"maxAge"] = @(self->maxAge);
  }

  return dict;
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
  return self->height;
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
  switch (type) {
  case TILE_DIRT:
  case TILE_DIRT_GRASS:
  case TILE_DIRT_GRASS_FROZEN:
  case TILE_COMPOST:
  case TILE_COMPOST_GRASS:
  case TILE_COMPOST_GRASS_FROZEN:
    return YES;
  default:
    return NO;
  }
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
  return YES;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  return NO;
}

- (TreeType)treeType
{
  return TREE_NOTHING;
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