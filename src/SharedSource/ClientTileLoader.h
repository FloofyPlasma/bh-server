#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "MJMath.h"
#import "World.h"

@class BHClient, NoiseFunction;

@interface ClientTileLoader : NSObject {
  World* world;
  BHClient* client;
  NSString* saveID;
  NSString* blockDirectory;
  NoiseFunction* heightNoiseFunctionA;
  NoiseFunction* heightNoiseFunctionB;
  NoiseFunction* sandNoiseFunction;
  NoiseFunction* faultNoiseFunction;
  NoiseFunction* caveNoiseFunctionA;
  NoiseFunction* caveNoiseFunctionB;
  NoiseFunction* flintDensityNoiseFunction;
  NoiseFunction* flintDensityNoiseFunctionLegacy;
  int* dirtHeights;
  int* rockHeights;
  BOOL hasDistanceOrderedFoodTypes;
  int distanceOrderedFoodTypes[31];
  std::vector<ClientMacroBlockRequest>
      queuedBlockRequests;
  std::map<
      int, ClientMacroBlockRequest>
      sentBlockRequests;
  NSMutableDictionary* blockRequestDates;
  int xFrequencyMultiplier;
  float yHeightDivider;
}

- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes;
- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes;
- (void)initialDataRecievedFromServer:(NSData*)initialData;
- (void)lightBlockDataRecievedFromServer:(NSData*)blockData;
- (void)blockDataRecievedFromServer:(NSData*)blockData;
- (void)updateQueue;
- (void)blockDataNotLoadedOnServer:(uint32_t)macroIndex;
- (BOOL)waitingForFoodTypes;
- (BOOL)waitingForBlocks;
- (FoodType*)distanceOrderedFoodTypes;
- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock
                    atPos:(intpair)pos
            withTilesData:(NSData*)tilesData
                lightData:(NSData*)lightData
            extraDataDict:(NSDictionary*)extraDataDict;
- (void)requestBlockFromServerAtPos:(intpair)createIfNotCreated createIfNotCreated:(BOOL)createIfNotCreated;
- (int)waitingForBlocksCount;
- (int)unmodifiedGroundLevelForX:(int)x;
- (void)getRockAndDirtHeightforX:(int)x
                      rockHeight:(int*)rockHeight
                      dirtHeight:(int*)dirtHeight;
- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset;
- (int)faultOffsetForX:(int)x y:(int)y;
- (int)maxOfRockAndDirtHeightForX:(int)x;
- (void)getInitialRockAndDirtHeightforX:(int)x
                             rockHeight:(float*)rockHeight
                             dirtHeight:(float*)dirtHeight;
- (BOOL)shouldBeCrystalBlockAtX:(int)x y:(int)y;
- (void)dealloc;
- (void)deleteTimers;
- (id)initWithWorld:(World*)world_
             client:(BHClient*)client_
             saveID:(NSString*)saveID_
         randomSeed:(int)randomSeed
          cameraPos:(intpair)cameraPos;

@end
