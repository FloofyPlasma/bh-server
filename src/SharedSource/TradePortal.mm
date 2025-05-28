#import "TradePortal.h"

@implementation TradePortal

- (NSString *)actionTitle {
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY {
}

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (void)buyItem:(ItemType)itemType atTotalPrice:(int)listedPrice count:(int)count {
}

- (BOOL)canBeUsedInExpertModeWhenNotOwned {
}

- (int)currentBlockheadCash {
}

- (int)currentBlockheadCountOfInventoryItemsOfType:(ItemType)type {
}

- (float)currentBlockheadUsageMultiplierForFirstItemOfType:(ItemType)type {
}

- (void)dealloc {
}

- (ItemType)destroyItemType {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (uint16_t)freeBlockCreationDataA {
}

- (uint16_t)freeBlockCreationDataB {
}

- (NSMutableDictionary *)freeBlockCreationSaveDict {
}

- (int)freeblockCreationItemType {
}

- (Vector)getLightRGB {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (TradePortal *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache *)cache_ item:(InventoryItem *)item flipped:(BOOL)flipped_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId clientName:(NSString *)clientName {
}

- (TradePortal *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (TradePortal *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (uint16_t)interactionObjectType {
}

- (int)interactionRenderItemType {
}

- (BOOL)isDoubleHeight {
}

- (int)lightGlowQuadCount {
}

- (Vector)lightPos {
}

- (void)loadPriceOffsets:(NSDictionary *)savedOffsets {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesNormalContents {
}

- (void)randomizeLocalTradeOffsets {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)remove:(Blockhead *)removeBlockhead {
}

- (void)removeFromMacroBlock {
}

- (BOOL)requiresHumanInteraction {
}

- (NSString *)secondOptionTitle {
}

- (void)sellItem:(ItemType)itemType atTotalPrice:(int)arg2 count:(int)count usageMultiplier:(float)usageMultiplier {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)setPaused:(BOOL)paused {
}

- (void)setWorkbenchChoiceUIOption:(int)option {
}

- (int)staticGeometryDrawCubeCount {
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (BOOL)takeItemsFromBlockheadForUpgradeToNextLevel {
}

- (NSString *)thirdOptionTitle {
}

- (NSString *)title {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePortalLight {
}

- (CraftableItem)upgradeCraftableItem {
}

- (void)upgradeToNextLevel {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end