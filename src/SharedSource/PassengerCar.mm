#import "PassengerCar.h"

@implementation PassengerCar

- (NSString *)actionTitle {
}

- (void)addRider:(Blockhead *)blockhead {
}

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (NSMutableDictionary *)getSaveDict {
}

- (PassengerCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId {
}

- (PassengerCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (PassengerCar *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (ItemType)itemType {
}

- (void)loadDerivedStuff {
}

- (int)maxNumberOfRiders {
}

- (DynamicObjectType)objectType {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (Vector2)renderPos {
}

- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead *)blockhead cameraX:(float)cameraX {
}

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead {
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

@end