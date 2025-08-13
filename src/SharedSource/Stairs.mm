#import "Stairs.h"

@implementation Stairs

@synthesize itemType;

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawCubeDataLocal:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
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

- (int)imageIndex
{
  return 0;
}

- (void)initSubDerivedItems
{
}

- (Stairs*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return nil;
}

- (Stairs*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Stairs*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isTransparent
{
  return NO;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesNormalContents
{
  return NO;
}

- (void)paint:(uint16_t)colorIndex
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
  return 0;
}

- (int)staticGeometryDrawCubeCountTrans
{
  return 0;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateConfiguration
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end