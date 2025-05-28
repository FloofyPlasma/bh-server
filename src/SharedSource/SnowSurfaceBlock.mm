#import "SnowSurfaceBlock.h"

@implementation SnowSurfaceBlock

- (void)dealloc {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (SnowSurfaceBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ {
}

- (SnowSurfaceBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (void)removeAllSnow {
}

- (void)removeFromMacroBlock {
}

- (BOOL)removeIfFloating {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)spreadGrass:(Tile *)belowTile tile:(Tile *)tile {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateGroundFrozen:(Tile *)belowTile tile:(Tile *)tile {
}

- (void)updateInTimeSinceSaved {
}

- (void)updateRain:(float)rainFraction dt:(float)dt {
}

- (void)updateSnowContent:(BOOL)forceUpdate tile:(Tile *)tile {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end