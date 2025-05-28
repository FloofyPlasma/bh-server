#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

@interface WorldHelper : NSObject {
}

+ (BOOL)clientMacroTileRequestCanBeCancelledAtMacroPos:(intpair)macroPos
                                                 world:(World*)world;
+ (BOOL)checkIfMacroTileCanBeDecommissioned:(MacroTile*)macroTile
                                      world:(World*)world
                                     minAge:(NSTimeInterval)minAge
                   blockToSavePhyscialBlock:(BOOL)blockToSavePhyscialBlock;
+ (void)recalculateLightingForPhysicalBlockIfNeeded:(PhysicalBlock*)physicalBlock
                                              world:(World*)world
                              clientLightBlockIndex:(int)clientLightBlockIndex
                                       forBlockhead:(Blockhead*)blockhead;
+ (void)updateSunLightRemovedForTile:(Tile*)tile
                               atPos:(intpair)pos
                               world:(World*)world;
+ (void)recursivelyRemoveAllSunLightWithList:(NSMutableArray*)openList
                                 openIndices:(NSMutableIndexSet*)openIndices
                         lightWasRemovedList:(NSMutableArray*)lightWasRemovedList
                               removeIndices:(NSMutableIndexSet*)removeIndices
                                       world:(World*)world
                                        minx:(int)minX
                                        maxX:(int)maxX;
+ (void)updateSunLightForTile:(Tile*)tile
                        atPos:(intpair)pos
                        world:(World*)world;
+ (void)recursivelyUpdateSunLightWithList:(NSMutableArray*)openList
                              openIndices:(NSMutableIndexSet*)openIndices
                                    world:(World*)world;

@end
