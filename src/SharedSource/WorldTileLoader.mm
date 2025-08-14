#import "WorldTileLoader.h"

#import "Database.h"
#import "DatabaseEnvironment.h"
#import "NoiseFunction.h"
#import "World.h"

@implementation WorldTileLoader

@synthesize lightBlockDatabase;
@synthesize yHeightDivider;
@synthesize xFrequencyMultiplier;
@synthesize needsToExit;
@synthesize highestPoint;
@synthesize plantPositions;
@synthesize npcPositions;
@synthesize treePositions;
@synthesize seasonOffsetNoiseFunction;
@synthesize treeDensityNoiseFunction;
@synthesize bestStartPosition;
@synthesize randomSeed;

- (void)archiveLightBlocksForClient:(NSString*)clientID
{
}

- (void)compressBlocks
{
}

- (void)dealloc
{
  [self->blockDirectory release];
  [self->heightNoiseFunctionA release];
  [self->heightNoiseFunctionB release];
  [self->faultNoiseFunction release];
  [self->treeDensityNoiseFunction release];
  [self->rockTypeNoiseFunction release];
  [self->flintDensityNoiseFunction release];
  [self->tinDensityNoiseFunction release];
  [self->sandNoiseFunction release];
  [self->seasonOffsetNoiseFunction release];
  [self->caveNoiseFunctionA release];
  [self->caveNoiseFunctionB release];
  [self->gemNoiseFunction release];
  free(self->treePositions);
  free(self->npcPositions);
  free(self->plantPositions);
  free(self->dirtHeights);
  free(self->rockHeights);
  free(self->lakeHeights);
  [self->lightBlockDatabase release];
  [self->lightBlockDatabaseEnvironment release];

  [super dealloc];
}

- (FoodType*)distanceOrderedFoodTypes
{
  return nullptr;
}

- (int)faultOffsetForX:(int)x y:(int)y
{
  return 0;
}

- (void)fillDirtTile:(Tile*)tile worldPos:(intpair)worldPos worldDirtHeight:(int)worldDirtHeight parentType:(TileType)parentType
{
}

- (intpair)findBestStartPosition
{
  return intpair();
}

- (BOOL)finishBulkLightBlockTransaction
{
  return NO;
}

- (int)getCloudHeightForX:(int)x
{
  return 0;
}

- (void)getInitialRockAndDirtHeightforX:(int)x rockHeight:(float*)rockHeight dirtHeight:(float*)dirtHeight
{
}

- (void)getRockAndDirtHeightforX:(int)x rockHeight:(int*)rockHeight dirtHeight:(int*)dirtHeight
{
}

- (WorldTileLoader*)initWithWorld:(World*)world_ randomSeed:(unsigned int)randomSeed_ isNewWorld:(BOOL)isNewWorld saveID:(NSString*)saveID loadedVersion:(int)loadedVersion blockDatabase:(Database*)blockDatabase_
{
  return nil;
}

- (BOOL)isBeachForPos:(intpair)worldPos height:(int)height
{
  return NO;
}

- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset
{
  return NO;
}

- (BOOL)isDesertForPos:(intpair)worldPos height:(int)height
{
  return NO;
}

- (BOOL)isDesertOrBeachForPos:(intpair)worldPos height:(int)height
{
  return NO;
}

- (BOOL)isFloatingIslandCaveForX:(int)x y:(int)y
{
  return NO;
}

- (int)lakeHeightForX:(int)x
{
  return 0;
}

- (float)limestoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset
{
  return 0;
}

- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex clientID:(NSString*)clientID intoPhysicalBlock:(PhysicalBlock*)physicalBlock
{
}

- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock atXPos:(int)xPos yPos:(int)yPos createIfNotCreated:(BOOL)createIfNotCreated
{
}

- (int)maxOfRockAndDirtHeightForX:(int)x
{
  return 0;
}

- (void)placeGemsInCaveForPhysicalBlock:(PhysicalBlock*)physicalBlock tileIndex:(int)tileIndex worldX:(int)worldX worldY:(int)worldY floatingIslandType:(IslandType)floatingIslandType
{
}

- (void)recursivelyFlowOutDirtFromTile:(Tile*)tile atPos:(intpair)worldPos
{
}

- (void)recursivelyFlowOutWaterFromTile:(Tile*)tile atPos:(intpair)worldPos
{
}

- (void)refineTerrain
{
}

- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes
{
  return 0;
}

- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes
{
  return 0;
}

- (float)sandstoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset limestoneFraction:(float)limestoneFraction
{
  return 0;
}

- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex clientID:(NSString*)clientID physicalBlock:(PhysicalBlock*)physicalBlock sendNow:(BOOL)sendNow
{
}

- (void)savePhysicalBlock:(PhysicalBlock*)physicalBlock macroTile:(MacroTile*)macroTile sendToClients:(NSArray*)clientsToSend server:(BHServer*)server sendReliably:(BOOL)sendReliably
{
}

- (BOOL)sendBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock pos:(intpair)pos sendToClient:(NSString*)clientToSend server:(BHServer*)server sendDynamicObjects:(BOOL)sendDynamicObjects reliable:(BOOL)reliable
{
  return NO;
}

- (BOOL)sendLightBlockToClientWithoutSavingForBlock:(PhysicalBlock*)physicalBlock pos:(intpair)pos sendToClient:(NSString*)client server:(BHServer*)server
{
  return NO;
}

- (void)startBulkLightBlockTransaction
{
}

- (void)unarchiveLightBlocksForClient:(NSString*)clientID
{
}

- (int)unmodifiedGroundLevelForX:(int)x
{
  return 0;
}

- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock
{
}

@end