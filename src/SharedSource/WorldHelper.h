

#import <Foundation/Foundation.h>

#import "MJMath.h"

@interface WorldHelper : NSObject {
}

+ (BOOL)clientMacroTileRequestCanBeCancelledAtMacroPos:(intpair)arg1
                                                 world:(id)arg2;
+ (BOOL)checkIfMacroTileCanBeDecommissioned:(struct MacroTile*)arg1
                                      world:(id)arg2
                                     minAge:(double)arg3
                   blockToSavePhyscialBlock:(BOOL)arg4;
+ (void)recalculateLightingForPhysicalBlockIfNeeded:(struct PhysicalBlock*)arg1
                                              world:(id)arg2
                              clientLightBlockIndex:(int)arg3
                                       forBlockhead:(id)arg4;
+ (void)updateSunLightRemovedForTile:(struct Tile*)arg1
                               atPos:(intpair)arg2
                               world:(id)arg3;
+ (void)recursivelyRemoveAllSunLightWithList:(id)arg1
                                 openIndices:(id)arg2
                         lightWasRemovedList:(id)arg3
                               removeIndices:(id)arg4
                                       world:(id)arg5
                                        minx:(int)arg6
                                        maxX:(int)arg7;
+ (void)updateSunLightForTile:(struct Tile*)arg1
                        atPos:(intpair)arg2
                        world:(id)arg3;
+ (void)recursivelyUpdateSunLightWithList:(id)arg1
                              openIndices:(id)arg2
                                    world:(id)arg3;

@end
