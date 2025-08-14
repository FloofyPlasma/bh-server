#import "Plant.h"

#import "NoiseFunction.h"

@implementation Plant

- (BOOL)canBreed
{
  return NO;
}

- (void)clearAllTileContents
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [super dealloc];
}

- (ItemType)droppedItemType
{
  return ITEM_FLAX_MAT;
}

- (int)gatherProgressForTile:(intpair)tilePos
{
  return 0;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (uint16_t)growthRateGeneVariation
{
  return 0;
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
  return nil;
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Plant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)isFlowering
{
  return NO;
}

- (BOOL)isGrowingInCompost
{
  return NO;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (void)loadSaveDictValues:(NSDictionary*)saveDict
{
}

- (uint16_t)maxAgeGeneVariation
{
  return 0;
}

- (int)numberOfOccupiedTilesAbove
{
  return 0;
}

- (int)numberOfOccupiedTilesBelow
{
  return 0;
}

- (BOOL)occupiesForegroundContents
{
  return NO;
}

- (PlantCreationNetData)plantCreationNetData
{
  return PlantCreationNetData();
}

- (int)plantType
{
  return 0;
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
  return 0;
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end