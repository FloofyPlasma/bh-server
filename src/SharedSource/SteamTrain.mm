#import "SteamTrain.h"

#import "DrawCube.h"
#import "MJSound.h"

@implementation SteamTrain

@synthesize needsToUpdateChoiceUI;

- (void)addToFuelForItem:(ItemType)itemType
{
}

- (BOOL)canDismissFuelUI
{
  return NO;
}

- (int)fuelCount
{
  return 0;
}

- (int)fuelItemCount
{
  return 0;
}

- (int*)fuelItems
{
  return nullptr;
}

- (Vector2)fuelUIPos
{
  return Vector2();
}

- (NSString*)title
{
  return nil;
}

- (NSString*)actionTitle
{
  return nil;
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
  [self->boilerCube release];
  [self->wheelRodCube release];
  [self->frontGrillCube release];
  [self->driverCabCube release];
  [self->chimneyCube release];
  [self->backWallCube release];
  [self->roofCube release];
  [self->roofPoleCube release];
  [self->doorCube release];
  [self->steamSound stop];
  [self->railSound stop];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}
- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isEngine
{
  return NO;
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

- (void)railOrStationNameChanged
{
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

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
  return Vector();
}

- (NSString*)secondOptionTitle
{
  return nil;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)setWorkbenchChoiceUIOption:(int)option
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateHasFuel
{
}

- (void)updateSearchForStations
{
}

@end
