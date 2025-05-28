#import "NormalPlant.h"

@implementation NormalPlant

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
}

- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index
{
}

- (BOOL)canDieSeason:(int)season
{
}

- (TileContents)contentsType
{
}

- (void)dealloc
{
}

- (ItemType)droppedItemType
{
}

- (BOOL)emitsLight
{
}

- (TileContents)flowerContentsType
{
}

- (BOOL)floweringSeason:(int)season
{
}

- (ItemType)folliageItemType
{
}

- (float)foodToRemoveWhenSpawningNPC
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (void)initSubDerivedItems
{
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeightGene:(int16_t)maxHeight_ growthRateGene:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (NormalPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
}

- (Vector)lightColor
{
}

- (float)lightFactor
{
}

- (int)lightGlowQuadCount
{
}

- (float)maxAgeBase
{
}

- (int)minAllowedTemperature
{
}

- (NPCType)npcSpawnType
{
}

- (int)numberOfOccupiedTilesAbove
{
}

- (DynamicObjectType)objectType
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (ImageType)renderImageType
{
}

- (ItemType)seedItemType
{
}

- (void)setFlowering:(BOOL)newFlowering
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
}

- (int)tileHarvested:(intpair)tilePos removeBlockhead:(Blockhead*)removeBlockhead correctToolMultiplier:(int)correctToolMultiplier
{
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end