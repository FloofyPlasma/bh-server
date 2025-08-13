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

/**
 * @class Plant
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)numberOfOccupiedTilesBelow;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)numberOfOccupiedTilesAbove;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBreed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clearAllTileContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)droppedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isFlowering;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)growthRateGeneVariation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxAgeGeneVariation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removePlantWithoutCreatingFreeblocks;
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
- (int)plantType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isRequiredSoilType:(TileType)type;
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
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setFlowering:(BOOL)newFlowering;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantCreationNetData)plantCreationNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Deallocates this Plant, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Plant*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Plant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Plant*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                    maxHeight:(int16_t)maxHeight_
                   growthRate:(int16_t)growthRate_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                   adultPlant:(BOOL)adultPlant;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;

@end
