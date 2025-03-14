#import <Foundation/Foundation.h>

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
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (BOOL)occupiesNormalContents;
- (int)interactionRenderItemType;
- (void)randomizeLocalTradeOffsets;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel;
- (struct CraftableItem)upgradeCraftableItem;
- (void)buyItem:(int)arg1 atTotalPrice:(int)arg2 count:(int)arg3;
- (void)sellItem:(int)arg1
       atTotalPrice:(int)arg2
              count:(int)arg3
    usageMultiplier:(float)arg4;
- (void)upgradeToNextLevel;
- (void)removeFromMacroBlock;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawCubeCount;
- (void)setPaused:(BOOL)arg1;
- (float)currentBlockheadUsageMultiplierForFirstItemOfType:(int)arg1;
- (int)currentBlockheadCountOfInventoryItemsOfType:(int)arg1;
- (int)currentBlockheadCash;
- (BOOL)requiresHumanInteraction;
- (void)setWorkbenchChoiceUIOption:(int)arg1;
- (id)thirdOptionTitle;
- (id)secondOptionTitle;
- (id)actionTitle;
- (id)title;
- (int)destroyItemType;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)isDoubleHeight;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (unsigned short)interactionObjectType;
- (id)getSaveDict;
- (void)dealloc;
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
- (void)loadPriceOffsets:(id)arg1;
- (void)updatePortalLight;
- (Vector)getLightRGB;
- (int)objectType;
- (void)initSubDerivedItems;

@end
