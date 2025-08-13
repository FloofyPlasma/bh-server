#import "Mirror.h"

@implementation Mirror

- (NSString*)actionTitle
{
  return nil;
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [super dealloc];
}

- (ItemType)destroyItemType
{
  return ITEM_FLAX_MAT;
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

- (Mirror*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (Mirror*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Mirror*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (uint16_t)interactionObjectType
{
  return 0;
}

- (ItemType)interactionRenderItemType
{
  return ITEM_FLAX_MAT;
}

- (BOOL)isDoubleHeight
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

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (void)removeFromMacroBlock
{
}

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (NSString*)title
{
  return nil;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end