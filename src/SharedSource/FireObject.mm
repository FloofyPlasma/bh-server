#import "FireObject.h"

@implementation FireObject

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (Vector)getLightRGB {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (FireObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ {
}

- (FireObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (FireObject *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (void)removeFromMacroBlock {
}

- (BOOL)requiresPhysicalBlock {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end