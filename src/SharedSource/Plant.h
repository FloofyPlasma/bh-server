//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

@class NoiseFunction;

@interface Plant : DynamicObject
{
    unsigned short maxAgeGene;
    unsigned short growthRateGene;
    NoiseFunction *treeDensityNoiseFunction;
    NoiseFunction *seasonOffsetNoiseFunction;
    int seasonOffset;
    float age;
    BOOL frozen;
    int gatherProgress;
    BOOL hasFloweredThisSeason;
    BOOL flowering;
    float maxAge;
    float growthRate;
    float ageCounter;
}

- (int)numberOfOccupiedTilesBelow;
- (int)numberOfOccupiedTilesAbove;
- (BOOL)occupiesForegroundContents;
- (BOOL)canBreed;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)clearAllTileContents;
- (BOOL)tileIsKindOfSelf:(struct Tile *)arg1;
- (int)droppedItemType;
- (BOOL)isFlowering;
- (unsigned short)growthRateGeneVariation;
- (unsigned short)maxAgeGeneVariation;
- (void)removePlantWithoutCreatingFreeblocks;
- (void)setGatherProgress:(int)arg1 forTile:(CDStruct_ffe6b7c1)arg2;
- (int)tileHarvested:(CDStruct_ffe6b7c1)arg1 removeBlockhead:(id)arg2 correctToolMultiplier:(int)arg3;
- (int)gatherProgressForTile:(CDStruct_ffe6b7c1)arg1;
- (int)plantType;
- (BOOL)isRequiredSoilType:(int)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)isGrowingInCompost;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (void)setFlowering:(BOOL)arg1;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct PlantCreationNetData)plantCreationNetData;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)dealloc;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 cache:(id)arg3 netData:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4 treeDensityNoiseFunction:(id)arg5 seasonOffsetNoiseFunction:(id)arg6;
- (void)loadSaveDictValues:(id)arg1;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(CDStruct_ffe6b7c1)arg3 cache:(id)arg4 maxAgeGene:(unsigned short)arg5 growthRateGene:(unsigned short)arg6 treeDensityNoiseFunction:(id)arg7 seasonOffsetNoiseFunction:(id)arg8 adultPlant:(BOOL)arg9;
- (void)removeFromMacroBlock;

@end

