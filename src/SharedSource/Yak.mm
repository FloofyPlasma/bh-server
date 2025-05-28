#import "Yak.h"

@implementation Yak

- (BOOL)canBeMilkedByBlockhead:(Blockhead *)blockhead {
}

- (BOOL)canBeShavedByBlockhead:(Blockhead *)blockhead {
}

- (ItemType)captureRequiredItemType {
}

- (ItemType)capturedItemType {
}

- (void)createItemDropsForDeath {
}

- (uint64_t)creationDataStructSize {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
}

- (void)doYakRemoteUpdate:(YakUpdateNetData)remoteData {
}

- (void)drawSubClassStuff:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix {
}

- (ItemType)foodItemType {
}

- (PlantType)foodPlantType {
}

- (float)foodToRemoveWhenSpawningNPC {
}

- (NSMutableDictionary *)getSaveDict {
}

- (Yak *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString *)clientId {
}

- (Yak *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (BOOL)jumps {
}

- (BOOL)jumpsOnSwipe {
}

- (void)loadDerivedStuff {
}

- (float)maxAge {
}

- (uint16_t)maxHealth {
}

- (BOOL)milkByBlockhead:(Blockhead *)blockhead {
}

- (float)minFullness {
}

- (NPCType)npcType {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)setAdultCreationStartValues {
}

- (void)setupMatrices:(Vector2)renderPos dt:(float)dt {
}

- (BOOL)shaveByBlockhead:(Blockhead *)blockhead {
}

- (NSString *)speciesName {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updateTextures {
}

- (YakUpdateNetData)yakUpdateNetDataForClient:(NSString *)clientIDToSendTo {
}

@end