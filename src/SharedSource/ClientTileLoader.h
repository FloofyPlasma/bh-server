#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

@class BHClient, NoiseFunction;

@interface ClientTileLoader : NSObject
{
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

- (float)sandFractionForPos:(intpair)arg1 height:(int)arg2 highRes:(BOOL)arg3;
- (float)sandFractionForPos:(intpair)arg1 highRes:(BOOL)arg2;
- (void)initialDataRecievedFromServer:(id)arg1;
- (void)lightBlockDataRecievedFromServer:(id)arg1;
- (void)blockDataRecievedFromServer:(id)arg1;
- (void)updateQueue;
- (void)blockDataNotLoadedOnServer:(unsigned int)arg1;
- (BOOL)waitingForFoodTypes;
- (BOOL)waitingForBlocks;
- (int*)distanceOrderedFoodTypes;
- (void)loadPhysicalBlock:(PhysicalBlock*)arg1
                    atPos:(intpair)arg2
            withTilesData:(id)arg3
                lightData:(id)arg4
            extraDataDict:(id)arg5;
- (void)requestBlockFromServerAtPos:(intpair)arg1 createIfNotCreated:(BOOL)arg2;
- (int)waitingForBlocksCount;
- (int)unmodifiedGroundLevelForX:(int)arg1;
- (void)getRockAndDirtHeightforX:(int)arg1
                      rockHeight:(int*)arg2
                      dirtHeight:(int*)arg3;
- (BOOL)isCaveForX:(int)arg1 y:(int)arg2 faultOffset:(int)arg3;
- (int)faultOffsetForX:(int)arg1 y:(int)arg2;
- (int)maxOfRockAndDirtHeightForX:(int)arg1;
- (void)getInitialRockAndDirtHeightforX:(int)arg1
                             rockHeight:(float*)arg2
                             dirtHeight:(float*)arg3;
- (BOOL)shouldBeCrystalBlockAtX:(int)arg1 y:(int)arg2;
- (void)dealloc;
- (void)deleteTimers;
- (id)initWithWorld:(id)arg1
             client:(id)arg2
             saveID:(id)arg3
         randomSeed:(int)arg4
          cameraPos:(intpair)arg5;

@end
