#import "Tree.h"

#import "DynamicObjectType.h"

@interface AppleTree : Tree {
  float availableFood;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (TreeType)treeType;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)makeTileDead:(Tile*)tile;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (NSMutableDictionary*)getSaveDict;
- (AppleTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (AppleTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                    maxHeight:(int16_t)maxHeight_
                   growthRate:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                    adultTree:(BOOL)adultTree
                  adultMaxAge:(float)adultMaxAge;
- (DynamicObjectType)objectType;
- (BOOL)fruitShouldFallInSeason:(int)arg1;
- (ItemType)fruitItemType;
- (void)setAvailableFood:(float)food;
- (float)availableFood;

@end
