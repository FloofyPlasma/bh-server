#import <Foundation/Foundation.h>

#import "CraftableItem.h"
#import "InteractionObject.h"

struct TradePortalNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint8_t level;
  uint8_t padding[7];
};

@class ArtificialLight, MJSound;

/**
 * @class TradePortal
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @property isSellInteraction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL isSellInteraction; // @synthesize isSellInteraction;
/**
 * @property level
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int level; // @synthesize level;
@property (readonly)
    NSDictionary* localPriceOffsets; // @synthesize localPriceOffsets;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)randomizeLocalTradeOffsets;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lightGlowQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CraftableItem)upgradeCraftableItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)buyItem:(ItemType)itemType atTotalPrice:(int)listedPrice count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sellItem:(ItemType)itemType
       atTotalPrice:(int)arg2
              count:(int)count
    usageMultiplier:(float)usageMultiplier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)upgradeToNextLevel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)currentBlockheadUsageMultiplierForFirstItemOfType:(ItemType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentBlockheadCountOfInventoryItemsOfType:(ItemType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentBlockheadCash;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorkbenchChoiceUIOption:(int)option;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)thirdOptionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)secondOptionTitle;
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
- (int)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
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
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradePortal*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                        cache:(CPCache*)cache_
                      netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradePortal*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TradePortal*)initWithWorld:(World*)world_
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
- (void)loadPriceOffsets:(NSDictionary*)savedOffsets;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePortalLight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getLightRGB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
