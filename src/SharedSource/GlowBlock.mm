#import "GlowBlock.h"

@implementation GlowBlock

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (void)dealloc
{
  [self->light release];

  [super dealloc];
}

- (Vector)getLightRGB
{
  return Vector();
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (GlowBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (GlowBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ tile:(Tile*)tile_
{
  return nil;
}

- (int)lightGlowQuadCount
{
  return 0;
}

- (Vector)lightPos
{
  return Vector();
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)removeFromMacroBlock
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end