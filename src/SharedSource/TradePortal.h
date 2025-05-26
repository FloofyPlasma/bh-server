#import <Foundation/Foundation.h>

#import "CraftableItem.h"
#import "InteractionObject.h"

struct TradePortalNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint8_t level;
  uint8_t padding[7];
};

@class ArtificialLight, MJSound;

@interface TradePortal : InteractionObject {
  ArtificialLight* light;
  float animationLoopTimer;
  int animationLoopIndex;
  MJSound* sound;
  BOOL paused;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  NSMutableDictionary* localPriceOffsets;
  int level;
  BOOL isSellInteraction;
  BOOL isMissionInteraction;
}

@property (readonly)
    BOOL isMissionInteraction; // @synthesize isMissionInteraction;
@property (readonly) BOOL isSellInteraction; // @synthesize isSellInteraction;
@property (readonly) int level; // @synthesize level;
@property (readonly)
    NSDictionary* localPriceOffsets; // @synthesize localPriceOffsets;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (BOOL)occupiesNormalContents;
- (int)interactionRenderItemType;
- (void)randomizeLocalTradeOffsets;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel;
- (CraftableItem)upgradeCraftableItem;
- (void)buyItem:(ItemType)itemType atTotalPrice:(int)listedPrice count:(int)count;
- (void)sellItem:(ItemType)itemType
       atTotalPrice:(int)arg2
              count:(int)count
    usageMultiplier:(float)usageMultiplier;
- (void)upgradeToNextLevel;
- (void)removeFromMacroBlock;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawCubeCount;
- (void)setPaused:(BOOL)paused;
- (float)currentBlockheadUsageMultiplierForFirstItemOfType:(ItemType)type;
- (int)currentBlockheadCountOfInventoryItemsOfType:(ItemType)type;
- (int)currentBlockheadCash;
- (BOOL)requiresHumanInteraction;
- (void)setWorkbenchChoiceUIOption:(int)option;
- (NSString*)thirdOptionTitle;
- (NSString*)secondOptionTitle;
- (NSString*)actionTitle;
- (NSString*)title;
- (ItemType)destroyItemType;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)isDoubleHeight;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
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
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (TradePortal*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
- (TradePortal*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_;
- (TradePortal*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
                         item:(InventoryItem*)item
                      flipped:(BOOL)flipped_
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientId
                   clientName:(NSString*)clientName;
- (void)loadPriceOffsets:(NSDictionary*)savedOffsets;
- (void)updatePortalLight;
- (Vector)getLightRGB;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
