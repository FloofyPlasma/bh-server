#import "Door.h"

@implementation Door

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (void)checkAndUpdateBlockedStatus
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->ironPlaceClientID release];
  [self->ownerID release];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (uint16_t)freeBlockCreationDataA
{
  return 0;
}

- (uint16_t)freeBlockCreationDataB
{
  return 0;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Door*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isOpen
{
  return NO;
}

- (ItemType)itemType
{
  return ITEM_FLAX_MAT;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesBackgroundContents
{
  return NO;
}

- (BOOL)occupiesNormalContents
{
  return NO;
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
  return 0;
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end