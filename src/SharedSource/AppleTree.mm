#import "AppleTree.h"

#import "DynamicWorld.h"

@implementation AppleTree

- (AppleTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge {
    return nil;
}

- (AppleTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
    return nil;
}

- (BOOL)fruitShouldFallInSeason:(int)season {
    return season == 3;
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
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

- (DynamicObjectType)objectType {
    return DYNAMIC_OBJECT_TYPE_APPLE_TREE;
}

- (ItemType)fruitItemType {
    return ITEM_APPLE;
}

- (NSMutableDictionary *)getSaveDict {
    NSMutableDictionary *dict = [super getSaveDict];

    dict[@"availableFood"] = @(self->availableFood);

    return dict;
}

- (TreeType)treeType {
    return TREE_APPLE;
}

- (float)availableFood {
    return self->availableFood;
}

- (void)makeTileDead:(Tile *)tile {
    if (tile->contents == CONTENTS_APPLE_TREE_BUSH) {
        tile->contents = CONTENTS_APPLE_TREE_BUSH_DEAD;
    } else if (tile->contents == CONTENTS_APPLE_TREE_TRUNK || tile->contents == CONTENTS_APPLE_TREE_TRUNK_BUSH) {
        tile->contents = CONTENTS_APPLE_TREE_TRUNK_DEAD;
    }
}

- (void)setAvailableFood:(float)food {
    self->availableFood = food;
    [self->dynamicWorld dynamicWorldChangedAtPos:[self pos] objectType:[self objectType]];
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
    [super update:dt accurateDT:accurateDT isSimulation:isSimulation];

    if (!self->dead) {
        // TODO:
    }
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks {
}

@end
