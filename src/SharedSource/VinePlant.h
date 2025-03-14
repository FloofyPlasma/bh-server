

#import "Plant.h"

@interface VinePlant : Plant {
  float availableFood;
  int checkWeatherCount;
  int killCount;
  int belowGatherProgress[16];
  float growthTimer;
  int numberOfOccupiedTilesBelow;
}

@property float availableFood; // @synthesize availableFood;
- (void)removeFromMacroBlock;
- (int)addForegroundDrawQuadData:(float*)arg1
                       fromIndex:(int)arg2
                     forMacroPos:(intpair)arg3;
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)arg1;
- (int)droppedItemType;
- (void)setNeedsRemoved:(BOOL)arg1;
- (int)numberOfOccupiedTilesBelow;
- (void)setGatherProgress:(int)arg1 forTile:(intpair)arg2;
- (int)tileHarvested:(intpair)arg1
          removeBlockhead:(id)arg2
    correctToolMultiplier:(int)arg3;
- (int)gatherProgressForTile:(intpair)arg1;
- (BOOL)isRequiredSoilType:(int)arg1;
- (int)plantType;
- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
- (void)dieOfOldAge;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)isGrowingInCompost;
- (struct PlantCreationNetData)plantCreationNetData;
- (void)dealloc;
- (void)remoteUpdate:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
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
                   maxAgeGene:(unsigned short)arg5
               growthRateGene:(unsigned short)arg6
     treeDensityNoiseFunction:(id)arg7
    seasonOffsetNoiseFunction:(id)arg8
                   adultPlant:(BOOL)arg9;
- (void)initSubDerivedItems;
- (int)objectType;

@end
