#import <Foundation/Foundation.h>

#import "Plant.h"

/**
 * @class KelpPlant
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)droppedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)numberOfOccupiedTilesAbove;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)gatherProgressForTile:(intpair)tilePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isRequiredSoilType:(TileType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantType)plantType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dieOfOldAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantCreationNetData)plantCreationNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (KelpPlant*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (KelpPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (KelpPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                   maxAgeGene:(uint16_t)maxAgeGene_
               growthRateGene:(uint16_t)growthRateGene_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
