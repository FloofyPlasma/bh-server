#import "Bed.h"

@implementation Bed

- (NSString *)actionTitle {
}

- (BOOL)isPaintable {
}

- (BOOL)occupiesNormalContents {
}

- (BOOL)twoBlocksWide {
}

- (Bed *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId clientName:(NSString *)clientName {
}

- (Bed *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Bed *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (ItemType)freeblockCreationItemType {
}

- (ItemType)interactionRenderItemType {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (NSMutableDictionary *)freeBlockCreationSaveDict {
}

- (NSMutableDictionary *)getSaveDict {
}

- (NSString *)title {
}

- (int)destroyItemType {
}

- (uint16_t)freeBlockCreationDataA {
}

- (uint16_t)freeBlockCreationDataB {
}

- (uint16_t)interactionObjectType {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)initSubDerivedItems {
}

- (void)paint:(uint16_t)colorIndex {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)remove:(Blockhead *)removeBlockhead {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end