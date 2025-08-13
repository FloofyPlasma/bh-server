#import "PassengerCar.h"

@implementation PassengerCar

- (NSString*)actionTitle
{
  return nil;
}

- (void)addRider:(Blockhead*)blockhead
{
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
  return Vector2();
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->platformCube release];
  [self->poleCube release];
  [self->longWallCube release];
  [self->roofCube release];
  [self->shortWallCube release];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (PassengerCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (PassengerCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (PassengerCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (ItemType)itemType
{
  return ITEM_FLAX_MAT;
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

- (Vector2)renderPos
{
  return Vector2();
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

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
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

@end
