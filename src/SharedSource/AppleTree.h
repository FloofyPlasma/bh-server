#import "Tree.h"

#import "DynamicObjectType.h"

/**
 * @class AppleTree
 */
@interface AppleTree : Tree {
  float availableFood;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TreeType)treeType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)makeTileDead:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (AppleTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)fruitShouldFallInSeason:(int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)fruitItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setAvailableFood:(float)food;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)availableFood;

@end
