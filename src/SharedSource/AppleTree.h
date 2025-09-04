#import "Tree.h"

#import "DynamicObjectType.h"

/**
 * @class AppleTree
 */
@interface AppleTree : Tree {
    float availableFood;
}

/**
 * @copydoc Tree::tileIsKindOfSelf:
 * @returns YES if tile contents are one of the following: CONTENTS_APPLE_TREE_BUSH_DEAD, CONTENTS_APPLE_TREE_BUSH, CONTENTS_APPLE_TREE_TRUNK, CONTENTS_APPLE_TREE_TRUNK_BUSH, CONTENTS_APPLE_TREE_TRUNK_DEAD. NO otherwise
 */
- (BOOL)tileIsKindOfSelf:(Tile *)tile;

/**
 * @copydoc Tree::treeType
 * @returns TREE_APPLE
 */
- (TreeType)treeType;

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;

- (void)makeTileDead:(Tile *)tile;

- (void)updateGrowth:(BOOL)addNewBranchBlocks;

- (NSMutableDictionary *)getSaveDict;

/**
 * @copydoc Tree::initWithWorld:dynamicWorld:atPosition:cache:treeDensityNoiseFunction:seasonOffsetNoiseFunction:
 * @returns Initialized AppleTree instance, or nil if initialization fails.
 */
- (AppleTree *)initWithWorld:(World *)world_
                dynamicWorld:(DynamicWorld *)dynamicWorld_
                  atPosition:(intpair)pos_
                       cache:(CPCache *)cache_
    treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_
   seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_;

/**
 * @copydoc Tree::initWithWorld:dynamicWorld:atPosition:cache:maxHeight:growthRate:treeDensityNoiseFunction:seasonOffsetNoiseFunction:adultTree:adultMaxAge:
 * @returns Initialized AppleTree instance, or nil if initialization fails.
 */
- (AppleTree *)initWithWorld:(World *)world_
                dynamicWorld:(DynamicWorld *)dynamicWorld_
                  atPosition:(intpair)pos_
                       cache:(CPCache *)cache_
                   maxHeight:(int16_t)maxHeight_
                  growthRate:(int16_t)growthRate_
    treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_
   seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_
                   adultTree:(BOOL)adultTree
                 adultMaxAge:(float)adultMaxAge;

/**
 * @copydoc Tree::objectType
 * @returns DYNAMIC_OBJECT_TYPE_APPLE_TREE
 */
- (DynamicObjectType)objectType;

/**
 * @copydoc Tree::fruitShouldFallInSeason:
 * @returns YES if season = 3
 */
- (BOOL)fruitShouldFallInSeason:(int)season;

/**
 * @copydoc Tree::fruitItemType
 * @returns ITEM_APPLE
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
