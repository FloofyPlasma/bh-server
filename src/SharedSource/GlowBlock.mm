#import "GlowBlock.h"

@implementation GlowBlock

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY {
}

- (void)dealloc {
}

- (Vector)getLightRGB {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (GlowBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (GlowBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ tile:(Tile *)tile_ {
}

- (int)lightGlowQuadCount {
}

- (Vector)lightPos {
}

- (DynamicObjectType)objectType {
}

- (void)removeFromMacroBlock {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end