#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <vector>

#import "MJMath.h"

@class Blockhead, CPTexture2D, ClownFish, MJSound, Shader, World, CPCache;

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
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)setPaused:(BOOL)paused;
- (ClownFish*)hookedFish;
- (void)setHookedFish:(ClownFish*)hookedFish_;
- (Vector2)hookedFishDirection;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)directionalSwipe:(Vector2)vec;
- (BOOL)isCasting;
- (Vector2)cameraPos;
@property BOOL valid;
- (void)dealloc;
- (id)initWithWorld:(World*)world_ blockhead:(Blockhead*)blockhead_ cache:(CPCache*)cache_;

@end
