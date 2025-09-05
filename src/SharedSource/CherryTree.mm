#import "CherryTree.h"

@implementation CherryTree

- (ItemType)fruitItemType {
    return ITEM_CHERRY;
}

- (BOOL)fruitShouldFallInSeason:(int)season {
    return season == 3;
}

- (NSMutableDictionary *)getSaveDict {
    return [super getSaveDict];
}

- (Tree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge {
    return nil;
}

- (CherryTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
    return nil;
}

- (void)makeTileDead:(Tile *)tile {
    if (tile->contents == CONTENTS_CHERRY_TREE_BUSH) {
        tile->contents = CONTENTS_CHERRY_TREE_BUSH_DEAD;
    } else if (tile->contents == CONTENTS_CHERRY_TREE_TRUNK || tile->contents == CONTENTS_CHERRY_TREE_TRUNK_BUSH) {
        tile->contents = CONTENTS_CHERRY_TREE_TRUNK_DEAD;
    }
}

- (DynamicObjectType)objectType {
    return DYNAMIC_OBJECT_TYPE_CHERRY_TREE;
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
    switch (tile->contents) {
        case CONTENTS_CHERRY_TREE_TRUNK:
        case CONTENTS_CHERRY_TREE_BUSH:
        case CONTENTS_CHERRY_TREE_TRUNK_BUSH:
        case CONTENTS_CHERRY_TREE_TRUNK_DEAD:
        case CONTENTS_CHERRY_TREE_BUSH_DEAD:
            return YES;
        default:
            return NO;
    }
}

- (TreeType)treeType {
    return TREE_CHERRY;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks {
}

@end