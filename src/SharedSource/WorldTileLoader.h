#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "NPC.h"
#import "Plant.h"
#import "Tree.h"
#import "World.h"

enum IslandType {
  ISLAND_NONE = 0x0,
  ISLAND_AMETHYST = 0x1,
  ISLAND_SAPPHIRE = 0x2,
  ISLAND_EMERALD = 0x3,
  ISLAND_RUBY = 0x4,
  ISLAND_DIAMOND = 0x5,
  ISLAND_APPLE = 0x6,
  ISLAND_COCONUT = 0x7,
  ISLAND_ORANGE = 0x8,
  ISLAND_PINE = 0x9,
  ISLAND_LIME = 0xA,
  ISLAND_CACTUS = 0xB,
  ISLAND_CHERRY = 0xC,
  ISLAND_COFFEE = 0xD,
  ISLAND_MAPLE = 0xE,
  ISLAND_MANGO = 0xF,
};

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
  TreeType* treePositions;
  NPCType* npcPositions;
  PlantType* plantPositions;
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
@property (readonly) PlantType* plantPositions; // @synthesize plantPositions;
@property (readonly) NPCType* npcPositions; // @synthesize npcPositions;
@property (readonly) TreeType* treePositions; // @synthesize treePositions;
@property (readonly) NoiseFunction* seasonOffsetNoiseFunction; // @synthesize seasonOffsetNoiseFunction;
@property (readonly) NoiseFunction* treeDensityNoiseFunction; // @synthesize treeDensityNoiseFunction;
@property (readonly) intpair bestStartPosition; // @synthesize bestStartPosition;
@property (readonly) unsigned int randomSeed; // @synthesize randomSeed;
- (BOOL)finishBulkLightBlockTransaction;
- (void)startBulkLightBlockTransaction;
- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                      clientID:(NSString*)clientID
                                 physicalBlock:(PhysicalBlock*)physicalBlock
                                       sendNow:(BOOL)sendNow;
- (BOOL)sendLightBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock
                                                pos:(intpair)pos
                                       sendToClient:(NSString*)client
                                             server:(BHServer*)server;
- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                      clientID:(NSString*)clientID
                             intoPhysicalBlock:(PhysicalBlock*)physicalBlock;
- (void)archiveLightBlocksForClient:(NSString*)clientID;
- (void)unarchiveLightBlocksForClient:(NSString*)clientID;
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock;
- (FoodType*)distanceOrderedFoodTypes;
- (intpair)findBestStartPosition;
- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock
                   atXPos:(int)xPos
                     yPos:(int)yPos
       createIfNotCreated:(BOOL)createIfNotCreated;
- (void)placeGemsInCaveForPhysicalBlock:(PhysicalBlock*)physicalBlock
                              tileIndex:(int)tileIndex
                                 worldX:(int)worldX
                                 worldY:(int)worldY
                     floatingIslandType:(IslandType)floatingIslandType;
- (void)recursivelyFlowOutDirtFromTile:(Tile*)tile atPos:(intpair)worldPos;
- (void)recursivelyFlowOutWaterFromTile:(Tile*)tile atPos:(intpair)worldPos;
- (void)fillDirtTile:(Tile*)tile
            worldPos:(intpair)worldPos
     worldDirtHeight:(int)worldDirtHeight
          parentType:(TileType)parentType;
- (BOOL)isDesertOrBeachForPos:(intpair)worldPos height:(int)height;
- (BOOL)isBeachForPos:(intpair)worldPos height:(int)height;
- (BOOL)isDesertForPos:(intpair)worldPos height:(int)height;
- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes;
- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes;
- (void)savePhysicalBlock:(PhysicalBlock*)physicalBlock
                macroTile:(MacroTile*)macroTile
            sendToClients:(NSArray*)clientsToSend
                   server:(BHServer*)server
             sendReliably:(BOOL)sendReliably;
- (BOOL)sendBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock
                                           pos:(intpair)pos
                                  sendToClient:(NSString*)clientToSend
                                        server:(BHServer*)server
                            sendDynamicObjects:(BOOL)sendDynamicObjects
                                      reliable:(BOOL)reliable;
- (BOOL)isFloatingIslandCaveForX:(int)x y:(int)y;
- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset;
- (int)lakeHeightForX:(int)x;
- (int)maxOfRockAndDirtHeightForX:(int)x;
- (int)unmodifiedGroundLevelForX:(int)x;
- (float)sandstoneFractionForX:(int)worldX
                             y:(int)worldY
                   faultOffset:(int)faultOffset
             limestoneFraction:(float)limestoneFraction;
- (float)limestoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset;
- (int)getCloudHeightForX:(int)x;
- (void)getRockAndDirtHeightforX:(int)x
                      rockHeight:(int*)rockHeight
                      dirtHeight:(int*)dirtHeight;
- (int)faultOffsetForX:(int)x y:(int)y;
- (void)getInitialRockAndDirtHeightforX:(int)x
                             rockHeight:(float*)rockHeight
                             dirtHeight:(float*)dirtHeight;
- (void)refineTerrain;
- (void)dealloc;
- (void)compressBlocks;
- (WorldTileLoader*)initWithWorld:(World*)world_
                       randomSeed:(unsigned int)randomSeed_
                       isNewWorld:(BOOL)isNewWorld
                           saveID:(NSString*)saveID
                    loadedVersion:(int)loadedVersion
                    blockDatabase:(Database*)blockDatabase_;

@end
