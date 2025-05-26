#import <Foundation/Foundation.h>

#import "Tree.h"

@interface CherryTree : Tree {
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (TreeType)treeType;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)makeTileDead:(Tile*)tile;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (NSMutableDictionary*)getSaveDict;
- (CherryTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (Tree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                    maxHeight:(int16_t)maxHeight_
                   growthRate:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                    adultTree:(BOOL)adultTree
                  adultMaxAge:(float)adultMaxAge;
- (BOOL)fruitShouldFallInSeason:(int)season;
- (ItemType)fruitItemType;
- (DynamicObjectType)objectType;

@end
