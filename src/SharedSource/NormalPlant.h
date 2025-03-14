

#import "Plant.h"

@class ArtificialLight, CPTexture2D, Shader;

@interface NormalPlant : Plant {
  Shader* shader;
  CPTexture2D* texture;
  CPTexture2D* tileDestructTexture;
  int checkWeatherCount;
  int killCount;
  float availableFood;
  ArtificialLight* light;
  float lastLightFactor;
}

@property float availableFood; // @synthesize availableFood;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
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
- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (int)addLightGlowQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)lightGlowQuadCount;
- (void)remoteUpdate:(id)arg1;
- (void)setFlowering:(BOOL)arg1;
- (id)getSaveDict;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)dealloc;
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
- (Vector)lightColor;
- (float)lightFactor;
- (BOOL)emitsLight;
- (int)npcSpawnType;
- (BOOL)canDieSeason:(int)arg1;
- (BOOL)floweringSeason:(int)arg1;
- (float)foodToRemoveWhenSpawningNPC;
- (int)renderImageType;
- (int)folliageItemType;
- (int)seedItemType;
- (int)minAllowedTemperature;
- (int)flowerContentsType;
- (int)contentsType;
- (float)maxAgeBase;
- (int)objectType;

@end
