#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@class ArtificialLight;

@interface GlowBlock : DynamicObject {
  ArtificialLight* light;
  int tileType;
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (GlowBlock*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
- (GlowBlock*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_
                       tile:(Tile*)tile_;
- (Vector)getLightRGB;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
