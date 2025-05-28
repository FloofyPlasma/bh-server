#import "Plant.h"

@implementation Plant

- (BOOL)canBreed
{
}

- (void)clearAllTileContents
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (ItemType)droppedItemType
{
}

- (int)gatherProgressForTile:(intpair)tilePos
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (uint16_t)growthRateGeneVariation
{
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
}

- (BOOL)isFlowering
{
}

- (BOOL)isGrowingInCompost
{
}

- (BOOL)isRequiredSoilType:(TileType)type
{
}

- (void)loadSaveDictValues:(NSDictionary*)saveDict
{
}

- (uint16_t)maxAgeGeneVariation
{
}

- (int)numberOfOccupiedTilesAbove
{
}

- (int)numberOfOccupiedTilesBelow
{
}

- (BOOL)occupiesForegroundContents
{
}

- (PlantCreationNetData)plantCreationNetData
{
}

- (int)plantType
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (void)removePlantWithoutCreatingFreeblocks
{
}

- (void)setFlowering:(BOOL)newFlowering
{
}

- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
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

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end