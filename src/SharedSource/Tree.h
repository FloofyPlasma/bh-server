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
  unsigned short maxHeightGene;
  unsigned short growthRateGene;
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
- (unsigned short)growthRateGeneVariation;
- (unsigned short)maxHeightGeneVariation;
- (int)treeType;
- (BOOL)isRequiredSoilType:(int)arg1;
- (void)updateAllOwnedTilesToNewIDSize;
- (void)removeAllOwnedTiles:(BOOL)arg1;
- (void)killAllOwnedTilesAboveY:(int)arg1;
- (void)checkIfDeadTilesNeedRemoved;
- (void)killAllOwnedTiles;
- (void)makeTileDead:(Tile*)arg1;
- (BOOL)tileIsKindOfSelf:(Tile*)arg1;
- (void)updateGrowth:(BOOL)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)incrementHeight;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (id)getSaveDict;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
                 dynamicWorld:(id)arg2
                     saveDict:(id)arg3
                        cache:(id)arg4
     treeDensityNoiseFunction:(id)arg5
    seasonOffsetNoiseFunction:(id)arg6;
- (void)loadSaveDictValues:(id)arg1;
- (void)growInTimeSinceSaved:(double)arg1;
- (void)addFallenFruits;
- (BOOL)fruitShouldFallInSeason:(int)arg1;
- (BOOL)shouldAddFallenFruits;
- (int)fruitItemType;
- (BOOL)isGrowingInCompost;
- (id)initWithWorld:(id)arg1
                 dynamicWorld:(id)arg2
                   atPosition:(intpair)arg3
                        cache:(id)arg4
                    maxHeight:(short)arg5
                   growthRate:(short)arg6
     treeDensityNoiseFunction:(id)arg7
    seasonOffsetNoiseFunction:(id)arg8
                    adultTree:(BOOL)arg9
                  adultMaxAge:(float)arg10;
- (id)initStaticTreeWithWorld:(id)arg1
                 dynamicWorld:(id)arg2
                   atPosition:(intpair)arg3
                        cache:(id)arg4
     treeDensityNoiseFunction:(id)arg5
    seasonOffsetNoiseFunction:(id)arg6;
- (void)removeFromMacroBlock;

@end
