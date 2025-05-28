#import "Chest.h"

@implementation Chest

- (NSString *)actionTitle {
}

- (int)addDodoEggDrawQuadData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawCubeData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawItemQuadData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (BOOL)canBeUsedByBlockhead:(Blockhead *)blockhead {
}

- (ChestType)chestType {
}

- (void)contentsDidChange {
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

- (ItemType)freeblockCreationItemType {
}

- (NSMutableDictionary *)getSaveDict {
}

- (NSMutableDictionary *)getSaveDictIncludingInventory:(BOOL)includeInventory {
}

- (void)initSubDerivedItems {
}

- (Chest *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId clientName:(NSString *)clientName {
}

- (Chest *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Chest *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (uint16_t)interactionObjectType {
}

- (ItemType)interactionRenderItemType {
}

- (NSData *)inventoryDataAllowingEmpty:(BOOL)allowEmptyInventory {
}

- (NSArray *)inventoryItems {
}

- (BOOL)isPaintable {
}

- (void)loadInventoryItemsFromDiskIfNeeded {
}

- (int)moveInventoryItemsFromArray:(NSMutableArray *)fromItemSlot toIndex:(int)toIndex count:(int)count {
}

- (int)moveInventoryItemsFromArray:(NSMutableArray *)fromItemSlot toIndex:(int)toIndex count:(int)count assignedIndexes:(std::set<int> *)assignedIndexes {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesNormalContents {
}

- (void)paint:(uint16_t)colorIndex {
}

- (void)remoteInventoryDataRecieved:(NSData *)remoteInventoryData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)remove:(Blockhead *)removeBlockhead {
}

- (void)removeFromMacroBlock {
}

- (BOOL)removeItemIfAvailable:(ItemType)itemType {
}

- (BOOL)requiresHumanInteraction {
}

- (void)setNeedsRemoved:(BOOL)newNeedsRemoved {
}

- (void)startInteractionWithBlockhead:(Blockhead *)blockhead {
}

- (int)staticGeometryDodoEggCount {
}

- (int)staticGeometryDrawCubeCount {
}

- (int)staticGeometryDrawItemQuadCount {
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (NSString *)title {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateInventoryWithData:(NSData *)inventoryData {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePosition:(intpair)newPosition {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end