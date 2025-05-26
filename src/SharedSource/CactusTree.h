#include "DynamicObjectType.h"
#import <Foundation/Foundation.h>

#import "Tree.h"

@interface CactusTree : Tree {
  int splitHeightA;
  int splitHeightB;
  BOOL splitDirection;
  float availableFood;
}

@property float availableFood; // @synthesize availableFood;
- (BOOL)isRequiredSoilType:(TileType)type;
- (TreeType)treeType;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (void)makeTileDead:(Tile*)tile;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (NSMutableDictionary*)getSaveDict;
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
- (CactusTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (CactusTree*)initWithWorld:(World*)world_
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
