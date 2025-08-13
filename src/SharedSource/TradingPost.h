#import <Foundation/Foundation.h>

#import "InteractionObject.h"

struct TradingPostNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint32_t cointCount;
  uint16_t priceTier;
  uint8_t padding[2];
};

@class BitmapString, Shader;

/**
 * @class TradingPost
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @property sellSlot
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSMutableArray* sellSlot; // @synthesize sellSlot;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPaintable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paint:(uint16_t)colorIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDodoEggCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawItemQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)sellTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)buyButtonTappedWithQuantity:(int)quantity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentBlockheadCash;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPriceTier:(int)priceTier_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)priceTier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)price;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadIsSeller:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remove:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateBitmapString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)contentsDidChange;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)moveInventoryItemsToSellSlotFromArray:(NSMutableArray*)fromItemSlot count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradingPost*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                         item:(InventoryItem*)item
                      flipped:(BOOL)flipped_
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientId
                   clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSlotsWithSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
