#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

@class Database, DatabaseEnvironment, NoiseFunction, World;

@interface WorldTileLoader : NSObject {
  World* world;
  unsigned int randomSeed;
  NSString* blockDirectory;
  NoiseFunction* heightNoiseFunctionA;
  NoiseFunction* heightNoiseFunctionB;
  NoiseFunction* faultNoiseFunction;
  NoiseFunction* treeDensityNoiseFunction;
  NoiseFunction* rockTypeNoiseFunction;
  NoiseFunction* flintDensityNoiseFunction;
  NoiseFunction* tinDensityNoiseFunction;
  NoiseFunction* sandNoiseFunction;
  NoiseFunction* seasonOffsetNoiseFunction;
  NoiseFunction* caveNoiseFunctionA;
  NoiseFunction* caveNoiseFunctionB;
  NoiseFunction* gemNoiseFunction;
  int* treePositions;
  int* npcPositions;
  int* plantPositions;
  intpair bestStartPosition;
  intpair highestPoint;
  int* dirtHeights;
  int* rockHeights;
  int* lakeHeights;
  BOOL hasRefinedTerrain;
  int distanceOrderedFoodTypes[31];
  int refineTerrainCount;
  BOOL needsToExit;
  int xFrequencyMultiplier;
  float yHeightDivider;
  DatabaseEnvironment* lightBlockDatabaseEnvironment;
  Database* lightBlockDatabase;
  Database* blockDatabase;
}

@property (readonly)
    Database* lightBlockDatabase; // @synthesize lightBlockDatabase;
@property (readonly) float yHeightDivider; // @synthesize yHeightDivider;
@property (readonly)
    int xFrequencyMultiplier; // @synthesize xFrequencyMultiplier;
@property BOOL needsToExit; // @synthesize needsToExit;
@property (readonly) intpair highestPoint; // @synthesize highestPoint;
@property (readonly) int* plantPositions; // @synthesize plantPositions;
@property (readonly) int* npcPositions; // @synthesize npcPositions;
@property (readonly) int* treePositions; // @synthesize treePositions;
@property (readonly) NoiseFunction* seasonOffsetNoiseFunction; // @synthesize seasonOffsetNoiseFunction;
@property (readonly) NoiseFunction* treeDensityNoiseFunction; // @synthesize treeDensityNoiseFunction;
@property (readonly) intpair bestStartPosition; // @synthesize bestStartPosition;
@property (readonly) unsigned int randomSeed; // @synthesize randomSeed;
- (BOOL)finishBulkLightBlockTransaction;
- (void)startBulkLightBlockTransaction;
- (void)saveLightBlockForClientLightBlockIndex:(int)arg1
                                      clientID:(id)arg2
                                 physicalBlock:(PhysicalBlock*)arg3
                                       sendNow:(BOOL)arg4;
- (BOOL)sendLightBlockToClientWithoutSavingForBlock:(PhysicalBlock*)arg1
                                                pos:(intpair)arg2
                                       sendToClient:(id)arg3
                                             server:(id)arg4;
- (void)loadLightBlockForClientLightBlockIndex:(int)arg1
                                      clientID:(id)arg2
                             intoPhysicalBlock:(PhysicalBlock*)arg3;
- (void)archiveLightBlocksForClient:(id)arg1;
- (void)unarchiveLightBlocksForClient:(id)arg1;
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)arg1;
- (int*)distanceOrderedFoodTypes;
- (intpair)findBestStartPosition;
- (void)loadPhysicalBlock:(PhysicalBlock*)arg1
                   atXPos:(int)arg2
                     yPos:(int)arg3
       createIfNotCreated:(BOOL)arg4;
- (void)placeGemsInCaveForPhysicalBlock:(PhysicalBlock*)arg1
                              tileIndex:(int)arg2
                                 worldX:(int)arg3
                                 worldY:(int)arg4
                     floatingIslandType:(int)arg5;
- (void)recursivelyFlowOutDirtFromTile:(Tile*)arg1 atPos:(intpair)arg2;
- (void)recursivelyFlowOutWaterFromTile:(Tile*)arg1 atPos:(intpair)arg2;
- (void)fillDirtTile:(Tile*)arg1
            worldPos:(intpair)arg2
     worldDirtHeight:(int)arg3
          parentType:(int)arg4;
- (BOOL)isDesertOrBeachForPos:(intpair)arg1 height:(int)arg2;
- (BOOL)isBeachForPos:(intpair)arg1 height:(int)arg2;
- (BOOL)isDesertForPos:(intpair)arg1 height:(int)arg2;
- (float)sandFractionForPos:(intpair)arg1 height:(int)arg2 highRes:(BOOL)arg3;
- (float)sandFractionForPos:(intpair)arg1 highRes:(BOOL)arg2;
- (void)savePhysicalBlock:(PhysicalBlock*)arg1
                macroTile:(MacroTile*)arg2
            sendToClients:(id)arg3
                   server:(id)arg4
             sendReliably:(BOOL)arg5;
- (BOOL)sendBlockToClientWithoutSavingForBlock:(PhysicalBlock*)arg1
                                           pos:(intpair)arg2
                                  sendToClient:(id)arg3
                                        server:(id)arg4
                            sendDynamicObjects:(BOOL)arg5
                                      reliable:(BOOL)arg6;
- (BOOL)isFloatingIslandCaveForX:(int)arg1 y:(int)arg2;
- (BOOL)isCaveForX:(int)arg1 y:(int)arg2 faultOffset:(int)arg3;
- (int)lakeHeightForX:(int)arg1;
- (int)maxOfRockAndDirtHeightForX:(int)arg1;
- (int)unmodifiedGroundLevelForX:(int)arg1;
- (float)sandstoneFractionForX:(int)arg1
                             y:(int)arg2
                   faultOffset:(int)arg3
             limestoneFraction:(float)arg4;
- (float)limestoneFractionForX:(int)arg1 y:(int)arg2 faultOffset:(int)arg3;
- (int)getCloudHeightForX:(int)arg1;
- (void)getRockAndDirtHeightforX:(int)arg1
                      rockHeight:(int*)arg2
                      dirtHeight:(int*)arg3;
- (int)faultOffsetForX:(int)arg1 y:(int)arg2;
- (void)getInitialRockAndDirtHeightforX:(int)arg1
                             rockHeight:(float*)arg2
                             dirtHeight:(float*)arg3;
- (void)refineTerrain;
- (void)dealloc;
- (void)compressBlocks;
- (id)initWithWorld:(id)arg1
         randomSeed:(unsigned int)arg2
         isNewWorld:(BOOL)arg3
             saveID:(id)arg4
      loadedVersion:(int)arg5
      blockDatabase:(id)arg6;

@end
