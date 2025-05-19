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

@interface Tree : DynamicObject {
  uint16_t maxHeightGene;
  uint16_t growthRateGene;
  int height;
  int maxHeightReached;
  float growthCounter;
  float growthRate;
  NoiseFunction* treeDensityNoiseFunction;
  NoiseFunction* seasonOffsetNoiseFunction;
  int treeSeasonOffset;
  int maxHeight;
  float maxAge;
  float age;
  float ageCounter;
  BOOL dead;
  double timeDied;
  float removeCheckCount;
  TreeFruit* treeFruits;
  int fruitCount;
  float noLightDieTimer;
}

- (BOOL)occupiesNormalContents;
- (BOOL)isStaticTree;
- (int)height;
- (uint16_t)growthRateGeneVariation;
- (uint16_t)maxHeightGeneVariation;
- (TreeType)treeType;
- (BOOL)isRequiredSoilType:(TileType)type;
- (void)updateAllOwnedTilesToNewIDSize;
- (void)removeAllOwnedTiles:(BOOL)createFreeBlocks;
- (void)killAllOwnedTilesAboveY:(int)yMin;
- (void)checkIfDeadTilesNeedRemoved;
- (void)killAllOwnedTiles;
- (void)makeTileDead:(Tile*)tile;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)incrementHeight;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (Tree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
- (void)growInTimeSinceSaved:(NSTimeInterval)saveTime;
- (void)addFallenFruits;
- (BOOL)fruitShouldFallInSeason:(int)season;
- (BOOL)shouldAddFallenFruits;
- (ItemType)fruitItemType;
- (BOOL)isGrowingInCompost;
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
- (Tree*)initStaticTreeWithWorld:(World*)world_
                    dynamicWorld:(DynamicWorld*)dynamicWorld_
                      atPosition:(intpair)pos_
                           cache:(CPCache*)cache_
        treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
       seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (void)removeFromMacroBlock;

@end
