

#import "Tree.h"

@interface PineTree : Tree {
  float availableFood;
}

- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
- (int)treeType;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)makeTileDead:(struct Tile*)arg1;
- (void)updateGrowth:(BOOL)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
                 dynamicWorld:(id)arg2
                     saveDict:(id)arg3
                        cache:(id)arg4
     treeDensityNoiseFunction:(id)arg5
    seasonOffsetNoiseFunction:(id)arg6;
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
- (BOOL)shouldAddFallenFruits;
- (int)fruitItemType;
- (int)objectType;

@end
