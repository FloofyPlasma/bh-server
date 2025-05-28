#import "Column.h"

@implementation Column

- (int)addCylinderData:(float *)buffer fromIndex:(int)index {
}

- (int)addCylinderDataLocal:(float *)buffer fromIndex:(int)index {
}

- (int)addCylinderDataTrans:(float *)buffer fromIndex:(int)index {
}

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

- (int)freeblockCreationItemType {
}

- (NSMutableDictionary *)getSaveDict {
}

- (int)imageIndex {
}

- (void)initSubDerivedItems {
}

- (Column *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (Column *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Column *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (BOOL)isTransparent {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesForegroundContents {
}

- (void)paint:(uint16_t)colorIndex {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeFromMacroBlock {
}

- (int)staticGeometryCylinderCount {
}

- (int)staticGeometryCylinderCountTrans {
}

- (int)staticGeometryDrawCubeCount {
}

- (int)staticGeometryDrawCubeCountLocal {
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