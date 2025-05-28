#import "SurfaceBlock.h"

@implementation SurfaceBlock

- (SurfaceBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_
{
  return nil;
}

- (SurfaceBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)removeFromMacroBlock
{
}

- (void)removeIfFloatingAndEmptyOfWater
{
}

- (BOOL)requiresPhysicalBlock
{
  return NO;
}

- (void)subtractWater:(int)amount fromOtherTile:(Tile*)otherTile atPos:(intpair)otherPos
{
}

- (BOOL)takeAnyWaterFromTileAtPos:(intpair)otherPos tile:(Tile*)tile
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end