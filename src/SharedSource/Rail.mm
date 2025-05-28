#import "Rail.h"

@implementation Rail

- (int)addDrawCubeData:(float *)buffer fromIndex:(int)index {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (RailConfiguration)currentConfiguration {
}

- (void)dealloc {
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

- (id)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache *)cache_ type:(ItemType)itemType_ ownedByStation:(BOOL)ownedByStation_ {
}

- (Rail *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Rail *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesForegroundContents {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeFromMacroBlock {
}

- (int)staticGeometryDrawCubeCount {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updateRailConfiguration {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end