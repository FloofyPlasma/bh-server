#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

/**
 * @class WorldHelper
 * @brief Placeholder! Please remember to fill this in.
 */
@interface WorldHelper : NSObject {
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (BOOL)clientMacroTileRequestCanBeCancelledAtMacroPos:(intpair)macroPos
                                                 world:(World*)world;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (BOOL)checkIfMacroTileCanBeDecommissioned:(MacroTile*)macroTile
                                      world:(World*)world
                                     minAge:(NSTimeInterval)minAge
                   blockToSavePhyscialBlock:(BOOL)blockToSavePhyscialBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)recalculateLightingForPhysicalBlockIfNeeded:(PhysicalBlock*)physicalBlock
                                              world:(World*)world
                              clientLightBlockIndex:(int)clientLightBlockIndex
                                       forBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)updateSunLightRemovedForTile:(Tile*)tile
                               atPos:(intpair)pos
                               world:(World*)world;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)recursivelyRemoveAllSunLightWithList:(NSMutableArray*)openList
                                 openIndices:(NSMutableIndexSet*)openIndices
                         lightWasRemovedList:(NSMutableArray*)lightWasRemovedList
                               removeIndices:(NSMutableIndexSet*)removeIndices
                                       world:(World*)world
                                        minx:(int)minX
                                        maxX:(int)maxX;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)updateSunLightForTile:(Tile*)tile
                        atPos:(intpair)pos
                        world:(World*)world;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (void)recursivelyUpdateSunLightWithList:(NSMutableArray*)openList
                              openIndices:(NSMutableIndexSet*)openIndices
                                    world:(World*)world;

@end
