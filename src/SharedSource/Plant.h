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
  unsigned short maxAgeGene;
  unsigned short growthRateGene;
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
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)clearAllTileContents;
- (BOOL)tileIsKindOfSelf:(struct Tile*)arg1;
- (int)droppedItemType;
- (BOOL)isFlowering;
- (unsigned short)growthRateGeneVariation;
- (unsigned short)maxAgeGeneVariation;
- (void)removePlantWithoutCreatingFreeblocks;
- (void)setGatherProgress:(int)arg1 forTile:(intpair)arg2;
- (int)tileHarvested:(intpair)arg1
          removeBlockhead:(id)arg2
    correctToolMultiplier:(int)arg3;
- (int)gatherProgressForTile:(intpair)arg1;
- (int)plantType;
- (BOOL)isRequiredSoilType:(int)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)isGrowingInCompost;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)setFlowering:(BOOL)arg1;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct PlantCreationNetData)plantCreationNetData;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
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
- (void)loadSaveDictValues:(id)arg1;
- (id)initWithWorld:(id)arg1
                 dynamicWorld:(id)arg2
                   atPosition:(intpair)arg3
                        cache:(id)arg4
                   maxAgeGene:(unsigned short)arg5
               growthRateGene:(unsigned short)arg6
     treeDensityNoiseFunction:(id)arg7
    seasonOffsetNoiseFunction:(id)arg8
                   adultPlant:(BOOL)arg9;
- (void)removeFromMacroBlock;

@end
