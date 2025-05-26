#import <Foundation/Foundation.h>

#import "Plant.h"

@class CPTexture2D, Shader;

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
- (unsigned short)colorGenesVariation;
- (unsigned short)mixGenesVariation;
- (BOOL)canBreed;
- (void)removeFromMacroBlock;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (ItemType)droppedItemType;
- (int)numberOfOccupiedTilesAbove;
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)setFlowering:(BOOL)newFlowering;
- (PlantCreationNetData)plantCreationNetData;
- (NSMutableDictionary*)getSaveDict;
- (TulipPlant*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
- (TulipPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (TulipPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                   maxAgeGene:(int16_t)maxHeight_
               growthRateGene:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
