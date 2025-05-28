#import "ClientTileLoader.h"

@implementation ClientTileLoader

- (void)blockDataNotLoadedOnServer:(uint32_t)macroIndex
{
}

- (void)blockDataRecievedFromServer:(NSData*)blockData
{
}

- (void)dealloc
{
}

- (void)deleteTimers
{
}

- (FoodType*)distanceOrderedFoodTypes
{
}

- (int)faultOffsetForX:(int)x y:(int)y
{
}

- (void)getInitialRockAndDirtHeightforX:(int)x rockHeight:(float*)rockHeight dirtHeight:(float*)dirtHeight
{
}

- (void)getRockAndDirtHeightforX:(int)x rockHeight:(int*)rockHeight dirtHeight:(int*)dirtHeight
{
}

- (id)initWithWorld:(World*)world_ client:(BHClient*)client_ saveID:(NSString*)saveID_ randomSeed:(int)randomSeed cameraPos:(intpair)cameraPos
{
}

- (void)initialDataRecievedFromServer:(NSData*)initialData
{
}

- (BOOL)isCaveForX:(int)x y:(int)y faultOffset:(int)faultOffset
{
}

- (void)lightBlockDataRecievedFromServer:(NSData*)blockData
{
}

- (void)loadPhysicalBlock:(PhysicalBlock*)physicalBlock atPos:(intpair)pos withTilesData:(NSData*)tilesData lightData:(NSData*)lightData extraDataDict:(NSDictionary*)extraDataDict
{
}

- (int)maxOfRockAndDirtHeightForX:(int)x
{
}

- (void)requestBlockFromServerAtPos:(intpair)createIfNotCreated createIfNotCreated:(BOOL)createIfNotCreated
{
}

- (float)sandFractionForPos:(intpair)worldPos height:(int)height highRes:(BOOL)highRes
{
}

- (float)sandFractionForPos:(intpair)worldPos highRes:(BOOL)highRes
{
}

- (BOOL)shouldBeCrystalBlockAtX:(int)x y:(int)y
{
}

- (int)unmodifiedGroundLevelForX:(int)x
{
}

- (void)updateQueue
{
}

- (BOOL)waitingForBlocks
{
}

- (int)waitingForBlocksCount
{
}

- (BOOL)waitingForFoodTypes
{
}

@end