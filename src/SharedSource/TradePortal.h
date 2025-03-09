//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "InteractionObject.h"

@class ArtificialLight, MJSound, NSDictionary, NSMutableDictionary;

@interface TradePortal : InteractionObject
{
    ArtificialLight *light;
    float animationLoopTimer;
    int animationLoopIndex;
    MJSound *sound;
    BOOL paused;
    float *savedDrawBuffer;
    int savedDrawBufferIndex;
    NSMutableDictionary *localPriceOffsets;
    int level;
    BOOL isSellInteraction;
    BOOL isMissionInteraction;
}

@property(readonly) BOOL isMissionInteraction; // @synthesize isMissionInteraction;
@property(readonly) BOOL isSellInteraction; // @synthesize isSellInteraction;
@property(readonly) int level; // @synthesize level;
@property(readonly) NSDictionary *localPriceOffsets; // @synthesize localPriceOffsets;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1 yPos:(int)arg2;
- (BOOL)occupiesNormalContents;
- (int)interactionRenderItemType;
- (void)randomizeLocalTradeOffsets;
- (struct Vector)lightPos;
- (int)lightGlowQuadCount;
- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel;
- (struct CraftableItem)upgradeCraftableItem;
- (void)buyItem:(int)arg1 atTotalPrice:(int)arg2 count:(int)arg3;
- (void)sellItem:(int)arg1 atTotalPrice:(int)arg2 count:(int)arg3 usageMultiplier:(float)arg4;
- (void)upgradeToNextLevel;
- (void)removeFromMacroBlock;
- (int)staticGeometryDrawQuadCountForMacroPos:(CDStruct_ffe6b7c1)arg1;
- (int)addDrawQuadData:(float *)arg1 fromIndex:(int)arg2 forMacroPos:(CDStruct_ffe6b7c1)arg3;
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
- (void)worldContentsChanged:(vector_07678c45 *)arg1;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (void)draw:(float)arg1 projectionMatrix:(union _GLKMatrix4)arg2 modelViewMatrix:(union _GLKMatrix4)arg3 cameraMinXWorld:(int)arg4 cameraMaxXWorld:(int)arg5 cameraMinYWorld:(int)arg6 cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (unsigned short)interactionObjectType;
- (id)getSaveDict;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 cache:(id)arg3 netData:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(CDStruct_ffe6b7c1)arg3 cache:(id)arg4 item:(id)arg5 flipped:(BOOL)arg6 saveDict:(id)arg7 placedByClient:(id)arg8 clientName:(id)arg9;
- (void)loadPriceOffsets:(id)arg1;
- (void)updatePortalLight;
- (struct Vector)getLightRGB;
- (int)objectType;
- (void)initSubDerivedItems;

@end

