#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct FireCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
};

@class ArtificialLight, CPTexture2D, Shader;

@interface FireObject : DynamicObject {
  float burnTimer;
  float spreadTimers[4];
  ArtificialLight* light;
  Shader* shader;
  CPTexture2D* texture;
  int animationLoopIndex;
  float animationLoopTimer;
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)requiresPhysicalBlock;
- (void)removeFromMacroBlock;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                  atPosition:(intpair)pos
                       cache:(CPCache*)cache_;
- (Vector)getLightRGB;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
