#import "SteamTrain.h"

@implementation SteamTrain

- (void)addToFuelForItem:(ItemType)itemType
{
}

- (BOOL)canDismissFuelUI
{
}

- (int)fuelCount
{
}

- (int)fuelItemCount
{
}

- (int*)fuelItems
{
}

- (Vector2)fuelUIPos
{
}

- (NSString*)title
{
}

- (NSString*)actionTitle
{
}

- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead
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

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (SteamTrain*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)isEngine
{
}

- (ItemType)itemType
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
}

- (BOOL)requiresFuel
{
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead cameraX:(float)cameraX
{
}

- (Vector)riderPosForBlockhead:(Blockhead*)blockhead
{
}

- (NSString*)secondOptionTitle
{
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