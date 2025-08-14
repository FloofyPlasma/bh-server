#import "HandCar.h"

#import "DrawCube.h"
#import "MJMultiSound.h"

@implementation HandCar

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
  return Vector2();
}

- (BOOL)connectsToOtherCars
{
  return NO;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->platformCube release];
  [self->poleCube release];
  [self->handleCube release];
  [self->pivotCube release];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (int)itemType
{
  return 0;
}

- (void)loadDerivedStuff
{
}

- (int)maxNumberOfRiders
{
  return 0;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeRider:(Blockhead*)blockhead
{
}

- (Vector2)renderPos
{
  return Vector2();
}

- (BOOL)requiresFuel
{
  return NO;
}

- (float)riderAnimationTimer
{
  return 0;
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
  return Vector();
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end
