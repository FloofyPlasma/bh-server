#import "Chest.h"

@implementation Chest

- (NSString*)actionTitle
{
  return nil;
}

- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index
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

- (ChestType)chestType
{
  return CHEST_GOLD;
}

- (void)contentsDidChange
{
}

- (void)dealloc
{
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

- (NSMutableDictionary*)getSaveDictIncludingInventory:(BOOL)includeInventory
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (Chest*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (Chest*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Chest*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
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

- (NSData*)inventoryDataAllowingEmpty:(BOOL)allowEmptyInventory
{
  return nil;
}

- (NSArray*)inventoryItems
{
  return nil;
}

- (BOOL)isPaintable
{
  return NO;
}

- (void)loadInventoryItemsFromDiskIfNeeded
{
}

- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot toIndex:(int)toIndex count:(int)count
{
  return 0;
}

- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot toIndex:(int)toIndex count:(int)count assignedIndexes:(std::set<int>*)assignedIndexes
{
  return 0;
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

- (void)remoteInventoryDataRecieved:(NSData*)remoteInventoryData
{
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

- (BOOL)removeItemIfAvailable:(ItemType)itemType
{
  return NO;
}

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (void)setNeedsRemoved:(BOOL)newNeedsRemoved
{
}

- (void)startInteractionWithBlockhead:(Blockhead*)blockhead
{
}

- (int)staticGeometryDodoEggCount
{
  return 0;
}

- (int)staticGeometryDrawCubeCount
{
  return 0;
}

- (int)staticGeometryDrawItemQuadCount
{
  return 0;
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

- (void)updateInventoryWithData:(NSData*)inventoryData
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updatePosition:(intpair)newPosition
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end