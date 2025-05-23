#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <vector>

#import "MJMath.h"

@class Blockhead, CPTexture2D, ClownFish, MJSound, Shader, World;

@interface FishingRod : NSObject {
  World* world;
  Blockhead* blockhead;
  BOOL casting;
  std::vector<Vector2> lineLocations;
  Vector2 hookVelocity;
  Vector2 hookPos;
  Vector2 nextRealInHookPos;
  BOOL isInCastingAnimation;
  float castAnimationProgress;
  BOOL hookInAir;
  BOOL castingRight;
  Shader* shader;
  Shader* hookShader;
  CPTexture2D* itemsTexture;
  ClownFish* hookedFish;
  MJSound* reelInSound;
  float realInFraction;
  float* verts;
  BOOL valid;
  BOOL done;
  BOOL isNet;
}

@property (readonly) Blockhead* blockhead; // @synthesize blockhead;
@property Vector2 hookPos; // @synthesize hookPos;
@property BOOL castingRight; // @synthesize castingRight;
@property BOOL hookInAir; // @synthesize hookInAir;
@property float castAnimationProgress; // @synthesize castAnimationProgress;
@property BOOL isInCastingAnimation; // @synthesize isInCastingAnimation;
- (void)blockheadUnloaded:(id)arg1;
- (void)setPaused:(BOOL)arg1;
- (id)hookedFish;
- (void)setHookedFish:(id)arg1;
- (Vector2)hookedFishDirection;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)directionalSwipe:(Vector2)arg1;
- (BOOL)isCasting;
- (Vector2)cameraPos;
@property BOOL valid;
- (void)dealloc;
- (id)initWithWorld:(id)arg1 blockhead:(id)arg2 cache:(id)arg3;

@end
