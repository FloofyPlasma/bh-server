#import "TradePortal.h"

@implementation TradePortal

- (NSString*)actionTitle
{
  return nil;
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (void)buyItem:(ItemType)itemType atTotalPrice:(int)listedPrice count:(int)count
{
}

- (BOOL)canBeUsedInExpertModeWhenNotOwned
{
  return NO;
}

- (int)currentBlockheadCash
{
  return 0;
}

- (int)currentBlockheadCountOfInventoryItemsOfType:(ItemType)type
{
  return 0;
}

- (float)currentBlockheadUsageMultiplierForFirstItemOfType:(ItemType)type
{
  return 0;
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

- (int)freeblockCreationItemType
{
  return 0;
}

- (Vector)getLightRGB
{
  return Vector();
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (TradePortal*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (TradePortal*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (TradePortal*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (uint16_t)interactionObjectType
{
  return 0;
}

- (int)interactionRenderItemType
{
  return 0;
}

- (BOOL)isDoubleHeight
{
  return NO;
}

- (int)lightGlowQuadCount
{
  return 0;
}

- (Vector)lightPos
{
  return Vector();
}

- (void)loadPriceOffsets:(NSDictionary*)savedOffsets
{
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesNormalContents
{
  return NO;
}

- (void)randomizeLocalTradeOffsets
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

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (NSString*)secondOptionTitle
{
  return nil;
}

- (void)sellItem:(ItemType)itemType atTotalPrice:(int)arg2 count:(int)count usageMultiplier:(float)usageMultiplier
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setWorkbenchChoiceUIOption:(int)option
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

- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel
{
  return NO;
}

- (NSString*)thirdOptionTitle
{
  return nil;
}

- (NSString*)title
{
  return nil;
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updatePortalLight
{
}

- (CraftableItem)upgradeCraftableItem
{
  return CraftableItem();
}

- (void)upgradeToNextLevel
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end