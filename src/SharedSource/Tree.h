#import <Foundation/Foundation.h>

#import "DynamicObject.h"
#import "MJMath.h"

enum TreeType {
    TREE_NOTHING = 0x0,
    TREE_APPLE = 0x1,
    TREE_MANGO = 0x2,
    TREE_MAPLE = 0x3,
    TREE_PINE = 0x4,
    TREE_CACTUS = 0x5,
    TREE_COCONUT = 0x6,
    TREE_ORANGE = 0x7,
    TREE_CHERRY = 0x8,
    TREE_COFFEE = 0x9,
    TREE_LIME = 0xA,
    TREE_GEM_AMETHYST = 0xB,
    TREE_GEM_SAPPHIRE = 0xC,
    TREE_GEM_EMERALD = 0xD,
    TREE_GEM_RUBY = 0xE,
    TREE_GEM_DIAMOND = 0xF,
};

struct TreeFruit {
    intpair pos;
    BOOL hasCreatedFreeBlockThisSeason;
};

@class NoiseFunction;

/**
 * @class Tree
 */
@interface Tree : DynamicObject {
    uint16_t maxHeightGene;
    uint16_t growthRateGene;
    int height;
    int maxHeightReached;
    float growthCounter;
    float growthRate;
    NoiseFunction *treeDensityNoiseFunction;
    NoiseFunction *seasonOffsetNoiseFunction;
    int treeSeasonOffset;
    int maxHeight;
    float maxAge;
    float age;
    float ageCounter;
    BOOL dead;
    double timeDied;
    float removeCheckCount;
    TreeFruit *treeFruits;
    int fruitCount;
    float noLightDieTimer;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;

/**
 * @brief Defines if this tree is static. (Meaning it does not grow larger)
 * @returns NO
 */
- (BOOL)isStaticTree;

/**
 * @brief Returns the height of this tree.
 * @returns #height
 */
- (int)height;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)growthRateGeneVariation;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHeightGeneVariation;

/**
 * @brief Defines what type of tree this is.
 * @returns TREE_NOTHING
 */
- (TreeType)treeType;

/**
 * @brief Checks if a TileType is valid for this tree.
 * @returns YES if TileType is dirt or compost, otherwise NO
 */
- (BOOL)isRequiredSoilType:(TileType)type;

/**
 * @brief Placeholder! Please remember to fill this in.
 * @note I believe this is a leftover function that would migrate this Tree to a new save version. I do not think it is currently used. \n-FloofyPlasma, August 13th, 2025
 */
- (void)updateAllOwnedTilesToNewIDSize;

/**
 * @brief Deletes all tiles owned by this Tree.
 */
- (void)removeAllOwnedTiles:(BOOL)createFreeBlocks;

/**
 * @brief Changes all tiles owned by this Tree above a certain Y value to a dead variant of this TreeType.
 */
- (void)killAllOwnedTilesAboveY:(int)yMin;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)checkIfDeadTilesNeedRemoved;

/**
 * @brief Changes all tiles owned by this Tree to a dead variant of this TreeType.
 */
- (void)killAllOwnedTiles;

/**
 * @brief Changes a tile to a dead variant of this TreeType.
 */
- (void)makeTileDead:(Tile *)tile;

/**
 * @brief Returns whether a tile is a part of this Tree.
 */
- (BOOL)tileIsKindOfSelf:(Tile *)tile;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGrowth:(BOOL)addNewBranchBlocks;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementHeight;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions;

/**
 * @brief Returns a dictionary representing the current state of this Tree.
 * @returns NSMutableDictionary containing all relevant properties of the Tree.
 */
- (NSMutableDictionary *)getSaveDict;

/**
 * @brief Deallocates this Tree, and frees any memory it may have allocated.
 */
- (void)dealloc;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Tree *)  initWithWorld:(World *)world_
             dynamicWorld:(DynamicWorld *)dynamicWorld_
               atPosition:(intpair)pos_
                    cache:(CPCache *)cache_
 treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_
seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadSaveDictValues:(NSDictionary *)saveDict;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)growInTimeSinceSaved:(NSTimeInterval)saveTime;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addFallenFruits;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)fruitShouldFallInSeason:(int)season;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldAddFallenFruits;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)fruitItemType;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isGrowingInCompost;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Tree *)  initWithWorld:(World *)world_
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
 * @brief Placeholder! Please remember to fill this in.
 */
- (Tree *)initStaticTreeWithWorld:(World *)world_
                     dynamicWorld:(DynamicWorld *)dynamicWorld_
                       atPosition:(intpair)pos_
                            cache:(CPCache *)cache_
         treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_
        seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;

@end
