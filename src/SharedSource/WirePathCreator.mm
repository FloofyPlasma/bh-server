#import "WirePathCreator.h"

#import "DynamicObject.h"
#import "World.h"

@implementation WirePathCreator

- (void)dealloc
{
  free(self->derivedTilePropertiesArray);
  [self->openList release];
  [self->closedList release];

  [super dealloc];
}

- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject
{
  return 0;
}

- (WirePathCreator*)initWithWorld:(World*)world_
{
  return nil;
}

- (WirePathTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex
{
  return nullptr;
}

@end