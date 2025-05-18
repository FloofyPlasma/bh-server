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

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)requiresPhysicalBlock;
- (void)removeFromMacroBlock;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4;
- (Vector)getLightRGB;
- (int)objectType;
- (void)initSubDerivedItems;

@end
