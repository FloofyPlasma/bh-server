#import "CactusTree.h"

@implementation CactusTree

@synthesize availableFood;

- (ItemType)fruitItemType {
    return ITEM_PRICKLY_PEAR;
}

- (BOOL)fruitShouldFallInSeason:(int)season {
    return season == 4;
}

- (NSMutableDictionary *)getSaveDict {
    NSMutableDictionary *saveDict = [super getSaveDict];

    saveDict[@"splitHeightA"] = @(self->splitHeightA);
    saveDict[@"splitHeightB"] = @(self->splitHeightB);
    saveDict[@"splitDirection"] = @(self->splitDirection);
    saveDict[@"availableFood"] = @(self->availableFood);

    return saveDict;
}

- (CactusTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge {
    return nil;
}

- (CactusTree *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
    return nil;
}

- (BOOL)isRequiredSoilType:(TileType)type {
    switch (type) {
        case TILE_SAND:
        case TILE_SAND_BEACH:
        case TILE_BLACK_SAND:
        case TILE_COMPOST:
        case TILE_COMPOST_GRASS:
        case TILE_COMPOST_GRASS_FROZEN:
            return YES;
        default:
            return NO;
    }
}

- (void)loadSaveDictValues:(NSDictionary *)saveDict {
    [super loadSaveDictValues:saveDict];

    self->splitHeightA = [saveDict[@"splitHeightA"] intValue];
    self->splitHeightB = [saveDict[@"splitHeightB"] intValue];
    self->splitDirection = [saveDict[@"splitDirection"] boolValue];
    self->availableFood = [saveDict[@"availableFood"] floatValue];
}

- (void)makeTileDead:(Tile *)tile {
    if (tile->contents == CONTENTS_CACTUS) {
        tile->contents = CONTENTS_CACTUS_DEAD;
    }
}

- (DynamicObjectType)objectType {
    return DYNAMIC_OBJECT_TYPE_CACTUS_TREE;
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
    switch (tile->contents) {
        case CONTENTS_CACTUS:
        case CONTENTS_CACTUS_DEAD:
            return YES;
        default:
            return NO;
    }
}

- (TreeType)treeType {
    return TREE_CACTUS;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks {
}

@end
