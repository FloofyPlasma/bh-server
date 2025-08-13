#import <Foundation/Foundation.h>

#import "Plant.h"

@class CPTexture2D, Shader;

/**
 * @class TulipPlant
 * @brief Placeholder! Please remember to fill this in.
 */
@interface TulipPlant : Plant {
  float availableFood;
  int checkWeatherCount;
  int killCount;
  unsigned short colorGenes;
  unsigned short mixGenes;
  unsigned short mateColorGenes;
  Vector topColor;
  Vector bottomColor;
  Shader* shader;
  CPTexture2D* texture;
  float randomRotation;
}

@property unsigned short colorGenes; // @synthesize colorGenes;
@property float availableFood; // @synthesize availableFood;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (unsigned short)colorGenesVariation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (unsigned short)mixGenesVariation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBreed;
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
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setFlowering:(BOOL)newFlowering;
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
- (TulipPlant*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TulipPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TulipPlant*)initWithWorld:(World*)world_
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
