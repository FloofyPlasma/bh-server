#import "GemTree.h"

@implementation GemTree

- (int)bushContentsType
{
}

- (ItemType)fruitItemType
{
}

- (BOOL)fruitShouldFallInSeason:(int)season
{
}

- (ItemType)gemItemType
{
}

- (id)getSaveDict
{
}

- (GemTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ gemTreeType:(TreeType)gemTreeType_
{
}

- (GemTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
}

- (BOOL)isStaticTree
{
}

- (void)loadSaveDictValues:(NSDictionary*)saveDict
{
}

- (void)makeTileDead:(Tile*)tile
{
}

- (DynamicObjectType)objectType
{
}

- (void)recursivelyAddOwnedTile:(intpair)tilePos toPositions:(std::unordered_set<int>*)ownedTilePositions
{
}

- (BOOL)shouldAddFallenFruits
{
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
}

- (TreeType)treeType
{
}

- (int)trunkBushContentsType
{
}

- (int)trunkContentsType
{
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