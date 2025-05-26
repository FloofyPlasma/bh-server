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
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (ItemType)droppedItemType;
- (int)numberOfOccupiedTilesAbove;
- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos;
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
- (int)gatherProgressForTile:(intpair)tilePos;
- (BOOL)isRequiredSoilType:(TileType)type;
- (PlantType)plantType;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)dieOfOldAge;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
- (PlantCreationNetData)plantCreationNetData;
- (NSMutableDictionary*)getSaveDict;
- (KelpPlant*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
- (KelpPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (KelpPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                   maxAgeGene:(uint16_t)maxAgeGene_
               growthRateGene:(uint16_t)growthRateGene_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
