#import "DropBear.h"

@implementation DropBear

- (void)blockheadUnloaded:(Blockhead *)blockhead {
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead *)blockhead withItemType:(ItemType)itemType {
}

- (NSString *)cantBeCapturedTipStringForBlockhead:(Blockhead *)blockhead withItemType:(ItemType)itemType {
}

- (ItemType)captureRequiredItemType {
}

- (ItemType)capturedItemType {
}

- (uint64_t)creationDataStructSize {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)doRemoteUpdate:(DropBearUpdateNetData)updateNetData {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (DropBearUpdateNetData)dropBearUpdateNetDataForClient:(NSString *)clientIDToSendTo {
}

- (ItemType)foodItemType {
}

- (NSString **)getNamesArray {
}

- (int)getNamesArrayCount {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)hitWithForce:(int)force blockhead:(Blockhead *)blockhead {
}

- (DropBear *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString *)clientId {
}

- (DropBear *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (DropBear *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (void)loadDerivedStuff {
}

- (float)maxAge {
}

- (uint16_t)maxHealth {
}

- (NPCType)npcType {
}

- (void)reactToBeingFed {
}

- (void)reactToBeingHit {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (Vector2)renderPos {
}

- (BOOL)ridableWhenTamed {
}

- (NSString *)speciesName {
}

- (void)successfulTame {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end