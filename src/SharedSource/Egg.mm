#import "Egg.h"

@implementation Egg

- (int)addDodoEggDrawQuadData:(float *)buffer fromIndex:(int)index {
}

- (uint16_t)breed {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (void)dealloc {
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

- (BOOL)hatch:(BOOL)playSound {
}

- (void)initSubDerivedItems {
}

- (Egg *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict {
}

- (Egg *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Egg *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesForegroundContents {
}

- (void)removeFromMacroBlock {
}

- (int)staticGeometryDodoEggCount {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end