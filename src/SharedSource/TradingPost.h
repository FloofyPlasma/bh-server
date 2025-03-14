

#import "InteractionObject.h"

@class BitmapString, NSMutableArray, NSString, Shader;

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
- (void)paint:(unsigned short)arg1;
- (int)interactionRenderItemType;
- (void)removeFromMacroBlock;
- (int)addDodoEggDrawQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDodoEggCount;
- (int)addDrawItemQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawItemQuadCount;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCount;
- (id)sellTitle;
- (void)buyButtonTappedWithQuantity:(int)arg1;
- (int)currentBlockheadCash;
- (void)setPriceTier:(int)arg1;
- (int)priceTier;
- (int)price;
- (BOOL)blockheadIsSeller:(id)arg1;
- (BOOL)requiresHumanInteraction;
- (id)actionTitle;
- (id)title;
- (int)destroyItemType;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)updateBitmapString;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)contentsDidChange;
- (int)moveInventoryItemsToSellSlotFromArray:(id)arg1 count:(int)arg2;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (unsigned short)interactionObjectType;
- (id)getSaveDict;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
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
- (void)initSlotsWithSaveDict:(id)arg1;
- (int)objectType;

@end
