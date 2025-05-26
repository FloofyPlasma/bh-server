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

@class NSMutableArray;

@interface Chest : InteractionObject {
  NSMutableArray* inventoryItems;
  BOOL inventoryChanged;
  int chestType;
  BOOL inventoryNeedsToBeSentWithUpdate;
  int shelfRenderItems[4];
  uint16_t shelfItemDataBs[4];
}

@property (readonly) BOOL inventoryChanged; // @synthesize inventoryChanged;
- (BOOL)removeItemIfAvailable:(ItemType)itemType;
- (BOOL)occupiesNormalContents;
- (NSArray*)inventoryItems;
- (void)loadInventoryItemsFromDiskIfNeeded;
- (BOOL)isPaintable;
- (void)paint:(uint16_t)colorIndex;
- (ItemType)interactionRenderItemType;
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDodoEggCount;
- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawItemQuadCount;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (void)startInteractionWithBlockhead:(Blockhead*)blockhead;
- (int)staticGeometryDrawCubeCount;
- (void)removeFromMacroBlock;
- (void)updatePosition:(intpair)newPosition;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (ChestType)chestType;
- (BOOL)requiresHumanInteraction;
- (NSString*)actionTitle;
- (NSString*)title;
- (ItemType)destroyItemType;
- (void)setNeedsRemoved:(BOOL)newNeedsRemoved;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)contentsDidChange;
- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot toIndex:(int)toIndex count:(int)count;
- (int)moveInventoryItemsFromArray:(NSMutableArray*)fromItemSlot
                           toIndex:(int)toIndex
                             count:(int)count
                   assignedIndexes:(std::set<int>*)assignedIndexes;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (uint16_t)interactionObjectType;
- (NSMutableDictionary*)getSaveDictIncludingInventory:(BOOL)includeInventory;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (void)remoteInventoryDataRecieved:(NSData*)remoteInventoryData;
- (void)updateInventoryWithData:(NSData*)inventoryData;
- (NSData*)inventoryDataAllowingEmpty:(BOOL)allowEmptyInventory;
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
               saveDict:(NSDictionary*)saveDict
                  cache:(CPCache*)cache_;
- (Chest*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
             atPosition:(intpair)pos
                  cache:(CPCache*)cache_
                   type:(ItemType)itemType_
               saveDict:(NSDictionary*)saveDict
         placedByClient:(NSString*)clientId
             clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
