#import "TradingPost.h"

@implementation TradingPost

- (NSString*)actionTitle
{
}

- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index
{
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
}

- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
}

- (BOOL)blockheadIsSeller:(Blockhead*)blockhead
{
}

- (void)buyButtonTappedWithQuantity:(int)quantity
{
}

- (void)contentsDidChange
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (int)currentBlockheadCash
{
}

- (void)dealloc
{
}

- (ItemType)destroyItemType
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

- (void)initSlotsWithSaveDict:(NSDictionary*)saveDict
{
}

- (void)initSubDerivedItems
{
}

- (TradingPost*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
}

- (TradingPost*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (TradingPost*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (uint16_t)interactionObjectType
{
}

- (ItemType)interactionRenderItemType
{
}

- (BOOL)isPaintable
{
}

- (int)moveInventoryItemsToSellSlotFromArray:(NSMutableArray*)fromItemSlot count:(int)count
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesNormalContents
{
}

- (void)paint:(uint16_t)colorIndex
{
}

- (int)price
{
}

- (int)priceTier
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
}

- (NSString*)sellTitle
{
}

- (void)setPriceTier:(int)priceTier_
{
}

- (int)staticGeometryDodoEggCount
{
}

- (int)staticGeometryDrawCubeCount
{
}

- (int)staticGeometryDrawItemQuadCount
{
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
}

- (NSString*)title
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateBitmapString
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
}

@end