#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum PlantType {
  PLANT_NOTHING = 0x0,
  PLANT_FLAX = 0x1,
  PLANT_SUNFLOWER = 0x2,
  PLANT_CORN = 0x3,
  PLANT_CARROT = 0x4,
  PLANT_CHILLI = 0x5,
  PLANT_KELP = 0x6,
  PLANT_VINE = 0x7,
  PLANT_TULIP = 0x8,
  PLANT_WHEAT = 0x9,
  PLANT_TOMATO = 0xA,
};

struct PlantCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t age;
  uint16_t displayGeneDataA;
  uint16_t displayGeneDataB;
  uint16_t displayGeneDataC;
  int16_t extraData;
  uint8_t flowering;
  uint8_t padding[5];
};

@class NoiseFunction;

@interface Plant : DynamicObject {
  uint16_t maxAgeGene;
  uint16_t growthRateGene;
  NoiseFunction* treeDensityNoiseFunction;
  NoiseFunction* seasonOffsetNoiseFunction;
  int seasonOffset;
  float age;
  BOOL frozen;
  int gatherProgress;
  BOOL hasFloweredThisSeason;
  BOOL flowering;
  float maxAge;
  float growthRate;
  float ageCounter;
}

- (int)numberOfOccupiedTilesBelow;
- (int)numberOfOccupiedTilesAbove;
- (BOOL)occupiesForegroundContents;
- (BOOL)canBreed;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)clearAllTileContents;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (ItemType)droppedItemType;
- (BOOL)isFlowering;
- (uint16_t)growthRateGeneVariation;
- (uint16_t)maxAgeGeneVariation;
- (void)removePlantWithoutCreatingFreeblocks;
- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos;
- (int)tileHarvested:(intpair)tilePos
          removeBlockhead:(Blockhead*)removeBlockhead
    correctToolMultiplier:(int)correctToolMultiplier;
- (int)gatherProgressForTile:(intpair)tilePos;
- (int)plantType;
- (BOOL)isRequiredSoilType:(TileType)type;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)isGrowingInCompost;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)setFlowering:(BOOL)newFlowering;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (PlantCreationNetData)plantCreationNetData;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (Plant*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
- (Plant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
- (Plant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                    maxHeight:(int16_t)maxHeight_
                   growthRate:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
- (void)removeFromMacroBlock;

@end
