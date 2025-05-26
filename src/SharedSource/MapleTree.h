#import <Foundation/Foundation.h>

#import "Tree.h"

@interface MapleTree : Tree {
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (TreeType)treeType;
- (void)makeTileDead:(Tile*)tile;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (NSMutableDictionary*)getSaveDict;
- (MapleTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                     saveDict:(NSMutableDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (MapleTree*)initWithWorld:(World*)world_
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
