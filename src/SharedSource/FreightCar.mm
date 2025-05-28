#import "FreightCar.h"

@implementation FreightCar

- (void)childNeedsSaving:(DynamicObject*)child
{
}

- (NSString*)actionTitle
{
  return nil;
}

- (InteractionObject*)actsAsInteractionObject
{
  return nil;
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType
{
  return NO;
}

- (void)blockheadsLoaded
{
}

- (Vector2)cameraPos
{
  return Vector2();
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (NSDictionary*)getChestSaveDict
{
  return nil;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (FreightCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (FreightCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (FreightCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict chestSaveDict:(NSDictionary*)chestSaveDict cache:(CPCache*)cache_
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

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)setUpdateNeedsToBeSent:(BOOL)updateNeedsToBeSent
{
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (BOOL)updateNeedsToBeSent
{
  return NO;
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updatePosition:(intpair)newPosition
{
}

@end