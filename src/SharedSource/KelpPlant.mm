#import "KelpPlant.h"

@implementation KelpPlant

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (void)dealloc
{
}

- (void)dieOfOldAge
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
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

- (KelpPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxAgeGene:(uint16_t)maxAgeGene_ growthRateGene:(uint16_t)growthRateGene_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant
{
  return nil;
}

- (KelpPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (KelpPlant*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
  return nil;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (int)numberOfOccupiedTilesAbove
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

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
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