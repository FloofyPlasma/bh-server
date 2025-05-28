#import "WorldHelper.h"

@implementation WorldHelper

+ (BOOL)checkIfMacroTileCanBeDecommissioned:(MacroTile *)macroTile world:(World *)world minAge:(NSTimeInterval)minAge blockToSavePhyscialBlock:(BOOL)blockToSavePhyscialBlock {
}

+ (BOOL)clientMacroTileRequestCanBeCancelledAtMacroPos:(intpair)macroPos world:(World *)world {
}

+ (void)recalculateLightingForPhysicalBlockIfNeeded:(PhysicalBlock *)physicalBlock world:(World *)world clientLightBlockIndex:(int)clientLightBlockIndex forBlockhead:(Blockhead *)blockhead {
}

+ (void)recursivelyRemoveAllSunLightWithList:(NSMutableArray *)openList openIndices:(NSMutableIndexSet *)openIndices lightWasRemovedList:(NSMutableArray *)lightWasRemovedList removeIndices:(NSMutableIndexSet *)removeIndices world:(World *)world minx:(int)minX maxX:(int)maxX {
}

+ (void)recursivelyUpdateSunLightWithList:(NSMutableArray *)openList openIndices:(NSMutableIndexSet *)openIndices world:(World *)world {
}

+ (void)updateSunLightForTile:(Tile *)tile atPos:(intpair)pos world:(World *)world {
}

+ (void)updateSunLightRemovedForTile:(Tile *)tile atPos:(intpair)pos world:(World *)world {
}

@end