

#import "DynamicObject.h"

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
  struct TreeFruit* treeFruits;
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
- (void)makeTileDead:(struct Tile*)arg1;
- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
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
