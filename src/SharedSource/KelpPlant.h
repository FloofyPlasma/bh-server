#import <Foundation/Foundation.h>

#import "Plant.h"

@interface KelpPlant : Plant {
  int checkWeatherCount;
  int killCount;
  int aboveGatherProgress[16];
  float waveTimer;
  float growthTimer;
  float availableFood;
  float* savedDrawBuffers[2];
  int savedDrawBufferIndexes[2];
  int numberOfOccupiedTilesAbove;
}

@property float availableFood; // @synthesize availableFood;
- (void)removeFromMacroBlock;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)droppedItemType;
- (int)numberOfOccupiedTilesAbove;
- (void)setGatherProgress:(int)arg1 forTile:(intpair)arg2;
- (int)tileHarvested:(intpair)arg1
          removeBlockhead:(id)arg2
    correctToolMultiplier:(int)arg3;
- (int)gatherProgressForTile:(intpair)arg1;
- (BOOL)isRequiredSoilType:(int)arg1;
- (int)plantType;
- (BOOL)tileIsKindOfSelf:(Tile*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)dieOfOldAge;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
- (PlantCreationNetData)plantCreationNetData;
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
