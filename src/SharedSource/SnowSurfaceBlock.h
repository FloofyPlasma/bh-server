#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@class NSMutableDictionary;

/**
 * @class SnowSurfaceBlock
 * @brief Placeholder! Please remember to fill this in.
 */
@interface SnowSurfaceBlock : DynamicObject {
  float temperature;
  float partialContent;
  NSMutableDictionary* saveDictCached;
  float rainRandomTimer;
}

@property float partialContent; // @synthesize partialContent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)removeIfFloating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeAllSnow;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateSnowContent:(BOOL)forceUpdate tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGroundFrozen:(Tile*)belowTile tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)spreadGrass:(Tile*)belowTile tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateRain:(float)rainFraction dt:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateInTimeSinceSaved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SnowSurfaceBlock*)initWithWorld:(World*)world_
                      dynamicWorld:(DynamicWorld*)dynamicWorld
                          saveDict:(NSDictionary*)saveDict
                             cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SnowSurfaceBlock*)initWithWorld:(World*)world_
                      dynamicWorld:(DynamicWorld*)dynamicWorld
                        atPosition:(intpair)pos
                             cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
