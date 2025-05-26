#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@interface SurfaceBlock : DynamicObject {
  int lastSaveContent;
  BOOL pingPong;
  BOOL currentlyRequiresPhysicalBlock;
  BOOL removeNextFrame;
  BOOL removeNextFrameEmpty;
}

- (BOOL)requiresPhysicalBlock;
- (void)removeIfFloatingAndEmptyOfWater;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)removeFromMacroBlock;
- (SurfaceBlock*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                      saveDict:(NSDictionary*)saveDict
                         cache:(CPCache*)cache_;
- (SurfaceBlock*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                    atPosition:(intpair)pos
                         cache:(CPCache*)cache_;
- (BOOL)takeAnyWaterFromTileAtPos:(intpair)otherPos tile:(Tile*)tile;
- (void)subtractWater:(int)amount
        fromOtherTile:(Tile*)otherTile
                atPos:(intpair)otherPos;
- (DynamicObjectType)objectType;

@end
