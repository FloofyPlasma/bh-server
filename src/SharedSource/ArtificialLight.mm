#import "ArtificialLight.h"

@implementation ArtificialLight

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject colorR:(int)colorR_ colorG:(int)colorG_ colorB:(int)colorB_ heat:(int)heat_ radius:(int)radius_ lightDirection:(LightDirectionType)lightDirection
{
  return nil;
}

- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (void)addToTiles
{
}

- (void)dealloc
{
  [self removeFromTiles];
  free(self->contributionGrid);
  free(self->addedGrid);

  [super dealloc];
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject
{
  return nil;
}

- (Vector)lightColor
{
  return Vector();
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)recursivelyUpdateLightWithList:(std::list<unsigned int>*)openList
{
}

- (void)removeFromMacroBlock
{
}

- (void)removeFromTiles
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end