#import <Foundation/Foundation.h>

#import "Tree.h"

@interface GemTree : Tree {
  int gemTreeType;
  int fruitYear;
}

- (BOOL)isStaticTree;
- (BOOL)tileIsKindOfSelf:(Tile*)arg1;
- (int)gemItemType;
- (int)treeType;
- (void)recursivelyAddOwnedTile:(intpair)arg1
                    toPositions:(std::unordered_set<int>*)arg2;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)makeTileDead:(Tile*)arg1;
- (int)trunkBushContentsType;
- (int)trunkContentsType;
- (int)bushContentsType;
- (void)updateGrowth:(BOOL)arg1;
- (void)loadSaveDictValues:(id)arg1;
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
     treeDensityNoiseFunction:(id)arg5
    seasonOffsetNoiseFunction:(id)arg6
                  gemTreeType:(int)arg7;
- (BOOL)shouldAddFallenFruits;
- (BOOL)fruitShouldFallInSeason:(int)arg1;
- (int)fruitItemType;
- (int)objectType;

@end
