//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "Tree.h"

@interface CoconutTree : Tree
{
}

- (BOOL)isRequiredSoilType:(int)arg1;
- (int)treeType;
- (BOOL)tileIsKindOfSelf:(struct Tile *)arg1;
- (void)makeTileDead:(struct Tile *)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)updateGrowth:(BOOL)arg1;
- (id)getSaveDict;
- (void)loadSaveDictValues:(id)arg1;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4 treeDensityNoiseFunction:(id)arg5 seasonOffsetNoiseFunction:(id)arg6;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(intpair)arg3 cache:(id)arg4 maxHeight:(short)arg5 growthRate:(short)arg6 treeDensityNoiseFunction:(id)arg7 seasonOffsetNoiseFunction:(id)arg8 adultTree:(BOOL)arg9 adultMaxAge:(float)arg10;
- (BOOL)fruitShouldFallInSeason:(int)arg1;
- (int)fruitItemType;
- (int)objectType;

@end

