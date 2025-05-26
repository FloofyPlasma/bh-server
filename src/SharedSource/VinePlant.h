#import <Foundation/Foundation.h>

#import "Plant.h"

@interface VinePlant : Plant {
  float availableFood;
  int checkWeatherCount;
  int killCount;
  int belowGatherProgress[16];
  float growthTimer;
  int numberOfOccupiedTilesBelow;
}

@property float availableFood; // @synthesize availableFood;
- (void)removeFromMacroBlock;
- (int)addForegroundDrawQuadData:(float*)buffer
                       fromIndex:(int)index
                     forMacroPos:(intpair)macroPos;
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos;
- (ItemType)droppedItemType;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (int)numberOfOccupiedTilesBelow;
- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos;
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
- (int)gatherProgressForTile:(intpair)tilePos;
- (BOOL)isRequiredSoilType:(TileType)type;
- (PlantType)plantType;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (void)dieOfOldAge;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)isGrowingInCompost;
- (PlantCreationNetData)plantCreationNetData;
- (void)dealloc;
- (void)remoteUpdate:(NSData*)netData;
- (NSMutableDictionary*)getSaveDict;
- (VinePlant*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
- (VinePlant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (VinePlant*)initWithWorld:(World*)world_
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
