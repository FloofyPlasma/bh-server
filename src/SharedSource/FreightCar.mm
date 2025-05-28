#import "FreightCar.h"

@implementation FreightCar

- (void)childNeedsSaving:(DynamicObject *)child {
}

- (NSString *)actionTitle {
}

- (InteractionObject *)actsAsInteractionObject {
}

- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType {
}

- (void)blockheadsLoaded {
}

- (Vector2)cameraPos {
}

- (void)childNeedsSaving:(DynamicObject *)child {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (NSMutableDictionary *)freeBlockCreationSaveDict {
}

- (NSDictionary *)getChestSaveDict {
}

- (NSMutableDictionary *)getSaveDict {
}

- (FreightCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (FreightCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (FreightCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict chestSaveDict:(NSDictionary *)chestSaveDict cache:(CPCache *)cache_ {
}

- (ItemType)itemType {
}

- (void)loadDerivedStuff {
}

- (DynamicObjectType)objectType {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (Vector2)renderPos {
}

- (BOOL)requiresHumanInteraction {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
}

- (void)setUpdateNeedsToBeSent:(BOOL)updateNeedsToBeSent {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (BOOL)updateNeedsToBeSent {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePosition:(intpair)newPosition {
}

@end