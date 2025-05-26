#import <Foundation/Foundation.h>

#import "InteractionObject.h"

struct TradingPostNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint32_t cointCount;
  uint16_t priceTier;
  uint8_t padding[2];
};

@class BitmapString, Shader;

@interface TradingPost : InteractionObject {
  NSMutableArray* sellSlot;
  int coinCount;
  int priceTier;
  NSString* sellerClientName;
  Shader* usageShader;
  BitmapString* bitmapString;
  BOOL needsToUpdateBitmapString;
  BOOL inventoryNeedsToBeSentWithUpdate;
  BOOL blackText;
}

@property int coinCount; // @synthesize coinCount;
@property (readonly) NSMutableArray* sellSlot; // @synthesize sellSlot;
- (BOOL)occupiesNormalContents;
- (BOOL)isPaintable;
- (void)paint:(uint16_t)colorIndex;
- (ItemType)interactionRenderItemType;
- (void)removeFromMacroBlock;
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDodoEggCount;
- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawItemQuadCount;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (NSString*)sellTitle;
- (void)buyButtonTappedWithQuantity:(int)quantity;
- (int)currentBlockheadCash;
- (void)setPriceTier:(int)priceTier_;
- (int)priceTier;
- (int)price;
- (BOOL)blockheadIsSeller:(Blockhead*)blockhead;
- (BOOL)requiresHumanInteraction;
- (NSString*)actionTitle;
- (NSString*)title;
- (ItemType)destroyItemType;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)updateBitmapString;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)contentsDidChange;
- (int)moveInventoryItemsToSellSlotFromArray:(NSMutableArray*)fromItemSlot count:(int)count;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (uint16_t)interactionObjectType;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_;
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                         item:(InventoryItem*)item
                      flipped:(BOOL)flipped_
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientId
                   clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (void)initSlotsWithSaveDict:(NSDictionary*)saveDict;
- (DynamicObjectType)objectType;

@end
