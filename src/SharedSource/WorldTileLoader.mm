#import "WorldTileLoader.h"

@implementation WorldTileLoader

- (void)archiveLightBlocksForClient:(NSString *)clientID {
}

- (void)compressBlocks {
}

- (void)dealloc {
}

- (FoodType *)distanceOrderedFoodTypes {
}

- (int)faultOffsetForX:(int)x y:(int)y {
}

- (void)fillDirtTile:(Tile *)tile worldPos:(intpair)worldPos worldDirtHeight:(int)worldDirtHeight parentType:(TileType)parentType {
}

- (intpair)findBestStartPosition {
}

- (BOOL)finishBulkLightBlockTransaction {
}

- (int)getCloudHeightForX:(int)x {
}

- (void)getInitialRockAndDirtHeightforX:(int)x rockHeight:(float *)rockHeight dirtHeight:(float *)dirtHeight {
}

- (void)getRockAndDirtHeightforX:(int)x rockHeight:(int *)rockHeight dirtHeight:(int *)dirtHeight {
}

- (WorldTileLoader *)initWithWorld:(World *)world_ randomSeed:(unsigned int)randomSeed_ isNewWorld:(BOOL)isNewWorld saveID:(NSString *)saveID loadedVersion:(int)loadedVersion blockDatabase:(Database *)blockDatabase_ {
}

- (BOOL)isBeachForPos:(intpair)worldPos height:(int)height {
}

- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset {
}

- (BOOL)isDesertForPos:(intpair)worldPos height:(int)height {
}

- (BOOL)isDesertOrBeachForPos:(intpair)worldPos height:(int)height {
}

- (BOOL)isFloatingIslandCaveForX:(int)x y:(int)y {
}

- (int)lakeHeightForX:(int)x {
}

- (float)limestoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset {
}

- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex clientID:(NSString *)clientID intoPhysicalBlock:(PhysicalBlock *)physicalBlock {
}

- (void)loadPhysicalBlock:(PhysicalBlock *)physicalBlock atXPos:(int)xPos yPos:(int)yPos createIfNotCreated:(BOOL)createIfNotCreated {
}

- (int)maxOfRockAndDirtHeightForX:(int)x {
}

- (void)placeGemsInCaveForPhysicalBlock:(PhysicalBlock *)physicalBlock tileIndex:(int)tileIndex worldX:(int)worldX worldY:(int)worldY floatingIslandType:(IslandType)floatingIslandType {
}

- (void)recursivelyFlowOutDirtFromTile:(Tile *)tile atPos:(intpair)worldPos {
}

- (void)recursivelyFlowOutWaterFromTile:(Tile *)tile atPos:(intpair)worldPos {
}

- (void)refineTerrain {
}

- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes {
}

- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes {
}

- (float)sandstoneFractionForX:(int)worldX y:(int)worldY faultOffset:(int)faultOffset limestoneFraction:(float)limestoneFraction {
}

- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex clientID:(NSString *)clientID physicalBlock:(PhysicalBlock *)physicalBlock sendNow:(BOOL)sendNow {
}

- (void)savePhysicalBlock:(PhysicalBlock *)physicalBlock macroTile:(MacroTile *)macroTile sendToClients:(NSArray *)clientsToSend server:(BHServer *)server sendReliably:(BOOL)sendReliably {
}

- (BOOL)sendBlockToClientWithoutSavingForBlock:(PhysicalBlock *)physicalBlock pos:(intpair)pos sendToClient:(NSString *)clientToSend server:(BHServer *)server sendDynamicObjects:(BOOL)sendDynamicObjects reliable:(BOOL)reliable {
}

- (BOOL)sendLightBlockToClientWithoutSavingForBlock:(PhysicalBlock *)physicalBlock pos:(intpair)pos sendToClient:(NSString *)client server:(BHServer *)server {
}

- (void)startBulkLightBlockTransaction {
}

- (void)unarchiveLightBlocksForClient:(NSString *)clientID {
}

- (int)unmodifiedGroundLevelForX:(int)x {
}

- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock *)physicalBlock {
}

@end