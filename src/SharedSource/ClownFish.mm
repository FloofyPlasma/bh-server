#import "ClownFish.h"

@implementation ClownFish

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

- (ClownFishUpdateNetData)clownFishUpdateNetDataForClient:(NSString *)clientIDToSendTo {
}

- (uint64_t)creationDataStructSize {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)die:(Blockhead *)killBlockhead_ {
}

- (void)doRemoteUpdate:(ClownFishUpdateNetData)updateNetData {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
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

- (ClownFish *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString *)clientId {
}

- (ClownFish *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (ClownFish *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
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

- (void)remoteBlockheadHookedYou:(Blockhead *)blockhead {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (Vector2)renderPos {
}

- (BOOL)ridableWhenTamed {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (NSString *)speciesName {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

@end