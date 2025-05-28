#import "LimeTree.h"

@implementation LimeTree

- (ItemType)fruitItemType {
}

- (BOOL)fruitShouldFallInSeason:(int)season {
}

- (NSMutableDictionary *)getSaveDict {
}

- (LimeTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge {
}

- (LimeTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ saveDict:(NSMutableDictionary *)saveDict cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (void)makeTileDead:(Tile *)tile {
}

- (DynamicObjectType)objectType {
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
}

- (TreeType)treeType {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks {
}

@end