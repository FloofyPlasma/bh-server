#import "Mirror.h"

@implementation Mirror

- (NSString *)actionTitle {
}

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
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

- (void)initSubDerivedItems {
}

- (Mirror *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ item:(InventoryItem *)item flipped:(BOOL)flipped_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId clientName:(NSString *)clientName {
}

- (Mirror *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Mirror *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (uint16_t)interactionObjectType {
}

- (ItemType)interactionRenderItemType {
}

- (BOOL)isDoubleHeight {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesNormalContents {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)remove:(Blockhead *)removeBlockhead {
}

- (void)removeFromMacroBlock {
}

- (BOOL)requiresHumanInteraction {
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (NSString *)title {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end