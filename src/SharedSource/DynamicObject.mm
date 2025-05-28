#import "DynamicObject.h"

@implementation DynamicObject

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY {
}

- (int)addCylinderData:(float *)buffer fromIndex:(int)index {
}

- (int)addCylinderDataTrans:(float *)buffer fromIndex:(int)index {
}

- (int)addDodoEggDrawQuadData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawCubeData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawCubeDataTrans:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawItemQuadData:(float *)buffer fromIndex:(int)index {
}

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (int)addForegroundDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (int)addLightGlowQuadData:(float *)buffer fromIndex:(int)index {
}

- (void)blockheadUnloaded:(Blockhead *)blockhead {
}

- (void)blockheadsLoaded {
}

- (BOOL)canBeRemovedByBlockhead:(Blockhead *)blockhead {
}

- (NSString *)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (DynamicObjectNetData)dynamicObjectNetData {
}

- (uint16_t)freeBlockCreationDataA {
}

- (uint16_t)freeBlockCreationDataB {
}

- (NSMutableDictionary *)freeBlockCreationSaveDict {
}

- (ItemType)freeblockCreationItemType {
}

- (Vector)getLightRGB {
}

- (NSMutableDictionary *)getSaveDict {
}

- (BOOL)initDerivedStuff:(BOOL)wasSaveLoad loadPhysicalBlockIfNeeded:(BOOL)loadPhysicalBlockIfNeeded {
}

- (DynamicObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ {
}

- (DynamicObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (DynamicObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (DynamicObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (BOOL)isDownlight {
}

- (BOOL)isUplight {
}

- (int)lightGlowQuadCount {
}

- (Vector)lightPos {
}

- (BOOL)mayOnlyBeRemovedByOwner {
}

- (BOOL)needsNetDataToBeSent {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesBackgroundContents {
}

- (BOOL)occupiesForegroundContents {
}

- (BOOL)occupiesNormalContents {
}

- (NSString *)ownerID {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeFromMacroBlock {
}

- (Vector2)renderPos {
}

- (BOOL)requiresPhysicalBlock {
}

- (void)setFloatPosAndUpdatePosition:(Vector2)floatPos_ {
}

- (BOOL)shouldAddToMacroBlock {
}

- (BOOL)shouldSaveEveryChangeInPosition {
}

- (int)staticGeometryCylinderCount {
}

- (int)staticGeometryCylinderCountTrans {
}

- (int)staticGeometryDodoEggCount {
}

- (int)staticGeometryDrawCubeCount {
}

- (int)staticGeometryDrawCubeCountTrans {
}

- (int)staticGeometryDrawItemQuadCount {
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePosition:(intpair)newPosition {
}

- (void)waterContentChanged:(std::vector<intpair> *)waterContentChangedPositions {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end