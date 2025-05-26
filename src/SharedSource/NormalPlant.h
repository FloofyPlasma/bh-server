#import <Foundation/Foundation.h>

#import "NPC.h"
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
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
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
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index;
- (int)lightGlowQuadCount;
- (void)remoteUpdate:(NSData*)netData;
- (void)setFlowering:(BOOL)newFlowering;
- (NSMutableDictionary*)getSaveDict;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)dealloc;
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                maxHeightGene:(int16_t)maxHeight_
               growthRateGene:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
- (void)initSubDerivedItems;
- (Vector)lightColor;
- (float)lightFactor;
- (BOOL)emitsLight;
- (NPCType)npcSpawnType;
- (BOOL)canDieSeason:(int)season;
- (BOOL)floweringSeason:(int)season;
- (float)foodToRemoveWhenSpawningNPC;
- (ImageType)renderImageType;
- (ItemType)folliageItemType;
- (ItemType)seedItemType;
- (int)minAllowedTemperature;
- (TileContents)flowerContentsType;
- (TileContents)contentsType;
- (float)maxAgeBase;
- (DynamicObjectType)objectType;

@end
