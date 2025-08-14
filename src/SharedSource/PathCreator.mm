#import "PathCreator.h"

#import "DynamicObject.h"
#import "World.h"

@implementation PathCreator

@synthesize extraData;
@synthesize hasPath;
@synthesize pathType;
@synthesize goalInteraction;
@synthesize goalY;
@synthesize goalX;
@synthesize pathUser;
@synthesize inProgress;
@synthesize path;

- (void)abortPath
{
}

- (NSArray*)calculateFallPath
{
  return nil;
}

- (void)calculatePath
{
}

- (void)createPathWithDict:(NSDictionary*)pathDict
{
}

- (void)dealloc
{
  [self->arrayPathsToRelease release];
  [self->pathUser release];
  [self->openList release];
  [self->closedList release];
  [self->path release];
  [self->extraData release];

  [super dealloc];
}

- (PathCreator*)initWithWorld:(World*)world_
{
  return nil;
}

- (DerivedTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex
{
  return nullptr;
}

- (void)updatePath
{
}

@end