#import "Tree.h"

@implementation Tree

- (void)addFallenFruits {
}

- (void)checkIfDeadTilesNeedRemoved {
}

- (void)dealloc {
}

- (ItemType)fruitItemType {
}

- (BOOL)fruitShouldFallInSeason:(int)season {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)growInTimeSinceSaved:(NSTimeInterval)saveTime {
}

- (uint16_t)growthRateGeneVariation {
}

- (int)height {
}

- (void)incrementHeight {
}

- (Tree *)initStaticTreeWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (Tree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge {
}

- (Tree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (BOOL)isGrowingInCompost {
}

- (BOOL)isRequiredSoilType:(TileType)type {
}

- (BOOL)isStaticTree {
}

- (void)killAllOwnedTiles {
}

- (void)killAllOwnedTilesAboveY:(int)yMin {
}

- (void)loadSaveDictValues:(NSDictionary *)saveDict {
}

- (void)makeTileDead:(Tile *)tile {
}

- (uint16_t)maxHeightGeneVariation {
}

- (BOOL)occupiesNormalContents {
}

- (void)removeAllOwnedTiles:(BOOL)createFreeBlocks {
}

- (void)removeFromMacroBlock {
}

- (BOOL)shouldAddFallenFruits {
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
}

- (TreeType)treeType {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateAllOwnedTilesToNewIDSize {
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end