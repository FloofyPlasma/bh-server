//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "Tree.h"

@interface GemTree : Tree
{
    int gemTreeType;
    int fruitYear;
}

- (BOOL)isStaticTree;
- (BOOL)tileIsKindOfSelf:(struct Tile *)arg1;
- (int)gemItemType;
- (int)treeType;
- (void)recursivelyAddOwnedTile:(intpair)arg1 toPositions:(unordered_set_22babbde *)arg2;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)makeTileDead:(struct Tile *)arg1;
- (int)trunkBushContentsType;
- (int)trunkContentsType;
- (int)bushContentsType;
- (void)updateGrowth:(BOOL)arg1;
- (void)loadSaveDictValues:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4 treeDensityNoiseFunction:(id)arg5 seasonOffsetNoiseFunction:(id)arg6;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(intpair)arg3 cache:(id)arg4 treeDensityNoiseFunction:(id)arg5 seasonOffsetNoiseFunction:(id)arg6 gemTreeType:(int)arg7;
- (BOOL)shouldAddFallenFruits;
- (BOOL)fruitShouldFallInSeason:(int)arg1;
- (int)fruitItemType;
- (int)objectType;

@end

