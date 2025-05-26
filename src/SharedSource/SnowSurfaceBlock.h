#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@class NSMutableDictionary;

@interface SnowSurfaceBlock : DynamicObject {
  float temperature;
  float partialContent;
  NSMutableDictionary* saveDictCached;
  float rainRandomTimer;
}

@property float partialContent; // @synthesize partialContent;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (BOOL)removeIfFloating;
- (void)removeAllSnow;
- (void)updateSnowContent:(BOOL)forceUpdate tile:(Tile*)tile;
- (void)updateGroundFrozen:(Tile*)belowTile tile:(Tile*)tile;
- (void)spreadGrass:(Tile*)belowTile tile:(Tile*)tile;
- (void)updateRain:(float)rainFraction dt:(float)dt;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)updateInTimeSinceSaved;
- (void)removeFromMacroBlock;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (SnowSurfaceBlock*)initWithWorld:(World*)world_
                      dynamicWorld:(DynamicWorld*)dynamicWorld
                          saveDict:(NSDictionary*)saveDict
                             cache:(CPCache*)cache_;
- (SnowSurfaceBlock*)initWithWorld:(World*)world_
                      dynamicWorld:(DynamicWorld*)dynamicWorld
                        atPosition:(intpair)pos
                             cache:(CPCache*)cache_;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
