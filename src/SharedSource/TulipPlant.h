

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
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)droppedItemType;
- (int)numberOfOccupiedTilesAbove;
- (int)tileHarvested:(intpair)arg1
          removeBlockhead:(id)arg2
    correctToolMultiplier:(int)arg3;
- (BOOL)isRequiredSoilType:(int)arg1;
- (int)plantType;
- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)setFlowering:(BOOL)arg1;
- (struct PlantCreationNetData)plantCreationNetData;
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
