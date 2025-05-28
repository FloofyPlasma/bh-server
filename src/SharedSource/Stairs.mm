#import "Stairs.h"

@implementation Stairs

- (int)addDrawCubeData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawCubeDataLocal:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawCubeDataTrans:(float *)buffer fromIndex:(int)index {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
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

- (int)imageIndex {
}

- (void)initSubDerivedItems {
}

- (Stairs *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (Stairs *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Stairs *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (BOOL)isTransparent {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesNormalContents {
}

- (void)paint:(uint16_t)colorIndex {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeFromMacroBlock {
}

- (int)staticGeometryDrawCubeCount {
}

- (int)staticGeometryDrawCubeCountTrans {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateConfiguration {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end