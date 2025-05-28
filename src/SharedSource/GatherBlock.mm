#import "GatherBlock.h"

@implementation GatherBlock

- (NSMutableDictionary *)getSaveDict {
}

- (GatherBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end