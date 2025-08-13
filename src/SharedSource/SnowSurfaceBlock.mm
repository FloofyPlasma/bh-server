#import "SnowSurfaceBlock.h"

@implementation SnowSurfaceBlock

@synthesize partialContent;

- (void)dealloc
{
  [self->saveDictCached release];

  [super dealloc];
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (SnowSurfaceBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_
{
  return nil;
}

- (SnowSurfaceBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)removeAllSnow
{
}

- (void)removeFromMacroBlock
{
}

- (BOOL)removeIfFloating
{
  return NO;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)spreadGrass:(Tile*)belowTile tile:(Tile*)tile
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGroundFrozen:(Tile*)belowTile tile:(Tile*)tile
{
}

- (void)updateInTimeSinceSaved
{
}

- (void)updateRain:(float)rainFraction dt:(float)dt
{
}

- (void)updateSnowContent:(BOOL)forceUpdate tile:(Tile*)tile
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end