#import <Foundation/Foundation.h>

#import "Plant.h"

/**
 * @class VinePlant
 * @brief Placeholder! Please remember to fill this in.
 */
@interface VinePlant : Plant {
  float availableFood;
  int checkWeatherCount;
  int killCount;
  int belowGatherProgress[16];
  float growthTimer;
  int numberOfOccupiedTilesBelow;
}

@property float availableFood; // @synthesize availableFood;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addForegroundDrawQuadData:(float*)buffer
                       fromIndex:(int)index
                     forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)droppedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)numberOfOccupiedTilesBelow;
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
- (void)dieOfOldAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isGrowingInCompost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantCreationNetData)plantCreationNetData;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (VinePlant*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (VinePlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (VinePlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                   maxAgeGene:(int16_t)maxHeight_
               growthRateGene:(int16_t)growthRate_
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
