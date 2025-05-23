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
  unsigned short shelfItemDataBs[4];
}

@property (readonly) BOOL inventoryChanged; // @synthesize inventoryChanged;
- (BOOL)removeItemIfAvailable:(int)arg1;
- (BOOL)occupiesNormalContents;
- (id)inventoryItems;
- (void)loadInventoryItemsFromDiskIfNeeded;
- (BOOL)isPaintable;
- (void)paint:(unsigned short)arg1;
- (int)interactionRenderItemType;
- (int)addDodoEggDrawQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDodoEggCount;
- (int)addDrawItemQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawItemQuadCount;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (void)startInteractionWithBlockhead:(id)arg1;
- (int)staticGeometryDrawCubeCount;
- (void)removeFromMacroBlock;
- (void)updatePosition:(intpair)arg1;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (int)chestType;
- (BOOL)requiresHumanInteraction;
- (id)actionTitle;
- (id)title;
- (int)destroyItemType;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)contentsDidChange;
- (int)moveInventoryItemsFromArray:(id)arg1 toIndex:(int)arg2 count:(int)arg3;
- (int)moveInventoryItemsFromArray:(id)arg1
                           toIndex:(int)arg2
                             count:(int)arg3
                   assignedIndexes:(std::set<int>*)arg4;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (unsigned short)interactionObjectType;
- (id)getSaveDictIncludingInventory:(BOOL)arg1;
- (id)getSaveDict;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (void)remoteInventoryDataRecieved:(id)arg1;
- (void)updateInventoryWithData:(id)arg1;
- (id)inventoryDataAllowingEmpty:(BOOL)arg1;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               item:(id)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (void)initSubDerivedItems;
- (int)objectType;

@end
