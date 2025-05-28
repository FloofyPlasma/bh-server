#import <Foundation/Foundation.h>

#import "Tree.h"

/**
 * @class GemTree
 * @brief Placeholder! Please remember to fill this in.
 */
@interface GemTree : Tree {
  int gemTreeType;
  int fruitYear;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isStaticTree;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)gemItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TreeType)treeType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)recursivelyAddOwnedTile:(intpair)tilePos
                    toPositions:(std::unordered_set<int>*)ownedTilePositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
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
- (int)trunkBushContentsType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)trunkContentsType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)bushContentsType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GemTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GemTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                  gemTreeType:(TreeType)gemTreeType_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldAddFallenFruits;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)fruitShouldFallInSeason:(int)season;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)fruitItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
