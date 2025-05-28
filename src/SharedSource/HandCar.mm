#import "HandCar.h"

@implementation HandCar

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)connectsToOtherCars
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (HandCar*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (int)itemType
{
}

- (void)loadDerivedStuff
{
}

- (int)maxNumberOfRiders
{
}

- (DynamicObjectType)objectType
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
}

- (BOOL)requiresFuel
{
}

- (float)riderAnimationTimer
{
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
}

- (void)setTargetVelocity:(Vector2)targetVelocity
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end