#import "ElevatorMotor.h"

@implementation ElevatorMotor

- (BOOL)isStorageDevice
{
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
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

- (uint16_t)freeBlockCreationDataA
{
}

- (uint16_t)freeBlockCreationDataB
{
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
}

- (ItemType)freeblockCreationItemType
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (BOOL)hasRequiredPower
{
}

- (void)initSubDerivedItems
{
}

- (ElevatorMotor*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (ElevatorMotor*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (ElevatorMotor*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesNormalContents
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (int)staticGeometryDrawCubeCount
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)usePower
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end