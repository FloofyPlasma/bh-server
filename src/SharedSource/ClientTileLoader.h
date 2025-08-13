#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "MJMath.h"
#import "World.h"

@class BHClient, NoiseFunction;

/**
 * @class ClientTileLoader
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initialDataRecievedFromServer:(NSData*)initialData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)lightBlockDataRecievedFromServer:(NSData*)blockData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockDataRecievedFromServer:(NSData*)blockData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateQueue;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockDataNotLoadedOnServer:(uint32_t)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForFoodTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FoodType*)distanceOrderedFoodTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock
                    atPos:(intpair)pos
            withTilesData:(NSData*)tilesData
                lightData:(NSData*)lightData
            extraDataDict:(NSDictionary*)extraDataDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)requestBlockFromServerAtPos:(intpair)createIfNotCreated createIfNotCreated:(BOOL)createIfNotCreated;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)waitingForBlocksCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)unmodifiedGroundLevelForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getRockAndDirtHeightforX:(int)x
                      rockHeight:(int*)rockHeight
                      dirtHeight:(int*)dirtHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)faultOffsetForX:(int)x y:(int)y;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)maxOfRockAndDirtHeightForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getInitialRockAndDirtHeightforX:(int)x
                             rockHeight:(float*)rockHeight
                             dirtHeight:(float*)dirtHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldBeCrystalBlockAtX:(int)x y:(int)y;
/**
 * @brief Deallocates this ClientTileLoader, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)deleteTimers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithWorld:(World*)world_
             client:(BHClient*)client_
             saveID:(NSString*)saveID_
         randomSeed:(int)randomSeed
          cameraPos:(intpair)cameraPos;

@end
