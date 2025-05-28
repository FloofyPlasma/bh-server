#import <Foundation/Foundation.h>

#import "NPC.h"
#import "Plant.h"

@class ArtificialLight, CPTexture2D, Shader;

/**
 * @class NormalPlant
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
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
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lightGlowQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setFlowering:(BOOL)newFlowering;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NormalPlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                maxHeightGene:(int16_t)maxHeight_
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
- (Vector)lightColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)lightFactor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)emitsLight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCType)npcSpawnType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDieSeason:(int)season;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)floweringSeason:(int)season;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)foodToRemoveWhenSpawningNPC;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ImageType)renderImageType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)folliageItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)seedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)minAllowedTemperature;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TileContents)flowerContentsType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TileContents)contentsType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAgeBase;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
