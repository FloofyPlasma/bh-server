#import "VinePlant.h"

@implementation VinePlant

@synthesize availableFood;

- (int)addForegroundDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (void)dealloc
{
  [super dealloc];
}

- (void)dieOfOldAge
{
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

- (void)initSubDerivedItems
{
}

- (VinePlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxAgeGene:(int16_t)maxHeight_ growthRateGene:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
  return nil;
}

- (VinePlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (VinePlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)isGrowingInCompost
{
  return NO;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (int)numberOfOccupiedTilesBelow
{
  return 0;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (PlantCreationNetData)plantCreationNetData
{
  return PlantCreationNetData();
}

- (PlantType)plantType
{
  return PLANT_KELP;
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
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

@end