#import "SurfaceBlock.h"

@implementation SurfaceBlock

- (SurfaceBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ {
}

- (SurfaceBlock *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (DynamicObjectType)objectType {
}

- (void)removeFromMacroBlock {
}

- (void)removeIfFloatingAndEmptyOfWater {
}

- (BOOL)requiresPhysicalBlock {
}

- (void)subtractWater:(int)amount fromOtherTile:(Tile *)otherTile atPos:(intpair)otherPos {
}

- (BOOL)takeAnyWaterFromTileAtPos:(intpair)otherPos tile:(Tile *)tile {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

@end