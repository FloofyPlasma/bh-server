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

/**
 * @class WorldTileLoader
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @property yHeightDivider
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) float yHeightDivider; // @synthesize yHeightDivider;
@property (readonly)
    int xFrequencyMultiplier; // @synthesize xFrequencyMultiplier;
@property BOOL needsToExit; // @synthesize needsToExit;
/**
 * @property highestPoint
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair highestPoint; // @synthesize highestPoint;
/**
 * @property plantPositions
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) PlantType* plantPositions; // @synthesize plantPositions;
/**
 * @property npcPositions
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NPCType* npcPositions; // @synthesize npcPositions;
/**
 * @property treePositions
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) TreeType* treePositions; // @synthesize treePositions;
/**
 * @property seasonOffsetNoiseFunction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NoiseFunction* seasonOffsetNoiseFunction; // @synthesize seasonOffsetNoiseFunction;
/**
 * @property treeDensityNoiseFunction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NoiseFunction* treeDensityNoiseFunction; // @synthesize treeDensityNoiseFunction;
/**
 * @property bestStartPosition
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair bestStartPosition; // @synthesize bestStartPosition;
/**
 * @property randomSeed
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) unsigned int randomSeed; // @synthesize randomSeed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)finishBulkLightBlockTransaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startBulkLightBlockTransaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                      clientID:(NSString*)clientID
                                 physicalBlock:(PhysicalBlock*)physicalBlock
                                       sendNow:(BOOL)sendNow;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendLightBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock
                                                pos:(intpair)pos
                                       sendToClient:(NSString*)client
                                             server:(BHServer*)server;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                      clientID:(NSString*)clientID
                             intoPhysicalBlock:(PhysicalBlock*)physicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)archiveLightBlocksForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)unarchiveLightBlocksForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FoodType*)distanceOrderedFoodTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)findBestStartPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock
                   atXPos:(int)xPos
                     yPos:(int)yPos
       createIfNotCreated:(BOOL)createIfNotCreated;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)placeGemsInCaveForPhysicalBlock:(PhysicalBlock*)physicalBlock
                              tileIndex:(int)tileIndex
                                 worldX:(int)worldX
                                 worldY:(int)worldY
                     floatingIslandType:(IslandType)floatingIslandType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)recursivelyFlowOutDirtFromTile:(Tile*)tile atPos:(intpair)worldPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)recursivelyFlowOutWaterFromTile:(Tile*)tile atPos:(intpair)worldPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fillDirtTile:(Tile*)tile
            worldPos:(intpair)worldPos
     worldDirtHeight:(int)worldDirtHeight
          parentType:(TileType)parentType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDesertOrBeachForPos:(intpair)worldPos height:(int)height;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isBeachForPos:(intpair)worldPos height:(int)height;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDesertForPos:(intpair)worldPos height:(int)height;
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
- (void)savePhysicalBlock:(PhysicalBlock*)physicalBlock
                macroTile:(MacroTile*)macroTile
            sendToClients:(NSArray*)clientsToSend
                   server:(BHServer*)server
             sendReliably:(BOOL)sendReliably;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock
                                           pos:(intpair)pos
                                  sendToClient:(NSString*)clientToSend
                                        server:(BHServer*)server
                            sendDynamicObjects:(BOOL)sendDynamicObjects
                                      reliable:(BOOL)reliable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isFloatingIslandCaveForX:(int)x y:(int)y;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lakeHeightForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)maxOfRockAndDirtHeightForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)unmodifiedGroundLevelForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)sandstoneFractionForX:(int)worldX
                             y:(int)worldY
                   faultOffset:(int)faultOffset
             limestoneFraction:(float)limestoneFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)limestoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)getCloudHeightForX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getRockAndDirtHeightforX:(int)x
                      rockHeight:(int*)rockHeight
                      dirtHeight:(int*)dirtHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)faultOffsetForX:(int)x y:(int)y;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getInitialRockAndDirtHeightforX:(int)x
                             rockHeight:(float*)rockHeight
                             dirtHeight:(float*)dirtHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)refineTerrain;
/**
 * @brief Deallocates this WorldTileLoader, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)compressBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (WorldTileLoader*)initWithWorld:(World*)world_
                       randomSeed:(unsigned int)randomSeed_
                       isNewWorld:(BOOL)isNewWorld
                           saveID:(NSString*)saveID
                    loadedVersion:(int)loadedVersion
                    blockDatabase:(Database*)blockDatabase_;

@end
