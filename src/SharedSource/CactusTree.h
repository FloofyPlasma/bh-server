#import <Foundation/Foundation.h>

#import "Tree.h"

/**
 * @class CactusTree
 */
@interface CactusTree : Tree {
    int splitHeightA;
    int splitHeightB;
    BOOL splitDirection;
    float availableFood;
}

@property float availableFood; // @synthesize availableFood;
/**
 * @copydoc Tree::isRequiredSoilType:
 * @returns YES if tile type is one of the following: TILE_SAND, TILE_SAND_BEACH, TILE_BLACK_SAND, TILE_COMPOST, TILE_COMPOST_GRASS, TILE_COMPOST_GRASS_FROZEN. NO otherwise
 */
- (BOOL)isRequiredSoilType:(TileType)type;

/**
 * @copydoc Tree::treeType
 * @returns TREE_CACTUS
 */
- (TreeType)treeType;

/**
 * @copydoc Tree::tileIsKindOfSelf:
 * @returns YES if tile contents are one of the following: CONTENTS_CACTUS, CONTENTS_CACTUS_DEAD. NO otherwise.
 */
- (BOOL)tileIsKindOfSelf:(Tile *)tile;

- (void)makeTileDead:(Tile *)tile;

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;

- (void)updateGrowth:(BOOL)addNewBranchBlocks;

- (NSMutableDictionary *)getSaveDict;

- (void)loadSaveDictValues:(NSDictionary *)saveDict;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CactusTree *)initWithWorld:(World *)world_
                 dynamicWorld:(DynamicWorld *)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache *)cache_
     treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CactusTree *)initWithWorld:(World *)world_
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
 * @copydoc Tree::fruitShouldFallInSeason:
 * @returns YES if season == 4, NO otherwise
 */
- (BOOL)fruitShouldFallInSeason:(int)season;

/**
 * @copydoc Tree::fruitItemType
 * @returns ITEM_PRICKLY_PEAR
 */
- (ItemType)fruitItemType;

/**
 * @copydoc DynamicObject::objectType
 * @returns DYNAMIC_OBJECT_TYPE_CACTUS_TREE
 */
- (DynamicObjectType)objectType;

@end
