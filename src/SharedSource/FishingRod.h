#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <vector>

#import "MJMath.h"

@class Blockhead, CPTexture2D, ClownFish, MJSound, Shader, World, CPCache;

/**
 * @class FishingRod
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @property blockhead
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Blockhead* blockhead; // @synthesize blockhead;
@property Vector2 hookPos; // @synthesize hookPos;
@property BOOL castingRight; // @synthesize castingRight;
@property BOOL hookInAir; // @synthesize hookInAir;
@property float castAnimationProgress; // @synthesize castAnimationProgress;
@property BOOL isInCastingAnimation; // @synthesize isInCastingAnimation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ClownFish*)hookedFish;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setHookedFish:(ClownFish*)hookedFish_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)hookedFishDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)directionalSwipe:(Vector2)vec;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCasting;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPos;
@property BOOL valid;
/**
 * @brief Deallocates this FishingRod, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithWorld:(World*)world_ blockhead:(Blockhead*)blockhead_ cache:(CPCache*)cache_;

@end
