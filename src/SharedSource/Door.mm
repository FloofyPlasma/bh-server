#import "Door.h"

@implementation Door

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
}

- (void)checkAndUpdateBlockedStatus
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

- (void)initSubDerivedItems
{
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (BOOL)isOpen
{
}

- (ItemType)itemType
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesBackgroundContents
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

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setOpen:(BOOL)open_ direction:(int)direction
{
}

- (int)staticGeometryDrawCubeCount
{
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end