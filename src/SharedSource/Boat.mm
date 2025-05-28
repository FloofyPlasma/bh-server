#import "Boat.h"

@implementation Boat

- (NSString *)actionTitle {
}

- (InteractionObject *)actsAsInteractionObject {
}

- (void)addRider:(Blockhead *)blockhead {
}

- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType {
}

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead {
}

- (BOOL)isDoubleHeight {
}

- (BOOL)jumpsOnSwipe {
}

- (void)removeRider:(Blockhead *)blockhead {
}

- (BOOL)requiresFuel {
}

- (int)rideDirection {
}

- (float)riderBodyYRotationForBlockhead:(Blockhead *)blockhead {
}

- (BOOL)riderDPadShouldAllowUpDown {
}

- (BOOL)riderDPadShouldGiveDiscreteValues {
}

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead {
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
}

- (void)swipeUpGesture {
}

- (NSString *)actionTitle {
}

- (InteractionObject *)actsAsInteractionObject {
}

- (void)addRider:(Blockhead *)rider_ {
}

- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType {
}

- (void)blockheadUnloaded:(Blockhead *)blockhead {
}

- (void)blockheadsLoaded {
}

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (ItemType)freeblockCreationItemType {
}

- (NSMutableDictionary *)getSaveDict {
}

- (Boat *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (Boat *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Boat *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (BOOL)isDoubleHeight {
}

- (BOOL)jumpsOnSwipe {
}

- (void)loadDerivedStuff {
}

- (uint16_t)maxHealth {
}

- (DynamicObjectType)objectType {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeRider:(Blockhead *)rider_ {
}

- (Vector2)renderPos {
}

- (BOOL)requiresFuel {
}

- (int)rideDirection {
}

- (float)riderBodyYRotationForBlockhead:(Blockhead *)blockhead {
}

- (float)riderBodyZRotation {
}

- (BOOL)riderDPadShouldAllowUpDown {
}

- (BOOL)riderDPadShouldGiveDiscreteValues {
}

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved_ {
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
}

- (void)swipeUpGesture {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePosition:(intpair)newPosition {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end