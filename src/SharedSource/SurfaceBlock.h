#import <Foundation/Foundation.h>

#import "DynamicObject.h"

/**
 * @class SurfaceBlock
 * @brief Placeholder! Please remember to fill this in.
 */
@interface SurfaceBlock : DynamicObject {
  int lastSaveContent;
  BOOL pingPong;
  BOOL currentlyRequiresPhysicalBlock;
  BOOL removeNextFrame;
  BOOL removeNextFrameEmpty;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeIfFloatingAndEmptyOfWater;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SurfaceBlock*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                      saveDict:(NSDictionary*)saveDict
                         cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SurfaceBlock*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                    atPosition:(intpair)pos
                         cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)takeAnyWaterFromTileAtPos:(intpair)otherPos tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)subtractWater:(int)amount
        fromOtherTile:(Tile*)otherTile
                atPos:(intpair)otherPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
