#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <set>

#import "InteractionObject.h"

enum ChestType {
  CHEST_STANDARD = 0x0,
  CHEST_SAFE = 0x1,
  CHEST_SHELF = 0x2,
  CHEST_GOLD = 0x3,
  CHEST_PORTAL = 0x4,
  CHEST_DISPLAY_CABINET = 0x5,
  CHEST_FEEDER = 0x6,
};

struct ChestNetData {
  InteractionObjectCreationNetData interactionobjectCreationNetData;
  uint16_t renderItems[4];
  uint16_t renderItemDatabs[4];
  uint8_t chestType;
  uint8_t padding[7];
};

/**
 * @class Chest
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Chest : InteractionObject {
  NSMutableArray* inventoryItems;
  BOOL inventoryChanged;
  int chestType;
  BOOL inventoryNeedsToBeSentWithUpdate;
  int shelfRenderItems[4];
  uint16_t shelfItemDataBs[4];
}

/**
 * @property inventoryChanged
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL inventoryChanged; // @synthesize inventoryChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)removeItemIfAvailable:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)inventoryItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadInventoryItemsFromDiskIfNeeded;
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
- (void)startInteractionWithBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ChestType)chestType;
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
- (void)setNeedsRemoved:(BOOL)newNeedsRemoved;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)contentsDidChange;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot toIndex:(int)toIndex count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot
                           toIndex:(int)toIndex
                             count:(int)count
                   assignedIndexes:(std::set<int>*)assignedIndexes;
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
- (InteractionObjectType)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDictIncludingInventory:(BOOL)includeInventory;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteInventoryDataRecieved:(NSData*)remoteInventoryData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateInventoryWithData:(NSData*)inventoryData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)inventoryDataAllowingEmpty:(BOOL)allowEmptyInventory;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
               saveDict:(NSDictionary*)saveDict
                  cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
             atPosition:(intpair)pos
                  cache:(CPCache*)cache_
                   type:(ItemType)itemType_
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
- (DynamicObjectType)objectType;

@end
